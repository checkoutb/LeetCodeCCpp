
#include "../header/myheader.h"

class LT2998
{
public:

    // D

// When x > y, we have 4 options.
//
//     plus then divide 5
//     minus then divide 5
//     plus then divide 11
//     minus then divide 11


    // g

    // 749,361 -> 213 ...

    int minimumOperationsToMakeEqual(int x, int y)
    {
        if (x <= y)
            return y - x;

        vector<int> vi(x + 12, INT_MAX);
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> priq;    // <step, value>
        priq.push(std::make_pair(0, x));

        while (!priq.empty())
        {
            auto [cnt, t2] = priq.top();
            priq.pop();

#ifdef __test
            cout<<cnt<<", "<<t2<<endl;
#endif

            if (t2 == y)
                return cnt;

            if (t2 % 11 == 0)
            {
                if (vi[t2 / 11] > cnt + 1)
                {
                    vi[t2 / 11] = cnt + 1;
                    priq.push(make_pair(cnt + 1, t2 / 11));
                }
            }
            if (t2 % 5 == 0)
            {
                if (vi[t2 / 5] > cnt + 1)
                {
                    vi[t2 / 5] = cnt + 1;
                    priq.push(std::make_pair(cnt + 1, t2 / 5));
                }
            }
            if (t2 >= 2 && vi[t2 - 1] > cnt + 1)
            {
                vi[t2 - 1] = cnt + 1;
                priq.push(std::make_pair(cnt + 1, t2 - 1));
            }

            if (t2 <= x)
            {
                int mxi = max((t2 / 11 + (t2 % 11 == 0 ? 0 : 1)) * 11, (t2 / 5 + (t2 % 5 == 0 ? 0 : 1)) * 5);
                t2 += 1;
                cnt += 1;
                while (t2 <= mxi)
                {
                    if (vi[t2] > cnt)
                    {
                        vi[t2] = cnt;
                        priq.push(make_pair(cnt, t2));
                    }
                    ++t2;
                    ++cnt;
                }
            }
        }
        return -1;
    }


    // 18,1 -> 5;   18-15-3-1:6   18-20-4-1:6  18-22-2-1:6   18-20-4-5-1:5
    // 5,2 -> 2 ;   5->1->2
    // example 2
    int minimumOperationsToMakeEqual_error(int x, int y)
    {
        if (x <= y)
            return y - x;

        vector<int> vi(x + 12, INT_MAX);
        vi[x] = 0;
        for (int i = x + 1; i < vi.size(); ++i)
            vi[i] = vi[i - 1] + 1;

        for (int i = vi.size() - 1; i > y; --i)
        {
            if (i % 11 == 0)
            {
                vi[i / 11] = min(vi[i / 11], vi[i] + 1);
            }
            if (i % 5 == 0)
            {
                vi[i / 5] = min(vi[i / 5], vi[i] + 1);
            }
            vi[i - 1] = min(vi[i - 1], vi[i] + 1);
        }
        // return vi[y];
        int ans = vi[y];

        for (int i = 1; i < y; ++i)
        {
            if (vi[i] != INT_MAX)
            {
                ans = min(ans, vi[i] + (y - i));
            }
        }
        return ans;
    }

};

int main()
{

    LT2998 lt;
    // int a{18}, b{1};
    int a{9}, b{4};

    cout<<lt.minimumOperationsToMakeEqual(a, b)<<endl;

    return 0;
}
