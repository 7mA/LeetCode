#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution {  //优解：使用异或运算符^，一正一反的计数可以考虑这种灵活的方法。
public:
	char findTheDifference(string s, string t) {
		map<char, int> m;
		for (auto c : s){
			if (m.find(c) == m.end()) m[c] = 1;
			else m[c]++;
		}
		for (auto c : t){
			if (m.find(c) != m.end() && m[c] > 0) m[c]--;
			else return c;
		}
	}
};