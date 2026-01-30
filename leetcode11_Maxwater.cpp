#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//双指针 O(n)
class Solution
{
    public:
    int MaxArea(vector<int> &height)
    {
        int ans=0;
        int left = 0;
        int right = height.size() - 1;
        while(left<right){
            //首先判断左右最远距离的情况
            
            int area = (right - left) * min(height[left], height[right]);
            ans = max(ans, area);
            // 当前柱子是最两侧的柱子，水的宽度 d 为最大，其他的组合，水的宽度都比这个小。
            // 左边柱子较短，决定了水的高度为 1。如果移动左边的柱子，新的水面高度不确定，一定不会超过右边的柱子高度 7。
            // 如果移动右边的柱子，新的水面高度一定不会超过左边的柱子高度 1，也就是不会超过现在的水面高度。
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    int Max_res = s.MaxArea(height);
    cout << "接雨水最多为：" << Max_res << endl;
    return 0;
}