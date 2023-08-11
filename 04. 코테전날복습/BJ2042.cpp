#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
int N, M, K;

int makeSegIndex(int origin, int height){
	return (int) pow(2, height) + origin - 1;
}

void updateSegTree(long long SegTree[], int height, int index, long long value){
	index = makeSegIndex(index, height);
	
	while(index > 0){
		SegTree[index] = value;
		if(index % 2 == 0) value = SegTree[index] + SegTree[index+1];
		else value = SegTree[index-1] + SegTree[index];
		index = index / 2;
	}
}

long long getHap(long long SegTree[], int height, int start, int end){
	long long res = 0;
	
	start = makeSegIndex(start, height);
	end = makeSegIndex(end, height);
	
	while(start <= end){
		if(start <= 0 || end <= 0) break;
		
		if(start % 2 == 1) res += SegTree[start];
		if(end % 2 == 0) res += SegTree[end];
		
		start = (start + 1) / 2;
		end = (end - 1) / 2;
	}
	
	return res;
}

int main(void){
	cin >> N >> M >> K;
	int height = ceil(log10(N) / log10(2));
	
	int TreeSize = (int) pow(2, height + 1);
	long long SegTree[TreeSize];
	fill_n(SegTree, TreeSize, 0);
	
	long long value;
	for(int idx = 1; idx <= N; idx ++){
		cin >> value;
		updateSegTree(SegTree, height, idx, value);
	}
		
	int a, b;
	long long c;
	for(int phs = 0; phs < M+K; phs ++){
		cin >> a >> b >> c;
		if(a == 1) updateSegTree(SegTree, height, b, c);
		else cout << getHap(SegTree, height, b, c) << "\n";
	}
	
	return 0;
}
