#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
참고 자료 : https://velog.io/@emplam27/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B7%B8%EB%A6%BC%EC%9C%BC%EB%A1%9C-%EC%95%8C%EC%95%84%EB%B3%B4%EB%8A%94-LCS-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Longest-Common-Substring%EC%99%80-Longest-Common-Subsequence 
*/

int main(void){
	string A, B;
	cin >> A;
	cin >> B;
	
	int D [A.length() + 1][B.length() + 1];
	fill(&D[0][0], &D[A.length()][B.length() + 1], 0);
	
	for(int i = 1 ; i <= A.length(); i ++){
		for(int j = 1 ; j <= B.length(); j ++){
			if(A.at(i-1) == B.at(j-1)){
				D[i][j] = D[i-1][j-1] + 1;
			}
			else{
				D[i][j] = max(D[i-1][j], D[i][j-1]);
			}
		}
	}
	
	int i = A.length(), j = B.length();
	vector<char> result;
	while(i> 0 && j > 0){
		
		if(D[i][j] == 0) break;
		
		if(D[i-1][j] == D[i][j]){
			i --;
		}
		else if(D[i][j-1] == D[i][j]){
			j --;
		}
		else{
			result.push_back(A.at(i-1));
			i--;
			j--;
		}
	}
		
	cout << D[A.length()][B.length()] << endl;
	for(int idx = result.size() - 1; idx >= 0; idx --) cout << result[idx];
	
	return 0;
}
