#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = INT_MAX-100;
struct Node{
	int arrive;
	int weight;
	
	Node(){
	}
	Node(int arrive, int weight){
		this -> arrive = arrive;
		this -> weight = weight;
	}
	
	bool operator < (const Node n) const{
		return this -> weight > n.weight;
	}
};

int findMinDistIndex(int * visited, int * result, int V){
	int min = INF;
	int res = 0;
	for(int idx = 1; idx < V; idx ++){
		if(min > result[idx] && !visited[idx]){
			res = idx;
			min = result[idx];
		}
	}
	
	return res;
}


 
int main(void){
	
	// 0. 입력 변수 선언 및 받기 
	int V, E;
	int K;
	
	cin >> V >> E;
	cin >> K;
	
	// 1. 그래프 받기
	vector<Node> G[V+1];
	int u, v, w;
	
	for(int phs = 0; phs < E; phs ++){
		cin >> u >> v >> w;
		G[u].push_back(Node(v, w));
	}
	
	// 2. 다익스트라 자원
	int visited[V+1];
	fill_n(visited, V+1, false);
	int result[V+1];
	fill_n(result, V+1, INF);
	
	priority_queue<Node> pq;
	pq.push(Node(K, 0));
	result[K] = 0;
	
	// 3. 다익스트라 실행
	while(!pq.empty()){
		Node cur = pq.top();
		pq.pop();
		
		if(visited[cur.arrive]) continue;
		visited[cur.arrive] = true;
		
		for(int idx = 0; idx < (int) G[cur.arrive].size(); idx ++){
			Node next_node = G[cur.arrive][idx];
			int next_arrive = next_node.arrive;
			int next_weight = next_node.weight;
			
			if(result[next_arrive] > result[cur.arrive] + next_weight){
				result[next_arrive] = result[cur.arrive] + next_weight;
				pq.push(Node(next_arrive, result[next_arrive]));
			}
		}
	} 
	
	// 4. 결과 출력
	for(int idx = 1; idx <= V; idx ++){
		if(result[idx] == INF) cout <<"INF\n";
		else cout << result[idx] <<"\n";
	} 
	
	 
	return 0;
}
