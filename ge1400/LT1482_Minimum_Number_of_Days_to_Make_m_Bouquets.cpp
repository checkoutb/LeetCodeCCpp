
#include "../header/myheader.h"

class LT1482
{
public:


//int n = A.size(), left = 1, right = 1e9;



// ....
//Runtime: 936 ms, faster than 5.44% of C++ online submissions for Minimum Number of Days to Make m Bouquets.
//Memory Usage: 110.9 MB, less than 10.87% of C++ online submissions for Minimum Number of Days to Make m Bouquets.
// error .. ++..
    int lt1482a(vector<int>& bloomDay, int m, int k)
    {
        int sz1 = bloomDay.size();
        if (sz1 < m * k)
            return -1;
        set<int> set2(begin(bloomDay), end(bloomDay));
        vector<int> vd(begin(set2), end(set2));
        int st = 0;
        int en = vd.size() - 1;
        int flag = false;
        if (st == en)
            return vd[0];
        while (st < en)
        {
            int mid = (st + en) / 2;
            int day = vd[mid];
            int conti = 0;
            int cnt = 0;
            for (int i = 0; i < sz1; ++i)
            {
                if (bloomDay[i] <= day)
                {
                    conti++;
                }
                else
                {
                    conti = 0;
                }
                if (conti == k)
                {
                    cnt++;
                    conti = 0;
                }
            }
            if (cnt >= m)
                en = mid;
            else if (cnt < m)
                st = mid + 1;
        }
        return vd[en];
    }

};

int main()
{

//    vector<int> v = {1,10,3,10,2};
//    int m{3}, k{1};

//    vector<int> v = {1,10,3,10,2};
//    int m{3}, k{2};

//    vector<int> v = {7,7,7,7,12,7,7};
//    int m{2}, k{3};

//    vector<int> v = {10000000, 10000000};
//    int m{1}, k{1};

    vector<int> v = {1,10,2,9,3,8,4,7,5,6};
    int m{4}, k{2};

    LT1482 lt;

    cout<<lt.lt1482a(v, m, k);

    return 0;
}
