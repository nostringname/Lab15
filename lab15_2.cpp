#include<iostream>
using namespace std;

const int N = 5;

void inputMatrix(double [][N]);

void findLocalMax(const double [][N], bool [][N]);

void showMatrix(const bool [][N]);

int main(){
	double A[N][N]; 
	bool B[N][N]; 
	cout << "Input the matrix.....\n";
	inputMatrix(A);
	findLocalMax(A,B);
	cout << "Result is \n";
	showMatrix(B);
	return 0;
}

void inputMatrix(double A[][N]){
	for(int i =0;i<N;i++) {
		cout << "Row " << i+1 << ": ";
		for(int j=0;j<N;j++) {
			cin >> A[i][j];
		}
	}
}

void findLocalMax(const double A[][N],bool B[][N]){

	for (int i =0;i<N;i++){
		B[0][i] = 0; 
	}

	for(int y = 1;y<N;y++){
		for (int z = 0;z <N;z++){
			if (z == 1 || z == 2 || z == 3) continue;
			B[y][z] = 0;
		}
	}

	for (int i =0;i<N;i++){
		B[N-1][i] = 0; 
	}

	for(int i=1;i<=N-2;i++){
		for(int z=1;z<=N-2;z++){
			if((A[i][z] >= A[i-1][z]) && (A[i][z] >= A[i+1][z]) && (A[i][z] >= A[i][z+1]) && (A[i][z] >= A[i][z-1])){
				B[i][z] = 1;
			}
			else B[i][z] = 0;
		}
	}
	
}

void showMatrix(const bool B[][N]){
	for(int i=0;i<N;i++){
		for(int r = 0;r<N;r++){
			cout << B[i][r] << " ";
		}
		cout << endl;
	}
}

