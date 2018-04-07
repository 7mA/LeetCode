#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {   //�Ž⣺��һ������������ǰ�ˣ�����ͽ���һ�ݶ��ˡ���ûɶ˵��Ҳ��һ������
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		if (!root) return res;
		if (!root->left && !root->right){
			res.push_back(to_string(root->val));
			return res;
		}
		for (auto a : binaryTreePaths(root->left)) res.push_back(to_string(root->val) + "->" + a);
		for (auto a : binaryTreePaths(root->right)) res.push_back(to_string(root->val) + "->" + a);
		return res;
	}
};