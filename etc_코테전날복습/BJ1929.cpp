#include <iostream>

using namespace std;

bool isPrime(int number){
	if(number == 1) return false;
	if(number == 2 || number == 3) return true;
	
	for(int div = 2; div * div <= number; div ++){
		if(number % div == 0) return false;
	}
	return true;
}

int main(void){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int M, N;
	cin >> M >> N;
	
	for(int check = M; check <= N; check++){
		if(isPrime(check)) cout << check << "\n";
	}
	return 0;
}
