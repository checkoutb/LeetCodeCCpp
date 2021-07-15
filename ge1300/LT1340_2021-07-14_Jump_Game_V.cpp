
#include "../header/myheader.h"

class LT1340
{
public:

// D D

// https://mp.weixin.qq.com/s/kEQ00_WLqDTG6tbsjQ2Xjw
// 单调栈， O(n)






//Runtime: 40 ms, faster than 56.38% of C++ online submissions for Jump Game V.
//Memory Usage: 14.9 MB, less than 68.55% of C++ online submissions for Jump Game V.
//In addition, you can only jump from index i to index j
//if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).
// 跳过的点，必须都低于i
// 返回最多可以访问几个下标， 就是跳得越多越好。
// dfs + memo ?
    int lt1340a(vector<int>& arr, int d)
    {
        int sz1 = arr.size();
        vector<int> memo(sz1, -1);
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            int t2 = dfsa1(arr, d, memo, i);
            ans = max(t2, ans);
        }
        #ifdef __test
        showVectorInt(memo);
        #endif // __test
        return ans;
    }
//    int ans = 0;
    int dfsa1(vector<int>& arr, int d, vector<int>& memo, int idx)
    {
//        if (idx < 0 || idx >= arr.size())
//            return 0;

        if (memo[idx] != -1)
            return memo[idx];
        memo[idx] = 1;
        for (int i = 1; i <= d; ++i)
        {
            if (idx + i >= arr.size())
                break;
            if (arr[idx + i] >= arr[idx])
                break;
            int t2 = dfsa1(arr, d, memo, idx + i);
            memo[idx] = max(memo[idx], t2 + 1);
        }
        for (int i = 1; i <= d; ++i)
        {
            if (idx - i < 0)
                break;
            if (arr[idx - i] >= arr[idx])
                break;
            int t2 = dfsa1(arr, d, memo, idx - i);
            memo[idx] = max(memo[idx], t2 + 1);
        }
        return memo[idx];
    }

};

int main()
{
//    myvi v = {6,4,14,6,8,13,9,7,10,6,12};
//    int d = 2;

//    myvi v = {3,3,3,3};
//    int d = 3;

//    myvi v = {7,6,5,4,3,2,1};
//    int d = 1;

//    myvi v = {7,1,7,1,7,1};
//    int d = 2;

    myvi v = {66};
    int d = 1;

    LT1340 lt;

    cout<<lt.lt1340a(v, d)<<endl;

    return 0;
}
