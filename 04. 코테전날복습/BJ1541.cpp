#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string DATA;
	cin >> DATA;
	
	vector<int> numbers;
	vector<char> plus_minus;
	
	int num;
	for(int i = 0; i < DATA.size(); i ++){
		if(DATA[i] == '-' || DATA[i] == '+'){
			plus_minus.push_back(DATA[i]);
			numbers.push_back(num);
			num = 0;
		}
		else if(0 <= DATA[i] - '0' && DATA[i] - '0'<10){
			num = num * 10 + (DATA[i] - '0');
		}
		if(i == DATA.size() - 1){
			numbers.push_back(num);
			break;
		}
	}
	
	int answer = numbers[0];
	
	bool isMinus = false;
	for(int idx = 1; idx <numbers.size(); idx ++){
		if(plus_minus[idx-1] == '-'){
			isMinus = true;
			answer -= numbers[idx];
		}
		else if(isMinus){
			answer -= numbers[idx];
		}
		else{
			answer += numbers[idx];
		}
	}
	cout << answer;

	return 0;
}
