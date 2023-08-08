#include <iostream>

using namespace std;

/*
입력 변수 
- N = 전체 사람의 수
- H1, H1 = 촌수를 계산해야 하는 두 사람의 번호
- M = 부모 자식간의 관계의 수
- G ; G[i][j] = 1이면 i 와 j 는 부모자식 관계이다 
*/
int N, H1, H2, M;
int G[101][101];

int visited[101];
int answer = -1;

void DFS(int cur, int depth){
	if(visited[cur]) return;
	if(cur == H2){
		answer = depth;
		return;
	}
	visited[cur] = true;
	for(int next = 1; next <= N; next ++){
		if(G[cur][next] == true) DFS(next, depth + 1);
	}
}

int main(void){
	// 1. N, H1, H2, M 받기
	cin >> N; cin>> H1; cin >> H2; cin >> M;
	// 2. G 받기
	int h1, h2;
	for(int phs = 0; phs < M; phs ++){
		cin >> h1; cin >> h2;
		G[h1][h2] = true;
		G[h2][h1] = true;
	} 
	
	// 3. DFS 로 촌수 계산
	DFS(H1, 0); 
	
	// 4. 결과 출력
	cout << answer; 
	return 0;
} 
