class Solution {
public:
    void que(vector<int>&a, vector<int>& b,int x,int y,int t,vector<vector<int>>& res,vector<int>& k){
        if(x >= a.size() && y >= b.size()){
            k.push_back(t);
            res.push_back(k);
            k.pop_back();
            return;
        }
        if(x < a.size()){
            k.push_back(a[x]);
            que(a,b,x+1,y,t,res,k);
            k.pop_back();
        }
        if(y < b.size()){
            k.push_back(b[y]);
            que(a,b,x,y+1,t,res,k);
            k.pop_back();
        }
    }
    vector<vector<int>> BSTS(TreeNode* root){
        if(!root) return {};
        vector<vector<int>> a = BSTS(root->left);
        vector<vector<int>> b = BSTS(root->right);
        vector<vector<int>> res;
        if(a.empty() && !b.empty()){
            for(int i = 0; i < b.size(); ++i){
                auto p = b[i];
                p.push_back(root->val);
                res.push_back(p);
            }
        }
        else if(!a.empty() && b.empty()){
            for(int i = 0; i < a.size(); ++i){
                auto p = a[i];
                p.push_back(root->val);
                res.push_back(p);
            }
        }
        else if(a.empty() && b.empty()){
            vector<int> temp(1,root->val);
            res.push_back(temp);
        }
        else{
            for(int i = 0 ; i < a.size(); ++i){
                for(int j = 0 ; j < b.size(); ++j){
                    vector<int> k;
                    que(a[i],b[j],0,0,root->val,res,k);
                }
            }
        }
        return res;
    }
    vector<vector<int>> BSTSequences(TreeNode* root) {
        vector<vector<int>> res(1,vector<int>({}));
        if(!root) return res;
        res = BSTS(root);
        for(int i = 0 ; i < res.size(); ++i){
            reverse(res[i].begin(),res[i].end());
        }
        return res;
    }
};
