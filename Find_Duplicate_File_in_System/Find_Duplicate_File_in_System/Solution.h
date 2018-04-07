#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {  //优解：思路基本相同，但是细节处相差太大。很多地方是可以优化的，比如说不用那么多的find
	              //还有应该先emplace_back给一个temp数组，再把temp数组emplace_back到结果数组中。
	              //最后大可不必使用erase，直接移动到一个新数组里会更省时间一点。
public:
	vector<vector<string>> findDuplicate(vector<string>& paths) {
		map<string, int> m;
		vector<vector<string>> res;
		string t, t1, t2;
		int n = 0, p, pos = 0;
		for (int i = 0; i < paths.size(); i++){
			t = paths[i].substr(paths[i].find("(", pos) + 1, paths[i].find(")", pos) - paths[i].find("(", pos) - 1);
			if (m.find(t) == m.end()){
				m[t] = n;
				res.push_back(vector<string>(0, " "));
				t1 = paths[i].substr(0, paths[i].find(" "));
				t2 = paths[i].substr(paths[i].find(" ", pos) + 1, paths[i].find("(", pos) - paths[i].find(" ", pos) - 1);
				res[n].push_back(t1 + "/" + t2);
				n++;
			}
			else{
				p = m[t];
				t1 = paths[i].substr(0, paths[i].find(" "));
				t2 = paths[i].substr(paths[i].find(" ", pos) + 1, paths[i].find("(", pos) - paths[i].find(" ", pos) - 1);
				res[p].push_back(t1 + "/" + t2);
			}
			pos = paths[i].find(")", pos) + 1;
			if (paths[i].find("(", pos) != string::npos){
				i--;
			}
			else{
				pos = 0;
			}
		}
		for (int i = 0; i < res.size(); i++){
			if (res[i].size() == 1){
				res.erase(res.begin() + i, res.begin() + i);
			}
		}
		return res;
	}
};