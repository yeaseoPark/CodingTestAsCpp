#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int visited[7];
vector<int> a[8];

void bfs(int start){
	// 1. 필요 자원 선언
	queue<int> q;
	
	// 2. 첫 시작점 갱신
	visited[start] = true;
	q.push(start);
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		printf("%d ", x);
		
		for(int i = 0; i < a[x].size(); i ++){
			int y = a[x][i];
			if(!visited[y]){
				q.push(y);
				visited[y] = true;
			}
		}
	} // while end
	
}

int main(void){
	a[1].push_back(2);
	a[2].push_back(1);
	
	a[1].push_back(3);
	a[3].push_back(1);
	
	a[2].push_back(3);
	a[3].push_back(2);
	
	a[2].push_back(4);
	a[4].push_back(2);
	
	a[2].push_back(5);
	a[5].push_back(2);
	
	a[4].push_back(5);
	a[5].push_back(4);
	
	a[3].push_back(6);
	a[6].push_back(3);
	
	a[3].push_back(7);
	a[7].push_back(3);
	
	a[6].push_back(7);
	a[7].push_back(6);
	
	bfs(1);
	
	return 0;
}
