
#include "../header/myheader.h"

class LT0974
{
public:


// D

// sum = sum % K， 如果<0 -> sum += K, 当2次sum%k 相等，那么这2个之间组成的subarray就是符合的


// gg
// 看了discuss 的 title， O(N), hashMap, prefix sum。。。 前缀和不理解怎么用。。
    int lt0974b(vector<int>& A, int K)
    {
        unordered_map<int, int> map2;
        int ans = 0;
        int sz1 = A.size();
        for (int i = 0; i < sz1; i++)
        {
            int t3 = A[i] % K;
            if (t3 == 0)
                ans++;
            int t2 = -t3;
            int t1 = t3 < 0 ? -K - t3 : K - t3;
            ans += (map2[t2] + map2[t1]);

        }
    }



// 68/73 tle
    int lt0974a(vector<int>& A, int K)
    {
        int ans = 0;
        int sz1 = A.size();
        for (int i = 1; i < sz1; i++)
        {
            A[i] = A[i - 1] + A[i];
        }

        for (int i = 0; i < sz1; i++)
        {
            int ai = A[i];
            if (ai % K == 0)
                ans++;
            for (int j = i + 1; j < sz1; j++)
            {
                if ((A[j] - ai) % K == 0)
                    ans++;
            }
        }
        return ans;
    }

};

int main()
{

    cout<<(-5 % 7)<<", "<<(-8 % 7)<<", "<<(5 % 7)<<", "<<endl;

    vector<int> v = {4,5,0,-2,-3,1};
    int k = 5;

    LT0974 lt;

    cout<<lt.lt0974a(v, k)<<endl;

    return 0;
}
