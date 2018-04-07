#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {   //优解：新课题，深度优先搜索，东拼西凑出了一个样子，优解思路找唯一找的是首个元素而不是整个数组。
	               //另外循环也比多次递归要省点时间。递归一定要找完，而循环边找边加。
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> temp;
		set<vector<int>> s;
		solve(nums, temp, s, 0);
		return vector<vector<int>>(s.begin(), s.end());
	}

	void solve(vector<int> vec, vector<int>& tmp, set<vector<int>>& s, int num){
		if (num == vec.size()){
			if (tmp.size() >= 2) s.insert(tmp);
			return;
		}
		solve(vec, tmp, s, num + 1);
		if (tmp.empty() || tmp.back() <= vec[num]){
			tmp.push_back(vec[num]);
			solve(vec, tmp, s, num + 1);
			tmp.pop_back();
		}
	}
};