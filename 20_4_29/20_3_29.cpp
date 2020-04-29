class Solution {
public:
    vector<vector<int>> TreeArr;
    vector<int> arr;
    int num = 0;
    void run(TreeNode* root,int sum)
    {
        if(!root)
            return ;
        
        arr.push_back(root->val);
        num += root->val;
        if(num == sum && !root->left && !root->right)
        {
            TreeArr.resize(TreeArr.size()+1);
            for(auto ch:arr)
                TreeArr[TreeArr.size()-1].push_back(ch);
        }
        run(root->left,sum);
        run(root->right,sum);
        arr.pop_back();
        num -= root->val;
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        run(root,sum);
        return TreeArr;
    }
};