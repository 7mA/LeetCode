#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution {  //�Ž⣺ʹ����������^��һ��һ���ļ������Կ����������ķ�����
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