#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {  //�Ž⣺����û���뵽ͨ����ǰ������Ԫ�ظ������������������������е�������
public:
	vector<vector<int> > levelOrder(TreeNode *root) {
		vector<vector<int> > res;
		if (root == NULL) return res;

		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			vector<int> oneLevel;
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				TreeNode *node = q.front();
				q.pop();
				oneLevel.push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			res.push_back(oneLevel);
		}
		return res;
	}
};