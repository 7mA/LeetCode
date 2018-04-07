#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {  //�Ž⣺����������ͷ�������ˣ���ε�BFS˼·���ϴ�Ҳ������
				  //��εĶ��д����Ҷ�ӣ�ͨ����Ҷ�ӵ�˼�������⣬���ʣ�µ�һ�������ڵ���Ǹ���
	              //�Ž����ڼȴ�����߻����˽ڵ�Ķȣ��Կռ任ʱ�䡣
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		if (n == 1) return { 0 };
		vector<int> res, deg(n, 0);
		queue<int> q;
		for (auto edge : edges){
			deg[edge.first]++;
			deg[edge.second]++;
		}
		for (int i = 0; i < n; i++){
			if (deg[i] == 1) q.push(i);
		}
		while (n > 2){
			int size = q.size();
			n -= size;
			for (int i = 0; i < size; i++){
				int t = q.front();
				q.pop();
				for (auto edge : edges){
					if (edge.first == t) {
						deg[edge.second]--;
						if (deg[edge.second] == 1) q.push(edge.second);
					}
					if (edge.second == t) {
						deg[edge.first]--;
						if (deg[edge.first] == 1) q.push(edge.first);
					}
				}
			}
		}
		while (!q.empty()){
			res.push_back(q.front());
			q.pop();
		}
		return res;
	}
};