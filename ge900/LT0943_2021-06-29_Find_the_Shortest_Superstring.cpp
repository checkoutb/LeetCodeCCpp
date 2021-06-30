
#include "../header/myheader.h"

class LT0943
{
public:


// D

// Travelling Salesman Problem








// tle.   67/83
    string lt0943b(vector<string>& words)
    {
        int sz1 = words.size();
        vector<vector<string>> vvs1(sz1);        // prefix
        vector<vector<string>> vvs2(sz1);        // suffix
        for (int i = 0; i < words.size(); ++i)
        {
            vvs1[i].push_back(string(1, words[i][0]));
            for (int j = 1; j < words[i].size(); ++j)
                vvs1[i].push_back(vvs1[i][j - 1] + words[i][j]);

            int sz2 = words[i].size();
            vvs2[i].push_back(string(1, words[i][sz2 - 1]));
            for (int j = 1; j < words[i].size(); ++j)
                vvs2[i].push_back(string(1, words[i][sz2 - j - 1]) + vvs2[i][j - 1]);
        }
        #ifdef __test
        for (vector<string>& vs : vvs1)
        {
            for (string& s : vs)
                cout<<s<<", ";
            cout<<endl;
        }
        for (vector<string>& vs : vvs2)
        {
            for (string& s : vs)
                cout<<s<<", ";
            cout<<endl;
        }
        #endif // __test

        unordered_map<int, int> map2;
        bitset<12> bs;
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = 0; j < words.size(); ++j)
            {
                if (i != j)
                {
                    int st = 0;
                    for (int k = min(words[i].size(), words[j].size()) - 1; k >= 0; --k)
                    {
                        if (vvs2[i][k] == vvs1[j][k])
                        {
                            st = k + 1;
                            break;
                        }
                    }
                    map2[i * 100 + j] = st;
                }
            }
        }

        #ifdef __test
        for (pair<int, int> p : map2)
            cout<<p.first<<", "<<p.second<<endl;
        #endif // __test
        string ans = dfsb1(words, bs, words.size(), "", -1, map2);
        return ans;
    }
    int mnlen = INT_MAX;
    string dfsb1(vector<string>& words, bitset<12>& bs, int remain, string s, int lstidx, unordered_map<int, int>& map2)
    {
//        if (bs.all())       // <12>....  or set(sz1, sz1+1 ... 11)
        if (remain == 0)
        {
            #ifdef __test
//            cout<<s.size()<<", "<<s<<endl;
            #endif // __test
            mnlen = min(mnlen, (int) s.size());
            return s;           // aaa + a +      aaab  ->  aaa + aaab    !->    a + aaab
        }
        if (s.size() > mnlen)
            return s;
        string lst = lstidx == -1 ? "" : words[lstidx];
        string ans;
        for (int i = 0; i < words.size(); ++i)
        {
            if (!bs.test(i))
            {
                bs.set(i);      // T
                int st = 0;

                if (map2.find(lstidx * 100 + i) != map2.end())
                    st = map2[lstidx * 100 + i];

                string s2 = s + words[i].substr(st);
                string s3 = dfsb1(words, bs, remain - 1, s2, i, map2);
                if (ans.empty() || ans.size() > s3.size())
                    ans = s3;
                bs.reset(i);        // F
            }
        }
        return ans;
    }



// 能贪心吗？
// tle... 加不加 map2 都一样，都是 57/83
// 先来个tle
    string lt0943a(vector<string>& words)
    {
        bitset<12> bs;
        unordered_map<int, int> map2;

        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = 0; j < words.size(); ++j)
            {
                if (i == j)
                    continue;
                int st = 0;
                for (int k = 1, mxk = min(words[i].size(), words[j].size()); k < mxk; ++k)
                {
                    for (int a = 0; a < k; ++a)
                    {
                        if (words[j][a] != words[i][words[i].size() - k + a])
                        {
                            goto BBB;
                        }
                    }
                    st = k;
                    BBB:
                    continue;
                }
                map2[i * 100 + j] = st;
            }
        }
        #ifdef __test
        for (pair<int, int> p : map2)
            cout<<p.first<<", "<<p.second<<endl;
        #endif // __test

        string ans = dfsa1(words, bs, words.size(), "", -1, map2);
        return ans;
    }
    string dfsa1(vector<string>& words, bitset<12>& bs, int remain, string s, int lstidx, unordered_map<int, int>& map2)
    {
//        if (bs.all())       // <12>....  or set(sz1, sz1+1 ... 11)
        if (remain == 0)
        {
            #ifdef __test
//            cout<<s.size()<<", "<<s<<endl;
            #endif // __test
            return s;           // aaa + a +      aaab  ->  aaa + aaab    !->    a + aaab
        }
        string lst = lstidx == -1 ? "" : words[lstidx];
        string ans;
        for (int i = 0; i < words.size(); ++i)
        {
            if (!bs.test(i))
            {
                bs.set(i);      // T
                int st = 0;

                if (map2.find(lstidx * 100 + i) != map2.end())
                    st = map2[lstidx * 100 + i];

//                for (int j = 1, mxj = min(lst.size(), words[i].size()); j < mxj; ++j)
//                {
//                    for (int a = 0; a < j; ++a)
//                    {
//                        if (words[i][a] != lst[lst.size() - j + a])
//                        {
//                            #ifdef __test
////                            cout<<"        "<<a<<", "<<words[i][a]<<", "<<lst[lst.size() - j + a]<<endl;
//                            #endif // __test
//                            goto AAA;
//                        }
//                    }
//                    st = j;
//                    AAA:            // 真得一个cache。
//                    continue;
////                    st++;
//                }
//                AAA:
                #ifdef __test
//                cout<<st<<endl;
                #endif // __test
                string s2 = s + words[i].substr(st);
                string s3 = dfsa1(words, bs, remain - 1, s2, i, map2);
                if (ans.empty() || ans.size() > s3.size())
                    ans = s3;
//                if (lst[lst.size()] == words[i][0])
//                {
//                    int t3 = 1;
//                    while ()
//                }
//                for (int j = 0)         // cache..
//                {
//
//                }
                bs.reset(i);        // F
            }
        }
        return ans;
    }

};

int main()
{
//    vector<string> vs = {"alex","loves","leetcode"};
    vector<string> vs = {"catg","ctaagt","gcta","ttca","atgcatc"};      // gctaagttcatgcatc   16

    LT0943 lt;

    cout<<lt.lt0943b(vs);

    return 0;
}
