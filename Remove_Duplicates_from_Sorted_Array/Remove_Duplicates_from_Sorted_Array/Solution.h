#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:              //��û���һ������ȫ�����ظ�������Ԫ�أ���һ��һ����Ҫ����Ч�ʡ�
	int removeDuplicates(vector<int>& nums) {
		int l = nums.size();
		vector<int>::iterator it = nums.begin();
		it++;
		for (int i = 1; i < l; ){
			if (nums[i] == nums[i - 1]){
				l--;
				it = nums.erase(it);
			}
			else{
				it++;
				i++;
			}
		}
		return l;
	}
};