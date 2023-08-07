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
	// 1. N, M 받기
	cin >> N; cin >> M;
	
	// 2. 그래프 받기(양방향; 방향 x)
	int v1, v2;
	for(int i = 0; i < M; i ++){
		cin >> v1;
		cin >> v2;
		
		GRAPH[v1][v2] = 1;
		GRAPH[v2][v1] = 1;
	}
	
	// 3. 모든 노드가 visited 가 될 때 까지 dfs
	// dfs 를 수행한 횟수가 그래프의 개수
	int res = 0; 
	for(int start = 1; start <= N; start ++){
		if(visited[start]) continue;
		DFS(start);
		res ++;
	}
	
	// 4. 결과 출력
	cout << res; 
	return 0;
}
