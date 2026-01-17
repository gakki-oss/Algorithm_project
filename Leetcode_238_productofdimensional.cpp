#include<iostream>
#include<vector>
using namespace std;


//

class Solution1 {
public:
    vector<int> productExceptSelf1(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size();i++)
        {
            int t = 1;
            for (int j = 0; j < nums.size();j++)
            {
               
                if(j!=i)
                {
                    t *= nums[j];
                }  
            }
            ans[i] = t;
        }
        return ans;
    }
};


//
class Solution2 {
public:
    vector<int> productExceptSelf2(vector<int>& nums) {
        int n =nums.size();
        vector<int> pre(n,1);
        vector<int> suf(n,1);
        vector<int> ans(n);
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=suf[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++)
        {
            ans[i]=pre[i]*suf[i];
        }
        return ans;
    }
};

int main()
{
    vector<int> nums1{-1,1,0,-3,3};
    vector<int> nums2{1, 2, 3, 4};
    Solution1 s1;
    Solution2 s2;
    vector<int> ans1 = s1.productExceptSelf1(nums1);
    cout << "法一:BF" << endl;
    for(auto i:ans1){
        cout << i << " ";
    }
    cout << endl;
    cout << "法二:前缀和" << endl;
    vector<int> ans2 = s2.productExceptSelf2(nums2);
    for(auto i : ans2)
    {
        cout << i << " ";
    }
    return 0;
}