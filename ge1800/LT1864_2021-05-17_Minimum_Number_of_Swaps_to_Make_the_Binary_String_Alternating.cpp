
#include "../header/myheader.h"

class LT1864
{
public:

// D D

//        int zo = 0, ze = 0;
//        int oo = 0, oe = 0;
//
//        for (int i=0;i<s.length();++i) {
//            if (i % 2 == 0) {
//                if (s[i] == '0') zo += 1;
//                else oo += 1;
//            } else {
//                if (s[i] == '0') ze += 1;
//                else oe += 1;
//            }
//        }
//        int best = 1001;
//        if (zo == oe) best = min(zo, best);
//        if (oo == ze) best = min(oo, best);
//        if (best >= 1000) best = -1;
//        return best;



//int swaps(string &s, char start, char end) {
//    int res = 0, i = 0, j = 0, sz = s.size() - 1;
//    while (i <= (sz - j)) {
//        if ((i % 2 == 0 && s[i] == start) || (i % 2 && s[i] != start))
//            ++i;
//        else if ((j % 2 == 0 && s[sz - j] == end) || (j % 2 && s[sz - j] != end))
//            ++j;
//        else
//            ++res, ++i, ++j;
//    }
//    return res;
//}
//int minSwaps(string s) {
//    int zeros = count(begin(s), end(s), '0'), ones = s.size() - zeros;
//    if (abs(zeros - ones) > 1)
//        return -1;
//    if (s.size() % 2)
//        return swaps(s, zeros > ones ? '0' : '1', zeros > ones ? '0' : '1');
//    return min(swaps(s, '0', '1'), swaps(s, '1', '0'));
//}



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Minimum Number of Swaps to Make the Binary String Alternating.
//Memory Usage: 6.6 MB, less than 16.67% of C++ online submissions for Minimum Number of Swaps to Make the Binary String Alternating.
    int lt1864a(string s)
    {
        int cnt0 = 0;
        int cnt1 = 0;
        for (char& ch : s)
            if (ch == '0')
                cnt0++;
        cnt1 = s.size() - cnt0;
        if (abs(cnt1 - cnt0) > 1)
            return -1;

        int ans = 0;
        if (cnt0 == cnt1)
        {
            char fst = '0';
            for (int i = 0; i < s.size(); i += 2)
            {
                if (s[i] != fst)
                    ans++;
            }
            ans = min(ans, (int) s.size() / 2 - ans);
            return ans;
        }

        char fst = '0';
        if (cnt0 < cnt1)
            fst = '1';

        for (int i = 0; i < s.size(); i += 2)
        {
            if (s[i] != fst)
                ans++;
        }
        return ans;
    }

};

int main()
{
//    string s = "111000";
//    string s = "0101";
//    string s = "010";
    string s = "1110";

    LT1864 lt;

    cout<<lt.lt1864a(s)<<endl;

    return 0;
}
