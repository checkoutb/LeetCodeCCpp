
#include "../header/myheader.h"

class LT1701
{
public:

// D D






//Runtime: 192 ms, faster than 97.40% of C++ online submissions for Average Waiting Time.
//Memory Usage: 72.9 MB, less than 86.98% of C++ online submissions for Average Waiting Time.
    double lt1701a(vector<vector<int>>& customers)
    {
        int sz1 = customers.size();
        long t2 = 0;
        long total = 0;
        for (int i = 0; i < sz1; ++i)
        {
            t2 = max(t2, (long) customers[i][0]);
            t2 += customers[i][1];
            total += (t2 - customers[i][0]);
        }
        return 1.0 * total / sz1;
    }


};

int main()
{

//    myvvi vv = {{1,2},{2,5},{4,3}};
    myvvi vv = {{5,2},{5,4},{10,3},{20,1}};

    LT1701 lt;

    cout<<lt.lt1701a(vv)<<endl;

    return 0;
}
