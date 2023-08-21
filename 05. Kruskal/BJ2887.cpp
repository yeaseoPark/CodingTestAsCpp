#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// pair<x좌표, 행성 번호> 
vector<pair<int, int> > xlist;
vector<pair<int, int> > ylist;
vector<pair<int, int> > zlist;

// pair<거리, pair<행성번호1, 행성번호2> > 
vector<pair<int, pair<int, int> > > edges;

bool compare(pair<int, int> p1, pair<int, int> p2){
	return p1.first < p2.first;
}

bool compareEdge(pair<int, pair<int, int> > p1, pair<int, pair<int, int> > p2){
	return p1.first < p2.first;
} 

int getParent(int parent[], int x){
	if(x == parent[x]) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void makeUnion(int parent[], int x, int y){
	x = getParent(parent, x);
	y = getParent(parent, y);
	
	if(x == y) return;
	else if(x < y) parent[y] = x;
	else parent[x] = y;
}


int main(void){
	
	int N;
	cin >> N;
	
	int planet_num = 0;
	int x, y, z;
	for(int phase = 1; phase <= N; phase ++) {
		cin >> x >> y >> z;
		planet_num ++;
		xlist.emplace_back(x, planet_num);
		ylist.emplace_back(y, planet_num);
		zlist.emplace_back(z, planet_num);
	}
	
	// x 리스트 정렬 후 넣기 
	sort(xlist.begin(), xlist.end(), compare);
	for(int idx = 1; idx < N; idx ++){
		pair<int, int> x1 = xlist[idx];
		pair<int, int> x2 = xlist[idx-1];
		
		pair<int, pair<int, int> > e = make_pair(abs(x1.first - x2.first), make_pair(x1.second, x2.second));
		edges.push_back(e);
	}
	
	// y리스트 정렬 후 엣지로 넣기 
	sort(ylist.begin(), ylist.end(), compare);
	for(int idx = 1; idx < N; idx ++){
		pair<int, int> y1 = ylist[idx];
		pair<int, int> y2 = ylist[idx-1];
		
		pair<int, pair<int, int> > e = make_pair(abs(y1.first - y2.first), make_pair(y1.second, y2.second));
		edges.push_back(e);
	}
	
	// z리스트 정렬 후 엣지로 넣기 
	sort(zlist.begin(), zlist.end(), compare);
	for(int idx = 1; idx < N; idx ++){
		pair<int, int> z1 = zlist[idx];
		pair<int, int> z2 = zlist[idx-1];
		
		pair<int, pair<int, int> > e = make_pair(abs(z1.first - z2.first), make_pair(z1.second, z2.second));
		edges.push_back(e);
	}
	
	int parent[N+1];
	for(int idx = 0; idx <= N; idx ++) parent[idx] = idx;
	
	sort(edges.begin(), edges.end(), compareEdge);
	
	int total_edge = 0;
	long long result = 0;
	for(pair<int, pair<int, int> > e : edges){
		if(total_edge == N-1) break;
		if(getParent(parent, e.second.first) == getParent(parent, e.second.second)) continue;
		total_edge ++;
		result += e.first;
		makeUnion(parent, e.second.first, e.second.second);
	}
	
	cout << result;
	
	return 0;
}
