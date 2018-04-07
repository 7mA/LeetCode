#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int l = nums.size();
		double max = 0, t;
		for (int i = 0; i < k; i++){
			max += nums[i];
			t = max;
		}
		for (int j = k; j < l; j++){
			t += nums[j] - nums[j - k];
			max = t > max ? t : max;
		}
		return max / k;
	}
};