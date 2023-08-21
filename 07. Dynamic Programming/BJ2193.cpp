#include <iostream>
#include <math.h>

using namespace std;

long long D[91];
long long D0[91];
long long D1[91];

long long getPinaryNumber(int x){
	D0[1] = 0;
	D1[1] = 1;
	D[1] = 1;
	
	D0[2] = 1;
	D1[2] = 0;
	D[2] = 1;
	
	
	for(int idx = 3; idx <= x; idx ++){
		D1[idx] = D0[idx-1];
		D0[idx] = D[idx-1];
		D[idx] = D1[idx] + D0[idx];
	}
	
	return D[x];
}

int main(void){
	int N;
	cin >> N;
	cout << getPinaryNumber(N);
	return 0;
}
