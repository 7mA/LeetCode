#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
                     //αmap���ƣ����㿪ʼ���±꣬��ʡ�ռ䣬�������ף�����find��ֱ�Ӷ����ڣ�ȱ���˷ѿռ�
class Solution {    //�Ž⣺����αmap�ⷨ��ʹ��������map�����ü���С�ķ�ʽ�����������0��ʼ�����У����ǲ�һ����ϵ��
public:             //Ȼ����αmap�����1����оͷ���true����������missing number֮���������Կ���
	                 //����find all disappeared�ǵ���
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() < 2){
			return false;
		}
		int l = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 1; i < l; i++){
			if (nums[i] == nums[i - 1]){
				return true;
			}
		}
		return false;
	}
};