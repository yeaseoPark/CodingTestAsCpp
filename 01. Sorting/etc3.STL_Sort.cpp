#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	vector<pair<int, string> > v;
	v.push_back(pair<int, string>(90, "박한울"));
	v.push_back(pair<int, string>(85, "이태일"));
	v.push_back(pair<int, string>(82, "나동빈"));
	v.push_back(pair<int, string>(98, "강종구"));
	v.push_back(pair<int, string>(79, "이상욱"));

	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i ++)
		cout << v[i].first<<',' << v[i].second << endl;
	return 0;
}
