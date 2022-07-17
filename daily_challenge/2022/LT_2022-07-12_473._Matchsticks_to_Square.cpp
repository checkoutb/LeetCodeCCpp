
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //if (sum == len) return dfs(nums, k - 1, 0, 0);
    //for (int i = start; i < nums.size(); i++) {
    //    if (st[i]) continue;
    //    if (sum == 0 && nums[i] + sum > len) return false;
    //    if (nums[i] + sum <= len) {
    //        st[i] = true;
    //        if (dfs(nums, k, sum + nums[i], i + 1))
    //            return true;
    //        st[i] = false;
    //    }
    //    while (i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;

    //}


    //lets say sides are currently : [5, 7, 5, 9] , the next element is 3.
    //    Therefore we will be applying dfs on the following :
    //[5 + 3, 7, 5, 9]
    //[5, 7 + 3, 5, 9]
    //[5, 7, 5 + 3, 9]
    //[5, 7, 5, 9 + 3]

    //First and third are basically the same, only in a different order.If in the first case, dfs returned false, the third case will return false too.
    //    So we don't run dfs in third case.


//Runtime: 422 ms, faster than 47.17 % of C++ online submissions for Matchsticks to Square.
//Memory Usage : 10.1 MB, less than 66.64 % of C++ online submissions for Matchsticks to Square.
    // tle
    bool ltc(vector<int>& matchsticks)
    {
        int sum2 = std::accumulate(begin(matchsticks), end(matchsticks), 0);
        if (sum2 % 4)
            return false;
        sort(begin(matchsticks), end(matchsticks));
        int tar = sum2 / 4;
        return dfsc1(matchsticks, 0, 0, 0, 0, matchsticks.size() - 1, tar);
    }

    bool dfsc1(vector<int>& vi, int a, int b, int c, int d, int idx, int tar)
    {
        if (a > tar || b > tar || c > tar || d > tar)
            return false;
        if (idx == -1)
        {
            return a == tar && b == tar && c == tar && d == tar;
        }
        int t2 = vi[idx];

        if (dfsc1(vi, a + t2, b, c, d, idx - 1, tar))
            return true;
        if (dfsc1(vi, a, b + t2, c, d, idx - 1, tar))
            return true;
        if (dfsc1(vi, a, b, c + t2, d, idx - 1, tar))
            return true;
        if (dfsc1(vi, a, b, c, d + t2, idx - 1, tar))
            return true;
        return false;
    }


    // tle¡£¡£¡£
    bool ltb(vector<int>& matchsticks)
    {
        int sum2 = std::accumulate(begin(matchsticks), end(matchsticks), 0);
        if (sum2 % 4)
            return false;

        sort(begin(matchsticks), end(matchsticks));

        int tar = sum2 / 4;

        return dfsb1(matchsticks, tar, 0, matchsticks.size() - 1, 1);
    }

    bool dfsb1(vector<int>& vi, int tar, int got, int idx, int turn)
    {
        if (got >= tar)
            return turn == 4 ? (got == tar) : (dfsb1(vi, tar, 0, vi.size() - 1, turn + 1));

        for (int i = idx; i >= 0; --i)
        {
            if (vi[i] == -1)
                continue;

            int t2 = vi[i];
            vi[i] = -1;
            if (dfsb1(vi, tar, got + t2, i - 1, turn))
            {
                vi[i] = t2;
                return true;
            }
            vi[i] = t2;
        }
        return false;
    }

    // error
    bool lta(vector<int>& matchsticks)
    {
        int sum2 = std::accumulate(begin(matchsticks), end(matchsticks), 0);
        if (sum2 % 4)
            return false;

        sort(begin(matchsticks), end(matchsticks));
        int tar = sum2 / 4;

        for (int i = 0; i < 4; ++i)
        {
            for (int a = matchsticks.size() - 1; a >= 0; --a)
            {
                if (matchsticks[a] != -1)
                {
                    if (dfsa1(matchsticks, tar, 0, a))
                    {
                        matchsticks[a] = -1;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool dfsa1(vector<int>& vi, int tar, int got, int idx)
    {
        if (got == tar)
            return true;
        if (got > tar)
            return false;

        for (int i = idx; i >= 0; --i)
        {
            if (vi[i] == -1)
                continue;
            if (dfsa1(vi, tar, got + vi[i], i - 1))
            {
                vi[i] = -1;
                return true;
            }
        }
        return false;
    }

};

int main()
{

    LT lt;

    //myvi v = { 5,1,2,2,2 };
    myvi v = { 13,11,1,8,6,7,8,8,6,7,8,9,8 };

    cout << lt.ltc(v) << endl;

    return 0;
}
