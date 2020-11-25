
#include "../header/myheader.h"

class LT1419
{
public:

// D D

//    int cnt[5] = {}, frogs = 0, max_frogs = 0;
//    for (auto ch : croakOfFrogs) {
//        auto n = string("croak").find(ch);
//        ++cnt[n];
//        if (n == 0)
//            max_frogs = max(max_frogs, ++frogs);
//        else if (--cnt[n - 1] < 0)
//            return -1;
//        else if (n == 4)
//            --frogs;
//    }
//    return frogs == 0 ? max_frogs : -1;




//Runtime: 28 ms, faster than 67.19% of C++ online submissions for Minimum Number of Frogs Croaking.
//Memory Usage: 9.4 MB, less than 84.37% of C++ online submissions for Minimum Number of Frogs Croaking.
// c++,k--.
    int lt1419a(string croakOfFrogs)
    {
        int sz1 = croakOfFrogs.size();
        if (sz1 % 5 != 0)
            return -1;
        int arr[123] = {0};
        int ans = 0;
        int cnt = 0;
        string croak = "croak";
        for (char ch : croakOfFrogs)
        {
            if (ch == 'c')
            {
                cnt++;
                ans = max(ans, cnt);
            }
            else if (ch == 'k')
            {
                cnt--;
            }
            arr[ch]++;
            for (int i = 0; i < croak.size() - 1; ++i)
                if (arr[croak[i]] < arr[croak[i + 1]])
                    return -1;
        }
//        cout<<croak.size()<<" : "<<sizeof("croak") / sizeof(char)<<endl;          // 5 : 6
        for (char ch : croak)       // 直接 ch : "croak" 多了一个符号。
        {
            if (arr[ch] != (sz1 / 5))
                return -1;
        }
        return ans;
    }

};

int main()
{
    string s = "aoocrrackk";

    LT1419 lt;

    cout<<lt.lt1419a(s)<<endl;

    return 0;
}
