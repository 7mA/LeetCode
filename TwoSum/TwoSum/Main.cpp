#include<iostream>
#include"Solution.h"
using namespace std;

void main(){
	Solution *s = new Solution();
	int n;
	int t;
	cout << "n:";
	cin >> n;
	vector<int> vec(n, 0);
	cout << "vector:" << endl;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
	}
	cout << "target:";
	cin >> t;
	vector<int> res = s->twoSum(vec, t);
	for (int i = 0; i < 2; i++){
		cout << res[i] << " ";
	}
	cout << endl;
}