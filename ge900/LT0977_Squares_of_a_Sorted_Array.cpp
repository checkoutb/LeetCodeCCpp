
#include "../header/myheader.h"

class LT0977
{
public:


// D D
// foreach { A[i] = A[i] * A[i] }. then l=0, r=sz1, while (l < r) { .. }. reverse.

// while (l < r) { if (A[l]^2 < A[i]^2) {ans[vi--] = } else {ans[vi--] = } }


//        int n = A.length;
//        int[] result = new int[n];
//        int i = 0, j = n - 1;
//        for (int p = n - 1; p >= 0; p--) {
//            if (Math.abs(A[i]) > Math.abs(A[j])) {
//                result[p] = A[i] * A[i];
//                i++;
//            } else {
//                result[p] = A[j] * A[j];
//                j--;
//            }
//        }

//  vector<int> res(A.size());
//  for (int pn = 0, pp = A.size() - 1, pos = A.size() - 1; pn <= pp; --pos)
//    res[pos] = pow(abs(A[pn]) < abs(A[pp]) ? A[pp--] : A[pn++], 2);
//  return res;


//Runtime: 56 ms, faster than 91.83% of C++ online submissions for Squares of a Sorted Array.
//Memory Usage: 25.8 MB, less than 69.81% of C++ online submissions for Squares of a Sorted Array.
    vector<int> lt0977a(vector<int>& A)
    {
        int sz1 = A.size();
        vector<int> ans(sz1, 0);
        int i0 = -1;
        while (++i0 < sz1)
        {
            if (A[i0] >= 0)
            {
                break;
            }
        }
        int l = i0 - 1;
        int r = i0;
        int vi = 0;

        while (l >= 0 && r < sz1)
        {
            if (-A[l] < A[r])
            {
                ans[vi++] = A[l] * A[l];
                l--;
            }
            else
            {
                ans[vi++] = A[r] * A[r];
                r++;
            }
        }
        while (l >= 0)
        {
            ans[vi++] = A[l] * A[l];
            l--;
        }
        while (r < sz1)
        {
            ans[vi++] = A[r] * A[r];
            r++;
        }

        return ans;
    }

};

int main()
{

//    vector<int> v = {-4,-1,0,3,10};
    vector<int> v = {-7,-3,2,3,11};

    LT0977 lt;

    vector<int> v2 = lt.lt0977a(v);
    cout<<endl;
    for_each(begin(v2), end(v2), fun_cout);
    cout<<endl;

    return 0;
}
