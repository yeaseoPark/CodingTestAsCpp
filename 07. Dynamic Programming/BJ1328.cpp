#include <iostream>
#define DIV 1000000007

using namespace std;

int main(void){
	// 1. N, L, R 갱신 
	int N, L, R;
	cin >> N >> L >> R;
	// 2. D 초기화
	long long D[N+1][N+1][N+1];
	fill(&D[0][0][0], &D[N][N][N+1], 0);
	D[1][1][1] = 1;
	D[2][2][1] = 1;
	D[2][1][2] = 1;
	
	// 3. 점화식
	/*
	아이디어
	- D[N][L][R] = D[N-1][L-1][R] + D[N-1][L][R-1] + D[N-1][L][R] * (N-2)
	- 이미 세워진 건물에서 가장 작은 건물을 하나 더 세운다고 생각하면 됨 
	*/

	for(int n = 3; n <= N; n++){
		for(int l = 1; l <= L; l ++){
			for(int r = 1; r <= R; r++){
				D[n][l][r] = (D[n-1][l-1][r] + D[n-1][l][r-1] + D[n-1][l][r] * (n-2)) % DIV;
			}
		}
	} 
	
	// 4. 출력
	cout << D[N][L][R]; 
	
	return 0;
} 
