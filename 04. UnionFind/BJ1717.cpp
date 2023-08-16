#include <iostream>
#include <string>

using namespace std;

int getParent(int parent[], int x){
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	
	if(a < b) parent[b] = a;
	else parent[a] = b;
}

bool findParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	
	if(a == b) return true;
	return false;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string res = "";
	
	// 1. N, M 받기 
	int N, M;
	cin >> N >> M;
	// 2. Parent 배열 선언
	int Parent[N+1];
	for(int idx = 0; idx <= N; idx ++) Parent[idx] = idx;
	
	// 3. 질의 받기
	int q, a, b;
	for(int phase = 1; phase <= M; phase ++){
		cin >> q >> a >> b;
		if(q == 0) unionParent(Parent, a, b);
		else{
			if(findParent(Parent, a, b)) res += "YES\n";
			else res += "NO\n";
		}
	} 
	
	cout << res;
	return 0;
}
