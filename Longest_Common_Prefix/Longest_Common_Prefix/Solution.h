#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {  //�Ž⣺��ʵ������򵥵�һ��һ���Աȣ���һ�����Ծͷ��أ���ʵ������򵥸���Щ����find��ֱ����
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0) return "";
		sort(strs.begin(), strs.end(), compare);
		int l = strs[0].length();
		string res = "";
		bool f;
		for (int i = l; i > 0; i--){
			f = true;
			res = strs[0].substr(0, i);
			for (string str : strs){
				if (str.find(res) != 0){
					f = false;
					break;
				}
			}
			if (f) return res;
		}
		return false;
	}
	
	bool static compare(string a, string b){
		return a.length() < b.length();
	}
};