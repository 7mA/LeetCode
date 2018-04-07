#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution {  //目前对C++的string对象还一无所知，通过优解学习了find()函数和string::npos的含义与作用。
public:
	bool checkRecord(string s) {
		map<char, int> m;
		m['A'] = 0;
		m['L'] = 0;
		m['P'] = 0;
		int i = 0;
		while (s[i] != '\0'){
			m[s[i++]]++;
			if (m['L'] > 2 || m['A'] > 1){
				return false;
			}
			if (i - 2 >= 0 && s[i - 2] == 'L' && s[i - 1] != 'L'){
				m[s[i - 2]] = 0;
			}
		}
		return true;
	}
};