#include<iostream>
using namespace std;

class Solution { //�Ž⣺���������ȷʵͦ���ĵģ����ǿ��ת��ת��long��long intҪʡʱ�䡣
public:
	int arrangeCoins(int n) {
		long tmp = n;
		tmp *= 8;
		return (-1 + sqrt(1 + tmp)) / 2;
	}
};