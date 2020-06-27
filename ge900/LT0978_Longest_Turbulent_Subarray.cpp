
#include "../header/myheader.h"

class LT0978
{
public:


// D D
//  for (auto i = 0, cnt = 0; i + 1 < A.size(); ++i, cnt *= -1) {
//    if (A[i] > A[i + 1]) cnt = cnt > 0 ? cnt + 1 : 1;
//    else if (A[i] < A[i + 1])  cnt = cnt < 0 ? cnt - 1 : -1;
//    else cnt = 0;
//    res = max(res, abs(cnt));
//  }
//  return res + 1;

//        int inc = 1, dec = 1, result = 1;
//        for (int i = 1; i < A.length; i++) {
//            if (A[i] < A[i - 1]) {
//                dec = inc + 1;
//                inc = 1;
//            } else if (A[i] > A[i - 1]) {
//                inc = dec + 1;
//                dec = 1;
//            } else {
//                inc = 1;
//                dec = 1;
//            }
//            result = Math.max(result, Math.max(dec, inc));
//        }
//        return result;

//        int n = A.length, maxLen = 0;
//        int[][] state = new int[n][2];
//
//        for (int i = 1; i < n; i++) {
//            if (A[i - 1] < A[i]) {
//                state[i][0] = state[i - 1][1] + 1;
//                maxLen = Math.max(maxLen, state[i][0]);
//            } else if (A[i - 1] > A[i]) {
//                state[i][1] = state[i - 1][0] + 1;
//                maxLen = Math.max(maxLen, state[i][1]);
//            }
//        }

// i == i-1 不需要向后搜，不，我这种还必须向后搜。bool没有第三个状态。

//Runtime: 208 ms, faster than 23.76% of C++ online submissions for Longest Turbulent Subarray.
//Memory Usage: 40.2 MB, less than 89.37% of C++ online submissions for Longest Turbulent Subarray.
    int lt0978a(vector<int>& A)
    {
        if (A.size() < 2)
            return A.size();

        int ans = 1;
        int i = 1;
        int sz1 = A.size();
        bool isUp = false;
        while (i < sz1)
        {
            if (A[i] != A[i - 1])
            {
                isUp = A[i] > A[i - 1];
                break;
            }
            i++;
        }
        int t3 = 1;     // 此时i是 上面的循环的最后一个i值。这个i值也是下面的第一个元素，肯定会执行t3++，所以t3=1;
        for (; i < sz1; i++)
        {
            if (A[i] == A[i - 1])
            {
                ans = std::max(ans, t3);
                t3 = 1;

                while (i < sz1)
                {
                    if (A[i] != A[i - 1])
                    {
                        isUp = A[i] > A[i - 1];
                        i--;
                        break;
                    }
                    i++;
                }

                continue;
            }
            if (A[i] < A[i - 1])
            {
                if (isUp)
                {
                    ans = max(ans, t3);
                    t3 = 2;             // 此时已经有2个元素了 A[i], A[i - 1]。
                }
                else
                {
                    t3++;
                }
                isUp = true;
                continue;
            }
            else
            {
                if (isUp)
                {
                    t3++;
                }
                else
                {
                    ans = max(ans, t3);
                    t3 = 2;
                }
                isUp = false;
                continue;
            }
        }
        ans = max(ans, t3);
        return ans;
    }

};

int main()
{

    vector<int> v = {9,4,2,10,7,8,8,1,9};

//    vector<int> v = {4,8,12,16};

    LT0978 lt;

    cout<<lt.lt0978a(v)<<endl;

    return 0;
}
