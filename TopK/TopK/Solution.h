#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;     //优解：使用priority_queue来实现选择

typedef pair<int, int> PAIR;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> m;
		vector<int> res;
		for (auto num : nums){
			if (m.find(num) != m.end()) m[num]++;
			else m[num] = 1;
		}
		vector<PAIR> vec(m.begin(), m.end());
		sort(vec.begin(), vec.end(), compare);
		for (int i = 0; i < k; i++){
			res.push_back(vec[i].first);
		}
		return res;
	}

	static bool compare(PAIR a, PAIR b){
		if (a.second > b.second) return true;
		else return false;
	}
};