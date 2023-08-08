#include <iostream>

using namespace std;

/*
�Է� ���� 
- N = ��ü ����� ��
- H1, H1 = �̼��� ����ؾ� �ϴ� �� ����� ��ȣ
- M = �θ� �ڽİ��� ������ ��
- G ; G[i][j] = 1�̸� i �� j �� �θ��ڽ� �����̴� 
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
	// 1. N, H1, H2, M �ޱ�
	cin >> N; cin>> H1; cin >> H2; cin >> M;
	// 2. G �ޱ�
	int h1, h2;
	for(int phs = 0; phs < M; phs ++){
		cin >> h1; cin >> h2;
		G[h1][h2] = true;
		G[h2][h1] = true;
	} 
	
	// 3. DFS �� �̼� ���
	DFS(H1, 0); 
	
	// 4. ��� ���
	cout << answer; 
	return 0;
} 
