#include<iostream>
#include<vector>
using namespace std;

//BF
class Solution1 {
public:
    vector<int> corpFlightBookings1(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n,0);
        for(auto booking : bookings)
        {
            for (int i = booking[0]; i <= booking[1];i++)
            {
                ans[i - 1] += booking[2];
            }
        }
        return ans;
    }
};



//差分数组
class Solution2 {
public:
    vector<int> corpFlightBookings2(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n, 0);
        for(auto &booking:bookings)
        {
            diff[booking[0] - 1] += booking[2];
            if(booking[1]<n)
            {
                diff[booking[1]] -= booking[2];
            }
        }
        for (int i = 1; i < diff.size();i++)
        {
            diff[i] += diff[i - 1];
        }

            return diff;
    }
};


int main(){
    int n;
    cout << "输入航班数:";
    cin >> n;
    vector<vector<int>> Booking{{1,2,10},{2,3,20},{2,5,25}};
    vector<int> ans1(n,0);
    vector<int> ans2(n,0);
    for(auto &booking:Booking)
    {
         ;
    }
    Solution1 s;
    cout << "法一(暴力):"<< endl;
    ans1=s.corpFlightBookings1(Booking, n);
    cout << "航班预定信息:" << endl;
    for(auto i:ans1)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "法二(差分数组):"<< endl;
    Solution2 s1;
    ans2 = s1.corpFlightBookings2(Booking, n);
    for(auto j:ans2)
    {
        cout << j << " ";
    }
}