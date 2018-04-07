#include<iostream>
#include"Solution.h"
using namespace std;

void main(){
	Solution *s = new Solution();
	int r;
	int c;
	int temp;
	vector<vector<int>> vec;
	vector<int> row;
	cout << "r:";
	cin >> r;
	cout << "c:";
	cin >> c;
	int n = r * c;
	cout << "num:" << endl;
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cin >> temp;
			row.push_back(temp);
		}
		vec.push_back(row);
		row.clear();
	}
	cout << "new r:";
	cin >> r;
	cout << "new c:";
	cin >> c;
	vec = s->matrixReshape(vec, r, c);
	vector<vector<int>>::iterator vit;
	vector<int>::iterator rit;
	for (vit = vec.begin(); vit != vec.end(); vit++){
		for (rit = (*vit).begin(); rit != (*vit).end(); rit++){
			cout << *rit << " ";
		}
		cout << endl;
	}
}