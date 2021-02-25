
#include "../header/myheader.h"

class LT0982
{
public:

// D D


//        int N = 1 << 16;
//        int[] dp = new int[N];
//        dp[N - 1] = 1;
//        for (int i = 0; i < 3; i++) {
//            int[] temp = new int[N];
//            for (int k = 0; k < N; k++) {
//                for (int a : A) {
//                    temp[k & a] += dp[k];
//                }
//            }
//            dp = temp;
//        }
//        return dp[0];


//  int tuples[1 << 16] = {};
//  for (auto a : A)
//    for (auto b : A) ++tuples[a & b];
//  for (auto a : A)
//    for (auto i = 0; i < (1 << 16); ++i)
//      if ((i & a) == 0) cnt += tuples[i];
//  return cnt;


//Runtime: 376 ms, faster than 65.87% of C++ online submissions for Triples with Bitwise AND Equal To Zero.
//Memory Usage: 12.7 MB, less than 70.66% of C++ online submissions for Triples with Bitwise AND Equal To Zero.
// map
// ... i == j == k.
    int lt0982a(vector<int>& A)
    {
        unordered_map<int, int> map2;
        int ans = 0;
        int sz1 = A.size();
        if (sz1 == 0)
            return 0;
        if (sz1 > 1 && (A[0] & A[1]) == 0)
            ans = 6;
        if (A[0] == 0)      // 000
            ans++;
        if (sz1 > 1 && A[1] == 0)
            ans++;
        for (int i = 2; i < sz1; ++i)
        {
            if (A[i] == 0)
                ans++;
            int t2 = A[i - 1];
            if ((A[i] & t2) == 0)  // 112  122
            {
                ans += 6;
            }
            for (int j = 0; j < i - 1; ++j)
            {
                map2[t2 & A[j]]++;
                if ((A[i] & A[j]) == 0)
                    ans += 6;
            }
            for (unordered_map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
            {
                if ((it->first & A[i]) == 0)
                {
                    ans += it->second * 6;
                }
            }
        }
        return ans;
//        for (int i = 0; i < sz1; ++i)
//        {
//            for (int j = i + 1; j < sz1; ++j)
//            {
//                map2[A[i] & A[j]]++;
//            }
//
//        }
    }

};

int main()
{
//    myvi v = {2,1,3};
//    myvi v = {0,0,0};
    myvi v = {0};

    LT0982 lt;

    cout<<lt.lt0982a(v)<<endl;

    return 0;
}
