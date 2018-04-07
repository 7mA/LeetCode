#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {   //优解：比起找等于0的项，和非0项交换，找不等于0的项按顺序往前移，剩下的全置0更快一些
public:
	void moveZeroes(vector<int>& nums) {
		int i, j, l = nums.size();
		for (i = 0; i < l; i++){
			if (nums[i] == 0){
				for (j = i + 1; j < l; j++){
					if (nums[j] != 0){
						swap(nums[i], nums[j]);
						break;
					}
				}
			}
		}
	}
};