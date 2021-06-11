
#include "../../header/myheader.h"

class LT
{
public:

// D D

//public boolean dfs(char[] c1, char[] c2, char[] c3, int i, int j, int k, boolean[][] invalid) {
//	if(invalid[i][j]) return false;
//	if(k == c3.length) return true;
//	boolean valid =
//	    i < c1.length && c1[i] == c3[k] && dfs(c1, c2, c3, i + 1, j, k + 1, invalid) ||
//        j < c2.length && c2[j] == c3[k] && dfs(c1, c2, c3, i, j + 1, k + 1, invalid);
//	if(!valid) invalid[i][j] = true;
//    return valid;
//}
// memo


//        for (int i = 0; i <= s1.length(); i++) {
//            for (int j = 0; j <= s2.length(); j++) {
//                if (i == 0 && j == 0) {
//                    dp[i][j] = true;
//                } else if (i == 0) {
//                    dp[i][j] = dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1);
//                } else if (j == 0) {
//                    dp[i][j] = dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1);
//                } else {
//                    dp[i][j] = (dp[i - 1][j] && s1.charAt(i - 1) == s3.charAt(i + j - 1)) || (dp[i][j - 1] && s2.charAt(j - 1) == s3.charAt(i + j - 1));
//                }
//            }
//        }



// AC       4ms
//Could you solve it using only O(s2.length) additional memory space?
// tle，那就只有dp了， 而且上面说 O(s2.length)， 估计是 arr[s1.size][s2.size] dp的
// 因为 知道s1的下标，s2的下标， 2个相加，就是 s3的下标了。
// dp的二维数组转 一维数组，确实是可以的， 最多再加一个一维数组。
    bool ltc(string s1, string s2, string s3)
    {
        int sz1 = s1.size();
        int sz2 = s2.size();
        int sz3 = s3.size();
        if ((sz1 + sz2) != sz3)
            return false;

        int arr[123] = {0};
        for (char ch : s1)
            arr[ch]++;
        for (char ch : s2)
            arr[ch]++;
        for (char ch : s3)
            arr[ch]--;

        for (int i = 'a'; i <= 'z'; ++i)
            if (arr[i] != 0)
                return false;
//        vector<vector<int>> vvi(sz1, vector<int>())
        vector<vector<bool>> vvb(sz1 + 1, vector<bool>(sz2 + 1, false));
        vvb[0][0] = true;       // "" + "" == ""
        for (int i = 0; i <= sz1; ++i)
        {
            for (int j = 0; j <= sz2; ++j)
            {
                if (i > 0)
                {
                    if (vvb[i - 1][j])
                    {
                        if (s1[i - 1] == s3[i + j - 1])
                        {
                            vvb[i][j] = true;
                        }
                    }
                }
                if (j > 0)
                {
                    if (vvb[i][j - 1])
                    {
                        if (s2[j - 1] == s3[i + j - 1])
                        {
                            vvb[i][j] = true;
                        }
                    }
//                    else      // 会导致错误
//                    {
//                        break;
//                    }
                }
            }
        }
        #ifdef __test
        for (vector<bool>& vb : vvb)
        {
            for (bool b : vb)
                cout<<b<<", ";
            cout<<endl;
        }
        #endif // __test
        return vvb[sz1][sz2];
    }


// 还是先做一个过滤？  tle
// 估计java的代码现在也是超时的。。
//06/03/2021 09:07	Time Limit Exceeded	N/A	N/A	cpp
//06/27/2018 16:55	Accepted	849 ms	N/A	java
// 这道是 第97题。。
// tle....
    // brute-force   dfs   tle?
    // 空间复杂度 是 O(1) 吧， 方法调用的栈空间不算的话。
    bool ltb(string s1, string s2, string s3)
    {
        int i1{0}, i2{0}, i3{0};
        int sz1 = s1.size();
        int sz2 = s2.size();
        int sz3 = s3.size();
        if ((sz1 + sz2) != sz3)
            return false;

        int arr[123] = {0};
        for (char ch : s1)
            arr[ch]++;
        for (char ch : s2)
            arr[ch]++;
        for (char ch : s3)
            arr[ch]--;

        for (int i = 'a'; i <= 'z'; ++i)
            if (arr[i] != 0)
                return false;

        return dfsb(s1, s2, s3, i1, i2, i3);
    }

    bool dfsb(string& s1, string& s2, string& s3, int i1, int i2, int i3)
    {
        if (i3 == s3.size())
        {
            return true;
        }
        if (s1[i1] == s3[i3])
        {
            if (dfsb(s1, s2, s3, i1 + 1, i2, i3 + 1))
                return true;
        }
        if (s2[i2] == s3[i3])
        {
            if (dfsb(s1, s2, s3, i1, i2 + 1, i3 + 1))
                return true;
        }
        return false;
    }



// greedy?  ... no
    bool lta(string s1, string s2, string s3)
    {
        int i1, i2, i3;
        int sz1 = s1.size();
        int sz2 = s2.size();
        int sz3 = s3.size();
        if ((sz1 + sz2) != sz3)
            return false;

        while (i3 < sz3)
        {
            if (s1[i1] == s3[i3])
            {
                i1++;
            }
            else if (s2[i2] == s3[i3])
            {
                i2++;
            }
            else
            {
                cout<<i1<<", "<<i2<<", "<<i3<<endl;
                return false;
            }

            i3++;
        }
        return true;
    }

};

int main()
{
//    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
//    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
//    string s1 = "", s2 = "", s3 = "";
    string s1 = "", s2 = "", s3 = "a";

    LT lt;

    cout<<lt.ltc(s1, s2, s3)<<endl;

    return 0;
}
