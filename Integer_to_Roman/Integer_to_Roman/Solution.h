#include<iostream>
#include<string>
using namespace std;

class Solution {  //�Ž⣺ȷʵ��һ���ȴ����޵��⡣�����������ֵ�ʱ��С���ڰٿ��￴���ⷨ
	              //�Ž��˼·��֮ǰ�Լ�д��Roman to Integer��˼·���ƣ�Ч�ʿ��ܸ��������ʼ���ϡ�
public:
	string intToRoman(int num) {
		string c[4][10] = {
			{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
			{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
			{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
			{ "", "M", "MM", "MMM" }
		};
		string res;
		res.append(c[3][(num / 1000) % 10]);
		res.append(c[2][(num / 100) % 10]);
		res.append(c[1][(num / 10) % 10]);
		res.append(c[0][num % 10]);
		return res;
	}
};