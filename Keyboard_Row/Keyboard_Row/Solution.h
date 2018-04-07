#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {  //可能不是优解的优解：利用map设定每个字符的行数（1，2，3），之后让所有字符与第一个字符比，不一样就跳出
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> keyBoard(3, ""), res;
		keyBoard[0] = "qwertyuiopQWERTYUIOP";
		keyBoard[1] = "asdfghjklASDFGHJKL";
		keyBoard[2] = "zxcvbnmZXCVBNM";
		for (auto word : words){
			if (word == ""){
				res.push_back(word);
				break;
			}
			if (word.find_first_of(keyBoard[0]) != string::npos){
				if (word.find_first_of(keyBoard[1] + keyBoard[2]) == string::npos) res.push_back(word);
			}
			else if (word.find_first_of(keyBoard[1]) != string::npos){
				if (word.find_first_of(keyBoard[2]) == string::npos) res.push_back(word);
			}
			else res.push_back(word);
		}
		return res;
	}
};