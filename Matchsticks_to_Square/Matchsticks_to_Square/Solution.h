#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {   //�Ž⣺���˵ؽ����˵�һ�ݶӣ���һ��˼·�ǰ�index��Ϊ�ݹ��һ��������һ��4��Ԫ�ص����������������Ƚ�
public:
	bool makesquare(vector<int>& nums) {
		int sum = 0, tmp = 0, res = 0;
		set<int> s, t;
		for (auto a : nums) sum += a;
		if (sum % 4) return false;
		int edge = sum / 4; 
		sort(nums.begin(), nums.end(), compare);
		dfs(nums, tmp, res, 0, edge, s, t);
		if (res != 4) return false;
		else return true;
	}

	bool static compare(int a, int b){
		return a > b;
	}

	void dfs(vector<int>& nums, int& tmp, int& res, int num, int edge, set<int>& s, set<int>& t){
		if (tmp == edge){
			res++;
			tmp = 0;
			for (auto a : t) s.insert(a);
			t.clear();
			num = 0;
		}
		for (int i = num; i < nums.size(); i++){
			if (tmp + nums[i] <= edge && s.find(i) == s.end()){
				tmp += nums[i]; 
				t.insert(i);
				dfs(nums, tmp, res, i + 1, edge, s, t);
				tmp -= nums[i];
				t.erase(i);
			}
		}
	}
};