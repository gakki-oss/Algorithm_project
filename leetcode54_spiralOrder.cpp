#include<iostream>
#include<vector>
using namespace std;

//如果matrix为空直接返回
//定义上下左右四个边界 l , r , t , b
//从左至右 从上到下 从右至左 从下到上 循环加入ans
//每步完成收缩边界并判断是否越界

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return {};
        int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
        vector<int> ans;
        while(true)
        {
            for (int i = l; i <= r;i++)
                ans.push_back(matrix[t][i]);
            if(++t>b)
                break;
            for (int i = t; i <= b;i++)
                ans.push_back(matrix[i][r]);
            if(l > --r )
                break;
            for (int i = r; i >= l;i--)
                ans.push_back(matrix[b][i]);
            if( t > --b)
                break;
            for (int i = b; i >= t; i--)
                ans.push_back(matrix[i][l]);
            if(l++ > r)
                break;
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> martix{{1,2,3,},{4,5,6},{7,8,9}};
    vector<int> ans;
    Solution s;
    ans = s.spiralOrder(martix);
    for(auto i:ans)
    {
        cout << i << " ";
    }
    return 0;
}