
#include "../header/myheader.h"

class LT1109
{
public:

    // D D

    //vector<int> res(n);
    //for (auto& v : bookings) {
    //    res[v[0] - 1] += v[2];
    //    if (v[1] < n) res[v[1]] -= v[2];
    //}
    //for (auto i = 1; i < n; ++i) res[i] += res[i - 1];
    //return res;





//Runtime: 422 ms, faster than 24.87 % of C++ online submissions for Corporate Flight Bookings.
//Memory Usage : 67.8 MB, less than 73.58 % of C++ online submissions for Corporate Flight Bookings.
    vector<int> lt1109a(vector<vector<int>>& bookings, int n)
    {
        vector<int> vi(n);

        for (vector<int>& v : bookings)
        {
            vi[v[0] - 1] += v[2];
            if (v[1] != vi.size())
                vi[v[1]] -= v[2];
        }
        int t2 = 0;
        for (int i = 0; i < vi.size(); ++i)
        {
            t2 += vi[i];
            vi[i] = t2;
        }

        return vi;
    }

};

int main()
{

    LT1109 lt;

    //myvvi vv = { {1,2,10},{2,3,20},{2,5,25} };
    //int n = 5;

    myvvi vv = { {1,2,10},{2,2,15} };
    int n = 2;

    myvi v = lt.lt1109a(vv, n);

    showVectorInt(v);

    return 0;
}
