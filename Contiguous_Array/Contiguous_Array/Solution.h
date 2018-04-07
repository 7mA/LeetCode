#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {   //˼�룺ת��0Ϊ-1��ʹ0��-1����Թ�ϵ�����Ե���ȷ����������ϵ��
	               //�Ž⣺û����map��ֱ�Ӷ���һ������Ϊ2l+1����������͡�
public:
	int findMaxLength(vector<int>& nums) {
		map<int, int> m;
		int sum = 0, l = nums.size(), res = 0;
		m[0] = 0;
		for (int i = 0; i < l; i++){
			if (nums[i] == 0) nums[i] = -1;
			sum += nums[i];
			if (m.find(sum) == m.end()) m[sum] = i + 1;
			else res = max(res, i + 1 - m[sum]);
		}
		return res;
	}
};