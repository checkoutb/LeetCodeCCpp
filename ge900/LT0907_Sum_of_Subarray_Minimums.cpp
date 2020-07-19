
#include "../header/myheader.h"

class LT0907
{
public:


// D
// stack


// 91/100 tle
    int lt0907a(vector<int>& A)
    {
        int ans = 0;
        int e97 = 1E9 + 7;
        int mn = 0;
        int cnt = 0;
        for (int i = 0; i < A.size(); i++)
        {
            mn = A[i];
            cnt = 1;
            for (int j = i + 1; j < A.size(); j++)
            {
                if (A[j] >= mn)
                {
                    cnt++;
                }
                else
                {
                    ans = (ans + (mn * cnt) % e97) %e97;
                    mn = A[j];
                    cnt = 1;
                }
            }
            ans = (ans + (mn * cnt) % e97) %e97;
        }

        return ans;
    }

};

int main()
{

    vector<int> a = {3,1,2,4};

    LT0907 lt;

    cout<<lt.lt0907a(a)<<endl;

    return 0;
}
