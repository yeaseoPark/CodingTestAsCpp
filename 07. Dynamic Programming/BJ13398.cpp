#include <iostream>

using namespace std;

/*
D[idx][0] = 0�ε�������  idx �ε��������� ���� ��
idx ���� �����ϸ鼭 ���� ���� ���� �� �� ���� ū ��
D[idx][1] = 0�ε�������  idx �ε��������� ���� ��
idx ���� �����ϸ鼭 ���� �� �� �� ���� ū ��
*/

int D[100000][2];
int N;

int main(void){
	cin >> N;
	
	int tmp;
	cin >> tmp;

	D[0][0] = tmp;
	D[0][1] = tmp;

	int result = tmp;
	
	for(int idx = 1; idx < N; idx ++){
		cin >> tmp;
		D[idx][1] = max(D[idx-1][0], D[idx-1][1] + tmp);
		D[idx][0] = max(D[idx-1][0] + tmp, tmp);
		
		result = max(result, max(D[idx][1], D[idx][0]));
	}
	
	
	cout << result;
	
	return 0;
}
