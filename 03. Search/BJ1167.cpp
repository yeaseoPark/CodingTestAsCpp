#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
// pair(nextNode, 거리) 
vector<pair<int, int> > data[100001];

int BFS(int start){
	int res = -999;
	// 1. dfs 자원 선언: pair(node 번호, start 부터의 거리) 
	queue<pair<int, int> > q;
	int visited[N+1];
	
	// 2. start 갱신
	q.push(make_pair(start, 0));
	visited[start] = true;
	
	// 3. BFS 만들기
	pair<int, int> now;
	int now_node, now_distance, next_node, next_distance;
	
	// 3.1 큐가 빌 때까지 pop 
	while(!q.empty()){
		now = q.front();
		now_node = now.first;
		now_distance = now.second;
		q.pop();

		// 3.2 꺼낸 노드에서 이동할 수 있는 노드들 중에서		
		for(int next = 0; next < data[now_node].size() ; next ++){
			next_node = data[now_node][next].first;
			next_distance = data[now_node][next].second + now_distance;
			printf("%d \n", next_distance);
			// 3.3 방문하지 않은 노드는 q에 넣고 visit 갱신 
			if(!visited[next_node]){
				q.push(make_pair(next_node, next_distance));
				visited[next_node] = true;
				cout << next_distance << endl;
				
				// 3.4 만약 갱신할 거리가 res 보다 크다면 해당 거리로 res 갱신 
				res = max(res, next_distance);
			}
		} // for end
		
	} // while end
	
	// 4. 최대 길이 출력 
	cout << res << endl;;
	cout <<"**********" << endl;
	return res;
} // BFS end


int main(void){
	
	// 0. 데이터 받기 
	cin >> N;
	int parent = 0, child, distance;
	
	for(int i = 0; i < N; i ++){
		cin >> parent;
		
		cin >> child;
			
		while(child != -1){
			cin >> distance;
			data[parent].push_back(make_pair(child, distance));
			data[child].push_back(make_pair(parent, distance));
			cin >> child;
		}
	}
	
	// 디버깅용 코드 
	for(int i = 1; i <= N; i ++){
		for(int j = 0; j < data[i].size(); j ++){
			printf("(%d, %d)       ", data[i][j].first, data[i][j].second);
		}
		printf("\n");
	}
	
	// 4. 모든 노드들에 대해 bfs 수행
	int res = -999;
	for(int start = 1; start <= N; start ++) res = max(res, BFS(start));
	
	// 5. 결과 출력
	cout << res; 
	
	return 0;
}
