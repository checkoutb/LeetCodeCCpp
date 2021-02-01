
#include "../header/myheader.h"

class LT0072
{
public:


// D D





//Runtime: 12 ms, faster than 71.23% of C++ online submissions for Edit Distance.
//Memory Usage: 9 MB, less than 45.39% of C++ online submissions for Edit Distance.

// after discuss...

    int lt0072c(string word1, string word2)
    {
        int sz1 = word1.size();
        int sz2 = word2.size();
        vector<vector<int>> vvi(sz1 + 1, vector<int>(sz2 + 1, 0));
        for (int i = 1; i <= sz1; ++i)
        {
            vvi[i][0] = i;
        }
        for (int j = 1; j <= sz2; ++j)
            vvi[0][j] = j;

        for (int i = 1; i <= sz1; ++i)
        {
            for (int j = 1; j <= sz2; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    vvi[i][j] = vvi[i - 1][j - 1];
                }
                else
                {
                    // delete , replace, insert
                    vvi[i][j] = min(vvi[i - 1][j], min(vvi[i - 1][j - 1], vvi[i][j - 1])) + 1;
                }
            }
        }
        return vvi[sz1][sz2];
    }



// error
    int lt0072b(string word1, string word2)
    {
        int sz1 = word1.size();
        int sz2 = word2.size();
        vector<vector<int>> vvi(sz1, vector<int>(sz2, 0));
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (word1[i] == word2[j])
                {
                    vvi[i][j] = vvi[i - 1][j - 1];
                }
                else
                {
//                    vvi[i][j] = vvi[i - 1][j - 1] + 1;      // delete,
                    vvi[i][j] = min(vvi[i - 1][j], min(vvi[i - 1][j - 1], vvi[i][j - 1])) + 1;
                }
            }
        }
        return vvi[sz1 - 1][sz2 - 1];
    }



// add     if (ops >= ans) return;       28 / 1146 test cases passed.  tle
// 24 / 1146 test cases passed.    tle
// 每个char in word2, 包含 或者 不包含。 不， 对每个xx， insert / delete / replace
// [i,j] 中最长相同序列。
    int lt0072a(string word1, string word2)
    {
        dfsa1(word1, word2, 0, 0, 0);
        return ans;
    }
    int ans = INT_MAX;
    void dfsa1(string& s1, string& s2, int i1, int i2, int ops)
    {
        if (i1 == s1.size())
        {
            ops += s2.size() - i2;
            ans = min(ans, ops);
            return;
        }
        if (i2 == s2.size())
        {
            ops += s1.size() - i1;
            ans = min(ans, ops);
            return;
        }

        if (ops >= ans)
            return;

        if (s1[i1] == s2[i2])
        {
            dfsa1(s1, s2, i1 + 1, i2 + 1, ops);
        }
        else
        {
            ops++;
            dfsa1(s1, s2, i1, i2 + 1, ops);     // delete i2
            dfsa1(s1, s2, i1 + 1, i2 + 1, ops);     // replace
            dfsa1(s1, s2, i1 + 1, i2, ops);     // insert
        }
    }

};

int main()
{

    string s1{"horse"}, s2{"ros"};
//    string s1{"intention"}, s2{"execution"};
//    string s1{"aaaa"}, s2{"c"};

    LT0072 lt;

    cout<<lt.lt0072c(s1, s2)<<endl;

    return 0;
}
