#include<iostream>
#include<vector>
using namespace std;

class Solution {  //����һ��ֻ�в��������������һ�����Ȳ��ģ����Ȱ��������ÿ��λ�ø�ֵΪ1��֮���ٸ��ݹ����޸�
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vec;
		vector<int> temp;
		if (numRows == 0){
			return vec;
		}
		temp.push_back(1);
		vec.push_back(temp);
		temp.clear();
		for (int i = 1; i < numRows; i++){
			temp.push_back(1);
			for (int j = 1; j < i; j++){
				temp.push_back(vec[i - 1][j - 1] + vec[i - 1][j]);
			}
			temp.push_back(1);
			vec.push_back(temp);
			temp.clear();
		}
		return vec;
	}
};