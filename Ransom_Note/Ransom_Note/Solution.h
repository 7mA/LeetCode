#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {  //�Ž�˼·���������r����ÿһ���ַ�������������棬֮���ڱ���m�ַ������¼����ŵ㣺��ʹ��find
public:
	bool canConstruct(string ransomNote, string magazine) {
		int pos1, pos2;
		for (auto i = 'a'; i <= 'z'; i++){
			pos1 = 0;
			pos2 = 0;
			pos1 = ransomNote.find(i, pos1);
			pos2 = magazine.find(i, pos2);
			while (pos1 != string::npos){
				if (pos2 == string::npos) return false;
				pos1 = pos1 + 1;
				pos2 = pos2 + 1;
				pos1 = ransomNote.find(i, pos1);
				pos2 = magazine.find(i, pos2);
			}
		}
		return true;
	}
};