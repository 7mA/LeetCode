#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution { //O(n)�Ž⣺Ͱ���򣬿��Կ������漰��Ԫ�ز��������Ͱ���������Ч����ʱ�临�Ӷ�
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