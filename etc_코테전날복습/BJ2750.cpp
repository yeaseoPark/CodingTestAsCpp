#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void quickSort(vector<int> &D,int start, int end){
	if(start >= end) return;
	
	int pivot = D[(start + end) / 2];
	int left = start, right = end;
	int tmp;
	
	while(left <= right){
		while(D[left] < pivot) left ++;
		while(D[right] > pivot) right --;
		
		if(left <= right){
			tmp = D[left];
			D[left] = D[right];
			D[right] = tmp;
			
			left ++;
			right --;
		}
	}
	
	quickSort(D, start, right);
	quickSort(D, left, end);
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<int> D(N);
	
	for(int idx = 0; idx < N; idx ++) cin >> D[idx];
	quickSort(D, 0, N-1);
	for(int idx = 0; idx < N; idx ++) cout << D[idx] << "\n";
	
	return 0;
}
