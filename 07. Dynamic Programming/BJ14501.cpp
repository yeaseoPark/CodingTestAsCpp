#include <iostream>
#include <math.h>

using namespace std;

int dp(int T[], int P[], int N){
	int result[N+1];
	fill_n(result, N+1, 0);

	for(int idx = 1; idx <= N; idx ++){
		if(idx + T[idx] > N+1) continue;
		
		result[idx] += P[idx];
		for(int idx2 = idx + T[idx]; idx2 <= N; idx2 ++) result[idx2] = max(result[idx2], result[idx]);
	}
	
	int res = 0;
	for(int idx = 1; idx <= N; idx ++) {
		res = max(res, result[idx]);
	}
		
	return res;
}

int main(void){
	int N;
	cin >> N;
	int T[N+1];
	int P[N+1];
	
	int t, p;
	for(int idx = 1; idx <= N; idx ++) cin >> T[idx] >> P[idx];
	
	cout << dp(T, P, N);
	
}
