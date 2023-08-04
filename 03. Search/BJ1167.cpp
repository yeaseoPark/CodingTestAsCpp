#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
// pair(nextNode, �Ÿ�) 
vector<pair<int, int> > data[100001];

int BFS(int start){
	int res = -999;
	// 1. dfs �ڿ� ����: pair(node ��ȣ, start ������ �Ÿ�) 
	queue<pair<int, int> > q;
	int visited[N+1];
	
	// 2. start ����
	q.push(make_pair(start, 0));
	visited[start] = true;
	
	// 3. BFS �����
	pair<int, int> now;
	int now_node, now_distance, next_node, next_distance;
	
	// 3.1 ť�� �� ������ pop 
	while(!q.empty()){
		now = q.front();
		now_node = now.first;
		now_distance = now.second;
		q.pop();

		// 3.2 ���� ��忡�� �̵��� �� �ִ� ���� �߿���		
		for(int next = 0; next < data[now_node].size() ; next ++){
			next_node = data[now_node][next].first;
			next_distance = data[now_node][next].second + now_distance;
			printf("%d \n", next_distance);
			// 3.3 �湮���� ���� ���� q�� �ְ� visit ���� 
			if(!visited[next_node]){
				q.push(make_pair(next_node, next_distance));
				visited[next_node] = true;
				cout << next_distance << endl;
				
				// 3.4 ���� ������ �Ÿ��� res ���� ũ�ٸ� �ش� �Ÿ��� res ���� 
				res = max(res, next_distance);
			}
		} // for end
		
	} // while end
	
	// 4. �ִ� ���� ��� 
	cout << res << endl;;
	cout <<"**********" << endl;
	return res;
} // BFS end


int main(void){
	
	// 0. ������ �ޱ� 
	cin >> N;
	int parent = 0, child, distance;
	
	for(int i = 0; i < N; i ++){
		cin >> parent;
		
		cin >> child;
			
		while(child != -1){
			cin >> distance;
			data[parent].push_back(make_pair(child, distance));
			data[child].push_back(make_pair(parent, distance));
			cin >> child;
		}
	}
	
	// ������ �ڵ� 
	for(int i = 1; i <= N; i ++){
		for(int j = 0; j < data[i].size(); j ++){
			printf("(%d, %d)       ", data[i][j].first, data[i][j].second);
		}
		printf("\n");
	}
	
	// 4. ��� ���鿡 ���� bfs ����
	int res = -999;
	for(int start = 1; start <= N; start ++) res = max(res, BFS(start));
	
	// 5. ��� ���
	cout << res; 
	
	return 0;
}
