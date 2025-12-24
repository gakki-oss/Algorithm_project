#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int i=0;
   
    int n,a,b;
    cout << "请输入n:" << endl;
    cin >> n;
    int presum=0;
    vector<int> num(n,0);
    vector<int> p(n,0);
    cout << "请输入数组元素:" << endl;
    for(auto &it :num)
    {
        int t;
        cin >> t;
        it = t;
        presum+=t;
        p[i++]=presum;
    }
    int x = 2;
    cout << "请输入区间:" << endl;
    while(x--)
    {
        cin >> a >> b;
        int sum ;
        if(a==0) sum = p[b];
        else{
            sum = p[b] - p[a-1];
        }
        cout << sum << endl;
    }


    return 0;

}