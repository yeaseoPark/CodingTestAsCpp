#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MOVEM[] = {0, 0, -1, 1, 0, 0};
const int MOVEN[] = {0, 0, 0, 0, -1, 1};
const int MOVEH[] = {-1, 1, 0, 0, 0, 0};

int M, N, H;
int TOMATO[100][100][100];
int visited[100][100][100];

struct Node{
	// m = 가로좌표, n = 세로좌표, h = 높이좌표
	// day = 익는데 걸리는 시간 
	int h;
	int n;
	int m;
	int day;
	
	Node(){}
	
	Node(int h, int n, int m, int day){
		this -> m = m;
		this -> n = n;
		this -> h = h;
		this -> day = day;
	}
};

int main(void){
	
	// 1. M, N, H 구하기
	cin >> M; cin >> N; cin >> H;
	
	// 2. TOMATO 입력 받기
	for(int h = 0; h < H; h ++){
		for(int n = 0; n < N; n ++){
			for(int m = 0; m < M; m ++) cin >> TOMATO[h][n][m];
		}
	}
	
	// 3. BFS 사용하기
	// 3.1 자원 선언
	/*
	- q = BFS 방문용 자원; Node 참고 
	*/
	queue<Node> q;
	
	// 3.2 0일차 익은 토마토에 대해서 갱신
	for(int h = 0; h < H; h ++){
		for(int n = 0; n < N; n ++){
			for(int m = 0; m < M; m ++) {
				if(TOMATO[h][n][m] == 1){
					q.push(Node(h, n, m, 0));
					visited[h][n][m] = true;
				}
				if(TOMATO[h][n][m] == -1){
					visited[h][n][m] = true;
				}
			}
		}
	}
	
	// 3.3 1일차부터 BFS로 토마토 후숙시키기
	Node cur;
	int next_h, next_n, next_m;
	while(!q.empty()){
		cur = q.front();
		q.pop();		
		
		for(int move = 0; move < 6; move ++){
			next_h = cur.h + MOVEH[move];
			next_n = cur.n + MOVEN[move];
			next_m = cur.m + MOVEM[move];
			
			if(next_h < 0 || next_n < 0 || next_m < 0) continue;
			if(next_h > H || next_n > N || next_m > M) continue;
			if(visited[next_h][next_n][next_m]) continue;
			
			if(TOMATO[next_h][next_n][next_m] == 0){
				TOMATO[next_h][next_n][next_m] = 1;
				visited[next_h][next_n][next_m] = true;
				q.push(Node(next_h, next_n, next_m, cur.day + 1));
			}
		}
	}
	
	
	cout << "tomato" << endl;
	for(int h = 0; h < H; h ++){
		for(int n = 0; n < N; n ++){
			for(int m = 0; m < M; m ++) {
				printf("%d ", TOMATO[h][n][m]);
			}
			cout << endl;
		}
		cout << endl;
	}
	
	cout << "visited" << endl;
	for(int h = 0; h < H; h ++){
		for(int n = 0; n < N; n ++){
			for(int m = 0; m < M; m ++) {
				printf("%d ", visited[h][n][m]);
			}
			cout << endl;
		}
		cout << endl;
	}
	// 3.4 BFS의 가장 긴 높이값 반환(day) 
	
	// 4. 안 익은 토마토 찾기

	
	// 5. 결과 출력
	// 5.1 만일 안 익은 토마토가 있다면 -1 출력
	// 5.2 안 익은 토마토가 없다면 BFS 반환값 출력 
	
	return 0;
}
