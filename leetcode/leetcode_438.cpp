#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution
{
    public:
    vector<int> findAnagrams(string s,string p){
        vector<int> ans;
        unordered_map<char,int> map_p;
        unordered_map<char,int> map_s;
        //≥ı ºªØp
        for(auto c:p){
            map_p[c]++;
        }
        for (int right = 0, left = 0; right < s.size();right++)
        {
            map_s[s[right]] += 1;
            if(right-left+1>p.size())
            {
                if(map_s[s[left]]==1){
                    map_s.erase(s[left]);
                }else{
                    map_s[s[left]] -= 1;
                }
                left++;
            }
            if(map_p==map_s)
            {
                ans.push_back(left);
            }
        }
        return ans;
    }
};


int main()
{
    string s{"cbaebabacd"};
    string p{"abc"};
    vector<int> ans;
    Solution s1;
    ans=s1.findAnagrams(s, p);
    for(auto num:ans)
    {
        cout << num << ' ';
    }
    return 0;

}