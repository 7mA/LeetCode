#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {           //���ڵ���һ�ݶ���233��������������ĳɹ��䷶
public:                    //����������Ľⷨ��������ֻɾ��һ��ֵ��Ԫ�أ�
						   //�ǲ���Ҫ�������һ��c����֮ǰ�ı�ǵģ�ֻҪ��һ��c����ɾ������������
	int removeElement(vector<int>& nums, int val) {
		sort(nums.begin(), nums.end());
		int l = nums.size(), f = 0, c = 0;
		if (l == 0){
			return 0;
		}
		while (f < l){
			while (nums[f] == val){
				f++;
			}
			if (f < l){
				nums[c++] = nums[f++];
			}
		}
		return c;
	}
};