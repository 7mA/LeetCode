#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {  //O(n)解法：计数器，初始挑一个数。遇到固定的数加一，不是就减一，减到0就重新挑一个。 
public:           //因为要找的数出现次数大于半数，所以目标数的计数器也一定不会降到零。
	              //缺点：如果没有限制说输入数组中一定有ME，则该算法无效。
	int majorityElement(vector<int>& nums) {
		int l = nums.size();
		map<int, int> m;
		for (int i = 0; i < l; i++){
			if (m.find(nums[i]) == m.end()){
				m[nums[i]] = 1;
			}
			else{
				m[nums[i]]++;
			}
			if (m[nums[i]] > l / 2){
				return nums[i];
			}
		}
	}
};