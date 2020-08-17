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
	node->left = NULL;    //将该节点的左孩子设为NULL
	cur->right = node;    //将该节点赋给上一个节点的右孩子
	cur = node;           //更新cur
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