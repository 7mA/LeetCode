#include<iostream>
#include<string>
using namespace std;

class Solution { //�Ž⣺����⻹����һЩ����ģ���Ȼ��easy����ȴ��ʱ�ˡ��ѵ��Ĵ𰸺��Žⶼ��ͨ�������ķ�ʽ�����Լ���
	             //�Ĵ𰸴������Ϊ�ӷ������Լ�һ�β���֪�����Գ�ʱ�ˡ��ѵ��Ĵ�ֱ����9��λ�����Ž������������������
	             //����ûʲô��ͬ���ѵ��Ĵ�����õ���to_string()�ķ�ʽ��ȡ����λ�����������Ҳ������Ϊ������µ�
	             //�ٶ�û���Ž�졣
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