
#include "../header/myheader.h"

class LT0962
{
public:

// D
// stack
// res = max(res, i - s.top()), s.pop();


// 98 / 98 test cases passed, but took too long.
    int lt0962a(vector<int>& A) {
        int mn = INT_MAX;
//        int mni = 0;
//
//        int mx = -1;
//        int mxi = A.size() - 1;

        int ans = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] >= mn)
            {
                continue;
            }
            mn = A[i];
            for (int j = A.size() - 1; j > i; j--)
            {
                if (A[j] >= mn)
                {
                    ans = max(ans, j - i);
                }
            }
        }

        return ans;
    }

};

int main()
{

//    vector<int> a = {6,0,8,2,1,5};

    vector<int> a = {9,8,1,0,1,9,4,0,4,1};

    LT0962 lt;

    cout<<lt.lt0962a(a)<<endl;

    return 0;
}
