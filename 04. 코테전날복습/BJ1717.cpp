#include <iostream>

using namespace std;

int uf[1000001];

int find(int x){
	if(uf[x] == x) return x;
	return uf[x] = find(uf[x]);
}

void uf_union(int x, int y){
	x = find(x);
	y = find(y);
	
	if(x == y) return;
	if(x < y) uf[y] = x;
	else uf[x] = y;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	for(int idx = 0; idx <= N; idx ++) uf[idx] = idx;
	
	int q, a, b;
	for(int phs = 0; phs < M; phs ++){
		cin >> q >> a >> b;
		if(q == 0) uf_union(a, b);
		else{
			if(find(a) == find(b))cout << "YES\n";
			else cout <<"NO\n"; 
		}
	}
	
	return 0;
}
