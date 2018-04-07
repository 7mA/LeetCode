#include<iostream>
#include<vector>
using namespace std;

class Solution { //可以使用accummulate()函数，效率会高一些。
public:
	int missingNumber(vector<int>& nums) {
		int l = nums.size();
		int sum = 0;
		for (int i = 0; i < l; i++){
			sum += nums[i];
		}
		return (1 + l)*l / 2 - sum;
	}
};