#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
using namespace std;

class Solution {    //�Ž⣺˫���ϵ��ʹ������map���е㱿�ء����԰ѵڶ���map�ĳ�set������ֻ��Ҫ������û���ֹ������ˡ�
public:
	bool wordPattern(string pattern, string str) {
		map<char, string> m;
		map<string, char> m2;
		vector<string> vec;
		vector<string>::iterator it;
		string temp;
		stringstream input(str);
		while (input >> temp){
			vec.push_back(temp);
		}
		it = vec.begin();
		for (auto c : pattern){
			if (it == vec.end()) return false;
			auto x = m.find(c);
			if (x != m.end()){
				if ((*x).second != *it)
					return false;
			}
			else{
				if (m2.find(*it) != m2.end()) return false;
				m[c] = *it;
				m2[*it] = c;
			}
			it++;
		}
		if (it != vec.end()) return false;
		return true;
	}
};