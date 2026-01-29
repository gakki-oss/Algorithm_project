#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>


using namespace std;

class Solution
{
    public:
    int longsetConsecutive(vector<int> &nums)
    {
        //定义一个哈希集合,用于去重数组中可能存在的重复的数
        unordered_set<int> hash_set(nums.begin(), nums.end());
        int ans = 0;
        for(const int &num : nums)
        {
             //如何集合中存在小于当前数的数说明一定存在比已x为起点长的系列,可跳过当前的循环
            if(hash_set.find(num-1)!=hash_set.end())
            {
                
                continue;
            }
            //进行查找已x为起点的最长子序列为多长,跟新ans的值(x,x+1,x+2...)
            int y = num + 1;
            while(hash_set.find(y)!=hash_set.end())
            {
                y++;//不断查找下一个数是否在哈希表中
            }
              //循环结束后,y-1是最后一个在哈希表中的数
            ans = max(ans, y - num);//从x到y-1一共y-x个数
        }
        return ans;
    }

};

int main()
{
    vector<int> nums{1, 2, 1, 2, 3, 4};
    int ans;
    Solution s;
    ans = s.longsetConsecutive(nums);
    cout << "最长序列长度为:" << ans << endl;
    return 0;
}