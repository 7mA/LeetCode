#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {   //二分法优解，左右坐标哪个在中点等于目标值的时候不动，最后就返回哪个
public:
	int searchInsert(vector<int>& nums, int target) {
		map<int, int> m;
		int l = nums.size();
		for (int i = 0; i < l; i++){
			m[nums[i]] = i;
			while (m.find(target) != m.end()){
				return m[target];
			}
		}
		for (int i = 0; i < l; i++){
			if (nums[i] > target){
				return i;
			}
		}
		return l;
	}
};