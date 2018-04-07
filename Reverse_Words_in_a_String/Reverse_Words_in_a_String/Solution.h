#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {  //优解思路：先将所有字符倒置，再倒置每个单词，同时处理空格。
public:
	void reverseWords(string &s) {
		vector<string> vec = split(s, " ");
		s.clear();
		if (vec.size() == 0){
			return;
		}
		for (int i = vec.size() - 1; i >= 1; i--){
			s += vec[i] + " ";
		}
		s += vec[0];
	}

	vector<string> split(string str, string pattern)
	{
		vector<string> ret;
		if (pattern.empty()) return ret;
		size_t start = 0, index = str.find_first_of(pattern, 0);
		while (index != str.npos)
		{
			if (start != index)
				ret.push_back(str.substr(start, index - start));
			start = index + 1;
			index = str.find_first_of(pattern, start);
		}
		if (!str.substr(start).empty())
			ret.push_back(str.substr(start));
		return ret;
	}
};