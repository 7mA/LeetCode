#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {  //���ܲ����Ž���Ž⣺����map�趨ÿ���ַ���������1��2��3����֮���������ַ����һ���ַ��ȣ���һ��������
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