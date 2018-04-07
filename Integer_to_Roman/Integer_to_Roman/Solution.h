#include<iostream>
#include<string>
using namespace std;

class Solution {  //优解：确实是一道踩大于赞的题。。搜罗马数字的时候不小心在百科里看到解法
	              //优解的思路与之前自己写的Roman to Integer的思路类似，效率可能搞在数组初始化上。
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