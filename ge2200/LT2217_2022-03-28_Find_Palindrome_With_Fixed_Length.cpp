
#include "../header/myheader.h"

class LT2217
{
public:

// D D


//int reverse(long long n, bool skip) {
//    long long res = 0;
//    for (n = skip ? n / 10 : n; n > 0; n /= 10)
//        res = res * 10 + n % 10;
//    return res;
//}
//vector<long long> kthPalindrome(vector<int>& queries, int sz) {
//    vector<long long> res;
//    long long start = pow(10, (sz + 1) / 2 - 1), end = pow(10, (sz + 1 ) / 2), mul = pow(10, sz / 2);
//    for (int q : queries)
//        res.push_back(start + q > end ? -1 :
//            (start + q - 1) * mul + reverse(start + q - 1, sz % 2));
//    return res;
//}





//Runtime: 211 ms, faster than 82.35% of C++ online submissions for Find Palindrome With Fixed Length.
//Memory Usage: 49.7 MB, less than 100.00% of C++ online submissions for Find Palindrome With Fixed Length.
// 回文 前一半 就是 顺序。
    vector<long long> lt2217a(vector<int>& queries, int intLength)
    {
        long long fst = 1;
        for (int i = 2; i < intLength; i += 2)
        {
            fst *= 10;
        }
        vector<long long> ans(queries.size(), -1LL);
        for (int i = 0; i < queries.size(); ++i)
        {
            if (queries[i] > (fst * 9))
                continue;
            long long t2 = fst + queries[i] - 1;
            long long t3 = t2;
            if (intLength % 2)
            {
                t3 /= 10;
            }
            while (t3 > 0)
            {
                t2 *= 10;
                t2 += t3 % 10;
                t3 /= 10;
            }
            ans[i] = t2;
        }
        return ans;
    }

};

int main()
{

    LT2217 lt;

//    myvi v = {1,2,3,4,5,90};
//    int l = 3;

//    myvi v = {2,4,6};
//    int l = 4;

    myvi v = {2,201429812,8,520498110,492711727,339882032,462074369,9,7,6};
    int l = 1;


    vector<long long> vi = lt.lt2217a(v, l);

    for (long long ll : vi)
        cout<<ll<<", ";

    return 0;
}
