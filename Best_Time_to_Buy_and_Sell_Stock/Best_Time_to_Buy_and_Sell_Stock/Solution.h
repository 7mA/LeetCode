#include<iostream>
#include<vector>
using namespace std;

class Solution { //�ܲ���ѭ���Ͳ���ѭ����ѭ����ʱ�临�Ӷ�̫��
public:          //map.find()������׼ȷ���������Ҫ������ֵ����һ�����ϵĻ����Ͳ���ʹ��������������
	int maxProfit(vector<int>& prices) {
		int dif = 0;
		int l = prices.size();
		for (int i = 0; i < l; i++){
			for (int j = 0; j < i; j++){
				if (prices[i] - prices[j] > dif){
					dif = prices[i] - prices[j];
				}
			}
		}
		return dif;
	}
};