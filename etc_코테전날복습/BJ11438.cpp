#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
const int ROOT = 1;
int N, M;

vector<int> Tree[100001];
vector<int> Ancestor[100001];
int depth[100001];
int max_height = 0;

void getParent(int cur, int height){
	if(max_height < height) max_height = height;
	
	for(int idx = 0; idx < Tree[cur].size(); idx ++){
		int next = Tree[cur][idx];
		if(depth[next] == 0){
			depth[next] = height + 1;
			Ancestor[next][0] = cur;
			getParent(next, height + 1);
		}
	}
}

int getLCA(int n1, int n2){
	// n2 가 더 깊은 것 
	if(depth[n1] > depth[n2]){
		int tmp = n1;
		n1 = n2;
		n2 = tmp;
	}
	
	int k = Ancestor[n1].size() -1;
	
	while(depth[n1] != depth[n2]){
		if(depth[n1] > depth[Ancestor[n2][k]]) k --;
		else{
			n2 = Ancestor[n2][k];
		}
	}
	
	k  = Ancestor[n1].size() -1;
	
	while(k >= 0){
		if(Ancestor[n1][k] == Ancestor[n2][k]) k--;
		else{
			n1 = Ancestor[n1][k];
			n2 = Ancestor[n2][k];
		}
	}
	
	if(n1 == n2) return n1;
	return Ancestor[n1][0];

}

void getAncestor(){
	fill_n(depth, N+1, 0);
	cout << "yes" << endl;
	getParent(ROOT, 0);
	cout << "yes" << endl;

	
	Ancestor[0][0] = 0;
	Ancestor[ROOT][0] = 0;
	
	for(int j = 1; pow(2, j) < max_height; j ++){
		for(int i = 1; i <= N; i++){
			Ancestor[i][j] = Ancestor[Ancestor[i][j-1]][j-1];
		}
	}
}



int main(void){
	// 1. N 받기
	cin >> N;
	
	// 2. 트리 받기
	int v1, v2;
	for(int phs = 1; phs <= N-1; phs ++){
		cin >> v1 >> v2;
		Tree[v1].push_back(v2);
		Tree[v2].push_back(v1);
	}
	
	// 3. 조상 구하기
	getAncestor();
	
	// 4. M 받기
	cin >> M;
	
	// 5. 공통 조상 받기
	for(int phs = 1; phs <= M; phs ++) {
		cin >> v1 >> v2;
		cout << getLCA(v1, v2) << endl;
	}

	 
	return 0;
}
