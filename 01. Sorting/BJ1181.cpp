#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
string Data[20000];

// 0. sort stl compare 선언 
bool compare(string a, string b){
	// 길이가 같은 경우 사전순 
	if(a.length() == b.length()){
		if(a.compare(b) < 0) return true;
		return false;
	}
	
	// 길이가 다른 경우 짧은 순서대로 
	return a.length() < b.length();
}

int main(void){
	// 1. 데이터 받기 
	cin >> N;
	for(int i = 0; i < N; i ++) cin >> Data[i];
	
	// 2. 정렬 -> 정렬 기준 compare 참고 
	sort(Data, Data + N, compare);
	
	// 3. 출력 : 중복은 제외하고 출력 
	cout << Data[0] << endl;
	for(int i = 1; i < N; i ++) {
		if(Data[i] != Data[i-1]) cout << Data[i] << endl;
	}
	
	return 0;
}
