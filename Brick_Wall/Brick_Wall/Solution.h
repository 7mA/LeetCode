#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Solution {  //优解：一个最简单的求最大的问题，因为没分析好结果以为是求最小。。
public:
	int leastBricks(vector<vector<int>>& wall) {
		map<int, int> m;
		int l = wall.size(), n, sum;
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
		for (int i = 0; i < l; i++){
			n = wall[i].size();
			sum = 0;
			for (int j = 0; j < n - 1; j++){
				sum += wall[i][j];
				auto x = m.find(sum);
				if (x != m.end()) (*x).second++;
				else m[sum] = 1;
				pq.push(make_pair(sum, m[sum]));
			}
		}
		return pq.size() > 0 ? l - pq.top().second : l;
	}

	struct cmp{
		bool operator()(pair<int, int> a, pair<int, int> b){
			return a.second < b.second;
		}
	};
};