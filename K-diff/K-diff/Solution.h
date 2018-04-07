#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:                //25ms答案：先排序，再用左右两个游标从左到右找对应长度，可以有效解决unique问题
	int findPairs(vector<int>& nums, int k) {
		map<int, int> m;
		int l = nums.size(), t, n = 0;
		if (k < 0){
			return 0;
		}
		if (k == 0){
			for (int i = 0; i < l; i++){
				if (m.find(nums[i]) != m.end()){
					if (m[nums[i]] == 1){
						n++;
						m[nums[i]] = 0;
					}
					
				}
				else{
					m[nums[i]] = 1;
				}
			}
		}
		else{
			for (int i = 0; i < l; i++){
				if (m.find(nums[i]) == m.end()){
					m[nums[i]] = 3;
				}
				t = nums[i] - k;
				if (m.find(t) != m.end() && (m[t] == 2 || m[t] == 3)){
					n++;
					m[nums[i]]--;
					m[t] -= 2;
				}
				t = nums[i] + k;
				if (m.find(t) != m.end() && (m[t] == 1 || m[t] == 3)){
					n++;
					m[nums[i]] -= 2;
					m[t]--;
				}
			}
		}
		return n;
	}
};