#include <iostream>
#include <algorithm>

using namespace std;
int N, M;
int DATA[100000];

bool binarySearch(int s, int e, int target){
	if(s > e) return false;
	
	int mid = (s + e) / 2;
	
	if(DATA[mid] == target) return true;
	if(DATA[mid] > target) return binarySearch(s, mid-1,target);
	if(DATA[mid] < target) return binarySearch(mid+1, e,target); 
	
}


int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for(int idx = 0; idx < N ; idx ++) cin >> DATA[idx];
	sort(DATA, DATA + N);
	cin >> M;
	int q;
	for(int idx = 0; idx < M ; idx ++) {
		cin >> q;
		cout << binarySearch(0, N-1, q) << "\n";
	}
	
	return 0;
}
