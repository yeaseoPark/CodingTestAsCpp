#include <iostream>
#include <vector>

using namespace std;

int main(void){
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int N, M;
	cin >> N >> M;
	vector<long> dp(N+1);
	dp[0] = 0;
	for(int idx = 1; idx <= N; idx ++){
		long num;
		cin >> num;
		dp[idx] = dp[idx-1] + num;
	}
	
	
	for(int idx = 0; idx < M; idx ++){
		int q1, q2;
		cin >> q1 >> q2;
		cout << dp[q2] - dp[q1-1] << "\n";
	}
	
	return 0;
	
}
