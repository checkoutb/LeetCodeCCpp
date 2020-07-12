
#include "../header/myheader.h"

class LT0918
{
public:

// D
//....去找了下53题。。beats 1.45%....

// gg。。。 保持最大，最小， 如果最大>0，则取最大 or (全部-最小) : 最大。




//    int lt0918c(vector<int>& A)
//    {
//        int t2 = A[0];
//        int sza = A.size();
//        for (int i = 0; i < sza; i++)
//        {
//
//        }
//    }


// tle.........
// 合并。正负数。因为肯定要么全取，要么全不取。除了 全负数。
    int lt0918b(vector<int>& A)
    {
        int ans = A[0];
        vector<int> v2;
        int sza = A.size();
        int sum = A[0];
        for (int i = 1; i < sza; i++)
        {
            ans = max(A[i], ans);
            if ((A[i] ^ A[i-1]) < 0)            // 优先级。。
            {
                v2.push_back(sum);
                sum = A[i];
            }
            else
            {
                sum += A[i];
            }
        }
        v2.push_back(sum);

        #ifdef __test
        for_each(begin(v2), end(v2), fun_cout); cout<<endl;
        #endif // __test
        for (int i = 0; i < v2.size(); i++)
        {
            if (v2[i] <= 0)
            {
                continue;
            }
            else
            {
                sum = v2[i];
                ans = max(ans, sum);
                for (int j = (i + 1) % v2.size(); j != i; j = (j + 1 ) % v2.size())
                {
                    sum += v2[j];
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }


// tle
    int lt0918a(vector<int>& A)
    {
        int ans = A[0];
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] <= 0)
            {
                ans = max(ans, A[i]);
                continue;
            }
            else
            {
                int sum = A[i];
                ans = max(ans, sum);
                for (int j = (i + 1) % A.size(); j != i; j = (j + 1) % A.size())
                {
                    sum += A[j];
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }

};

int main()
{

//    vector<int> v = {3,-1,2,-1};
    vector<int> v = {-7,1,2,7,-2,-5};

    LT0918 lt;

    cout<<lt.lt0918b(v)<<endl;

    return 0;
}
