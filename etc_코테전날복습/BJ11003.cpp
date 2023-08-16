#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 1. N�� L�ޱ�
	int N, L;
	cin >> N >> L;
	
	// 2. ������ �ޱ�
	vector<long> D(N);
	for(int idx = 0; idx < N; idx ++) cin >> D[idx];
	
	// 3. �����̵� ������
	deque<pair<int, int> > sw;
	pair<int, int> cur;
	for(int check = 0; check < N; check ++){
		if(!sw.empty()){
			if(sw.front().second < check - L + 1) sw.pop_front();
		}
		while(!sw.empty() && sw.back().first > D[check]) sw.pop_back();
		sw.push_back(make_pair(D[check], check));
		cout << sw.front().first << " ";
	} 
	
	 
	return 0;
}
