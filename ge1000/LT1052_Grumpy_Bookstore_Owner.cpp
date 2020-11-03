
#include "../header/myheader.h"

class LT1052
{
public:

// D D

// 可以一次for循环， 最终是  X为0时的顾客和 + 最大的X的顾客和。
//    auto satisfied = 0, m_add_satisfied = 0, add_satisfied = 0;
//    for (auto i = 0; i < cs.size(); ++i) {
//        satisfied += grumpy[i] ? 0 : cs[i];
//        add_satisfied += grumpy[i] ? cs[i] : 0;
//        if (i >= X) add_satisfied -= grumpy[i - X] ? cs[i - X] : 0;
//        m_add_satisfied = max(m_add_satisfied, add_satisfied);
//    }
//    return satisfied + m_add_satisfied;


//Runtime: 60 ms, faster than 95.98% of C++ online submissions for Grumpy Bookstore Owner.
//Memory Usage: 32.2 MB, less than 15.24% of C++ online submissions for Grumpy Bookstore Owner.
    int lt1052a(vector<int>& customers, vector<int>& grumpy, int X)
    {
        int mxi = 0;
        int mxs = 0;
        int sum2 = 0;
        int i = 0;
        int sz1 = grumpy.size();
        for (; i < sz1 && i < X; i++)
        {
            if (grumpy[i])
            {
                sum2 += customers[i];
            }
        }
        mxs = sum2;
        mxi = 0;
        for (; i < sz1; i++)
        {
            sum2 += (grumpy[i] ? customers[i] : 0) - (grumpy[i - X] ? customers[i - X] : 0);
            if (sum2 > mxs)
            {
                mxs = sum2;
                mxi = i - X + 1;
            }
        }
        for (i = 0; i < X; i++)
        {
            grumpy[i + mxi] = 0;
        }
        int ans = 0;
        for (i = 0; i < sz1; i++)
        {
            ans += (grumpy[i] ? 0 : customers[i]);
        }
        return ans;
    }

};

int main()
{
    vector<int> cus = {1,0,1,2,1,1,7,5};
    vector<int> gru = {0,1,0,1,0,1,0,1};
    int x = 3;

    LT1052 lt;

    cout<<lt.lt1052a(cus, gru, x)<<endl;

    return 0;
}
