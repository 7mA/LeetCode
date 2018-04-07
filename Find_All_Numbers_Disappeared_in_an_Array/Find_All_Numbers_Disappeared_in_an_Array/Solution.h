#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int l = nums.size(), i;
		map<int, int> m;
		vector<int> res; 
		for (i = 0; i < l; i++){
			m[i + 1] = 0;
		}
		for (i = 0; i < l; i++){
			m[nums[i]]++;
		}
		for (i = 0; i < l; i++){
			if (m[i + 1] == 0){
				res.push_back(i + 1);
			}
		}
		return res;
	}	
};