#include <iostream>
#include <math.h>

using namespace std;

int d[1000001];
int dp(int x){
	if(x == 1) return 0;
	if(x == 2) return 1;
	if(x == 3) return 1;
	if(d[x] != 0) return d[x];
	
	d[x] = dp(x-1) + 1;
	
	if(x % 3 == 0) d[x] = min(dp(x / 3) + 1, d[x]);
	if(x % 2 == 0) d[x] = min(dp(x / 2) + 1, d[x]);
	
	return d[x];
}

int main(void){
	int N;
	
	cin >> N;
	cout << dp(N);
	
	return 0;
}
