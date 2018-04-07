#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {   //O(n)�ⷨ��Ͱ����֮�����ÿ��Ͱ�еĸ���ȷ������λ��͡�
public:
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int l = nums.size();
		int sum = 0;
		for (int i = 0; i < l; i += 2){
			sum += nums[i];
		}
		return sum;
	}
};

//Ͱ�����ȷ������λ����͵ķ���
//jump = 0;
//auto count = (buckets[i] - jump + 1) / 2;
//sum += i * count;
//jump = (buckets[i] - jump) % 2;