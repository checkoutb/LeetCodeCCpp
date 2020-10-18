
#include "../header/myheader.h"

class LT1031
{
public:

// D D
//        for (int i = 1; i < A.size(); ++i)
//            A[i] += A[i - 1];
//        int res = A[L + M - 1], Lmax = A[L - 1], Mmax = A[M - 1];
//        for (int i = L + M; i < A.size(); ++i) {
//            Lmax = max(Lmax, A[i - M] - A[i - L - M]);
//            Mmax = max(Mmax, A[i - L] - A[i - L - M]);
//            res = max(res, max(Lmax + A[i] - A[i - M], Mmax + A[i] - A[i - L]));
//        }
//        return res;
// 现在以i为结束：  L最大值 + M现在，  M最大值 + L现在


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Sum of Two Non-Overlapping Subarrays.
//Memory Usage: 9 MB, less than 92.31% of C++ online submissions for Maximum Sum of Two Non-Overlapping Subarrays.
    int lt1031a(vector<int>& A, int L, int M)
    {
        vector<int> dpl(A.size(), 0);
        vector<int> dpr(A.size(), 0);
        int sum = 0;
        for (int i = 0; i < L; i++)
        {
            sum += A[i];
        }
        dpl[L - 1] = sum;
        for (int i = L; i < A.size(); i++)
        {
            sum += (A[i] - A[i - L]);
            dpl[i] = max(dpl[i - 1], sum);
        }
        sum = 0;
        for (int i = 0; i < L; i++)
        {
            sum += A[A.size() - 1 - i];
        }
        dpr[A.size() - L] = sum;
        for (int i = A.size() - 1 - L; i >= 0; i--)
        {
            sum += (A[i] - A[i + L]);
            dpr[i] = max(dpr[i + 1], sum);
        }
        int ans = 0;
        sum = 0;
        for (int i = 0; i < M; i++)
        {
            sum += A[i];
        }
        ans = sum + dpr[M];
        for (int i = M; i + 1 < A.size(); i++)
        {
            sum += (A[i] - A[i - M]);
            ans = max(ans, max(sum + dpl[i - M], sum + dpr[i + 1]));
        }
        sum += (A[A.size() - 1] - A[A.size() - 1 - M]);
        ans = max(ans, sum + dpl[A.size() - 1 - M]);
        return ans;
    }

};

int main()
{

//    vector<int> v = {0,6,5,2,2,5,1,9,4};
//    int l = 1, m = 2;

//    vector<int> v = {3,8,1,3,2,1,8,9,0};
//    int l = 3, m = 2;

    vector<int> v = {2,1,5,6,0,9,5,0,3,8};
    int l = 4, m = 3;

    LT1031 lt;

    cout<<lt.lt1031a(v,m,l);

    return 0;
}
