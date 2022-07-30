
#include "../header/myheader.h"

class LT2156
{
public:

    // D D

    //for (int i = n - 1; i >= 0; --i) {
    //    cur = (cur * p + s[i] - 'a' + 1) % m;
    //    if (i + k >= n)
    //        pk = pk * p % m;
    //    else
    //        cur = (cur - (s[i + k] - 'a' + 1) * pk % m + m) % m;
    //    if (cur == hashValue)
    //        res = i;
    //}



    //long long hash = 0, res = 0, power_k = 1;
    //auto val = [&](int i) { return s[i] - '`'; };
    //for (int i = s.size() - 1; i >= 0; --i) {
    //    hash = (hash * power + val(i)) % mod;
    //    if (i < s.size() - k)
    //        hash = (mod + hash - power_k * val(i + k) % mod) % mod;
    //    else
    //        power_k = power_k * power % mod;
    //    if (hash == hashValue)
    //        res = i;
    //}



//Runtime: 28 ms, faster than 78.41 % of C++ online submissions for Find Substring With Given Hash Value.
//Memory Usage : 10.3 MB, less than 77.53 % of C++ online submissions for Find Substring With Given Hash Value.
    // 5+17 % 7= 1   5+3%7
    // s[0]*p^0  。 所以 得 倒序，但是 找 first。
    string lt2156a(string s, int power, int modulo, int k, int hashValue)
    {
        int sz1 = s.size();
        long long hs = 0LL;
        long long pw = 1LL;
        for (int i = sz1 - k + 1; i < sz1; ++i)
        {
            hs = (hs + (s[i] - 'a' + 1) * pw) % modulo;
            pw = (pw * power) % modulo;
        }
#ifdef __test
        cout << " //- " << hs << " - " << pw << endl;
#endif
        int ans = -1;
        for (int i = sz1 - k; i >= 0; --i)
        {
            hs = ((((hs - ((i + k < sz1) ? (s[i + k] - 'a' + 1) * pw : 0)) % modulo + modulo) % modulo * power) + (s[i] - 'a' + 1)) % modulo;

            hs = (hs + modulo) % modulo;
            
#ifdef __test
            cout << i << " - " << hs << endl;
            cout << " ===== " << (s[i] - 'a' + 1) + (s[i + 1] - 'a' + 1) * power << endl;
#endif

            if (hs == hashValue)
                ans = i;
        }
        if (ans == -1)
            return "-1";
        return s.substr(ans, k);
    }

};

int main()
{

    LT2156 lt;

    //string s = "leetcode";
    //int pw = 7;
    //int mod = 20;
    //int k = 2;
    //int hs = 0;

    //string s = "fbxzaad";
    //int pw = 31;
    //int mod = 100;
    //int k = 3;
    //int hs = 32;

    string s = "rlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblprlzblpbfleezoimfzxwnk";
    int pw = 842163460;
    int mod = 815354026;
    int k = 6;
    int hs = 472331242;


    cout << lt.lt2156a(s, pw, mod, k, hs) << endl;

    return 0;
}
