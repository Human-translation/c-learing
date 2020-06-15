class Solution {
    vector<bool> viewed;
    vector<vector<int>> adList;
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        viewed = vector<bool>(n,0);
        adList = vector(n,vector<int>(1,-1));
        for (int i=0;i<graph.size();i++){
            adList[graph[i][0]].push_back(graph[i][1]);
        }
        return search(start,target);
    }

    bool search(int start,int target){
        viewed[start] = 1;
        bool result = 0;
        for(int i=1;i<adList[start].size();i++){
            if (viewed[adList[start][i]]==0){
                if(adList[start][i]==target){
                    viewed[adList[start][i]] =1 ;
                    return 1;
                }
                result = search(adList[start][i],target);
                if(result==1)
                    break;
            }
        }
        return result;
    }
};
