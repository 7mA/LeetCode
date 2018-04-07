#include<iostream>
#include<vector>
using namespace std;

class Solution {   //优解：以数学为标签的题果然要从数学的角度优化。1+2+3=(3+4)/2，前者的计算确实要更简单一些，
				   //不需要最后的结算操作
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