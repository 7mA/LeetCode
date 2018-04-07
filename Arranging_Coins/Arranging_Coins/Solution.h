#include<iostream>
using namespace std;

class Solution { //优解：首先这道题确实挺无聊的，其次强制转换转成long比long int要省时间。
public:
	int arrangeCoins(int n) {
		long tmp = n;
		tmp *= 8;
		return (-1 + sqrt(1 + tmp)) / 2;
	}
};