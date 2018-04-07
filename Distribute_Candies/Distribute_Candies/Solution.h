#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {   //�Ž⣺ʹ��bitset���ݽṹ������࣬����Ч
public:
	int distributeCandies(vector<int>& candies) {
		int l = candies.size(), res = 0;
		map<int, bool> m;
		for (int i = 0; i < l; i++){
			if (m.find(candies[i]) == m.end()){
				m[candies[i]] = true;
				res++;
				if (res > l / 2) return l / 2;
			}
		}
		return res;
	}
};