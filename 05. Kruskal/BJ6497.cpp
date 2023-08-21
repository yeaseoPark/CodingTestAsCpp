#include <iostream>
#include <vector>
#include <algorithm>

#define maxHous 200000

using namespace std;

class Edge{
	public:
		int n1;
		int n2;
		long long cost;
		
		Edge(){
			
		}
		
		Edge(int n1, int n2, long long cost){
			this -> n1 = n1;
			this -> n2 = n2;
			this -> cost = cost;
		}
		
		bool operator < (const Edge e) const{
			return this -> cost < e.cost;
		}
};


class UnionFind{
	public:
		int M, N;
		int parent[maxHous];
		vector<Edge> Graph;
		int result = 0;
		
		UnionFind(){
			
		}
		
		UnionFind(int M, int N){
			this -> M = M;
			this -> N = N;
			
			for(int idx = 0; idx < M; idx ++) parent[idx] = idx;
		}
		
		void addEdge(int x, int y, long long z){
			Graph.emplace_back(x, y, z);
			result += z;
		}
		
		int getParent(int x){
			if(x == parent[x]) return x;
			return parent[x] = getParent(parent[x]);
		}
		
		void makeUnion(int x, int y){
			x = getParent(x);
			y = getParent(y);
			
			if(x == y) return;
			if(x < y) parent[y] = x;
			else parent[x] = y;
		}
		
		void kruskal(){
			sort(Graph.begin(), Graph.end());
			int edge_num = 0;
			for(Edge e : Graph){
				if(edge_num == M-1) break;
				if(getParent(e.n1) == getParent(e.n2)) continue;
				makeUnion(e.n1, e.n2);
				edge_num ++;
				this -> result -= e.cost;
			}
			
		}
};

int main(void){
	
	string result = "";
	int m, n;
	int x, y;
	long long z;
		
	while(1){
		cin >> m >> n;
		if(m == 0 && n == 0) break;
		UnionFind uf(m, n);
		
		for(int idx = 0; idx < n; idx ++){
			cin >> x >> y >> z;
			uf.addEdge(x, y, z);
		}
		
		uf.kruskal();
		
		result += to_string(uf.result);
		result += "\n";
	}
	
	cout << result;
	
	return 0;
}
