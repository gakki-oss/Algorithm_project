#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<vector<int>> Threesum(vector<int> &nums)
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 2;i++)
        {
            int x = nums[i];
            if(i && x==nums[i-1])
                continue;
            if(x+nums[i+1]+nums[i+2]>0)
                break;
            if(x+nums[n-1]+nums[n-2]<0)
                continue;
            int j = i + 1,k = n - 1;
            while(j<k)
            {
                int sum = x + nums[j] + nums[k];
                if(sum>0){
                    k--;
                }
                else if(sum<0){
                    j++;
                }else{
                    ans.push_back({x, nums[j], nums[k]});
                    for (j++; j < k && nums[j] == nums[j - 1];j++);
                    for (k--; j < k && nums[k] == nums[k + 1];k--);   
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums{-1, 0, 1,-1, 2, -4};
    vector<vector<int>> ans;
    Solution s;
    ans = s.Threesum(nums);
    for(auto &r:ans)
    {
        for(auto &c:r)
        {
            cout << c << ' ';
        }
        cout << endl;
    }
    return 0;
}