#include <iostream>
#include <math.h>

using namespace std;

long long d[1000001];
long long sum[1000001];

long long dp(int x){
	d[0] = 1;
	d[1] = 2;
	d[2] = 7;
	
	sum[0] = 1;
	sum[1] = 3;
	sum[2] = 10;
	
	for(int idx = 3; idx <= x; idx ++){
		d[idx] = (d[idx-1] * 2 + d[idx-2] * 3 + sum[idx-3] * 2) % 1000000007;
		sum[idx] = sum[idx-1] + d[idx];
		sum[idx] = sum[idx] % 1000000007;
	}
	
	return d[x];
}

int main(void){
	int N;
	cin >> N;
	cout << dp(N);
	return 0;
}
