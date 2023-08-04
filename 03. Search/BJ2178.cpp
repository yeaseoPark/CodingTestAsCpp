#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int ROWMOVE[] = {1, 0, -1, 0};
const int COLMOVE[] = {0, 1, 0, -1};

int N, M;
int G[102][102];
int visited[102][102];

void bfs(int start_row, int start_col){
	// 1. 필요 자원 선언 pair = (row, col)
	queue<pair<int, int> > q;
	
	// 2. 첫 시작 갱신
	q.push(make_pair(start_row, start_col));
	visited[start_row][start_col] = true;
	
	// 3. BFS 시작
	pair<int, int> now;
	int next_row, next_col;
	
	while(!q.empty()){
		now = q.front();
		q.pop();
		
		for(int move = 0; move < 4; move ++){
			next_row = now.first + ROWMOVE[move];
			next_col = now.second + COLMOVE[move];
			
			if(visited[next_row][next_col]) continue;
			
			if(G[next_row][next_col] != 0){
				visited[next_row][next_col] = true;
				q.push(make_pair(next_row, next_col));
				G[next_row][next_col] = G[now.first][now.second] + 1;
			}
		} // for end
	} // while end
} // BFS function end

int main(void){
	
	// 1. N, M 받기 
	scanf("%d %d", &N, &M);
	
	// 2. 그래프 받기
	for(int row = 1; row <= N; row ++){
		char s[M];
		scanf("%s", &s);
		
		for(int col = 1; col <= M; col ++) G[row][col] = s[col-1] - '0';
	}
	
	// 3. BFS 선언
	bfs(1, 1);
	
	// 4. 결과 출력
	printf("%d", G[N][M]); 
	
	return 0;
}
