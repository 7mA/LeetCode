#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {  //�Ž⣺˼·������ͬ������ϸ�ڴ����̫�󡣺ܶ�ط��ǿ����Ż��ģ�����˵������ô���find
	              //����Ӧ����emplace_back��һ��temp���飬�ٰ�temp����emplace_back����������С�
	              //����ɲ���ʹ��erase��ֱ���ƶ���һ������������ʡʱ��һ�㡣
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