#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class solution{
    public:
    int subarraySum(vector<int> &nums,int k)
    {
        int ans = 0, presum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int num:nums)
        {
            presum += num;
            if(mp.count(presum-k)){
                ans += mp[presum - k];
            }
            mp[presum]++;
        }
        return ans;
    }
};

int main()
{
    int ans = 0;
    vector<int> nums{1, 2, 3, 4};
    solution s;
    ans = s.subarraySum(nums, 3);
    cout << "和为3的子数组个数为:" << ans;
    return 0;
}