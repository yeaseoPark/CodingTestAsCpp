#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
const int FIRST[] = {2, 3, 5, 7};
const int NOT_FIRST[] = {1, 3, 7, 9};
vector<int> RESULT;

bool isPrime(int number){
	if(number == 1 || number == 0) return false;
	if(number == 2) return true;
	
	for(int div = 2; div * div <= number; div ++){
		if(number % div == 0) return false;
	}
	
	return true;
}

void DFS(int number, int jarisu){
	if(jarisu == N + 1) return;
	if(jarisu == N) RESULT.push_back(number);
	
	for(int idx = 0; idx < 4; idx ++){
		if(!isPrime(number * 10 + NOT_FIRST[idx])) continue;
		DFS(number * 10 + NOT_FIRST[idx], jarisu + 1);
	}
}

int main(void){
	cin >> N;
	for(int idx = 0; idx < 4; idx ++) DFS(FIRST[idx], 1);
	sort(RESULT.begin(), RESULT.end());
	for(int idx = 0; idx < RESULT.size(); idx ++)
		cout << RESULT[idx] << endl;
	return 0;
}
