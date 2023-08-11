#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

const int INF = 987654321;

int main(void){
	ios_base::sync_with_stdio(0);
	cin.tie();
	
	int N, M;
	int BUS[101][101];
	
	cin >> N;
	cin >> M;
	
	for(int i = 1; i <= N; i ++){
		for(int j = 1; j <= N; j ++){
			if(i == j) BUS[i][j] = 0;
			else BUS[i][j] = INF;
		}
	}
	
	int a, b, c;
	for(int phs = 1; phs <= M; phs ++){
		cin >> a;
		cin >> b;
		cin >> c;
		BUS[a][b] = min(BUS[a][b], c);
	}
	
	for(int k = 1; k <= N; k++){
		for(int s = 1; s<= N; s++){
			for(int e= 1; e<=N; e++){
				BUS[s][e] = min(BUS[s][e], BUS[s][k] + BUS[k][e]);
			}
		}
	}
	
	for(int i = 1; i <= N; i ++){
		for(int j = 1; j <= N; j++){
			if(BUS[i][j] == INF) cout <<"0";
			else cout << BUS[i][j];
			cout << " ";
		}
		cout << "\n";
	}
	
	return 0;
}
