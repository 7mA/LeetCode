#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int cn = nums[0].size();
		int rn = nums.size();
		if (r * c != cn * rn){
			return nums;
		}
		else{
			vector<vector<int>> vec;
			vector<int> row;
			int num;
			int ct;
			int rt;
			for (int i = 0; i < r; i++){
				for (int j = 0; j < c; j++){
					num = i * c + j;
					rt = num / cn;
					ct = num % cn;
					row.push_back(nums[rt][ct]);
				}
				vec.push_back(row);
				row.clear();
			}
			return vec;
		}
	}
};