
#include "../../header/myheader.h"

class LT6138
{
public:



    //1777 / 25931	Ouha 	17	0 : 51 : 53	0 : 05 : 46 	0 : 13 : 14 	0 : 40 : 43 	0 : 51 : 53


    // 第三题炸了。


    // AC
    // t 是 s 的子串
    // t的 相邻char 的 diff  <= k
    int longestIdealString(string s, int k)
    {
        int arr[123] = { 0 };           // 以这个char 为结尾的 最长 subseq

        for (int i = 0; i < s.size(); ++i)
        {
            int ch = s[i];
            int t2 = arr[ch];
            for (int j = max((int) 'a', ch - k), mxj = min((int)'z', ch + k); j <= mxj; ++j)
            {
                //arr[ch] = max(arr[j] + 1, arr[ch]);
                t2 = max(t2, arr[j] + 1);
            }
            arr[ch] = t2;
        }

#ifdef __test
        for (int i = 'a'; i <= 'z'; ++i)
        {
            cout << char (i) << " === " << arr[i] << endl;
        }
#endif


        int ans = 0;
        for (int i = 'a'; i <= 'z'; ++i)
        {
            ans = max(ans, arr[i]);
        }
        return ans;
    }

};

int main()
{

    LT6138 lt;

    //string s = "acfgbd";
    //int k = 2;

    string s = "abcd";
    int k = 3;

    cout << lt.longestIdealString(s, k) << endl;

    return 0;
}
