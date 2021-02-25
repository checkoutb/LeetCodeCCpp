
#include "../header/myheader.h"

class LT0691
{
public:

// D

// bfs, dp, dfs+memo



// 21 / 100  tle.
// The time limit may be more challenging than usual. ,, 那么dfs 估计会tle吧。
// 而且不同语言，不太可能差不多吧？  35ms/50 test case
// 先试下。
// 应该先剔除一些stickers，比如  an, and, 这种，直接剔除 an 。 但。。。
// 还有一些，和 target 没有交集的。
// 和target 的交集 char 的个数。 然后剔除 an and
    int lt0691a(vector<string>& stickers, string target)
    {
        vector<int> tar(26);
        for (char ch : target)
            tar[ch - 'a']++;
        vector<vector<int>> vvi;
        vector<bool> exist(26);
        for (string& s : stickers)
        {
            vector<int> vi(26);
            bool overlap = false;
            for (char ch : s)
            {
                if (tar[ch - 'a'] > 0)
                {
                    overlap = true;
                    vi[ch - 'a']++;
                    exist[ch - 'a'] = true;
                }
            }
            if (overlap)
            {
                vvi.push_back(std::move(vi));       // right?
            }
        }
        for (int i = 0; i < 26; ++i)
        {
            if (tar[i] > 0 && (exist[i] == false))
                return -1;
        }
        dfsa1(vvi, tar, 0);
        return ans;
    }
    int ans = INT_MAX;
    void dfsa1(vector<vector<int>>& vvi, vector<int>& tar, int cnt)
    {
//        bool all0 = true;
//        for (int i : tar)
//        {
//            if (i > 0)
//            {
//                all0 = false;
//            }
//        }

        for (int i : tar)
            if (i > 0)
                goto AAA;

        ans = min(ans, cnt);
        return;

        AAA:
        for (int i = 0; i < vvi.size(); ++i)
        {
            for (int j = 0; j < vvi[i].size(); ++j)
            {
                if (tar[j] > 0 && (vvi[i][j] != 0))
                {
                    for (int k = 0; k < 26; ++k)
                    {
                        tar[k] -= vvi[i][k];
                    }
                    dfsa1(vvi, tar, cnt + 1);
                    for (int k = 0; k < 26; ++k)
                    {
                        tar[k] += vvi[i][k];
                    }
                }
            }
        }

    }

};

int main()
{
//    vector<string> vs = {"with", "example", "science"};
//    string tar = "thehat";

    vector<string> vs = {"dad","rose","pay","else","condition","were","east","nor"};
    string tar = "easesoldier";


    LT0691 lt;

    cout<<lt.lt0691a(vs, tar);

    return 0;
}
