#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {   //���ַ��Ž⣬���������ĸ����е����Ŀ��ֵ��ʱ�򲻶������ͷ����ĸ�
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