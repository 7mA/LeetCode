#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {   //�Ž⣺��ʱ�任�ռ䣬���þ������룬֮�����ÿһ�о�����ȵ�������
	               //�Լ������⣺ÿһ�ַ�����һ�������ݣ�������һ����Ҫ����һ�����㣬����˷ѡ�
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