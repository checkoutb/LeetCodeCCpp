
#include "../header/myheader.h"

class LT2607
{
public:


// D D

//            vector <ll> vec;
//            for(ll j = i; j < n; j+=k)
//                vec.push_back(arr[j]);
//            sort(vec.begin(),vec.end());
//            ll mid = vec.size()/2;
//            for(ll ind = 0; ind < vec.size(); ind++)
//                ans+=abs(vec[mid]-vec[ind]);




//Runtime252 ms
//Beats
//29.91%
//Memory108.9 MB
//Beats
//82.78%


    // sum of subarray of size k
    // [i] == [i + k] ? , %
    //
    long long makeSubKSumEqual(vector<int>& arr, int k)
    {
        int sz1 = arr.size();
        k = gcda1(sz1, k);

//        if (k == 1 || sz1 % k != 0)
//        {
//            // all eq
//            return alleq(arr);
//        }

        long long ans = 0LL;
        for (int i = 0; i < k; ++i)
        {
            vector<int> vi;
            for (int j = i; j < sz1; j += k)
            {
                vi.push_back(arr[j]);
            }
            ans += alleq(vi);
        }
        return ans;
    }

    int gcda1(int a, int b)
    {
        return b == 0 ? a : gcda1(b, a % b);
    }

    long long alleq(vector<int>& vi)
    {
        sort(begin(vi), end(vi));
        long long sum2 = std::accumulate(begin(vi), end(vi), 0LL);
        long long sum3 = 0LL;
        long long ans = sum2 - vi[0] * vi.size();
        int sz1 = vi.size();
        for (int i = 0; i < sz1; ++i)
        {
            sum3 += vi[i];
            sum2 -= vi[i];
//            ans = min(ans, 1LL * vi[i] * ((long long)vi.size()) - 1LL * sum3 + 1LL * sum2);
            ans = min(ans, 1LL * vi[i] * (i + 1) - sum3 + sum2 - 1LL * (vi[i]) * ((long long)(vi.size()) - i - 1));
        }
        return ans;

//        int mn = vi[0];
//        long long sum2 = 0LL;
//        for (int i : vi)
//        {
//            sum2 += i;
//            if (mn > i)
//                mn = i;
//        }
//        return sum2 - mn * vi.size();

//        sort(begin(vi), end(vi));
//        long long sum2 = std::accumulate(begin(vi), end(vi), 0LL);
//        return sum2 - vi[0] * vi.size();
    }

};

int main()
{

    LT2607 lt;

//    myvi v = {1,4,1,3};
//    int k = 2;

//    myvi v = {2,5,5,7};
//    int k = 3;


// [0] - [4]
// [1] - [5]
// [2] - [0]
// [3] - [1]
// [4] - [2]
// [5] - [3]
    myvi v = {6,2,8,5,7,10};        // 10
    int k = 4;

    cout<<lt.makeSubKSumEqual(v, k)<<endl;

    return 0;
}
