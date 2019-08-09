
#include "../header/myheader.h"

class LT0424
{
public:



// discuss
// int[] 表示 下标char的个数。。
// max_element。上面或者用vector
// [s, e]区间中，每次e++，查看 int[] 中数量最多的 char，只需要用 下面的max_element 和 int[s[e]] 这个值做max。
// e - s + 1 + 上面的值 > k, e-s就是可能的值，s后移。利用max_element计算现在 [s,e]中最多的char。
// return max();
// 主要是int[]....以及 e-s+1+max(int[]) > k



//Runtime: 988 ms, faster than 5.06% of C++ online submissions for Longest Repeating Character Replacement.
//Memory Usage: 9.2 MB, less than 89.66% of C++ online submissions for Longest Repeating Character Replacement.

// ... a,b彻底翻车，c也翻了好?几次。。

    int lt0424c(string s, int k)
    {
        int sz1 = s.size();
        int ans = 0;
        for (int i = 0; i < sz1; i++)
        {
            if (i > 0 && s[i] == s[i - 1])
            {
                continue;
            }
            int k2 = 0;
            int t1 = i;
            int t2 = i;
            while (k2 <= k && t1 < sz1)
            {
                t1 = t2;
                t2 = t1 + 1;
                if (t2 >= sz1)
                    break;
                if (s[t2] != s[i])
                {
                    k2++;
                }
            }
            int t4 = 0;
            if (k2 <= k)
            {
                t4 += i;
                t4 += (sz1 - t2);
            }
            #ifdef __test
            cout<<ans<<", "<<t2<<" - "<<i<<" . "<<k-k2<<", "<<t4<<endl;
            #endif // __test
            ans = max(ans, t2 - i + max(0, min(k - k2, t4)));
        }
        return ans;
    }


    // error
    int lt0424b(string s, int k)
    {
        vector<vector<pair<int, int>>> v2(128, vector<pair<int, int>>());
        int st = 0;
        int sz1 = s.size();
        for (int i = 1; i < sz1; i++)
        {
            if (s[i] != s[i - 1])
            {
                v2[s[i - 1]].push_back(make_pair(st, i - 1));
                st = i;
            }
        }
        v2[s[sz1 - 1]].push_back(make_pair(st, sz1 - 1));

        int ans = 0;
        for (int i = 'A'; i <= 'Z'; i++)
        {
            vector<pair<int, int>> v3 = v2[i];
            int k2 = 0;
            st = 0;
            int e = 0;
            int sz3 = v3.size();
            while (e <= sz3 - 1)
            {
                #ifdef __test
                cout<<e<<endl;
                #endif // __test

                if (k2 < k)
                {
                    e++;
                    k2 += (v3[e].first - v3[e - 1].second - 1);

                    if (k2 <= k)
                    {
                        ans = max(ans, (v3[e].second) - (v3[st].first) + 1);
                    }
                }
                else
                {
                    st++;
                    k2 -= (v3[st].first - v3[st - 1].second - 1);
                }
            }
        }
        return ans;
    }


    // error .....
    int lt0424a(string s, int k)
    {
        vector<vector<pair<int, int>>> v2(128, vector<pair<int, int>>());
        int st = 0;
        int sz1 = s.size();
        for (int i = 1; i < sz1; i++)
        {
            if (s[i] != s[i - 1])
            {
                v2[s[i - 1]].push_back(make_pair(st, i - 1));
                st = i;
            }
        }
        v2[s[sz1 - 1]].push_back(make_pair(st, sz1 - 1));

        #ifdef __test
        for (auto& p : v2)
        {
            for (auto& p2 : p)
            {
                cout<<p2.first<<", "<<p2.second<<endl;
            }
//            cout<<"---------------"<<endl;
        }
        #endif // __test

        int ans = 0;
        for (int i = 'A'; i <= 'Z'; i++)
        {
            vector<pair<int, int>> v3 = v2[i];

            #ifdef __test
            for (auto& p : v3)
            {
                cout<<p.first<<" . . . "<<p.second<<endl;
            }
            #endif // __test

            int e = 0;
            int t1 = 0;
            int sz2 = v3.size();
            int t2 = 0;
            int n1 = 0;
            int n2 = 0;
            for (int i = 0; i < sz2; i++)
            {
                if (i == 0)
                {
                    n1 = v3[0].second - v3[0].first + 1;
                }
                t1 -= t2;
                n1 -= n2;
                n2 = 0;
                t2 = 0;
                int t3 = ((e + 1) <= sz2 - 1 ? v3[e + 1].first - v3[e].second - 1 : (k + 1));
                while ((t1 + t3) <= k)
                {
                    #ifdef __test
                    cout<<".       "<<t1<<", "<<t3<<", "<<n1<<endl;
                    cout<<"          "<<i<<", "<<e<<endl;
                    #endif // __test

                    if (n2 == 0)
                    {
                        t2 = t3;
                        n2 = t3 + v3[i].second - v3[i].first + 1;
                    }
                    t1 += t3;
                    n1 += (t3 + v3[e + 1].second - v3[e + 1].first + 1);
                    e++;
                    t3 = ((e + 1) <= sz2 - 1 ? v3[e + 1].first - v3[e].second - 1 : (k + 1));

                    #ifdef __test
                    cout<<t1<<"  ,   "<<t3<<", "<<e<<", "<<sz2<<", "<<endl;
                    #endif // __test

                }

                int nt = n1;

                n1 += (i == 0 && e == sz2 - 1) ? min(sz1 - v3[e].second - 1 + v3[0].first, k - t1) : (k - t1);

                #ifdef __test
                cout<<".n1: "<<nt<<" - "<<n1<<endl;
                #endif // __test

                ans = max(ans, n1);
                ans = max(ans, v3[i].second - v3[i].first + 1);     // "ABAA" ,, 0

                n1 = nt;
            }
        }
        return ans;
    }
};

int main()
{
    string s = "KRSCDCSONAJNHLBMDQGIFCPEKPOHQIHLTDIQGEKLRLCQNBOHNDQGHJPNDQPERNFSSSRDEQLFPCCCARFMDLHADJADAGNNSBNCJQOF";
    int k = 4;          // 7

//    string s = "ABAB";
//    int k = 2;

//    string s = "AABABBA";
//    int k = 1;

//    string s = "AAAA";
//    int k = 2;

//    string s = "AAAB";
//    int k = 0;

    LT0424 lt;
    cout<<lt.lt0424c(s, k)<<endl;

    return 0;
}
