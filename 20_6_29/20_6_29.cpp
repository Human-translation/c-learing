class Solution {
public:
    vector<string> ans;
    vector<string> permutation(string S) {
        dfs(S, 0);
        return ans;
    }

    void dfs(string S, int idx) {
        int n = S.size();
        if (idx == n) ans.emplace_back(S);
        for (int i = idx; i != n; ++i) {
            string tmp = S;
            swap(tmp[idx], tmp[i]);
            dfs(tmp, idx + 1);
        }
    }
};
