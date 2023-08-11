#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;
const long long INF = LONG_LONG_MAX;
const int START = 1;

struct Node{
	int from;
	int to;
	int time;
	
	Node(){
	}
	
	Node(int from, int to, int time){
		this -> from = from;
		this -> to = to;
		this -> time = time;
	}
};

int N, M;
vector<Node> Edges;

int main(void){
	
	// 1. N, M 받기
	cin >> N >> M;
	
	// 2. Edges 받기
	int a, b, c;
	for(int phs = 0; phs < M; phs ++){
		cin >> a >> b >> c;
		Edges.push_back(Node(a, b, c));
	} 
	
	// 3. 벨만포드 자원 선언
	long long Result[N+1];
	fill_n(Result, N+1, INF);
	Result[START] = 0;
	
	// 4. N-1 번 반복
	for(int phase = 1; phase <= N-1; phase ++){
		for(int idx = 0; idx < Edges.size(); idx ++){
			Node node = Edges[idx];
			int from = node.from;
			int to = node.to;
			int time = node.time;
			
			if(Result[from] == INF) continue;
			
			if(Result[to] > Result[from] + time) Result[to] = Result[from] + time;
		}
	} 
	
	// 5. 음수 사이클 확인
	for(int idx = 0; idx < Edges.size(); idx ++){
		Node node = Edges[idx];
		int from = node.from;
		int to = node.to;
		int time = node.time;
		
		if(Result[from] == INF) continue;
		if(Result[from] + time < Result[to]){
			cout << "-1";
			return 0;
		}
	}
	
	// 6. 결과 값 출력
	for(int idx = 2; idx <= N; idx ++) {
		if(Result[idx] == INF) cout <<"-1\n";
		else cout << Result[idx] << "\n";
	}
	 	
	return 0;
}
