#include <iostream>
#include <algorithm>

using namespace std;

int N;
string Data[50];

// 2. compare (비교 기준) 
bool compare(string a, string b){
	
	// 2.2 만약 길이가 다르다면 
	if(a.length() == b.length()){
		
		// 2.2.1 A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 
		int a_sum = 0, b_sum = 0;
		for(int i = 0; i < a.length(); i ++){
			if(a.at(i) - '0' < 10) a_sum += (a.at(i) - '0');
			if(b.at(i) - '0' < 10) b_sum += (b.at(i) - '0');
		}
		
		// 2.3 합이 동일하다면 사전순으로 비교 
		if(a_sum == b_sum){
			return a < b;
		}
		
		// 2.2.2 합이 작은 쪽이 먼저 오고 
		return a_sum < b_sum;
	}
	
	// 2.1 길이가 다르다면 짧은 것이 먼저 온다 
	return a.length() < b.length();
}

int main(void){
	
	// 1. N과 Data 받기 
	cin >> N;
	for(int i = 0; i < N; i ++) cin >> Data[i];
	
	// 2. sorting : compare 참고 
	sort(Data, Data + N, compare);
	
	// 3. 데이터 출력 
	for(int i = 0; i < N; i ++) cout << Data[i] << endl;
	
	return 0;
} 
