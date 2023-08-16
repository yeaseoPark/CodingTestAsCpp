#include <iostream>
#include <string>

using namespace std;

int getParent(int parent[], int x){
	if(x == parent[x]) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	
	if(a < b) parent[b] = a;
	else parent[a] = b;
}

bool isSameParent(int parent[], int a, int b){
	a = getParent(parent, a);
	b = getParent(parent, b);
	
	if(a == b) return true;
	return false;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 1. N, M 구하기
	int N, M;
	cin >> N;
	cin >> M;
	
	// 2. 데이터 받기
	// 2.1 parent 데이터 선언
	int parent[N+1];
	for(int idx = 0; idx <= N; idx ++) parent[idx] = idx;
	
	// 2.2 데이터 받기
	int connect;
	for(int i = 1; i <= N; i ++){
		for(int j = 1; j <= N; j ++){
			cin >> connect;
			if(connect == 1) unionParent(parent, i, j);
		}
	} 
	
	// 3. 결과 출력
	int first, other;
	cin >> first;
	for(int phase = 1; phase <= M-1; phase ++){
		cin >> other;
		if(!isSameParent(parent, first, other)){
			cout << "NO";
			return 0;
		}
	}
	
	cout << "YES";
	
	return 0;
}
