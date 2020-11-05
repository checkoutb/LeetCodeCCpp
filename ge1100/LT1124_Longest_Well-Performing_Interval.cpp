
#include "../header/myheader.h"

class LT1124
{
public:


// D D

//            score += hours[i] > 8 ? 1 : -1;
//            if (score > 0) {
//                res = i + 1;
//            } else {
//                if (seen.find(score) == seen.end())
//                    seen[score] = i;
//                if (seen.find(score - 1) != seen.end())
//                    res = max(res, i - seen[score - 1]);
//            }

// md，dp 还有这种形式的。
// 就是保存 每个score 的第一次出现， 然后每次 查看是否有 score-1 的 出现， 由于socre是+-1的， ，， 严格大于，且 最长， 所以 要么 从一开始就是，
// 要么从 第一个score-1 开始 到现在。



// cengjing,digui shi yishengzhidi, xianzai, dp shi yisheng zhidi. zhen tmd nan.
//Runtime: 1652 ms, faster than 5.44% of C++ online submissions for Longest Well-Performing Interval.
//Memory Usage: 22.2 MB, less than 5.16% of C++ online submissions for Longest Well-Performing Interval.
    int lt1124b(vector<int>& hours)
    {
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < hours.size(); i++)
        {
            if (hours[i] > 8)
                cnt++;
            else
                cnt--;
            hours[i] = cnt;
        }
        for (int i = 0; i < hours.size(); i++)
        {
            int hi = hours[i];
            if (hi > 0)
                ans = max(ans, i + 1);
            for (int j = i + ans; j < hours.size(); j++)
            {
                if (hours[j] > hi)
                {
                    ans = max(ans, j - i);
                }
            }
        }
        return ans;
    }


// tle
    int lt1124a(vector<int>& hours)
    {
        int ans = 0;
        for (int i = 0; i < hours.size(); i++)
        {
            int cnt = 0;
            for (int j = i; j < hours.size(); j++)
            {
                cnt += (hours[j] > 8 ? 1 : -1);
                if (cnt > 0)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }

};

int main()
{

//    vector<int> v = {9,9,6,0,6,6,9};
    vector<int> v = {6,6,9};

    LT1124 lt;

    cout<<lt.lt1124b(v)<<endl;

    return 0;
}
