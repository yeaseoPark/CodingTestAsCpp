#include <iostream>

using namespace std;

int DP[1001];

int main(void){
	int N;
	cin >> N;
	
	DP[1] = 1;
	DP[2] = 2;
	
	for(int idx = 3; idx <= N; idx ++) DP[idx] = (DP[idx-1] + DP[idx-2]) % 10007;
	
	cout << DP[N];
	
	return 0;
}
