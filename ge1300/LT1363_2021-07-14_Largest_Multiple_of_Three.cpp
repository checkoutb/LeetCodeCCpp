
#include "../header/myheader.h"

class LT1363
{
public:

// D

// 。。。 可惜了。。
// 全部累加，如果能被3整除，那就是结果， 不能整除，就尝试减去一个数， 然后尝试减去2个数。。。。
// 没有继续下去。。。

//int m1[] = {1, 4, 7, 2, 5, 8}, m2[] = {2, 5, 8, 1, 4, 7};
// 减去的数字，只减去一个。然后继续看 %3==0


//Calculate the sum of digits total = sum(A)
//If total % 3 == 0, we got it directly
//If total % 3 == 1 and we have one of 1,4,7 in A:
//we try to remove one digit of 1,4,7
//If total % 3 == 2 and we have one of 2,5,8 in A:
//we try to remove one digit of 2,5,8
//If total % 3 == 2:
//we try to remove two digits of 1,4,7
//If total % 3 == 1:
//we try to remove two digits of 2,5,8
//Submit



//    def largestMultipleOfThree(self, digits):
//        dp = [-1,-1,-1]
//        for a in sorted(digits)[::-1]:
//            for x in dp[:] + [0]:
//                y = x * 10 + a
//                dp[y % 3] = max(dp[y % 3], y)
//        return str(dp[0]) if dp[0] >= 0 else ""
// dp



// gg

// hint: dp
    string lt1363b(vector<int>& digits)
    {
        vector<int> arr(10, 0);
        for (int i : digits)
            arr[i]++;
        int n3 = arr[3];
        int n6 = arr[6];
        int n9 = arr[9];
        int n0 = arr[0];
        arr[0] = arr[3] = arr[6] = arr[9] = 0;
//        vector<vector<int>> vvi()     // ...zenme dp...
        vector<vector<vector<int>>> vvvi()      // 个数，余数，某一种排列。
    }



// error  2,2,1,1,1 .. 所有的数字都至少保存 9个？就是 9个1 可以配合3个2,3个5,3个8.。。不，
// 越大的数字保存的越少。 8,最多保存2个，   11888.。    8+4
// 全部累加，如果能被3整除，那就是结果， 不能整除，就尝试减去一个数， 然后尝试减去2个数。。。。

// dfs, 取或不取， 降序排列， 但是  2^(10^4) 。。。
// dp,
// 先把0踢了， 只要有3的倍数，后面加0 就是了。
// 。。 3也踢了。。    只要每位加起来能被3整除，那么这个数字就能被3整除。
// 。。那就可以了。  1+2 也一起踢， 6,9也踢。
// 多个数字的时候，应该先踢大的？   111 222 777 。。。   个数是3的倍数的 也能直接踢。。。 这样的话剩下的数量就很少了， 一个dfs。
// 2,2,1,1,1 .....
    string lt1363a(vector<int>& digits)
    {
//        int arr[10] = {0};
//        int ans[10] = {0};
        vector<int> arr(10, 0);
        vector<int> ans(10, 0);
        for (int i = 0; i < digits.size(); ++i)
        {
            arr[digits[i]]++;
        }
        ans[0] = arr[0];
        arr[0] = 0;
        for (int i = 1; i < 10; ++i)
        {
            if (i % 3 == 0)
            {
                ans[i] = arr[i];
                arr[i] = 0;
            }
            else
            {
                ans[i] = arr[i] / 3 * 3;        // .. * 3
                arr[i] = arr[i] % 3;
            }
        }
        vector<int> vi(10, 0);
        vector<int> tmp(10, 0);
        dfsa1(arr, vi, tmp, 0);
        for (int i = 0; i < vi.size(); ++i)
            ans[i] += vi[i];
        int t2 = 0;
        for (int i = 1; i < vi.size(); ++i)
            t2 += ans[i];

        #ifdef __test
        showVectorInt(ans);
        #endif // __test

        if (t2 == 0)
        {
            return ans[0] == 0 ? "" : "0";
        }
        string res;
        for (int i = 9; i >= 0; --i)
        {
            if (ans[i] > 0)
                res += string(ans[i], (char) ('0' + i));
        }
        return res;
    }
    void dfsa1(vector<int>& arr, vector<int>& vi, vector<int>& tmp, int idx)
    {
        if (idx >= arr.size())
        {
            // ...
            int t4 = 0;
            for (int i = 1; i < tmp.size(); ++i)
            {
                t4 += (tmp[i] * i);
            }
            if (t4 % 3 != 0)
                return;

            int t2 = std::accumulate(begin(tmp), end(tmp), 0);
            int t1 = std::accumulate(begin(vi), end(vi), 0);
            if (t1 < t2)
            {
                for (int i = 0; i < vi.size(); ++i)
                    vi[i] = tmp[i];
            }
            else if (t2 == t1)
            {
                t1 = t2 = 0;
                for (int i = 0; i < vi.size(); ++i)
                {
                    t1 += (vi[i] * i);
                    t2 += (tmp[i] * i);
                }
                if (t1 < t2)
                {
                    for (int i = 0; i < vi.size(); ++i)
                        vi[i] = tmp[i];
                }
            }
            return;
        }
        for (int i = arr[idx]; i >= 0; --i)
        {
            tmp[idx] = i;
            dfsa1(arr, vi, tmp, idx + 1);
            tmp[idx] = 0;
        }
    }

};

int main()
{
//    myvi v = {8,9,1};
//    myvi v = {8,6,7,1,0};
//    myvi v = {1};
//    myvi v = {0,0,0,0};
//    myvi v = {1,1,1};
    myvi v = {2,2,1,1,1};

    LT1363 lt;

    cout<<lt.lt1363a(v)<<endl;

    return 0;
}
