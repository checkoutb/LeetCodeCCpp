
#include "../header/myheader.h"

class LT2896
{
public:



    // g
    // 不是 外面 操作1， 里面操作2 的。。

    // [i]
    // 0-1  1-0
    // waimian i j  1st op.  limian i i+1   2nd op.
    int minOperations(string s1, string s2, int x)
    {
        int sz1 = s1.size();
        vector<vector<int>> vvi(sz1, vector<int>(sz1, -1)); // [i, j] use 2nd op
        bool flp = false;
        bool eq = false;
        for (int i = 0; i < sz1; ++i)
        {
            int cnt = 0;

            if (s1[i] == s2[i])
            {
                vvi[i][i] = 0;
                flp = false;
            }
            else
            {
                ++cnt;
                flp = true;
            }

            for (int j = i + 1; j < sz1; ++j)
            {
                eq = s1[j] == s2[j];
                if (flp)
                    eq = !eq;

                if (eq)
                {
                    if (vvi[i][j] == -1)
                        vvi[i][j] = cnt;
                    else
                        vvi[i][j] = min(vvi[i][j], cnt);

                    flp = false;
                }
                else
                {
                    ++cnt;
                    flp = true;
                }
            }
        }

        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test

//        int ans = INT_MAX;
        int ans = vvi[0][sz1 - 1] == -1 ? INT_MAX : vvi[0][sz1 - 1];
        int cnt = 0;
        int j = sz1 - 1;
        for (int i = 0; i < j; ++i)
        {
            if (s1[i] == s2[i])
                continue;

            while (j > i && s1[j] == s2[j])
            {
                --j;
            }

            if (j == i)
                break;
            cnt += x;
            if (vvi[i + 1][j - 1] != -1)
            {
                #ifdef __test
                cout<<i<<" - "<<j<<", "<<cnt<<", "<<vvi[i + 1][j - 1]<<endl;
                #endif // __test

                ans = min(ans, cnt + vvi[i + 1][j - 1]);
            }
            --j;
        }

//        int j = sz1 - 1;
//        for (int i = 0; i < sz1; ++i)
//        {
//            if (s1[i] == s2[i])
//                continue;
//
//            while (j > i && s1[j] == s2[j])
//            {
//                --j;
//            }
//            if (j == i)
//                break;
//
//            if ()     // if vvi == -1, i++ or --j
//            cnt = 0;
//            for (int j = sz1 - 1; j > i; --j)
//            {
//                if (s1[j] == s2[j])
//                    continue;
//                cnt += x;
//                if (vvi[i + 1][j - 1] != -1)
//                {
//                    ans = min(ans, vvi[i + 1][j - 1] + cnt);
//                }
//            }
//        }
        return ans == INT_MAX ? -1 : ans;
//        vector<vector<vector<int>>> vvvi(sz1, vector<vector<int>>(sz1, vector<int>(2, INT_MAX)));
//        for (int i = 0; i < sz1; ++i)
//        {
//            for (int j = sz1 - 1; j >= 0; --j)
//            {
//                if (s1[i] == s2[j])
//                {
//
//                }
//            }
//        }
    }

//    void dfsa1(string& s1, string& s2, int x, int st, int en, vector<vector<int>>& vvi)
//    {
//        while (st < en && s1[st] == s2[st])
//            ++st;
//
//        while (en > st && s1[en] == s2[en])
//            --en;
//
//
//    }

};

int main()
{

    LT2896 lt;

//    string s1 = "1100011000", s2 = "0101001010";
//    int x = 2;

//    string s1 = "10110", s2 = "00011";
//    int x = 4;

//    string s1 = "101101", s2 = "000000";
//    int x = 6;      // 4

    string s1 = "01010110000010010100", s2 = "10011011111100000110";
    int x = 2;      // 7

    cout<<lt.minOperations(s1, s2, x)<<endl;

    return 0;
}
