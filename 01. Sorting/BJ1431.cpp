#include <iostream>
#include <algorithm>

using namespace std;

int N;
string Data[50];

// 2. compare (�� ����) 
bool compare(string a, string b){
	
	// 2.2 ���� ���̰� �ٸ��ٸ� 
	if(a.length() == b.length()){
		
		// 2.2.1 A�� ��� �ڸ����� �հ� B�� ��� �ڸ����� ���� ���ؼ� 
		int a_sum = 0, b_sum = 0;
		for(int i = 0; i < a.length(); i ++){
			if(a.at(i) - '0' < 10) a_sum += (a.at(i) - '0');
			if(b.at(i) - '0' < 10) b_sum += (b.at(i) - '0');
		}
		
		// 2.3 ���� �����ϴٸ� ���������� �� 
		if(a_sum == b_sum){
			return a < b;
		}
		
		// 2.2.2 ���� ���� ���� ���� ���� 
		return a_sum < b_sum;
	}
	
	// 2.1 ���̰� �ٸ��ٸ� ª�� ���� ���� �´� 
	return a.length() < b.length();
}

int main(void){
	
	// 1. N�� Data �ޱ� 
	cin >> N;
	for(int i = 0; i < N; i ++) cin >> Data[i];
	
	// 2. sorting : compare ���� 
	sort(Data, Data + N, compare);
	
	// 3. ������ ��� 
	for(int i = 0; i < N; i ++) cout << Data[i] << endl;
	
	return 0;
} 
