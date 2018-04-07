#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution { //O(n)优解：桶排序，可以看出在涉及到元素差的问题中桶排序可以有效降低时间复杂度
public:
	int findMinDifference(vector<string>& timePoints) {
		vector<int> vec;
		int m, l = timePoints.size();
		for (int i = 0; i < l; i++){
			vec.push_back(stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3, 2)));
		}
		sort(vec.begin(), vec.end());
		m = vec[0] - vec[l - 1] + 1440;
		for (int i = 0; i < l - 1; i++){
			m = min(vec[i + 1] - vec[i], m);
		}
		return m;
	}
};