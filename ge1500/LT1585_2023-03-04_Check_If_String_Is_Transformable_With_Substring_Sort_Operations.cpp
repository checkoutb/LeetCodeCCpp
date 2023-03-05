
#include "../header/myheader.h"

class LT1585
{
public:

    // D
    // .... 并没有移动， 只是， 判断下 下次出现 与 现在下标 间 有没有 比 所需要的 小的。


    // g

    // hint : swap 而不是 sort。
    // 而且 sort 后 会破坏 vvi。
    // 不用 vvi 会 tle。
    bool lt1585b(string s, string t)
    {
        int sz1 = s.size(), sz2 = t.size();

        vector<vector<int>> vvi(10, vector<int>());

        for (int i = 0; i < sz1; ++i)
        {
            vvi[s[i] - '0'].push_back(i);
        }

        int arr[10] = { 0 };
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (s[i] != t[i])
            {
                t2 = t[i] - '0';
                while (arr[t2] < vvi[t2].size() && vvi[t2][arr[t2]] <= i)
                {
                    ++arr[t2];
                }
                if (arr[t2] == vvi[t2].size())
                    return false;



                //sort(begin(s) + i, begin(s) + vvi[t2][arr[t2]] + 1);
                ++arr[t2];
            }
        }
        return true;
    }


    // .......
    // 需要一个2， 所以往后找到最近的2， 然后 这个 substr  sort。  如果 中间有1， 那么 return false。
    bool lt1585a(string s, string t)
    {
        int sz1 = s.size(), sz2 = t.size();
        
        vector<vector<int>> vvi(10, vector<int>());

        for (int i = 0; i < sz1; ++i)
        {
            vvi[s[i] - '0'].push_back(i);
        }

        int arr[10] = { 0 };
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (s[i] != t[i])
            {
                t2 = t[i] - '0';
                while (arr[t2] < vvi[t2].size() && vvi[t2][arr[t2]] <= i)
                {
                    ++arr[t2];
                }
                if (arr[t2] == vvi[t2].size())
                    return false;

                sort(begin(s) + i, begin(s) + vvi[t2][arr[t2]] + 1);
                ++arr[t2];
            }
        }
        return true;
    }

};

int main()
{

    LT1585 lt;

    string s = "84532";
    string t = "34852";

    cout << lt.lt1585a(s, t) << endl;

    return 0;
}
