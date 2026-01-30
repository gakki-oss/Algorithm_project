#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//双指针
class Solusion1{
    public:
    void MoveZeros(vector<int> &nums)
    {
        for (int i = 0, j = 0; j < nums.size();j++)
        {
            if(nums[j]!=0)
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};

//原地栈
class Solusion2{
    public:
    void MoveZeros1(vector<int> &nums)
    {
        int stack_size = 0;
        for(int &x:nums)
        {
            if(x){
                nums[stack_size++] = x;
            }
        }
       fill(nums.begin() + stack_size, nums.end(), 0);
    }
};

int main(){
    vector<int> nums1{1, 0, 1, 2, 3};
    vector<int> nums2{1, 0, 0, 2, 3};
    Solusion1 s1;
    s1.MoveZeros(nums1);
    for(const int i : nums1)
    {
        cout << i << ' ';
    }
    cout << endl;
    Solusion2 s2;
    s2.MoveZeros1(nums2);
    for(int j : nums2)
    {
         cout << j << ' ';
    }
    return 0;
}