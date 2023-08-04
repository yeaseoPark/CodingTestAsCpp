#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
string Data[20000];

// 0. sort stl compare ���� 
bool compare(string a, string b){
	// ���̰� ���� ��� ������ 
	if(a.length() == b.length()){
		if(a.compare(b) < 0) return true;
		return false;
	}
	
	// ���̰� �ٸ� ��� ª�� ������� 
	return a.length() < b.length();
}

int main(void){
	// 1. ������ �ޱ� 
	cin >> N;
	for(int i = 0; i < N; i ++) cin >> Data[i];
	
	// 2. ���� -> ���� ���� compare ���� 
	sort(Data, Data + N, compare);
	
	// 3. ��� : �ߺ��� �����ϰ� ��� 
	cout << Data[0] << endl;
	for(int i = 1; i < N; i ++) {
		if(Data[i] != Data[i-1]) cout << Data[i] << endl;
	}
	
	return 0;
}
