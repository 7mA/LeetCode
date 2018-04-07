#include<iostream>
#include<string>
using namespace std;

class Solution {  //优解：蠢到atoi和atol没分清导致WA那么多次。。但是确实纳了闷了，优解的方式很简单就是没想出来
public:
	int reverse(int x) {
		int temp = x;
		if (x < 0) temp = -temp;
		long res = atol(reverseString(temp).c_str());
		long max = INT_MAX;
		if (res > max) return 0;
		else if(x < 0) return (int)0 - res;
		else return (int)res;
	}

	string reverseString(int x){
		int m = x % 10;
		int n = x / 10;
		int temp;
		string str;
		if (!n) return to_string(m);
		else{
			str = reverseString(n);
			str.insert(0, 1, m + '0');
			return str;
		}
	}
};