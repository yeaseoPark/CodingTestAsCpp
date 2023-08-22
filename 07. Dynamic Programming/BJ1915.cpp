#include <iostream>

using namespace std;

/*
���̵��
D[i][j] = (i,j)�� ������ ������ �ϴ� ���簢���� ����
D[i][j] ���� �ش� ��ǥ�� 1�̸� 
D[i-1][j-1], D[i-1][j], D[i][j-1] �� ��� ���� ���̸�
D[i][j] = D[i-1][j-1] + 1�̴�. 
*/ 


int main(void){
	// 1. N, M ������ �ޱ�
	int N, M;
	cin >> N >> M;
	
	// 2. �迭 ������ �ޱ�(��濡 0�� Wrapping �ϴ� ���)
	int Data[N+2][M+2];
	fill(&Data[0][0], &Data[N+1][M+2], 0);
	string tmp;
	for(int row = 1; row <= N; row ++){
		cin >> tmp;
		for(int col = 1; col <= M; col ++){
			Data[row][col] = tmp.at(col - 1) - '0';
		}
	} 
	
	// 3. ��ȭ�� D �ʱ�ȭ
	int D[N+2][M+2];
	fill(&D[0][0], &D[N+1][M+2], 0);
	
	// 4. ��ȭ�� ����
	int result = 0;
	for(int row = 1; row <= N; row ++){
		for(int col = 1; col <= M; col ++){
			if(Data[row][col] == 0) D[row][col] = 0;
			else{
				if(D[row-1][col-1] == D[row][col-1] &&
				   D[row-1][col-1] == D[row-1][col]){
				   	D[row][col] = D[row-1][col-1] + 1;
				   }
				else{
					D[row][col] = min(D[row-1][col-1], min(D[row-1][col], D[row][col-1])) + 1;
				}
			}
			
			result = max(result, D[row][col] * D[row][col]);
		}
	} 
	
	// 5. ���
	cout << result; 
	
	
	 
	return 0;
}
