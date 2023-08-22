#include <iostream>

using namespace std;

/*
D[idx][0] = 0인덱스부터  idx 인덱스까지의 수열 중
idx 값을 포함하면서 수를 빼지 않은 값 중 가장 큰 것
D[idx][1] = 0인덱스부터  idx 인덱스까지의 수열 중
idx 값을 포함하면서 수를 뺀 값 중 가장 큰 것
*/

int D[100000][2];
int N;

int main(void){
	cin >> N;
	
	int tmp;
	cin >> tmp;

	D[0][0] = tmp;
	D[0][1] = tmp;

	int result = tmp;
	
	for(int idx = 1; idx < N; idx ++){
		cin >> tmp;
		D[idx][1] = max(D[idx-1][0], D[idx-1][1] + tmp);
		D[idx][0] = max(D[idx-1][0] + tmp, tmp);
		
		result = max(result, max(D[idx][1], D[idx][0]));
	}
	
	
	cout << result;
	
	return 0;
}
