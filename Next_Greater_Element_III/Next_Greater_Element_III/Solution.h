#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {  //优解：没想到真的有全排列这样的库函数，next_permutation()一个函数解决问题
public:
	int nextGreaterElement(int n) {
			if (n < 10){
				return -1;
			}
			vector<int> vec(10, 0);
			string s = to_string(n);
			string temp = "";
			int pos;
			for (int i = s.length() - 1; i >= 1; i--){
				if (s[i - 1] < s[i]){
					for (int k = s[i - 1] + 1; k < s[i]; k++){
						pos = s.substr(i).find(k);
						if (pos != -1){
							pos += i;
							break;
						}
					}
					if (pos == -1) pos = i;
					vec[s[i] - '0']++;
					vec[s[pos] - '0']--;
					swap(s[i - 1], s[pos]);
					vec[s[pos] - '0']++;
					s.erase(s.begin() + i, s.end());
					for (int j = 0; j < 10; j++){
						temp += string(vec[j], j + '0');
					}
					s += temp;
					auto res = stol(s);
					return (res > INT_MAX || res <= n) ? -1 : res;
				}
				vec[s[i] - '0']++;
			}
			return -1;
	}
};