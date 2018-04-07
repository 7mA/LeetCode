#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {  //O(n)解法：左右各一游标，向中间赶，大了就动右边，小了就动左边（这么简单。。）
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int l = numbers.size(), f;
		map<int, int> m;
		vector<int> res(2, 0);
		if (target >= 0) f = target / 2;
		else f = target / 2 - 1;
		for (int i = 0; i < l; i++){
			if (numbers[i] <= f){
				if (numbers[i] == f){
					if (m.find(target - numbers[i]) != m.end()){
						res[0] = m[numbers[i]] + 1;
						res[1] = i + 1;
						return res;
					}
				}
				m[numbers[i]] = i;
			}
			else{
				if (m.find(target - numbers[i]) != m.end()){
					res[0] = m[target - numbers[i]] + 1;
					res[1] = i + 1;
					return res;
				}
			}
		}
	}
};