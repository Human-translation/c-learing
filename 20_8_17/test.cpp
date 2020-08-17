#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

TreeNode *ans = new TreeNode(0), *cur = ans;
void inOrder(TreeNode* node)
{
	if (node == NULL)  return;
	inOrder(node->left);
	node->left = NULL;    //���ýڵ��������ΪNULL
	cur->right = node;    //���ýڵ㸳����һ���ڵ���Һ���
	cur = node;           //����cur
	inOrder(node->right);
}
TreeNode* convertBiNode(TreeNode* root) {
	inOrder(root);
	return ans->right;
}
int main()
{
	cout << longestCommonSubsequence("abcde", "ace");
}