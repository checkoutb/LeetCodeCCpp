
#include "../header/myheader.h"

class LT1358
{
public:

    // D D

    //int last[3] = { -1, -1, -1 }, res = 0, n = s.length();
    //for (int i = 0; i < n; ++i) {
    //    last[s[i] - 'a'] = i;
    //    res += 1 + min({ last[0], last[1], last[2] });
    //}


    //int count[3] = { 0, 0, 0 }, res = 0, i = 0, n = s.length();
    //for (int j = 0; j < n; ++j) {
    //    ++count[s[j] - 'a'];
    //    while (count[0] && count[1] && count[2])
    //        --count[s[i++] - 'a'];
    //    res += i;
    //}



//Runtime: 32 ms, faster than 65.23 % of C++ online submissions for Number of Substrings Containing All Three Characters.
//Memory Usage : 8.5 MB, less than 87.07 % of C++ online submissions for Number of Substrings Containing All Three Characters.
    // 一旦包含，前面的也全部包含。
    int lt1358a(string s)
    {
        int lsta{ -1 }, lstb{ -1 }, lstc{ -1 };

        int ans = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            switch (s[i])
            {
            case 'a':
                lsta = i;
                break;
            case 'b':
                lstb = i;
                break;
            case 'c':
                lstc = i;
                break;
            }

            //if (lsta > -1 && lstb > -1 && lstc > -1)
            //{
            //    int mnidx = min({lsta, lstb, lstc})
            //}

            int mnidx = min({ lsta, lstb, lstc });
            if (mnidx > -1)
            {
                ans += mnidx + 1;
            }
        }
        return ans;
    }

};

int main()
{

    LT1358 lt;


    return 0;
}
