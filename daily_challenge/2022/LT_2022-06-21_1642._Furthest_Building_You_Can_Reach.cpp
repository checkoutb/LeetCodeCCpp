
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    // 最大堆，保存 -t2.


//Runtime: 235 ms, faster than 11.55 % of C++ online submissions for Furthest Building You Can Reach.
//Memory Usage : 53.8 MB, less than 42.34 % of C++ online submissions for Furthest Building You Can Reach.
    // ...related topics : Priority Queue...
    // 把 pri_q 中的 作为是 ladder。 如果size > ladder， 最小值pop，用砖头
    int ltb(vector<int>& heights, int bricks, int ladders)
    {
        priority_queue<int, vector<int>, greater<int>> priq;
        for (int i = 1; i < heights.size(); ++i)
        {
            if (heights[i] > heights[i - 1])
            {
                int t2 = heights[i] - heights[i - 1];
                priq.push(t2);
                if (priq.size() > ladders)
                {
                    int t3 = priq.top();
                    priq.pop();
                    if (t3 > bricks)
                    {
                        return i - 1;
                    }
                    else
                    {
                        bricks -= t3;
                    }
                }
            }
        }
        return heights.size() - 1;
    }


    // tle。。。
    // 差距最大的 用梯子。
    // 最小的用砖头。
    // 二分..不。 需要记录的数据太多。
    int lta(vector<int>& heights, int bricks, int ladders)
    {
        multiset<int> mset2;
        for (int i = 1; i < heights.size(); ++i)
        {
            if (heights[i] > heights[i - 1])
            {
                int t2 = heights[i] - heights[i - 1];
                mset2.insert(t2);

                if (mset2.size() <= ladders)
                {
                    ;
                }
                else
                {
                    //multiset<int>::iterator iten = begin(mset2) + (mset2.size() - ladders);
                    //int sum2 = std::accumulate(begin(mset2), iten, 0);
                    //int sum2 = 0;
                    //for (multiset<int>::iterator it = begin(mset2); it != begin(mset2) + (mset2.size() - ladders); it++)
                    //{
                    //    sum2 += *it;
                    //}
                    multiset<int>::iterator it = begin(mset2);
                    int sum2 = 0;
                    for (int i = 0, mxi = mset2.size() - ladders; i < mxi; ++i)
                    {
                        sum2 += *it;
                        it++;
                    }
                    if (sum2 > bricks)
                    {
                        return i - 1;
                    }
                }

            }
        }
        return heights.size() - 1;
    }

};

int main()
{

    LT lt;

    //myvi v = { 4,2,7,6,9,14,12 };
    //int b = 5;
    //int l = 1;

    //myvi v = { 4,12,2,7,3,18,20,3,19 };
    //int b = 10;
    //int l = 2;

    myvi v = { 14,3,19,3 };
    int b = 17;
    int l = 0;

    cout << lt.ltb(v, b, l) << endl;

    return 0;
}
