#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int l = digits.size(); 
		int n = 1;
		for (int i = l - 1; i >= 0; i--){
			digits[i] = (digits[i] + n) % 10;
			n = (digits[i] == 0 && n == 1);
		}
		if (n == 1){
			digits.insert(digits.begin(), 1, 1);
		}
		return digits;
	}
};	