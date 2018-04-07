#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

class Solution {   //优解：采用edges数组存储边的关系，省得一次次遍历prerequisites，而且处理过的点直接把对应的edge清空，加快效率
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		queue<int> q;
		vector<int> in(numCourses, 0);
		set<int> tmppre;
		int count = 0, size, temp;
		for (auto pre : prerequisites) in[pre.second]++;
		for (auto pre : prerequisites) if (!in[pre.first]) tmppre.insert(pre.first);
		for (auto pre : tmppre) q.push(pre);
		while (!q.empty()){
			tmppre.clear();
			size = q.size();
			for (int i = 0; i < size; i++){
				temp = q.front();
				q.pop();
				for (auto pre : prerequisites){
					if (pre.first == temp) {
						in[pre.second]--;
						tmppre.insert(pre.second);
					}
				}
			}
			for (auto pre : tmppre) if (!in[pre]) q.push(pre);
		}
		for (auto ind : in) if (ind) return false;
		return true;
	}
};