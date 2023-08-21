#include <iostream>
#include <algorithm>

#define DIV 1000000000

using namespace std;

// D[n][i] = n 자리의 계단수 중 i로 끝나는 수의 개수 
long long D[101][10];

long long getStairNum(int n){
	
	D[1][0] = 0;
	fill(&D[1][1], &D[1][10], 1);
	
	for(int phase = 2; phase <= n; phase ++){
		D[phase][9] = D[phase-1][8];
		D[phase][0] = D[phase-1][1];
		
		for(int idx = 1; idx <= 8; idx ++) D[phase][idx] = (D[phase-1][idx-1] + D[phase-1][idx+1]) % DIV;
	}
	
	long long res = 0;
	for(int idx = 0; idx <= 9; idx ++) res += D[n][idx] % DIV;
	
	return res % DIV;
		
}

int main(void){
	int N;
	cin >> N;
	cout << getStairNum(N);
	return 0;
}
