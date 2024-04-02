
#include "../header/myheader.h"

class LT0940
{
public:

    // D

    // https://leetcode.com/problems/distinct-subsequences-ii/solutions/242780/concise-solution-with-well-explanation/
    // 照这个，把 arr[ch] = t2; 确实应该可以。
    // 但和我想的不一样啊

//     Let's say we're handling i-th char s[i]=c, its previous duplicate is at j-th, all char after j and before i are not c, like this "....xc.....c".
// What sequences are counted twice because of duplicate c? All sequences for substring s[0..j-1], appended j-th char will duplicate those appended i-th char.
// So end[c] is res[j-1] that is previous result of res[j], not res[j]. And end[c] is updated to res[i-1] as well.

    // 我想的是 增加[j] 的时候 多了多少，那么 [i] 的时候 就要减去。 所以一直在找 ans - t2;



        // long endsWith[26] = {}, mod = 1e9 + 7;
        // for (char c : S)
        //     endsWith[c - 'a'] = accumulate(begin(endsWith), end(endsWith), 1L) % mod;
        // return accumulate(begin(endsWith), end(endsWith), 0L) % mod;
    // ....
    // 把当前ch 加上 所有现有的 subseq上， 现有的subseq 是唯一的， 都加上 当前ch， 也是唯一的。 再加上 ch 自己。



    // g


    // aaa -> 3
    // abcda
    // a -> a
    // ab -> {a}*2 + 1     =  {a}*2 is {a, ab}     +1 is {b}   == {a, ab, b}
    // abc -> {ab}*2 + 1    {a,ab,b} + {ac,abc,bc} + {c}
    // abcd -> {abc} + {abc} + 1     {a,ab,b,ac,abc,bc,c} + {ad,abc,db,acd,abcd,bcd,cd} + d
    // abcda -> {abcd} + {abcd} + 0 , 0 is because "a" has existed.
    // abcdb -> not {abcd} + {abcd} + 0 , for  "ab" "ab" will duplicate
    //            {abcd} +  >= last b
    // abbb
    // a - a
    // ab - a ab b
    // abb - a ab b abb bb
    // abbb - a ab b abb bb abbb bbb
    int distinctSubseqII(string s)
    {
        int sz1 = s.size();
        int ans = 0;
        const int MOD = 1e9 + 7;
        // int arr[123] = {-1};
        int arr[123] = {-1};
        std::fill(begin(arr), end(arr), -1);
        for (int i = 0; i < sz1; ++i)
        {
            int ch = s[i];

#ifdef __test
            cout<<ans<<", "<<arr[ch]<<endl;
#endif
            int t2 = ans;
            ans = (ans * 2 + (arr[ch] == -1 ? 1 : 0) - max(0, arr[ch])) % MOD;
            if (ans < 0)
                ans = (ans + MOD) % MOD;
            // arr[ch] = ans;
            // arr[ch] = (ans - t2 + MOD - (arr[ch] == 0 ? 0 : 1)) % MOD + (arr[ch] == 0 ? 0 : 0);
            // arr[ch] = t2;

            // arr[ch] = (ans - t2 + MOD - (arr[ch] == -1 ? 1 : 0)) % MOD;
            arr[ch] = t2;

            // if (arr[ch] == -1)
            // {
            //     ans = (ans * 2 + 1) % MOD;
            // }
            // else
            // {
            //     ans = (ans * 2 - arr[ch]) % MOD;
            // }
            // arr[ch] = i;
        }

        return ans;
    }

};

int main()
{

    LT0940 lt;

    // std::string s {"abasdasdzxcpwec"};  // 22319
    // string s = "aaa";
    // string s = "abc";
    string s = "aba";
    // string s = "abcb";      // 13
    // string s = "cfffe";     // 15
    // string s = "aaa";

    // a b c ab ac bc bb cb abc acb bcb abb abcb

    // a b c ab ac cb abc
    // ab bb cb abb acb cbb abcb




    cout<<lt.distinctSubseqII(s)<<endl;

    return 0;
}
