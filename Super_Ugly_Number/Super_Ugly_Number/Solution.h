#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {  //�Ž⣺�����û����������Ҫ˼����Ǵ����������������������Ƴ�������ª���ļ��ϡ�
	              //�Ž��õ��ǶѺ����������������ó��Ľ�����ѵĲ���ȷʵҪ������ѭ��Ҫ�졣
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> dp(n, 1), idx(primes.size(), 0);
		for (int i = 1; i < n; ++i) {
			dp[i] = INT_MAX;
			for (int j = 0; j < primes.size(); ++j) {
				dp[i] = min(dp[i], dp[idx[j]] * primes[j]);
			}
			for (int j = 0; j < primes.size(); ++j) {
				if (dp[i] == dp[idx[j]] * primes[j]) {
					++idx[j];
				}
			}
		}
		return dp.back();
	}

	/*int nthSuperUglyNumber(int n, vector<int>& primes) {
		int count = 1, i = 1;
		while (count < n){
			i++;
			if (isSupUglyNum(i, primes)) count++;
		}
		return i;
	} 

	bool isPrime(int n){
		if (n < 2) return false;
		for (int i = 2; i <= (int)sqrt(n); i++){
			if (!(n%i)) return false;
		}
		return true;
	}

	bool isMember(int n, vector<int>& vec){
		int l = vec.size();
		for (int k = 0; k < l; k++){
			if (n == vec[k]) return true;
		}
		return false;
	}

	bool isSupUglyNum(int n, vector<int>& primes){
		if (isPrime(n)) return isMember(n, primes);
		for (int j = 2; j <= n/2; j++){
			if (!(n%j) && isPrime(j) && !(isMember(j, primes))) return false;
		}
		return true;
	}*/
};