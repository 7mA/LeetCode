#include<iostream>
#include<vector>
using namespace std;

class Solution {  // 优解：这道题没想出来，没有想到倒着找才是递归的好方法。
				  // 优解用位运算的方式优化了记录矩阵的运算，减少了一个矩阵。
	vector<int> di = { 0, 0, 1, -1 };
	vector<int> dj = { 1, -1, 0, 0 };

public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		vector<int> temp;
		vector<pair<int, int>> res;
		int h = matrix.size();
		if (!h) return res;
		int w = matrix[0].size();
		vector<vector<bool>> Pflow(h, vector<bool>(w, false));
		vector<vector<bool>> Aflow(h, vector<bool>(w, false));
		for (int i = 0; i < h; i++){
			flow(matrix, Pflow, i, 0, h, w);
			flow(matrix, Aflow, i, w - 1, h, w);
		}
		for (int j = 0; j < w; j++){
			flow(matrix, Pflow, 0, j, h, w);
			flow(matrix, Aflow, h - 1, j, h, w);
		}
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				if (Pflow[i][j] && Aflow[i][j]) res.push_back(make_pair(i, j));
			}
		}
		return res;
	}

	void flow(vector<vector<int>>& matrix, vector<vector<bool>>& f, int i, int j, int h, int w){
		f[i][j] = true;
		for (int k = 0; k < 4; k++){
			int ni = i + di[k];
			int nj = j + dj[k]; 
			if (ni >= 0 && ni < h && nj >= 0 && nj < w){
				if (!f[ni][nj] && matrix[ni][nj] >= matrix[i][j]) flow(matrix, f, ni, nj, h, w);
			}
		}
	}
};