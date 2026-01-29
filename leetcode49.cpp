#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string , vector<string> > m;
        // 将字符串按从小到大的顺序重新排列 后加入同一组 , 排序后的字符串作为键 ， 排序前 的字符串作为值
        for(string &s:strs)
        {
            string sorted_s = s ; // 定义变量存储排序后的字符串 初始化
            sort(sorted_s.begin(),sorted_s.end()); // 对字符串进行排序(按照默认字符序从小到大排序)
            m[sorted_s].push_back(s);
        }
        //将排序后相同的字符串加入vector中 返回答案
        vector<vector<string>> ans;
        ans.reserve(m.size());
        for(auto &[first,second] : m)
        {
            ans.push_back(second);
        }
    return ans;
    }
};