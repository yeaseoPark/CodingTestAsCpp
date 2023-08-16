/*
아이디어
최소 신장 트리를 구하고
최소 신장 트리 내에서 가장 긴 경로를 뺀다. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
	int n1;
	int n2;
	int cost;
	
	Edge(){
		
	}
	
	Edge(int n1, int n2, int cost){
		this -> n1 = n1;
		this -> n2 = n2;
		this -> cost = cost;
	}
	
};

int N, M;
int CycleTable[100001];
vector<Edge> Graph;

bool compare(Edge e1, Edge e2);
int getParent(int x);
void make_union(int a, int b);


int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int result = 0;
	
	cin >> N;
	cin >> M;
	
	for(int idx = 0; idx <= N; idx ++) CycleTable[idx] = idx;
	
	int a, b, c;
	for(int idx = 0; idx < M; idx ++){
		cin >> a >> b >> c;
		Graph.emplace_back(a, b, c);
	}
	
	sort(Graph.begin(), Graph.end(), compare);
	
	int biggest_cost = -1;
	int total_edges = 0;
	for(Edge e : Graph){
		
		if(total_edges == N-1) break;
		if(getParent(e.n1) == getParent(e.n2)) continue;
		
		make_union(e.n1, e.n2);
		biggest_cost = max(biggest_cost, e.cost);
		result += e.cost;
		total_edges ++;
	}
	
	cout << result - biggest_cost;
		
	return 0;
}

bool compare(Edge e1, Edge e2){
	return e1.cost < e2.cost;
}

int getParent(int x){
	if(CycleTable[x] == x) return x;
	return CycleTable[x] = getParent(CycleTable[x]);
}

void make_union(int a, int b){
	a = getParent(a);
	b = getParent(b);
	
	if(a == b) return;
	
	if(a < b) CycleTable[b] = a;
	else CycleTable[a] = b;
}
