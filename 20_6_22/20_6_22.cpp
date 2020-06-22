class Solution {
private:
    int maxdep = -1;
    int total = 0;

public:
    void dfs(TreeNode* node, int dep) {
        if (!node) {
            return;
        }
        if (dep > maxdep) {
            maxdep = dep;
            total = node->val;
        }
        else if (dep == maxdep) {
            total += node->val;
        }
        dfs(node->left, dep + 1);
        dfs(node->right, dep + 1);
    }

    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return total;
    }
};

