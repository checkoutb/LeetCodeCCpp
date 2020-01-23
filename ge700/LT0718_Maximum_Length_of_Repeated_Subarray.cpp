
#include "../header/myheader.h"

class LT0718
{
public:


// discuss中基本都是dp
//dp[i][j] is the length of longest common subarray ending with nums[i-1] and nums[j-1]

// 也有一维数组dp的。


// details中 群魔乱舞。。




// 这里是j < sz2 - ans...
//Runtime: 420 ms, faster than 5.08% of C++ online submissions for Maximum Length of Repeated Subarray.
//Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Maximum Length of Repeated Subarray.
// 第一次tle， 加上 sz1 - ans 后过了。。。写这段话的时候才发现j < sz1 - ans。。。竟然过了。。
//Runtime: 920 ms, faster than 5.08% of C++ online submissions for Maximum Length of Repeated Subarray.
//Memory Usage: 8.7 MB, less than 100.00% of C++ online submissions for Maximum Length of Repeated Subarray.
    int lt0718a(vector<int>& A, vector<int>& B)
    {
        int sz1 = A.size();
        int sz2 = B.size();
        int ans = 0;
        for (int i = 0; i < sz1 - ans; i++)
        {
            int t1 = A[i];
            for (int j = 0; j < sz2 - ans; j++)
            {
                if (B[j] == t1)
                {
                    int maxlen = 1;
                    int k = 1;
                    int sz3 = min(sz1 - i, sz2 - j);
                    while (k < sz3 && B[j + k] == A[i + k])
                    {
                        k++;
                        maxlen++;
                    }
                    ans = max(ans, maxlen);
                }
            }
        }
        return ans;
    }

};

int main()
{

    vector<int> a = {1,2,3,2,1};
    vector<int> b = {3,2,1,5,6};

    LT0718 lt;

    cout<<lt.lt0718a(a, b)<<endl;

    return 0;
}
