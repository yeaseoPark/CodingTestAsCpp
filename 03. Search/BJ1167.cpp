#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int V;
vector<pair<int, int> > DATA[100001];

bool compare(pair<int, int> &a, pair<int, int> &b){
	return a.second > b.second;
}

// 3. BFS 실행(start 에서부터 가장 긴 거리와 가장 먼 노드 return) 
pair<int, int> BFS(int start){
	// 3.1 필요 자원 선언
	queue<pair<int, int> > q;
	int visited[V+1];
	fill_n(visited, V+1, 0);
	int res_dist = -999;
	int res_node;
	
	// 3.2 START 초기화
	q.push(make_pair(start, 0));
	visited[start] = true;
	
	// 3.3 q가 빌 때까지 방문
	pair<int, int> now;
	int now_node, now_dist, next_node, next_dist;
	while(!q.empty()){
		now = q.front();
		q.pop();
		now_node = now.first;
		now_dist = now.second;
	
		
		for(int next = 0; next <DATA[now_node].size(); next ++){
			next_node = DATA[now_node][next].first;
			next_dist = DATA[now_node][next].second + now_dist;
			
			if(visited[next_node] == 0){
				q.push(make_pair(next_node, next_dist));
				visited[next_node] = true;
				if(res_dist < next_dist){
					res_node = next_node;
					res_dist = next_dist;
				}
			} // if end
		} // for end
	} // while end
	
	return make_pair(res_node, res_dist);
} // BFS END


int main(void){
	
	// 1. 데이터 받기
	cin >> V;
	int v1, v2, dist;
	for(int idx = 0; idx < V; idx ++){
		cin >> v1;
		cin >> v2;
		
		while(v2 != -1){
			cin >> dist;
			DATA[v1].push_back(make_pair(v2, dist));
			DATA[v2].push_back(make_pair(v1, dist));
			cin >> v2;
		}
	}
	
	// 2. 데이터 오름차순 정렬
	for(int idx = 1; idx <= V; idx ++) sort(DATA[idx].begin(), DATA[idx].end(), compare);
	
	
	// 3. 임의의 점에서 bfs -> 임의의 점에서 가장 먼 곳에서 다시 한 번 bfs 
	pair<int, int> first_res, second_res;
	
	first_res = BFS(1);
	second_res = BFS(first_res.first);
	
	
	cout << max(first_res.second, second_res.second) << endl;
	
	return 0;
}


