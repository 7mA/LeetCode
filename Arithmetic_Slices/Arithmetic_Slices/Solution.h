#include<iostream>
#include<vector>
using namespace std;

class Solution {   //�Ž⣺����ѧΪ��ǩ�����ȻҪ����ѧ�ĽǶ��Ż���1+2+3=(3+4)/2��ǰ�ߵļ���ȷʵҪ����һЩ��
				   //����Ҫ���Ľ������
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int l = A.size(), count, res = 0, temp;
		if (l < 3) return res;
		count = 1;
		for (int i = 2; i < l; i++){
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) count++;
			else {
				res += count * (count - 1) / 2;
				count = 1;
			}
		}
		res += count * (count - 1) / 2;
		return res;
	}
};