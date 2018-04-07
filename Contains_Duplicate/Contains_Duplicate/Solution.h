#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
                     //伪map优势，从零开始的下标，节省空间，遍历容易，无需find，直接都存在，缺点浪费空间
class Solution {    //优解：采用伪map解法，使用数组作map，利用减最小的方式将所有数变成0开始的数列（倒是不一定联系）
public:             //然后找伪map里大于1的项，有就返回true。启发：解missing number之类的问题可以考虑
	                 //比如find all disappeared那道题
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() < 2){
			return false;
		}
		int l = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 1; i < l; i++){
			if (nums[i] == nums[i - 1]){
				return true;
			}
		}
		return false;
	}
};