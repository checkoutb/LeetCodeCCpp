
#include "../header/myheader.h"

class LT1093
{
public:

// D D




//Runtime: 8 ms, faster than 43.30% of C++ online submissions for Statistics from a Large Sample.
//Memory Usage: 8.5 MB, less than 49.48% of C++ online submissions for Statistics from a Large Sample.
//minimum, maximum, mean, median, and mode of the sample respectively,
// 平均，中位数，   mode？ 是指个数最多？
    vector<double> lt1093a(vector<int>& count)
    {
//        int totalCnt = std::accumulate(begin(count), end(count), 0);
        int totalCnt = 0;
        int mxCnt = 0;
        int sz1 = count.size();
        int mod = 0;
        long sum2 = 0;
        int mn = -1;
        int mx = 0;
        double med = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (count[i] == 0)
                continue;
            totalCnt += count[i];
            if (count[i] > mxCnt)
            {
                mxCnt = count[i];
                mod = i;
            }
            sum2 += i * count[i];
            if (mn == -1)
                mn = i;
            mx = i;
        }
        if (totalCnt % 2 == 0)
        {
            int t2 = totalCnt / 2 - 1;
            int i = 0;
            while (t2 > 0)
            {
                t2 -= count[i];
                med = i++;
            }
            if (t2 == -1)
            {
                for (; i < sz1; i++)
                {
                    if (count[i] != 0)
                    {
                        med = (med + i) / 2;
                        break;
                    }
                }
            }
        }
        else
        {
            int t2 = totalCnt / 2;
            int i = 0;
            while (t2 > 0)
            {
                t2 -= count[i];
                med = i++;
            }
        }
//        int t2 = totalCnt / 2;
//        int i = 0;
//        while (t2 > 0)
//        {
//            med = i++;
//            t2 -= count[i];
//        }
        return {double(mn),double(mx),double (sum2) / totalCnt,med,double(mod)};
    }

};

int main()
{
    myvi v = {0,1,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0};
//    myvi v = {0,4,3,2,2,0,0,0,0,0,0};

    LT1093 lt;

    vector<double> vd = lt.lt1093a(v);
    for (double d : vd)
        cout<<d<<", ";

    return 0;
}
