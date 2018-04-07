#include<iostream>
#include<vector>
using namespace std;

class Solution { //能不用循环就不用循环，循环的时间复杂度太大。
public:          //map.find()适用于准确检索，如果要检索的值属于一个集合的话，就不能使用这个这个方法。
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