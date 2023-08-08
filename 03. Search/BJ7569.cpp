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
	// m = ������ǥ, n = ������ǥ, h = ������ǥ
	// day = �ʹµ� �ɸ��� �ð� 
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
	
	// 1. M, N, H ���ϱ�
	cin >> M; cin >> N; cin >> H;
	
	// 2. TOMATO �Է� �ޱ�
	for(int h = 0; h < H; h ++){
		for(int n = 0; n < N; n ++){
			for(int m = 0; m < M; m ++) cin >> TOMATO[h][n][m];
		}
	}
	
	// 3. BFS ����ϱ�
	// 3.1 �ڿ� ����
	/*
	- q = BFS �湮�� �ڿ�; Node ���� 
	*/
	queue<Node> q;
	
	// 3.2 0���� ���� �丶�信 ���ؼ� ����
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
	
	// 3.3 1�������� BFS�� �丶�� �ļ���Ű��
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
	// 3.4 BFS�� ���� �� ���̰� ��ȯ(day) 
	
	// 4. �� ���� �丶�� ã��

	
	// 5. ��� ���
	// 5.1 ���� �� ���� �丶�䰡 �ִٸ� -1 ���
	// 5.2 �� ���� �丶�䰡 ���ٸ� BFS ��ȯ�� ��� 
	
	return 0;
}
