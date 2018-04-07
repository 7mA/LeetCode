#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {   //优解：使用bitset数据结构，更简洁，更高效
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