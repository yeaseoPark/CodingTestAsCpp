#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;
int GRAPH[1001][1001];
int visited[1001];

void DFS(int x){
	if(visited[x]) return;
	visited[x] = true;
	
	for(int next = 1; next <= N; next ++){
		if(GRAPH[x][next] == 1) DFS(next);
	}
}

int main(void){
	// 1. N, M �ޱ�
	cin >> N; cin >> M;
	
	// 2. �׷��� �ޱ�(�����; ���� x)
	int v1, v2;
	for(int i = 0; i < M; i ++){
		cin >> v1;
		cin >> v2;
		
		GRAPH[v1][v2] = 1;
		GRAPH[v2][v1] = 1;
	}
	
	// 3. ��� ��尡 visited �� �� �� ���� dfs
	// dfs �� ������ Ƚ���� �׷����� ����
	int res = 0; 
	for(int start = 1; start <= N; start ++){
		if(visited[start]) continue;
		DFS(start);
		res ++;
	}
	
	// 4. ��� ���
	cout << res; 
	return 0;
}
