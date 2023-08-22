#include <iostream>
#define DIV 1000000007

using namespace std;

int main(void){
	// 1. N, L, R ���� 
	int N, L, R;
	cin >> N >> L >> R;
	// 2. D �ʱ�ȭ
	long long D[N+1][N+1][N+1];
	fill(&D[0][0][0], &D[N][N][N+1], 0);
	D[1][1][1] = 1;
	D[2][2][1] = 1;
	D[2][1][2] = 1;
	
	// 3. ��ȭ��
	/*
	���̵��
	- D[N][L][R] = D[N-1][L-1][R] + D[N-1][L][R-1] + D[N-1][L][R] * (N-2)
	- �̹� ������ �ǹ����� ���� ���� �ǹ��� �ϳ� �� ����ٰ� �����ϸ� �� 
	*/

	for(int n = 3; n <= N; n++){
		for(int l = 1; l <= L; l ++){
			for(int r = 1; r <= R; r++){
				D[n][l][r] = (D[n-1][l-1][r] + D[n-1][l][r-1] + D[n-1][l][r] * (n-2)) % DIV;
			}
		}
	} 
	
	// 4. ���
	cout << D[N][L][R]; 
	
	return 0;
} 
