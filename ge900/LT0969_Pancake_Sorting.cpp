
#include "../header/myheader.h"

class LT0969
{
public:


// D D

//        vector<int> res;
//        int x,i;
//        for (x = A.size(); x > 0; --x) {
//            for (i = 0; A[i] != x; ++i);              // 有;;;;;;;;;;;;;;;;;;...
//            reverse(A.begin(), A.begin() + i + 1);
//            res.push_back(i + 1);
//            reverse(A.begin(), A.begin() + x);
//            res.push_back(x);
//        }
//        return res;

// reverse..





//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pancake Sorting.
//Memory Usage: 11.1 MB, less than 88.70% of C++ online submissions for Pancake Sorting.
// 找剩下最大，flip，flip，再找剩下最大。..A是[1...A,length],记录下标，然后直接计算，而不是每次找最大，有点难
    vector<int> lt0969a(vector<int>& A)
    {
        int sz1 = A.size();
        int sz12 = A.size() * 2;
        vector<int> ans(sz12);
        int vi = 0;
        int t2 = 0;

        while (vi < sz12)
        {
            int mxi = 0;
            int mxn = A[0];
            for (int i = 1; i < sz1 - t2; i++)
            {
                if (mxn < A[i])
                {
                    mxn = A[i];
                    mxi = i;
                }
            }
            ans[vi++] = mxi + 1;
            ans[vi++] = sz1 - t2;
            t2++;

            int l = 0;
            int r = ans[vi - 2] - 1;
            while (l < r)
            {
                int t5 = A[l];
                A[l] = A[r];
                A[r] = t5;
                l++;
                r--;
            }

            l = 0;
            r = ans[vi - 1] - 1;
            while (l < r)
            {
                int t5 = A[l];
                A[l] = A[r];
                A[r] = t5;
                l++;
                r--;
            }

            #ifdef __test
            cout<<mxi + 1<<", "<<sz1 - t2<<" - "<<mxi<<", "<<mxn<<endl;
            #endif // __test
        }

        return ans;
    }

};

int main()
{

    vector<int> v = {3,2,4,1};

    LT0969 lt;

    vector<int> v2 = lt.lt0969a(v);

    for_each(begin(v2), end(v2), fun_cout);
    cout<<endl;
    for_each(begin(v), end(v), fun_cout); cout<<endl;

//    for (int i = 0; i < v2.size(); i++)
//    {
//        int t2 = v2[i];
//        int l = 0;
//        int r = t2 - 1;
//        while (l < r)
//        {
//            int t5 = v[l];
//            v[l] = v[r];
//            v[r] = t5;
//            l++;
//            r--;
//        }
//    }
//
//    cout<<" -  - - -- - "<<endl;
//    for_each(begin(v), end(v), fun_cout);
//    cout<<endl;


    return 0;
}
