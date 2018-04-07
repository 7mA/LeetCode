#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {   //优解：以时间换空间，利用矩阵存距离，之后计算每一行距离相等的数量。
	               //自己的问题：每一轮放弃了一部分数据，导致下一轮需要再做一次运算，造成浪费。
public:
	int numberOfBoomerangs(vector<pair<int, int>>& points) {
		map<int, int> m;
		int l = points.size();
		int d, dx, dy, res = 0;
		for (int i = 0; i < l; i++){
			for (int j = 0; j < l; j++){
				dx = points[i].first - points[j].first;
				dy = points[i].second - points[j].second;
				d = dx * dx + dy * dy;
				if (m.find(d) != m.end()){
					res += m[d];
					m[d]++;
				}
				else m[d] = 1; 
			}
			m.clear();
		}
		return res * 2;
	}
};