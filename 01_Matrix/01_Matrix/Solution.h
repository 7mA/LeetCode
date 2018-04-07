#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {  //优解：广度优先搜索初见，自己写的方法果然TLE。。
				  //一开始总在想怎么模仿太平洋大西洋那道题，却不成功，没想到优解真就是左上扫描一遍，右下扫描一遍。。
	              //已经不是BFS了。。
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		if (matrix.empty()) return {};
		int h = matrix.size();
		int w = matrix[0].size();
		vector<vector<int>> dirs{ { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };
		queue<pair<int, int>> q;
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				if (matrix[i][j] == 0) q.push({ i, j });
				else matrix[i][j] = INT_MAX;
			}
		}
		while (!q.empty()){
			auto t = q.front();
			q.pop();
			for (auto dir : dirs){
				int x = t.first + dir[0], y = t.second + dir[1];
				if (x < 0 || x >= h || y < 0 || y >= w 
					|| matrix[x][y] <= matrix[t.first][t.second]) continue;
				matrix[x][y] = matrix[t.first][t.second] + 1;
				q.push({ x, y });
			}
		}
		return matrix;
	}
};