#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {   //第一道没有做出来的题。。使用DP解法，迭代思想
	               //优解：不需要使用一个二维数组来存储DP矩阵的所有值，通过一个一维数组和几个辅助数就可以实现。
public:
	int minDistance(string word1, string word2) {
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
		return dp[m][n];
	}
};