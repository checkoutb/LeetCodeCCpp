
#include "../header/myheader.h"

class LT1044
{
public:

// D D

//        A = [ord(c) - ord('a') for c in S]
//        mod = 2**63 - 1
//
//        def test(L):
//            p = pow(26, L, mod)
//            cur = reduce(lambda x, y: (x * 26 + y) % mod, A[:L], 0)
//            seen = {cur}
//            for i in xrange(L, len(S)):
//                cur = (cur * 26 + A[i] - A[i - L] * p) % mod
//                if cur in seen: return i - L + 1
//                seen.add(cur)
//        res, lo, hi = 0, 0, len(S)
//        while lo < hi:
//            mi = (lo + hi + 1) / 2
//            pos = test(mi)
//            if pos:
//                lo = mi
//                res = pos
//            else:
//                hi = mi - 1
//        return S[res:res + lo]


// Trie



//Runtime: 904 ms, faster than 80.08% of C++ online submissions for Longest Duplicate Substring.
//Memory Usage: 197.3 MB, less than 64.63% of C++ online submissions for Longest Duplicate Substring.
// hint1 二分
// hint2 Rabin-Karp
// 是把string hash，转为 int， 并且hash 是有记忆(回溯/递推) 的。 这样 sliding windows时， 只要 把剔除的减去，再加上新增的char，就是 hash值
// 如果这个hash值出现过，那么说明 之前有个 substr 可能 相等，  没出现过，不可能有相等的， 。。   bloom fileter。。。
// bloom 有好多亲戚。。Counting filters ，Compact approximators［11］
//Stable Bloom filters［12］
//Scalable Bloom filters［13］
//Attenuated Bloom filters［14］
    string lt1044b(string s)
    {
        int l = 0;
        int r = s.size();
        string ans = "";
        unordered_map<int, vector<int>> map2;       // hash : <indexs>
        while (l < r)
        {
            map2.clear();
            int mid = (l + r) / 2;
//            cout<<"mid        --------------------- "<<mid<<endl;
//            cout<<mid<<endl;
            int hsh = 0;
            int t2 = 0;
            for (int i = 0; i < mid; ++i)
            {
                hsh = (hsh * 27 + s[i]) % 6287;      // 26 是偶数，这样 会少一半 啊。 毕竟 不可能奇数。 当然后面有s[i]。 这种(26-27)会有提升吗？
                t2 = (t2 * 27) % 6287;
                if (i == 0)
                    t2 = 1;
            }
            map2[hsh].push_back(0);
//            cout<<"hsh : "<<hsh<<endl;
//            cout<<" . .ttt "<<t2<<endl;
            bool eql = false;
            int i = 1;
//            cout<<s.size() - mid<<endl;
            for (; i <= s.size() - mid; ++i)
            {
                hsh = ((hsh - t2 * s[i - 1]) * 27 + s[i + mid - 1]) % 6287;
                if (hsh < 0)                                 // ..............
                    hsh += 6287;

//                if (i == 800)
//                    cout<<"hhhsh : " <<hsh<<endl;

                if (map2.find(hsh) != map2.end())
                {
//                    string subi = s.substr
                    for (int j : map2[hsh])
                    {
                        eql = true;
                        for (int m = i, n = j, cnt = 0; cnt < mid; ++cnt, ++m, ++n)     // md, wang le ++m, ++n
                        {
                            if (s[m] != s[n])
                            {
                                eql = false;
                                break;
                            }
                        }
                        if (eql)
                        {
                            #ifdef __test
//                            cout<<"  .  "<<i<<", "<<j<<", "<<mid<<endl;
//                            string st2 = s.substr(i, mid);
//                            string st3 = s.substr(j, mid);
//                            cout<<st2<<" = "<<st3<<endl;
                            #endif // __test
                            goto AAA;
                        }
                    }
                }
                map2[hsh].push_back(i);
            }

            AAA:
            if (eql)
            {
//                cout<<i<<". "<<mid<<endl;
                ans = s.substr(i, mid);
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
//        cout<<" . . . "<<ans.size()<<endl;
        return ans;
    }
//    int hashb1()


// tle.  2个半屏幕的 string ...  二分 长度？
// 好像很简单啊。 hard？
    string lt1044a(string s)
    {
        int len = 0;
        string ans = "";
        for (int i = 0; i < s.size() - len; ++i)
        {
            string subs = s.substr(i, len + 1);
            while (s.find(subs, i + 1) != std::string::npos)
            {
                ans = subs;
                len++;
                subs = s.substr(i, len + 1);
            }
        }
        return ans;
    }

};

int main()
{
//    string s = "banana";
    string s = "abcd";
//    string s = "aa";

        // "njsi"
//    string s = "rikgjehlhvyrrohnqrxvzwsinblhxlbfnbvoqipehfhzhklafyyfwxsziwcrqmocoxcepakwmgetlnbiskidivapcqurdbstmlfinobxfyyeqcxgconruuokuxseinsywiziikzcdujsmxljvyzfqxeaxmgajepglxtyjplhokttbzzxlxjocuyazjvfywrdzjarlyjfjlnlsvmsnjsiyybuhjwchcfynulymjjhhyitzcomkahqbjilzqcgjfgwvuvryuzobifjnyuqdesriziqguzghcfcftrkjivylehhkxedkklsdwvmezhlokcyyhteumlcvskizidwwsklpdorqxcrjywuenhjqvtcpmpynjsiblaougocgifksqmdjfyumuutdiyvvcbgihnzvmbvxoesthhxixoyngtstychwwhffdseavyhncaedledetfxvjygculeglytuegadfwsgsgkuurbowcrytwepvsedpzzcihpwnarjmaojxdxoqlmejqxfdordbwnjowofssjzjpfcojynpttmnxexwkpehoxyjsqhdvnmqnqppxjjclbtjahnwhijswjndldgrzkhkjsqqxfknjtdrpkymmbucgcerkbwrbcqlsjonwdcuqqfgrwqsdivdbjtahlyrodsgydiotgnwygficmjlkcidxtggopfuioisxezoyhqirmeyrgjnasqbjdcksfwvbxajtfuhjfvphcwwnhecqbeehimyrsrxxstdnaeyqncxxwfqyrziqnuxafnbbagjnbrsqtzogivzpkzbouqvyuxdfpnikzqsvtaozsopgmvtgaujocwahahzh";


    LT1044 lt;

    cout<<lt.lt1044b(s)<<endl;

    return 0;
}
