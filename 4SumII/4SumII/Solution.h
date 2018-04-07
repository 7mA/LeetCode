#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {  //竟然忘记了第一道题的思路。。
				  //优解：没有使用map，用两个数组存分别前后两个数组，之后排序，往中间赶
	              //并不是很新的思路，可以说是将之前的思路加以运用
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int l = A.size(), res = 0;
		map<int, int> m;
		for (int i = 0; i < l; i++){
			for (int j = 0; j < l; j++){
				if (m.find(A[i] + B[j]) == m.end()){
					m[A[i] + B[j]] = 1;
				}
				else{
					m[A[i] + B[j]]++;
				}
			}
		}
		for (int i = 0; i < l; i++){
			for (int j = 0; j < l; j++){
				if (m.find(-C[i] - D[j]) != m.end()) res += m[-C[i] - D[j]];
			}
		}
		return res;
	}
};