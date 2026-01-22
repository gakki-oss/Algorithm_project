#include<iostream>
#include<vector>
using namespace std;

//差分数组法
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1024, 0);
        // diff的[from,to)区间整体加上车人数 ，[to,end)整体减下车人数
        for(auto &t : trips)
        {
            int num_Pass=t[0],from=t[1],to=t[2];
            diff[from]+=num_Pass;
            diff[to]-=num_Pass;
        }
        int sum=0;
        for (auto d : diff)
        {
            sum+=d;
            if(sum>capacity)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<int>> Car_pooling{{2, 1, 5}, {3, 3, 7}};
    int capacity;
    cout << "输入初始公交车乘客数:" << endl;
    cin >> capacity;
    bool ans;
    Solution s;
    ans = s.carPooling(Car_pooling, capacity);
    if(ans)
    {
        cout << "通过" << endl;
    }
    else{
        cout << "超载" << endl;
    }
    return 0;
}
