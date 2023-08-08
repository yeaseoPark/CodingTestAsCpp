#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> DATA[2000];
int visited[2000];
bool res = false;

// 3.2 DFS 수행 
void DFS(int x, int depth){
	
	// 3.2.1 만약 깊이가 4이상이면 더 이상 탐색 필요 x
	// -> 조건 충족(true) 
	if(depth >= 4 || res == true) {
		res = true;
		return;
	}
	
	// 3.2.2 현재의 노드에 연결된 다른 노드가 아직 탐색하지 않았다면
	// 탐색 시작 
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
	
	// 1. N, M 받기
	cin >> N; cin >> M;
	
	// 2. 데이터 받기
	int v1, v2;
	for(int i = 0; i < M; i ++){
		cin >> v1; cin >> v2;
		DATA[v1].push_back(v2);
		DATA[v2].push_back(v1);
	}
	
	// 3. 모든 노드에 대해서 DFS
	for(int start = 0; start < N ; start ++){
		// 3.1 visited 초기화 
		fill_n(visited, N, false);
		// 3.2 DFS 수행(상단 DFS 확인) 
		DFS(start, 0);
		if(res == true) {
			break;
		}
	}
	
    // 4. 결과 출력
	cout << res;
	return 0;
}

