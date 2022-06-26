
#include "../header/myheader.h"

class LT2315
{
public:

    // D D

    //for (int i = 0; i < s.size(); i++) {
    //    if (s[i] == '|') {
    //        while (s[++i] != '|');
    //    }
    //    else if (s[i] == '*')
    //        ans++;
    //}
    // 直接跳过

    //for (char ch : s) {
    //    if (ch == '|')
    //        count++;
    //    if (ch == '*' && (count % 2 == 0))
    //        ans++;
    //}
    // 计数


    //for (char& c : s)
    //    if ((sign ^= c == '|') && c == '*')
    //        res++;


//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Count Asterisks.
//Memory Usage : 6.3 MB, less than 77.78 % of C++ online submissions for Count Asterisks.
    int lt2315a(string s)
    {
        int b2 = true;
        int ans = 0;
        for (char ch : s)
        {
            if (ch == '|')
            {
                b2 = !b2;
            }
            else
            {
                if (ch == '*')
                    ans += b2 ? 1 : 0;
            }
        }
        return ans;
    }

};

int main()
{

    LT2315 lt;


    return 0;
}
