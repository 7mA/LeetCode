#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<sstream>
using namespace std;

class Solution {    //优解：双射关系，使用两个map是有点笨重。可以把第二个map改成set，这样只需要看它出没出现过就行了。
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