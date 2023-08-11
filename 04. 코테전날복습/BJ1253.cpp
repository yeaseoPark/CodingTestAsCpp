#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int answer = 0;
	
	// 1. N, 데이터 받기
	int N;
	cin >> N;
	vector<long> D(N);
	for(int idx = 0; idx < N; idx ++) cin >> D[idx];
	
	sort(D.begin(), D.end());
	
	// 2. 
	for(int k = 0; k < N; k ++){
		long find = D[k];
		int i = 0;
		int j = N-1;
		
		while(i < j){
			if(i == k) {
				i ++; continue;
			}
			if(j == k){
				j --; continue;
			}
			if(find > D[i] + D[j]) i ++;
			else if(D[i] + D[j] == find){
				answer ++;
				break;
			}
			else j --;
		}
	}
	
	cout << answer;
	return 0;
}
