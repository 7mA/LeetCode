#include<iostream>
#include<string>
using namespace std;

class Solution { //���ɷ��ϣ������һ��hard-coding���⡣�����ȿ���ǰ��λ������жϴ�����(Aa, aa, AA)
	             //֮��ֱ���жϺ�����ַ���Сд�Ƿ����ǰ��λ��Ӧ�����ͻ����һЩ������ҪǶ��if��
	             //aAֱ���ų�����AA����һ��ȫ�Ǵ�д��Aa��aa����ȫ��Сд��
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