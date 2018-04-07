#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:          //做了上道题，这道题就很简单了。。根据奇偶决定是否倒置数列即可
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL) return res;
		queue<TreeNode*> q;
		int count = 1;
		q.push(root);
		while (!q.empty()){
			vector<int> oneLevel;
			int size = q.size();
			for (int i = 0; i < size; i++){
				auto node = q.front();
				q.pop();
				oneLevel.push_back(node->val);
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
			if (count % 2 == 0) reverse(oneLevel.begin(), oneLevel.end());
			res.push_back(oneLevel);
			count++;
		}
		return res;
	} 
};