#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {  //O(n)�ⷨ������������ʼ��һ�����������̶�������һ�����Ǿͼ�һ������0��������һ���� 
public:           //��ΪҪ�ҵ������ִ������ڰ���������Ŀ�����ļ�����Ҳһ�����ή���㡣
	              //ȱ�㣺���û������˵����������һ����ME������㷨��Ч��
	int majorityElement(vector<int>& nums) {
		int l = nums.size();
		map<int, int> m;
		for (int i = 0; i < l; i++){
			if (m.find(nums[i]) == m.end()){
				m[nums[i]] = 1;
			}
			else{
				m[nums[i]]++;
			}
			if (m[nums[i]] > l / 2){
				return nums[i];
			}
		}
	}
};