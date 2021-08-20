
#include "../header/myheader.h"

class LT1888
{
public:

// D D

//    int res = INT_MAX, s0 = 0, s1 = 0, sz = s.size();
//    for (int i = 0; i < 2 * sz; ++i) {
//        s0 += s[i % sz] != '0' + i % 2;
//        s1 += s[i % sz] != '0' + (1 - i % 2);
//        if (i >= sz - 1) {
//            if (i >= sz) {
//                s0 -= s[i - sz] != '0' + (i - sz) % 2;
//                s1 -= s[i - sz] != '0' + (1 - (i - sz) % 2);
//            }
//            res = min(res, min(s0, s1));
//        }
//    }
//    return res;

// s = s + s ..........




// tired
//Runtime: 132 ms, faster than 5.18% of C++ online submissions for Minimum Number of Flips to Make the Binary String Alternating.
//Memory Usage: 44.9 MB, less than 5.18% of C++ online submissions for Minimum Number of Flips to Make the Binary String Alternating.
    int lt1888b(string s)
    {
        int sz1 = s.size();

        if (sz1 % 2 == 0)
        {
            return lt1888a(s);
        }

        vector<vector<int>> vvi(sz1, vector<int>(2));       // 0 偶数下标的1,  1 奇数下标的1.
        for (int i = 0; i < s.size(); ++i)
        {
            if (i % 2 == 0)
            {
                vvi[i][0] = (s[i] == '1' ? 1 : 0) + (i > 0 ? vvi[i - 1][0] : 0);
                vvi[i][1] = i > 0 ? vvi[i - 1][1] : 0;
            }
            else
            {
                vvi[i][0] = i > 0 ? vvi[i - 1][0] : 0;
                vvi[i][1] = (s[i] == '1' ? 1 : 0) + (i > 0 ? vvi[i - 1][1] : 0);
            }
        }
        #ifdef __test
//        for (myvi& vi : vvi)
//        {
//            cout<<vi[0]<<", "<<vi[1]<<endl;
//        }
//        for (char ch : s)
//            cout<<ch<<", ";
//        cout<<endl;
//        for (myvi& vi : vvi)
//        {
//            cout<<vi[0]<<", ";
//        }
//        cout<<endl;
//        for (myvi& vi : vvi)
//        {
//            cout<<vi[1]<<", ";
//        }
//        cout<<endl;
        #endif // __test
        int ans = INT_MAX;
        int sum1 = sz1 / 2;
        int sum0 = sum1 + 1;
        int cnt11 = vvi[sz1 - 1][1];
        int cnt00 = sum0 - vvi[sz1 - 1][0];     // 偶数总数 - 偶数位1 == 偶数位0
        ans = min(cnt00 + cnt11, sum0 - cnt00 + sum1 - cnt11);
        for (int i = 1; i < sz1; ++i)
        {
            cnt11 = vvi[sz1 - 1][(1 + i) % 2] - vvi[i - 1][(1 + i) % 2] + vvi[i - 1][(i + 0) % 2];
            cnt00 = sum0 - (vvi[sz1 - 1][(i + 0) % 2] - vvi[i - 1][(i + 0) % 2] + vvi[i - 1][(i + 1) % 2]);
//            if (i == 2)
//            {
//                cout<<cnt11<<", "<<cnt00<<endl;
//            }
            ans = min(ans, min(cnt00 + cnt11, sum0 - cnt00 + sum1 - cnt11));
        }
        return ans;
    }


// 应该是 返回type2 影响到的最少 char数量。
// 这种就是 for (1-n) 尝试 type1, 然后最少的。 估计之前的tle 就是这个。
// type1 会改变 下标的奇偶。
// 101 011     1234  3412   2341 。。。 肯定会改的， 因为移除了x个。
    int lt1888a(string s)
    {
        int cnt00 = 0;
        int cnt11 = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i % 2 == 0)
            {
                cnt00 += s[i] == '0';
            }
            else
            {
                cnt11 += s[i] == '1';
            }
        }
        int sum1 = s.size() / 2;
        int sum0 = s.size() - sum1;
        int ans = min(cnt00 + cnt11, sum1 - cnt11 + sum0 - cnt00);

//        // 不能直接减去的， 原先的，移动后， 下标的奇偶就变了。
//        for (int i = 0; i < s.size(); ++i)
//        {
            int t2 = cnt00;
            cnt00 = sum1 - cnt11;
            cnt11 = sum0 - t2;
            ans = min(ans, min(cnt00 + cnt11, sum1 - cnt11 + sum0 - cnt00));
//        }
        return ans;
    }

};

int main()
{

    string s = "111000";
//    string s = "010";
//    string s = "1110";
//    string s = "01001001101";       // 2
    //  1010100100
    //  010[01]101 01 ---
    // 0100110101   // 4


    LT1888 lt;

    cout<<lt.lt1888b(s)<<endl;

    return 0;
}
