#include<iostream>
#include<vector>

std::vector<std::vector<int>> preSum;

void init_preSum(std::vector<std::vector<int>> &maxter)
{
    int row, column;
    row = maxter.size();
    column = maxter[0].size();
    preSum.resize(row+1, std::vector<int>(column+1,0));
    for (int i = 1; i <= row;i++)
    {
        for (int j = 1; j <= column;j++)
        {
            preSum[i][j] = maxter[i-1][j-1] + preSum[i][j - 1] + preSum[i - 1][j] - preSum[i - 1][j - 1];
        }
             
    }
}

int Get_Sum(int x1,int y1,int x2,int y2)
{
    return preSum[x2+1][y2+1]-preSum[x2+1][y1]-preSum[x1][y2+1]+preSum[x1][y1];
}


int main()
{

    std::vector<std::vector<int>> maxter(2, std::vector<int>(3));
    for(auto &row :maxter)
    {
        for(auto &a:row)
        {
            std::cin >> a;
        }    
    }

    // for(auto row :maxter)
    // {
    //     for(auto &a:row)
    //     {
    //         std::cout << a << " ";
    //     }
    //     std::cout << std::endl;
    // }

    init_preSum(maxter);
    std::cout << "ÊäÈëx1,y1,x2,y2" << std::endl;
    std::cout << Get_Sum(0, 0, 1, 2) << " " << Get_Sum(1, 0, 1, 2) << std::endl;
    return 0;
}