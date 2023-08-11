#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 500;



int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 1. N �ޱ�
	int N;
	cin >> N;
	int Result[N+1];
	fill_n(Result, N+1, 0);
	
	// 2. ������ �ޱ�
	vector<int> G[N+1];
	int buildTime[N+1];
	fill_n(buildTime, N+1, 0);
	int inputDegree[N+1];
	fill_n(inputDegree, N+1, 0);
	
	int time, pre;
	for(int build = 1; build <= N; build ++){
		cin >> time;
		buildTime[build] = time;
		
		cin >> pre;
		while(pre != -1){
			G[pre].push_back(build);
			inputDegree[build] ++;
			cin >> pre;
		}
	}
	
	// 3. �������� ��Ʈ �ڿ� ����
	int visited[N+1];
	fill_n(visited, N+1, 0);
	queue<int> q;
	
	// 4. �������� ��Ʈ �ʱ� Ž��
	for(int build = 1; build <= N; build ++){
		if(inputDegree[build] == 0){
			q.push(build);
			visited[build] = true;
			Result[build] = buildTime[build];
		}
	} 
	
	// 5. �������� ��Ʈ Ž��
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		
		for(int idx = 0; idx < G[cur].size(); idx ++){
			int next = G[cur][idx];
			Result[next] = max(Result[next], buildTime[next] + Result[cur]);
			
			inputDegree[next] --;
			if(!visited[next] && inputDegree[next] == 0){
				visited[next] = true;
				q.push(next);
			}
		}
	} 
	
	// 6. ���
	for(int idx = 1; idx <= N; idx ++)
		cout << Result[idx] << endl; 
	return 0;
}
