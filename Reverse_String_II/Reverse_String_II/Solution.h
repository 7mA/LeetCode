#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {  //优解思路：不使用reverse，使用swap交换前后半部分的字符
public:
	string reverseStr(string s, int k) {
		int l = s.length();
		string temp = "";
		if (l < k){
			reverse(s.begin(), s.end());
			return s;
		}
		for (int i = 0; i < l; i += k){
			if (2 * i + k - 1 > l){
				reverse(s.begin() + 2 * i, s.end());
				return s;
			}
			temp = s.substr(2 * i, k);
			reverse(temp.begin(), temp.end());
			s.replace(2 * i, k, temp);
		}
		return s;
	}
};