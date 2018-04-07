#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int l = nums.size();
		double res = INT_MIN;
		for (int i = 0; i < l - k + 1; i++){
			double max = 0, t;
			for (int j = i; j < i + k; i++){
				max += nums[i];
				t = max;
			}
			max /= k;
			t /= k;
			for (int j = i + k; j < l; j++){
				t += nums[j];
				max = t > max ? t : max;
			}
			res = res >(max / k) ? res : (max / h);
		}
		return res;



		for (int h = k; h <= l; h++){
			double max = 0, t;
			for (int i = 0; i < h; i++){
				max += nums[i];
				t = max;
			}
			for (int j = h; j < l; j++){
				t += nums[j] - nums[j - h];
				max = t > max ? t : max;
			}
			res = res > (max / h) ? res : (max / h);
		}
		return res;
	}
};