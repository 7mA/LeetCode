#include<iostream>
#include<string>
using namespace std;

class Solution { //优解：这道题还是有一些诡异的，虽然是easy但是却超时了。搜到的答案和优解都是通过减法的方式，而自己的
	             //的答案大概是因为加法必须试加一次才能知道所以超时了。搜到的答案直接用9乘位数，优解用幂相减，两个方法
	             //好像没什么不同。搜到的答案最后用的是to_string()的方式获取具体位，看似巧妙，但也可能因为这个导致的
	             //速度没有优解快。
public:
	int findNthDigit(int n) {
		if (n < 10) return n;
		int i = 1, m = 1, base = 9;
		while (n > base * i){
			n -= base*(i++);
			m += base;
			base *= 10;
		}
		return to_string(m + (n - 1)/i)[(n - 1) % i] - '0';
	}
};