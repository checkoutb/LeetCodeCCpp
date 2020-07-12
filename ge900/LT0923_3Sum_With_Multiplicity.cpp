
#include "../header/myheader.h"

class LT0923
{
public:

// D D
// auto combi = [](auto m, auto n){ return n==2 ? m*(m-1) / 2 : m*(m-1)*(m-2) / 6; };

//    long m[101] = {}, res = 0;
//    for (auto n : nums) ++m[n];
//    for (auto i = 0; i < 101; ++i) {
//        if (i * 3 == target) res += m[i] * (m[i] - 1) * (m[i] - 2) / 6;
//        for (auto j = i + 1, k = target - i - j; j < 101; ++j, --k) {
//            if (i * 2 + j == target) res += m[i] * m[j] * (m[i] - 1) / 2;
//            if (i + j * 2 == target) res += m[i] * m[j] * (m[j] - 1) / 2;
//            if (k > j && k < 101) res += m[i] * m[j] * m[k];
//        }
//    }
//    return res % 1000000007;


//        for (int i = 0; i < A.length; i++) {
//            res = (res + map.getOrDefault(target - A[i], 0)) % mod;
//
//            for (int j = 0; j < i; j++) {
//                int temp = A[i] + A[j];
//                map.put(temp, map.getOrDefault(temp, 0) + 1);
//            }
//        }


//        for (int i = 0; i <= 100; i++)
//            for (int j = i; j <= 100; j++) {
//                int k = target - i - j;
//                if (k > 100 || k < 0) continue;
//                if (i == j && j == k)
//                    res += c[i] * (c[i] - 1) * (c[i] - 2) / 6;
//                else if (i == j && j != k)
//                    res += c[i] * (c[i] - 1) / 2 * c[k];
//                else if (j < k)
//                    res += c[i] * c[j] * c[k];
//            }

// O(n*n)


//Runtime: 12 ms, faster than 93.04% of C++ online submissions for 3Sum With Multiplicity.
//Memory Usage: 10.4 MB, less than 88.39% of C++ online submissions for 3Sum With Multiplicity.
    int lt0923a(vector<int>& A, int target)
    {
        int arr[101] = {0};
        for (int a : A)
            arr[a]++;
        int sum3 = 0;
        int t3 = 1E9 + 7;
        int ans = 0;
//        int prod = 0;
        for (int i = 0; i < 101; i++)
        {
            if (arr[i] == 0)
                continue;
            for (int j = i; j < 101; j++)
            {
                if (arr[j] == 0)
                    continue;
                for (int k = 100; k >= j; k--)
                {
                    if (arr[k] == 0)
                        continue;
                    sum3 = i + j + k;
                    if (sum3 > target)
                    {
                        continue;
                    }
                    else if (sum3 == target)
                    {
//                        ans = (ans + (arr[i] * (arr[j] - (j == i ? 1 : 0)) * (arr[k] - (j == i ? 1 : 0) - (k == j ? 1 : 0))) % t3) % t3;
                        ans = (ans + getCnta1(i, j, k, arr[i], arr[j], arr[k])) % t3;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return ans;
    }

    inline int getCnta1(int i, int j, int k, int ni, int nj, int nk)
    {
        long long cnt = 0;
        int t3 = 1E9 + 7;
        if (i == j && j == k)
        {
            //...?
            cnt = ((long long)(ni - 1) * (ni - 2) * ni / (6));      // 全排列 / 3个数字的全排列 ?
            cnt %= t3;
            return cnt;
        }
        if (i == j)
        {
//            cnt = (1 + ni) * ni / 2 * nk % (1E9 + 7);
            cnt = (ni - 1) * ni / 2 * nk % t3;
            return cnt;
        }
        if (j == k)
        {
//            cnt = (1 + nj) * nj / 2 * ni % (1E9 + 7);
            cnt = (nj - 1) * nj / 2 * ni % t3;
            return cnt;
        }
        cnt = ni * nj * nk % t3;
        return cnt;
    }

};

int main()
{
    vector<int> v = {1,1,2,2,3,3,4,4,5,5};
    int tar = 8;

//    vector<int> v = {1,1,2,2,2,2};
//    int tar = 5;

    LT0923 lt;

    cout<<lt.lt0923a(v, tar)<<endl;

    return 0;
}
