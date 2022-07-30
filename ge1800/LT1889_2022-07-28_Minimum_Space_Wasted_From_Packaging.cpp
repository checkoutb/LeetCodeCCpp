
#include "../header/myheader.h"

class LT1889
{
public:

    // D D

    // 并不需要 prefix sum ... 计算到最后，你知道 箱子的 总容积，  减去 sum(package) 就可以了
    // 只需要在 return 的时候 减去 sum(package) 这个 固定值。。。



    //sort(begin(packs), end(packs));
    //long sum_packs = accumulate(begin(packs), end(packs), 0l), res = LONG_MAX;
    //for (auto& boxes : suppliers) {
    //    sort(begin(boxes), end(boxes));
    //    if (boxes.back() >= packs.back()) {
    //        long prev = 0, cur = 0, total = 0;
    //        for (auto b : boxes) {
    //            cur = upper_bound(begin(packs) + prev, end(packs), b) - begin(packs);
    //            total += b * (cur - prev);
    //            prev = cur;
    //        }
    //        res = min(res, total - sum_packs);
    //    }
    //}
    //return res == LONG_MAX ? -1 : res % 1000000007;



    //public int minWastedSpace(int[] A, int[][] boxes) {
    //    Arrays.sort(A);
    //    long inf = (long)1e11, res = inf, mod = (long)1e9 + 7, sumA = 0L;
    //    for (int a : A)
    //        sumA += a;
    //    for (int[] B : boxes) {
    //        Arrays.sort(B);
    //        if (B[B.length - 1] < A[A.length - 1]) continue;
    //        long cur = 0, i = 0, j;
    //        for (int b : B) {
    //            j = binarySearch(A, b + 1);
    //            cur += b * (j - i);
    //            i = j;
    //        }
    //        res = Math.min(res, cur);
    //    }
    //    return res < inf ? (int)((res - sumA) % mod) : -1;
    //}
    //
    //private int binarySearch(int[] A, int b) {
    //    int l = 0, r = A.length;
    //    while (l < r) {
    //        int m = (l + r) / 2;
    //        if (A[m] < b)
    //            l = m + 1;
    //        else
    //            r = m;
    //    }
    //    return l;
    //}






//Runtime: 360 ms, faster than 94.52 % of C++ online submissions for Minimum Space Wasted From Packaging.
//Memory Usage : 116.1 MB, less than 26.03 % of C++ online submissions for Minimum Space Wasted From Packaging.
    // O(n^2) -> O(nlogn) , 原先是 for for 循环对比，虽然有一些判断可以提前退出。 现在是 for (二分)
    //   主要是 sum(boxes[j].length) <= 10^5  这个 和 sz1 是同一个量级的。
    // related topics: binary search, prefix sum
    int lt1889b(vector<int>& packages, vector<vector<int>>& boxes)
    {
        sort(begin(packages), end(packages));
        long long mnwst = LONG_MAX;
        const int MOD = 1e9 + 7;
        int sz1 = packages.size();
        vector<long long> vi(sz1, 0LL);
        for (int i = 0; i < sz1; ++i)
        {
            vi[i] = (i == 0 ? 0 : vi[i - 1]) + packages[i];
        }

        for (vector<int>& bx : boxes)
        {
            if (*max_element(begin(bx), end(bx)) < packages[sz1 - 1])
                continue;

            sort(begin(bx), end(bx));
            long long t3 = 0LL;
            int lst = 0;
            vector<int>::iterator it = begin(packages);
            for (int i = 0; i < bx.size(); ++i)
            {
                if (packages[lst] > bx[i])      // [[50000,100000],[50001,100000]]
                    continue;

                it = std::upper_bound(it, end(packages), bx[i]);

                int t2 = distance(begin(packages), it);

                t3 += 1LL * (t2 - lst) * bx[i] - (vi[t2 - 1] - (lst == 0 ? 0 : vi[lst - 1]));

#ifdef __test
                cout << t2 << ", " << lst << ", " << bx[i] << endl;
#endif

                lst = t2;

                if (t2 == sz1 || t3 > mnwst)
                    break;
            }

#ifdef __test
            showVectorInt(bx);
            cout << ", " << t3 << endl;
#endif

            if (t3 < mnwst)
                mnwst = t3;

        }
        return mnwst == LONG_MAX ? -1 : (int)(mnwst % MOD);
    }


    // tle * 2
    // long > 10^5^3
    int lt1889a(vector<int>& packages, vector<vector<int>>& boxes)
    {
        sort(begin(packages), end(packages));
        long long mnwst = LONG_MAX;
        const int MOD = 1e9 + 7;

        for (vector<int>& vi : boxes)
        {

            if (*max_element(begin(vi), end(vi)) < packages[packages.size() - 1])
                continue;

            sort(begin(vi), end(vi));

            int idx = 0;
            long long t2 = 0LL;
            for (int i = 0; i < packages.size() && t2 < mnwst; ++i)
            {
                if (packages[i] <= vi[idx])
                {
                    t2 += (vi[idx] - packages[i]);
                }
                else
                {
                    --i;
                    idx++;
                }
                if (idx == vi.size())
                    goto AAA;
            }
            if (mnwst > t2)
                mnwst = t2;

            AAA:
            continue;

        }
        if (mnwst == LONG_MAX)
            return -1;
        return (int)(mnwst % MOD);

    }

};

int main()
{

    LT1889 lt;

    //myvi v = { 2,3,5 };
    //myvvi vv = { {4,8},{2,8} };

    //myvi v = { 2,3,3333 };
    //myvvi vv = { {1,2},{3,4} };

    myvi v = { 3,5,8,10,11,12 };
    myvvi vv = { {12},{11,9},{10,5,14} };

    cout << lt.lt1889b(v, vv) << endl;

    return 0;
}
