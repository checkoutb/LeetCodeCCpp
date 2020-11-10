
#include "../header/myheader.h"

class LT1191
{
public:


// D
//    int n = arr.size(), sum = arr[0], mx = arr[0];
//    int64_t total = accumulate(arr.begin(), arr.end(), 0), mod = 1e9+7;
//    for (int i = 1; i < n * min(k, 2); i++) {
//        sum = max(arr[i % n], sum + arr[i % n]);
//        mx = max(mx, sum);
//    }
//    return max<int64_t>({0, mx, total * max(0, k - 2) + mx}) % mod;
// kadane.

// 。。。
// 才发现， % 都没有。。
// tle.....
// 感觉，如果 arr的和>0，那么就是 重复 k次的全部
// <=0, 则 必然在连接处.
// 不，，>0 有问题的。 <=0 也不一定在连接处。
// >0 要么全部，要么 arr中。
// 3倍 arr ？ 2倍。
// The behavior is undefined if first and last are iterators into *this.      vector.insert(iterator, iterator)
// bushi 2 bei...
// ok, 是因为 accumulate >0 ，所以 st 的时候 必然 加上后面的全部 才会是最大的。 所以要修改st 和 en？
// 不，好像只需要改 st，因为是加 全部的。
    int lt1191a(vector<int>& arr, int k)
    {
        int ans = 0;
        int sum2 = std::accumulate(begin(arr), end(arr), 0);
        if (sum2 > 0)
            ans = sum2 * k;

        #ifdef __test
        cout<<sum2<<", "<<ans<<endl;
        #endif // __test

        if (k > 1)
        {
            for (int i = 0, sz1 = arr.size(); i < sz1; i++)
            {
                arr.push_back(arr[i]);
            }
//            for (int i = 0, sz1 = arr.size(); i < sz1; i++)
//            {
//                arr.push_back(arr[i]);
//            }
//            for (int i = 0, sz1 = arr.size() / 4; i < sz1; i++)
//            {
//                arr.push_back(arr[i]);
//            }
        }
        #ifdef __test
        showVectorInt(arr);
        #endif // __test
        int sz1 = arr.size();
//        int st[sz1] = {0};
//        int en[sz1] = {0};
        vector<int> st(sz1, 0);
        vector<int> en(sz1, 0);
        int mx = 0;
        int sum3 = 0;
        for (int i = 0; i < sz1; i++)
        {
            mx = 0;
            sum3 = 0;
            for (int j = i; j < sz1; j++)
            {
                sum3 += arr[j];
                mx = std::max(mx, sum3);
            }
            if (k > 2 && sum2 > 0)                      // .
                mx += (k - 2) * sum2;
            st[i] = mx;
        }
        for (int i = 0; i < sz1; i++)
        {
            mx = 0;
            sum3 = 0;
            for (int j = i; j >= 0; --j)
            {
                sum3 += arr[j];
                mx = std::max(mx, sum3);
            }
            en[i] = mx;
        }
        #ifdef __test
        showVectorInt(st);
        showVectorInt(en);
        #endif // __test
        mx = max(st[0], 0);
        for (int i = 1; i < sz1; i++)
        {
            mx = std::max(mx, st[i] + en[i - 1]);
        }
        ans = std::max(ans, mx);
        return ans;
    }

};

int main()
{

//    vector<int> v = {1,2};
//    int k = 3;
//    vector<int> v = {1,-2,1};
//    int k = 5;
//    vector<int> v = {-1,-2};
//    int k = 7;

    vector<int> v = {-5,-2,0,0,3,9,-2,-5,4};        // 20
    int k = 5;

    LT1191 lt;

    cout<<lt.lt1191a(v, k)<<endl;

    return 0;
}
