
#include "../header/myheader.h"

class LT1534
{
public:

// D D

// and == &&



//Runtime: 16 ms, faster than 99.55% of C++ online submissions for Count Good Triplets.
//Memory Usage: 8.6 MB, less than 40.52% of C++ online submissions for Count Good Triplets.
    int lt1534a(vector<int>& arr, int a, int b, int c)
    {
        int ans = 0;
        int sz1 = arr.size();
        int t1 = 0;
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            t1 = arr[i];
            for (int j = i + 1; j < sz1; ++j)
            {
                t2 = arr[j];
                if (abs(t1 -  t2) > a)
                    continue;
                for (int k = j + 1; k < sz1; ++k)
                {
                    if (abs(t1 - arr[k]) <= c && abs(t2 - arr[k]) <= b)
                        ans++;
                }
            }
        }
        return ans;
    }

};

int main()
{
//    myvi v = {3,0,1,1,9,7};
//    int a{7},b{2},c{3};
    myvi v = {1,1,2,2,3};
    int a{0},b{0},c{1};

    LT1534 lt;

    cout<<lt.lt1534a(v,a,b,c);

    return 0;
}
