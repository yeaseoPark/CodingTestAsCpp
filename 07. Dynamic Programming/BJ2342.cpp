#include <iostream>
#include <vector>
#define INF 123456789

using namespace std;

/*
아이디어 : 맨 끝에서 맨 처음까지 추적해본다. 
*/
int calMove(int from, int to){
	if(from == to) return 1;
	if(from == 0) return 2;
	if((from + to) % 2 == 0) return 4;
	
	return 3;
}

int main(void){
	
	int tmp;
	vector<int> data;
	data.push_back(0);
	
	while(1){
		cin >> tmp;
		if(tmp == 0) break;
		data.push_back(tmp);
	}
	
	// D[idx][left][right] = idx 번째에서 left 위에 발이 있고 right 위에 오른발이 있을때
	// 최소값 
	int D[data.size()][5][5];
	fill(&D[0][0][0], &D[data.size()-1][4][5], INF);
	
	D[0][0][0] = 0;
	
	for(int phase = 1; phase < data.size(); phase ++){
		for(int left = 0; left < 5; left ++){
			for(int right = 0; right < 5; right ++){
				if(D[phase-1][left][right] == INF) continue;
				int leftMove = calMove(left, data[phase]);
				int rightMove = calMove(right, data[phase]);
				
				D[phase][data[phase]][right] =
				min(D[phase-1][left][right] + leftMove, D[phase][data[phase]][right]);
				D[phase][left][data[phase]] =
				min(D[phase-1][left][right] + rightMove, D[phase][left][data[phase]]);
			}
		}
	} 
	
	int result = INF;
	for(int left = 0; left < 5; left ++){
		for(int right = 0; right < 5; right ++){
			result = min(result, D[data.size() - 1][left][right]);
		}
	}
	

	cout << result;
	
	return 0;
}
