#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int V, E;
int uf[10001];

struct Edge{
	int v1;
	int v2;
	int weight;
	
	Edge(){
	}
	Edge(int v1, int v2, int weight){
		this -> v1 = v1;
		this -> v2 = v2;
		this -> weight = weight;
	}
	
	bool operator < (const Edge e) const{
		return this -> weight < e.weight;
	}
};

int uf_find(int x){
	if(x == uf[x]) return x;
	return uf[x] = uf_find(uf[x]);
}

void uf_union(int x, int y){
	x = uf_find(x);
	y = uf_find(y);
	
	if(x == y) return;
	if(x < y) uf[y] = x;
	else uf[x] = y;
}

int main(void){
	
	cin >> V >> E;
	
	vector<Edge> DATA;
	int v1, v2, weight;
	for(int phs = 1; phs <= E; phs++){
		cin >> v1 >> v2 >> weight;
		DATA.push_back(Edge(v1, v2, weight));
	}
	sort(DATA.begin(), DATA.end());
	
	for(int idx = 0; idx <=V; idx ++) uf[idx] = idx;
	
	int total_edge = 0, res = 0;
	for(int idx = 0; idx < DATA.size(); idx ++){
		v1 = DATA[idx].v1;
		v2 = DATA[idx].v2;
		weight = DATA[idx].weight;
		
		if(uf_find(v1) == uf_find(v2)) continue;
		total_edge ++;
		uf_union(v1, v2);
		res += weight;
		
		if(total_edge == V-1) break;
	}
	
	cout << res << endl;
	
	return 0;
}
