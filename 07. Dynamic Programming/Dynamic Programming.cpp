 #include <iostream>
 
 using namespace std;
 
 // ��ȿ���� 
 int recursivePivo(int x){
 	if(x == 1) return 1;
 	if(x == 2) return 1;
 	
 	return recursivePivo(x-1) + recursivePivo(x-2);
 }
 
 // ȿ���� -> DP ���
 int d[100]; 
 int dp(int x){
 	if(x == 1) return 1;
 	if(x == 2) return 1;
 	if(d[x] != 0) return d[x];
 	
 	return d[x] = dp(x-1) + dp(x-2);
 }
 
 int main(void){
 	
 	cout << dp(30);
 	return 0;
 }
 
 
