#include <iostream>
#include <algorithm>
#include <queue> 

using namespace std;

const int MMOVE[6] = {0, 0, 0, 0, 1, -1};
const int NMOVE[6] = {0, 0, 1, -1, 0, 0};
const int HMOVE[6] = {1, -1, 0, 0, 0, 0};

int M, N, H;
// TOMATAO[H][N][M] visited[H][N][M]
int TOMATO[100][100][100];
int visited[100][100][100];

int max_day = -1;

struct Node{
	int h;
	int n;
	int m;
	
	Node(){
		
	}
	
	Node(int h, int n, int m){
		this -> h = h;
		this -> n = n;
		this -> m = m;
	}
};

void showTomato(){
	for(int h = 0; h < H; h++){
		for(int n = 0; n < N; n ++){
			for(int m = 0; m < M; m ++) printf("%d ", TOMATO[h][n][m]);
			printf("\n");
		}
		printf("\n");
	} 
}

void bfs(){
	// 1. 초기 자원 선언
	// 1.1 visited 초기화 
	for(int h = 0; h < H; h++){
		for(int n = 0; n < N; n ++){
			for(int m = 0; m < M; m ++) visited[h][n][m] = false;
		}
	}
	// 1.2 queue 선언 : pair<node, day>
	queue<pair<Node, int> > q;
	
	// 2. 초기값 넣기
	for(int h = 0; h < H; h++){
		for(int n = 0; n < N; n ++){
			for(int m = 0; m < M; m ++){
				if(TOMATO[h][n][m] == 1){
					q.push(make_pair(Node(h, n, m), 0));
					visited[h][n][m] = true;
				}
				if(TOMATO[h][n][m] == -1){
					visited[h][n][m] = true;
				}
			}
		}
	} 
	
	// 3. 전체 노드 탐색
	pair<Node, int> cur;
	int next_h, next_n, next_m;
	while(!q.empty()){
		cur = q.front();
		q.pop();
		max_day = max(max_day, cur.second);
		
		for(int move = 0; move < 6; move ++){
			next_h = cur.first.h + HMOVE[move];
			next_n = cur.first.n + NMOVE[move];
			next_m = cur.first.m + MMOVE[move];
			
			// 3.1 상자 밖을 벗어나면 안 된다 
			if(next_h < 0 || next_n < 0 || next_m < 0) continue;
			if(next_h >= H || next_n >= N || next_m >= M) continue;
			// 3.2 방문한 노드를 재방문하지 않는다. 
			if(visited[next_h][next_n][next_m]) continue;
			// 3.3 익지않은 토마토만 익힌다. 
			if(TOMATO[next_h][next_n][next_m] != 0) continue;
			
			TOMATO[next_h][next_n][next_m] = 1;
			q.push(make_pair(Node(next_h, next_n, next_m), cur.second + 1));
			visited[next_h][next_n][next_m] = true;
		}
	} 
}

bool existZero(){
	for(int h = 0; h < H; h++){
		for(int n = 0; n < N; n ++){
			for(int m = 0; m < M; m ++) {
				if(TOMATO[h][n][m] == 0) return true;
			}
		}
	}
	
	return false;
}

int main(void){
	// 1. M, N, H
	cin >> M >> N >> H;
	
	// 2. 토마토 받기
	for(int h = 0; h < H; h++){
		for(int n = 0; n < N; n ++){
			for(int m = 0; m < M; m ++) cin >> TOMATO[h][n][m];
		}
	} 
	// 3. bfs
	bfs();
	
	// 4. 출력
	if(existZero()){
		cout << "-1";
	} else{
		cout << max_day;
	}

	return 0;
}
