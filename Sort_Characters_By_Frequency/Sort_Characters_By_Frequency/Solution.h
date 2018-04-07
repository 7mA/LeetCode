#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;

class Solution {  //优解：除了priority_queue之外，set也可以有排序的功能
public:
	string frequencySort(string s) {
		map<char, int> m;
		string res = "";
		priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
		for (auto c : s){
			auto x = m.find(c);
			if (x != m.end()) (*x).second++;
			else m[c] = 1;
		}
		for (auto p : m){
			pq.push(p);
		}
		while (!pq.empty()){
			for (int i = 0; i < pq.top().second; i++){
				res.append(1, pq.top().first);
			}
			pq.pop();
		}
		return res;
	}

	struct cmp{
		bool operator()(pair<char, int> a, pair<char, int> b){
			return a.second > b.second;
		}
	};
};