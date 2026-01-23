#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//思路详解：
// 要求是先将给出的字符串中多余的空格删除,并控制每个单词之间包含一个空格(快慢指针)
// 将字符串整体进行反转,后将每个单词再次进行反转

class Solution{
    public :
        //反转单词
        void reverse_Single(string &words ,int start,int end)
        {
            for (int i = start, j = end; i < j;i++,j--)
            {
                swap(words[i], words[j]);
            }
        }


        //slow指针:分割字符(手动添加空格),更新单词的起始位置
        void remove(string &s)
        {
            int slow = 0;
            for (int i = 0; i < s.size();i++)
            {
                if( s[i]!=' ')
                {
                    if(slow!=0)
                    {
                        s[slow++] = ' ';
                    }
                    while( s[i]!=' ' && i<s.size() )
                    {
                        s[slow++] = s[i++];
                    }
                }
            }
            //跟新remove操作后字符串大小
            s.resize(slow);
        }
    
        string reverseWords(string Words)
        {
            int start = 0;
            remove(Words);
            reverse_Single(Words , start,Words.size()-1 );
            for (int i = 0; i <= Words.size();i++)
            {
                if(Words[i] ==' ' || i == Words.size())
                {
                    reverse_Single(Words, start, i - 1);
                    start = i + 1;
                }
            }
            return Words;
        }
};

int main()
{
    string Words = "a good   example";
    string ans;
    Solution s;
    ans = s.reverseWords(Words);
    cout << "原字符串为:" << Words << endl;
    cout << "原地反转后字符串:" << ans << endl;
    return 0;
}