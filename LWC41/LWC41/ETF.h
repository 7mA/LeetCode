#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> exclusiveTime(int n, vector<string>& logs) {
		stack<int> ids, sts, ts;
		vector<int> vec(n, 0);
		int pos, t1, t2 = 0;
		for (auto log : logs){
			pos = log.find(":");
			if (log[pos + 1] == 's'){
				ids.push(stoi(log.substr(0, pos)));
				sts.push(stoi(log.substr(pos + 7)));
				ts.push(0);
			}
			else if (log[pos + 1] == 'e'){
				t1 = stoi(log.substr(pos + 5)) - sts.top() + 1;
				vec[ids.top()] += t1 - ts.top();
				ts.pop();
				if (!ts.empty()){
					t1 += ts.top();
					ts.pop();
					ts.push(t1);
				}
				ids.pop();
				sts.pop();
			}
		}
		return vec;
	}
};