
#include "../header/myheader.h"

class LT0845
{
public:

// D
//        for (int i = 1; i < A.size(); ++i) {
//            if (down && A[i - 1] < A[i] || A[i - 1] == A[i]) up = down = 0;
//            up += A[i - 1] < A[i];
//            down += A[i - 1] > A[i];
//            if (up && down) res = max(res, up + down + 1);
//        }
// 当 不再下降的时候，就知道山多长了。


//Runtime: 44 ms, faster than 46.43% of C++ online submissions for Longest Mountain in Array.
//Memory Usage: 18.6 MB, less than 41.75% of C++ online submissions for Longest Mountain in Array.
    int lt0845a(vector<int>& A)
    {
        int sz1 = A.size();
        int arr1[A.size()];
        memset(arr1, 0, sizeof arr1);
        int arr2[A.size()];
        memset(arr2, 0, sizeof arr2);

        int ans = 0;

        for (int i = 1; i < sz1; i++)
        {
            if (A[i] > A[i - 1])
                arr1[i] = arr1[i - 1] + 1;
        }
        for (int i = sz1 - 2; i > 0; i--)
        {
            if (A[i] > A[i + 1])
                arr2[i] = arr2[i + 1] + 1;
        }

        for (int i = 0; i < sz1; i++)
        {
            if (arr1[i] != 0 && arr2[i] != 0)
             ans = std::max(ans, arr1[i] + arr2[i] + 1);
        }

        return ans;
    }

};

int main()
{

    vector<int> a = {2,1,4,7,3,2,5};

    LT0845 lt;

    cout<<lt.lt0845a(a)<<endl;

    return 0;
}
