#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {  //优解思路：先算出来r串中每一个字符次数，用数组存，之后在遍历m字符串往下减。优点：不使用find
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