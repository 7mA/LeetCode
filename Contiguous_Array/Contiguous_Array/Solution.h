#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {   //思想：转化0为-1，使0与-1有相对关系，可以抵消确定其数量关系。
	               //优解：没有用map，直接定义一个长度为2l+1的数组来存和。
public:
	int findMaxLength(vector<int>& nums) {
		map<int, int> m;
		int sum = 0, l = nums.size(), res = 0;
		m[0] = 0;
		for (int i = 0; i < l; i++){
			if (nums[i] == 0) nums[i] = -1;
			sum += nums[i];
			if (m.find(sum) == m.end()) m[sum] = i + 1;
			else res = max(res, i + 1 - m[sum]);
		}
		return res;
	}
};