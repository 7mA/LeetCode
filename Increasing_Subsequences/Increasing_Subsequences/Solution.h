#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {   //�Ž⣺�¿��⣬���������������ƴ���ճ���һ�����ӣ��Ž�˼·��Ψһ�ҵ����׸�Ԫ�ض������������顣
	               //����ѭ��Ҳ�ȶ�εݹ�Ҫʡ��ʱ�䡣�ݹ�һ��Ҫ���꣬��ѭ�����ұ߼ӡ�
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