#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {   //优解：只有在两个字符串相同的时候才没有这种LUS，否则以长的为准。
public:
	int findLUSlength(string a, string b) {
		int gss = gssLength(a, b);
		int LUS = max(a.length(), b.length());
		if (gss < LUS) return LUS;
		else return -1;
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
		return (m + n - dp[m][n]) / 2;
	}
};