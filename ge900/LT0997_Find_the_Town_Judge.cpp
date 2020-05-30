
#include "../header/myheader.h"

class LT0997
{
public:


//        vector<int> count(N + 1, 0);
//        for (auto& t : trust)
//            count[t[0]]--, count[t[1]]++;
//        for (int i = 1; i <= N; ++i) {
//            if (count[i] == N - 1) return i;
//        }
//        return -1;
// 出度， 入度。
// 无重复边，无自环 的有向图。



//Runtime: 480 ms, faster than 21.90% of C++ online submissions for Find the Town Judge.
//Memory Usage: 77 MB, less than 12.50% of C++ online submissions for Find the Town Judge.
// 唯一 没有 在下标0出现，且所有其他数字都指向了它 的 数字。
    int lt0997a(int N, vector<vector<int>>& trust)
    {
        int arr1[1001] = {0};
        for (vector<int> v : trust)
        {
            arr1[v[0]] = v[0];
        }
        int sum2 = std::accumulate(begin(arr1), begin(arr1) + N + 1, 0);
        int t2 = (1 + N) * N / 2;
        int t3 = t2 - sum2;

        if (t3 > N || arr1[t3] != 0)
            return -1;

//        int t4 = arr1[t3];
        for (vector<int> v : trust)
        {
            if (v[1] == t3)
            {
                arr1[v[0]] = -v[0];
            }
        }
        arr1[t3] = -t3;
        sum2 = std::accumulate(begin(arr1), begin(arr1) + N + 1, 0);
        t2 = -t2;
        if (t2 == sum2)
            return t3;
        return -1;
    }

};

int main()
{

    vector<vector<int>> vv = {{1,2},{2,3}};
    int n = 3;

    LT0997 lt;

    cout<<lt.lt0997a(n, vv)<<endl;

    return 0;
}
