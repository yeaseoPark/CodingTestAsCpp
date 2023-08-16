#include <iostream>
#include <queue>

using namespace std;

int N, M, V;
int G[1001][1001];
int visited[1001];

void dfs(int cur){
	if(visited[cur]) return;
	cout << cur << " ";
	visited[cur] = true;
	
	for(int next = 1; next <= N; next ++){
		if(G[cur][next] == 1) dfs(next);
	}
}

void bfs(int start){
	queue<int> q;
	
	visited[start] = true;
	q.push(start);
	
	int cur;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		cout << cur << " ";
		
		for(int next = 1; next <= N; next ++){
			if(G[cur][next] != 1) continue;
			if(visited[next]) continue;
			visited[next] = true;
			q.push(next);
		}
	}
}

int main(void){
	
	cin >> N >> M >> V;
	
	int v1, v2;
	for(int phs = 0; phs < M; phs ++){
		cin >> v1 >> v2;
		G[v1][v2] = 1;
		G[v2][v1] = 1;
	}
	fill_n(visited, N+1, 0);
	dfs(V);
	cout <<"\n";
	fill_n(visited, N+1, 0);
	bfs(V);
	return 0;
}
