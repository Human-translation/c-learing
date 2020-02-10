#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<string> topKFrequent(vector<string>& words, int k)
{
        map<string,int> mp;
        for(auto &word :words)
        {
            ++mp[word];
        }
        multimap<int,string,greater<int>> mtp;
        for(auto&e:mp)
        {
            mtp.insert(make_pair(e.second,e.first));
        }
        vector<string> ans;
        for(auto&e:mtp)
        {
            ans.push_back(e.second);
            if(--k==0)
                break;
        }
    return ans;        
}
int main()
{
    vector<string> num = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    for(auto const &ch : topKFrequent(num,4))
    {
        cout<<ch<<' ';
    }
    system("pause");
    return 0;
}