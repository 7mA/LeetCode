#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {           //终于到第一梯队了233，先排序后搜索的成功典范
public:                    //【不用排序的解法】像这种只删除一个值的元素，
						   //是不需要再特意搞一个c来存之前的标记的，只要用一个c来存删掉几个就行了
	int removeElement(vector<int>& nums, int val) {
		sort(nums.begin(), nums.end());
		int l = nums.size(), f = 0, c = 0;
		if (l == 0){
			return 0;
		}
		while (f < l){
			while (nums[f] == val){
				f++;
			}
			if (f < l){
				nums[c++] = nums[f++];
			}
		}
		return c;
	}
};