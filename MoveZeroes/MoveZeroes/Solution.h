#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {   //�Ž⣺�����ҵ���0����ͷ�0������Ҳ�����0���˳����ǰ�ƣ�ʣ�µ�ȫ��0����һЩ
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