#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution{   //优解：想出来的方法虽然是DFS，不过还是逻辑漏洞，优解很巧妙，思想也是DFS
public:
	char pa[2] = { '(', ')' };
	char pa_re[2] = { ')', '(' };

	vector<string> removeInvalidParentheses(string s) {
		vector<string> ans;
		_remove(s, ans, 0, 0, pa);
		return ans;
	}

	void _remove(string s, vector<string> &ans, int last_i, int last_j, char pa[]){
		for (int i = last_i, count = 0; i < s.size(); i++){
			if (s[i] == pa[0]) count++;
			if (s[i] == pa[1]) count--;
			if (count >= 0) continue;
			for (int j = last_j; j <= i; j++)
				if (s[j] == pa[1] && (j == last_j || s[j - 1] != pa[1])){
					string newString = s.substr(0, j) + s.substr(j + 1);
					_remove(newString, ans, i, j, pa);
				}
			return;
		}

		string reversed_str;
		reversed_str.clear();
		for (int i = s.size() - 1; i >= 0; --i)
			reversed_str.push_back(s[i]);
		
		if (pa[0] == '(')
			_remove(reversed_str, ans, 0, 0, pa_re);
		else
			ans.push_back(reversed_str);
	}
};

/*class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		vector<string> res;
		unordered_set<string> set;
		int lpos = 0, rpos = s.length() - 1;
		while (s[lpos] != '(') {
			if (s[lpos] == ')') s.erase(s.begin());
			else lpos++;
			if (lpos >= s.length()) {
				res.push_back(s);
				return res;
			}
		}
		while (s[rpos] != ')') {
			if (s[rpos] == '(') s.erase(s.end() - s.length() + rpos);
			else rpos--;
			if (rpos < 0) {
				res.push_back(s);
				return res;
			}
		}
		int size = s.length();
		int lp = count(s.begin(), s.end(), '(');
		int rp = count(s.begin(), s.end(), ')');
		int del = abs(lp - rp);
		if (!del) {
			res.push_back(s);
			return res;
		}
		if (lp > rp){
			delp(s, del, set, size, '(', 1);
		}
		else{
			delp(s, del, set, size, ')', 1);
		}
		for (auto str : set){
			res.push_back(str);
		}
		return res;
	}

	void delp(string s, int del, unordered_set<string> &set, int size, char p, int start){
		if (del == 0) {
			set.insert(s);
			return;
		}
		for (int j = start; j < size - 1; j++){
			if (s[j] == p){
				string temp = s;
				delp(temp, del, set, size, p, j + 1);
				temp.erase(temp.begin() + j);
				delp(temp, del - 1, set, size, p, j);
			}
		}
	}
};*/