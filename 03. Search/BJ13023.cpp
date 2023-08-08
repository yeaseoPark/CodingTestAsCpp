#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> DATA[2000];
int visited[2000];
bool res = false;

// 3.2 DFS ���� 
void DFS(int x, int depth){
	
	// 3.2.1 ���� ���̰� 4�̻��̸� �� �̻� Ž�� �ʿ� x
	// -> ���� ����(true) 
	if(depth >= 4 || res == true) {
		res = true;
		return;
	}
	
	// 3.2.2 ������ ��忡 ����� �ٸ� ��尡 ���� Ž������ �ʾҴٸ�
	// Ž�� ���� 
	int next;
    visited[x] = true;
	for(int idx = 0; idx < DATA[x].size(); idx ++){
		next = DATA[x][idx];
		if(visited[next]) continue;
		DFS(next, depth + 1);
	}
    visited[x] = false;
}

int main(void){
	
	// 1. N, M �ޱ�
	cin >> N; cin >> M;
	
	// 2. ������ �ޱ�
	int v1, v2;
	for(int i = 0; i < M; i ++){
		cin >> v1; cin >> v2;
		DATA[v1].push_back(v2);
		DATA[v2].push_back(v1);
	}
	
	// 3. ��� ��忡 ���ؼ� DFS
	for(int start = 0; start < N ; start ++){
		// 3.1 visited �ʱ�ȭ 
		fill_n(visited, N, false);
		// 3.2 DFS ����(��� DFS Ȯ��) 
		DFS(start, 0);
		if(res == true) {
			break;
		}
	}
	
    // 4. ��� ���
	cout << res;
	return 0;
}

