
#include "../header/myheader.h"

class LT1018
{
public:



//Runtime: 20 ms, faster than 73.53% of C++ online submissions for Binary Prefix Divisible By 5.
//Memory Usage: 14.2 MB, less than 100.00% of C++ online submissions for Binary Prefix Divisible By 5.
// 5,0
    vector<bool> lt1018a(vector<int>& A)
    {
        int t = 0;
        vector<bool> ans(A.size());
        for (int i = 0; i < A.size(); i++)
        {
            t *= 2;
            t += A[i];
            if (t % 5 == 0)
                ans[i] = true;
            t -= 5 * (t / 5);
        }

        return ans;
    }

};

int main()
{

    vector<int> v = {0,1,1,1,1,1};

    LT1018 lt;

    vector<bool> vb = lt.lt1018a(v);

    for (int i = 0; i < vb.size(); i++)
    {
        cout<<vb[i]<<", ";
    }

    return 0;
}
