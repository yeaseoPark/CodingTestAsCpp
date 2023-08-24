#include <iostream>

#define max 10000
using namespace std;

int calSelfNum(int x){
	int res = x;
	while(x != 0){
		res += x % 10;
		x /= 10;
	}
	
	return res;
}

int main(void){
	
	int data[max + 1];
	for(int idx = 0; idx <= max; idx ++) data[idx] = idx;
	
	for(int i = 1; i <= max; i ++){
		if(data[i] == 0) continue;
		int j = calSelfNum(i);
		while(j <= max){
			data[j] = 0;
			j = calSelfNum(j);
		}
	}
	
	for(int idx = 1; idx <= max; idx ++)
		if(data[idx] != 0) cout << idx << endl;
	
	return 0;
}
