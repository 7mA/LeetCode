#include<iostream>
#include<vector>
using namespace std;

class Solution {  //以时间换空间，O(n^2)，优解可以不用额外空间，通过从后往前赶的策略。自身问题：只从前往后赶了
public:
	vector<int> getRow(int rowIndex) {
		vector<int> vec;
		vec.push_back(1);
		if (rowIndex == 0){
			return vec;
		}
		vec.push_back(1);
		if (rowIndex == 1){
			return vec;
		}
		for (int i = 2; i <= rowIndex; i++){
			for (int j = 0; j < vec.size() - 1; j += 2){
				vec.insert(vec.begin() + j + 1, vec[j] + vec[j + 1]);
			}
			for (int k = 2; k < vec.size() - 1; k++){
				vec.erase(vec.begin() + k);
			}
		}
		return vec;
	}
};