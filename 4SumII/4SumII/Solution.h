#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {  //��Ȼ�����˵�һ�����˼·����
				  //�Ž⣺û��ʹ��map�������������ֱ�ǰ���������飬֮���������м��
	              //�����Ǻ��µ�˼·������˵�ǽ�֮ǰ��˼·��������
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