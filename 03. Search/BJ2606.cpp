#include <iostream>

using namespace std;

const int START = 1;

int N, M;
int DATA[101][101];

int visited[101];
int answer = 0;

void DFS(int x){
	if(visited[x]) return;
	answer ++;
	visited[x] = true;
	
	for(int next = 1; next <= N; next ++){
		if(DATA[x][next] == true) DFS(next);
		
	}
}

int main(void){
	
	// 1. N�� M �ޱ�
	cin >> N; cin >> M;
	
	// 2. �׷��� �ޱ�
	int v1, v2;
	for(int idx = 0; idx < M; idx ++){
		cin >> v1 >> v2;
		DATA[v1][v2] = true;
		DATA[v2][v1] = true;
	}
	
	// 3. 1���� start �� �Ͽ� dfs
	DFS(START);
	
	// 4. ��� ���(1�� ��ǻ�� ����) 
	cout << answer - 1; 
	
	
	return 0;
}
