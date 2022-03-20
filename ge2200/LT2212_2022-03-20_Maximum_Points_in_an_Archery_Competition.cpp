
#include "../header/myheader.h"

class LT2212
{
public:

// D D






//Runtime: 521 ms, faster than 62.50% of C++ online submissions for Maximum Points in an Archery Competition.
//Memory Usage: 63.8 MB, less than 6.25% of C++ online submissions for Maximum Points in an Archery Competition.
    vector<int> lt2212b(int numArrows, vector<int>& aliceArrows)
    {
        vector<int> ans(12, 0);
        dfsb1(aliceArrows, numArrows, 0, 11, ans, vector<int>(12, 0));
        return ans;
    }

    void dfsb1(vector<int>& vi, int remain, int point, int idx, vector<int>& ans, vector<int> tmp)
    {
        if (remain == 0 || idx == 0)
        {
            if (idx == 0)
                tmp[0] = remain;
            int t2 = 0;
            for (int i = 1; i <= 11; ++i)
            {
                if (ans[i] > 0)
                    t2 += i;
            }
            if (point > t2)
            {
                ans = tmp;
            }
            return;
        }
        if (remain > vi[idx])
        {
            tmp[idx] = vi[idx] + 1;
            dfsb1(vi, remain - vi[idx] - 1, point + idx, idx - 1, ans, tmp);
            tmp[idx] = 0;
        }
        dfsb1(vi, remain, point, idx - 1, ans, tmp);
    }


// error
// 一共就12层，dfs下。
    vector<int> lt2212a(int numArrows, vector<int>& aliceArrows)
    {
        vector<int> ans(12, 0);
        int t2 = dfsa1(aliceArrows, numArrows, 0, 11, ans);
//        cout<<t2<<endl;
        return ans;
    }

    int dfsa1(vector<int>& vi, int remain, int point, int idx, vector<int>& ans)
    {
        if (idx == 0 || remain == 0)
        {
            if (idx == 0)
                ans[0] = remain;
            return point;
        }

        int t2 = 0;
        if (remain > vi[idx])
        {
            t2 = dfsa1(vi, remain - vi[idx] - 1, point + idx, idx - 1, ans);
        }
        int t3 = dfsa1(vi, remain, point, idx - 1, ans);
        if (t2 > t3)
        {
            ans[idx] = vi[idx] + 1;
        }
        else
        {
            ans[idx] = 0;
        }
        return t2;
    }

};

int main()
{

    LT2212 lt;

    int n = 9;
    myvi v = {1,1,0,1,0,0,2,1,0,1,2,0};

    myvi v2 = lt.lt2212b(n, v);

    showVectorInt(v2);

    return 0;
}
