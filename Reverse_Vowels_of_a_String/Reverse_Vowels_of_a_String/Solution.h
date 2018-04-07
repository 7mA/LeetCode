#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {  //优解：find_first_of()和find_last_of()，可以找参数字符串中的某个字符，简直就是为这道题设计的。
public: 
	string reverseVowels(string s) {
		int lpos = 0, rpos = s.length() - 1;
		while (true){
			for (int i = lpos; i <= rpos; i++){
				if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
					s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || i == rpos){
					lpos = i;
					break;
				}
			}
			for (int j = rpos; j >= lpos; j--){
				if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' ||
					s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U' || j == lpos){
					rpos = j;
					break;
				}
			}
			if (lpos < rpos){
				swap(s[lpos], s[rpos]);
				lpos++;
				rpos--;
			}
			else break;
		}
		return s;
	}
};