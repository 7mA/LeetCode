#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {  //�Ž⣺û�뵽�������λ�����������Ž����������ʱ������nth_element()����Ϊֻ��Ҫȷ���м��Ǹ�λ�õ�
	              //ֵ��������Ԫ�ز���Ҫ���򣬶�����������ĸ��Ӷ���O(n)����sort()��O(nlogn)Ҫ�ã�����Ч�ʸߡ�
public:
	int minMoves2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int mid = nums[nums.size() / 2], res = 0;
		for (int n : nums){
			res += abs(n - mid);
		}
		return res;
	}
};