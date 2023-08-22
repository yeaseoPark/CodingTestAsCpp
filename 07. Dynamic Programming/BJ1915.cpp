#include <iostream>

using namespace std;

/*
아이디어
D[i][j] = (i,j)를 오른쪽 끝으로 하는 정사각형의 넓이
D[i][j] 에서 해당 좌표가 1이며 
D[i-1][j-1], D[i-1][j], D[i][j-1] 이 모두 같은 값이면
D[i][j] = D[i-1][j-1] + 1이다. 
*/ 


int main(void){
	// 1. N, M 데이터 받기
	int N, M;
	cin >> N >> M;
	
	// 2. 배열 데이터 받기(사방에 0을 Wrapping 하는 방식)
	int Data[N+2][M+2];
	fill(&Data[0][0], &Data[N+1][M+2], 0);
	string tmp;
	for(int row = 1; row <= N; row ++){
		cin >> tmp;
		for(int col = 1; col <= M; col ++){
			Data[row][col] = tmp.at(col - 1) - '0';
		}
	} 
	
	// 3. 점화식 D 초기화
	int D[N+2][M+2];
	fill(&D[0][0], &D[N+1][M+2], 0);
	
	// 4. 점화식 전개
	int result = 0;
	for(int row = 1; row <= N; row ++){
		for(int col = 1; col <= M; col ++){
			if(Data[row][col] == 0) D[row][col] = 0;
			else{
				if(D[row-1][col-1] == D[row][col-1] &&
				   D[row-1][col-1] == D[row-1][col]){
				   	D[row][col] = D[row-1][col-1] + 1;
				   }
				else{
					D[row][col] = min(D[row-1][col-1], min(D[row-1][col], D[row][col-1])) + 1;
				}
			}
			
			result = max(result, D[row][col] * D[row][col]);
		}
	} 
	
	// 5. 출력
	cout << result; 
	
	
	 
	return 0;
}
