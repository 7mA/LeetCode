#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {   //O(n)解法：桶排序，之后根据每个桶中的个数确定奇数位求和。
public:
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int l = nums.size();
		int sum = 0;
		for (int i = 0; i < l; i += 2){
			sum += nums[i];
		}
		return sum;
	}
};

//桶排序后确定奇数位并求和的方法
//jump = 0;
//auto count = (buckets[i] - jump + 1) / 2;
//sum += i * count;
//jump = (buckets[i] - jump) % 2;