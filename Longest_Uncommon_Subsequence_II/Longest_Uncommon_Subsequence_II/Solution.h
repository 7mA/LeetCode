#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int findLUSlength(vector<string>& strs) {
		int l = strs.size();
		if (l == 0) return 0;
		if (l == 1) return strs[0].length();
		vector<vector<int>> vec(l, vector<int>(l, 0));
		sort(strs.begin(), strs.end(), compareL);
		for (int i = 0; i < l; i++){
			for (int j = 0; j < l; j++){
				if (i != j) vec[i][j] = gssLength(strs[i], strs[j]);
			}
			sort(vec[i].begin(), vec[i].end(), compareN);
			if (vec[i][0] < strs[i].length()) return strs[i].length();
		}
		return -1;
	}

	int gssLength(string word1, string word2){
		int m = word1.size();
		int n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++){
			dp[i][0] = i;
		}
		for (int j = 1; j <= n; j++){
			dp[0][j] = j;
		}
		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= n; j++){
				if (word1[i - 1] == word2[j - 1]){
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
				}
			}
		}
		return (m + n - dp[m][n])/2;
	}

	static bool compareL(string s1, string s2){
		return s1.length() > s2.length();
	}

	static bool compareN(int a, int b){
		return a > b;
	}
};