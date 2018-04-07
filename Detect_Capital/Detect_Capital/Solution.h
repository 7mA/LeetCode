#include<iostream>
#include<string>
using namespace std;

class Solution { //不可否认，这就是一道hard-coding的题。不过先考虑前两位的情况判断串类型(Aa, aa, AA)
	             //之后直接判断后面的字符大小写是否符合前两位对应的类型会更快一些，不需要嵌套if。
	             //aA直接排除掉，AA后面一定全是大写，Aa、aa后面全是小写。
public:
	bool detectCapitalUse(string word) {
		int i;
		if (word.size() == 1){
			return true;
		}
		if (word[0] >= 65 && word[0] <= 90){
			if (word[1] >= 65 && word[1] <= 90){
				i = 2;
				while (word[i] != '\0'){
					if (word[i] < 65 || word[i] > 90){
						return false;
					}
					i++;
				}
			}
			else{
				i = 2;
				while (word[i] != '\0'){
					if (word[i] >= 65 && word[i] <= 90){
						return false;
					}
					i++;
				}
			}
		}
		else{
			if (word[1] >= 65 && word[1] <= 90){
				return false;
			}
			else{	
				i = 2;
				while (word[i] != '\0'){
					if (word[i] >= 65 && word[i] <= 90){
						return false;
					}
					i++;
				}
			}
		}
		return true;
	}
};