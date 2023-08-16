#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class UnionFind{
	public:
		int name_count = 0;
		map<string, int> name_dict;
		map<string, int> :: iterator it;
		vector<int> friend_count;
		vector<int> parent;
		
		UnionFind(){
			friend_count.push_back(0);
			parent.push_back(0);
		}
		
		void addName(string name){
			name_count ++;
			name_dict[name] = name_count;
			friend_count.push_back(1);
			parent.push_back(name_count);
		}
		
	private:
		int getUFIndex(string name){
			it = name_dict.find(name);
			if(it != name_dict.end()) return name_dict[name];
			return 0;
		}
		
		int findParent(int x){
			if(parent[x] == x) return x;
			return parent[x] = findParent(parent[x]);
		}
		
		void makeUnion(int a, int b){
			a = findParent(a);
			b = findParent(b);
			
			if(a == b) return;
			else if(a < b){
				parent[b] = a;
				friend_count[a] += friend_count[b];
			}
			else{
				parent[a] = b;
				friend_count[b] += friend_count[a];
			}
		}
		
		int getFriendNum(int x){
			x = findParent(x);
			return friend_count[x];
		}
		
	public:
		void makeUnion(string n1, string n2){
			int a = getUFIndex(n1);
			int b = getUFIndex(n2);
			
			if(a == 0){
				addName(n1);
				a = getUFIndex(n1);
			}
			if(b == 0){
				addName(n2);
				b = getUFIndex(n2);
			}
			
			makeUnion(a, b);
		}
		
		int getFriendNum(string name){
			int x = getUFIndex(name);
			return getFriendNum(x);
		}
};

int main(void){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, F;
	string n1, n2;
	string res = "";
	
	cin >> T;
	
	for(int test = 1; test <= T; test ++){
		cin >> F;
		UnionFind uf;
		
		for(int f = 1; f <= F; f ++){
			cin >> n1 >> n2;
			uf.makeUnion(n1, n2);
			res += to_string(uf.getFriendNum(n1));
			res += "\n";
		}
	}
	
	cout << res;
	
	return 0;
}
