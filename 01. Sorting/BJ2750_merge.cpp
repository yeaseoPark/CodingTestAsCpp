#include <iostream>
#include <vector>

using namespace std;
int sorted[1000];

void merge(vector<int> &D, int start, int mid, int end){
	int target = start;
	int left = start;
	int right = mid + 1;
	
	while(left <=mid && right <= end){
		if(D[left] <= D[right]) sorted[target ++] = D[left ++];
		else sorted[target ++] = D[right ++];
	}
	while(left <= mid) sorted[target ++] = D[left ++];
	while(right <= end) sorted[target ++] = D[right ++];
	
	for(int t = start; t <= end; t ++) D[t] = sorted[t];
}

void mergeSort(vector<int> &D, int start, int end){
	if(start >= end) return;
	int mid = (start + end) / 2;
	mergeSort(D, start, mid);
	mergeSort(D, mid + 1, end);
	merge(D, start, mid, end);
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin >> N;
	vector<int> D(N);
	
	for(int idx = 0; idx < N; idx ++) cin >> D[idx];
	mergeSort(D, 0, N-1);
	for(int idx = 0; idx < N; idx ++) cout << D[idx] << "\n";
	
	return 0;
}
