#include<iostream>
#include<string>
#include"TreeNode.h"
using namespace std;

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {  //�Ž⣺�������öԽ���ַ��������Լӣ���ȴ��ĵݹ�졣
public:
	string tree2str(TreeNode* t) {
		if (t == NULL) return "";
		string ls = tree2str(t->left);
		string rs = tree2str(t->right);
		if (ls == "" && rs == "") return to_string(t->val);
		else if (ls != "" && rs == "") return to_string(t->val) + "(" + ls + ")";
		else return to_string(t->val) + "(" + ls + ")" + "(" + rs + ")";
	}
};	