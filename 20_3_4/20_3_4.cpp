#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <map>
using namespace std;


    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        map<int,int> m;
        int count = 0;
        int num = 0;
        int i=0,j=0,flag=0;
        for(;i<popped.size();i++)
        {
            flag=0;
            if(m.count(popped[i]))
            {
                flag = 1;
                map<int,int>::reverse_iterator it = m.rbegin();
                while(it != m.rend())                               //[1,2,5,8,7,4,6,9,3,0]
                {                                                   //[2,7,8,4,0,5,9,1,3,6]
                    if(it->second == count-1)
                    {
                        if(it->first == popped[i])
                        {
                            it->second = -1;
                            count--;
                            break;                                
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    it++;
                }
            }
            if(flag)    continue;
            for(;j<pushed.size();j++)
            {

                if(!m.count(popped[i]))
                {
                    if(popped[i] != pushed[j])
                    {
                        m[pushed[j]] = count;
                        count++;
                    }                
                    else
                    {
                        m[pushed[j]] = -1;
                        j++;
                        break;
                    }                    
                }
            }
            
        }
        return 1;
    }



    int main()
    {
        vector<int> pushnum = {1,2,5,8,7,4,6,9,3,0};
        vector<int> popnum = {2,7,8,4,0,5,9,1,3,6};
        cout<<validateStackSequences(pushnum,popnum);
        system("pause");
        return 0;
    }

/*
    vector<vector<int>> map;
    vector<int> num;
    void init(vector<vector<int>>& map,vector<vector<int>>& grid,int hang,int lie)
    {
        map.resize(hang+2);
        for(int i=0;i<hang+2;i++)
        {
            map[i].resize(lie+2);  
        }
        for(int i=0;i<hang;i++)
        {
            for(int j=0;j<lie;j++)
            {
                map[i+1][j+1] = grid[i][j];
            }
        }
    }

    void sousuo(vector<vector<int>>& grid,int hang,int lie){
        for(int i=0;i<hang+2;i++)
        {
            for(int j=0;j<lie+2;j++)
            {
                if(map[i][j] == 2)
                {
                    num.push_back(i);
                    num.push_back(j);
                }
            }
        }
    }

    int ganran(vector<vector<int>>& map,vector<int>& num){
        int size = num.size()/2;
        int count =0;
        int i = 0;
        while(size--)
        {
            if(map[num[i]-1][num[i+1]] == 1)
            {
                map[num[i]-1][num[i+1]] = 2;
                count++;
            }
            if(map[num[i]+1][num[i+1]] == 1)
            {
                map[num[i]+1][num[i+1]] = 2;
                count++;
            }
            if(map[num[i]][num[i+1]-1] == 1)
            {
                map[num[i]][num[i+1]-1] = 2;
                count++;
            }
            if(map[num[i]][num[i+1]+1] == 1)
            {
                map[num[i]][num[i+1]+1] = 2;
                count++;
            }
            i=i+2;
        }
        return count;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int hang = grid.size();
        int lie = grid[0].size();
        init(map,grid,hang,lie);
        int cishu = 0;
        int count;
        do
        {
            sousuo(map,hang,lie);
            count = ganran(map,num);
            if(!count)
                break;
            cishu++;
        }while(count);
        for(int i=0;i<hang+2;i++)
        {
            for(int j=0;j<lie+2;j++)
                if(map[i][j] == 1)
                {
                    return -1;
                }
        }
        return cishu;
    }

    int main()
    {
        vector<vector<int>> grid;
        grid.resize(3);


        grid[0].push_back(0);
        grid[0].push_back(2);

        grid[0].push_back(2);
        grid[0].push_back(1);
        grid[0].push_back(1);
        grid[1].push_back(1);
        grid[1].push_back(1);
        grid[1].push_back(0);
        grid[2].push_back(0);
        grid[2].push_back(1);
        grid[2].push_back(1);

        cout<<orangesRotting(grid);
        system("pause");
        return 0;
    }
*/







class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = popped.size();
        int j = 0;
        for (int i = 0; i < pushed.size(); ++i){
            st.push(pushed[i]);
            while(!st.empty() && j < n && st.top() == popped[j]){
                st.pop();
                ++j;
            }
        }
        return st.empty();
    }
};







