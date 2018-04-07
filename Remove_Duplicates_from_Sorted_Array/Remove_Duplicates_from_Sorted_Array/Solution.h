#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:              //最好还是一下子找全所有重复的相邻元素，比一个一个比要更有效率。
	int removeDuplicates(vector<int>& nums) {
		int l = nums.size();
		vector<int>::iterator it = nums.begin();
		it++;
		for (int i = 1; i < l; ){
			if (nums[i] == nums[i - 1]){
				l--;
				it = nums.erase(it);
			}
			else{
				it++;
				i++;
			}
		}
		return l;
	}
};