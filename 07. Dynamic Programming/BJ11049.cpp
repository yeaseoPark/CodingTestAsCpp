#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int> > matrix;
int dp[501][501];

int main(void){
	cin >> N;
	matrix.push_back({0, 0});
	
	int r, c;
	for(int idx = 0; idx < N; idx ++){
		cin >> r >> c;
		matrix.push_back({r, c});
	}
	
	for(int s = 1; s <= N; s ++) dp[s][s+1] = matrix[s].first * matrix[s].second * matrix[s+1].second;
	
	for(int dist = 2; dist <= N; dist ++){
		for(int s = 1; s + dist <= N; s ++){
			int e = s + dist;
			dp[s][e] = 123456789;
			for(int mid = s; mid <=e; mid ++){
				dp[s][e] = min(dp[s][e], dp[s][mid] + dp[mid+1][e] + matrix[s].first * matrix[mid].second * matrix[e].second);
			}
		}
	}
	
	cout << dp[1][N];
	
	return 0;
}
