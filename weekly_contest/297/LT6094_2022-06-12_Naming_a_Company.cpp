
#include "../../header/myheader.h"

class LT6094
{
public:



//Rank	        Name	Score	Finish Time 	Q1 (3)	    Q2 (5)	    Q3 (5)	    Q4 (6)
//1205 / 23263	Ouha 	13	    0:32:29	        0:11:40 	0:24:14 	0:32:29


// g


// 应该头尾分开。
// abbb
// bbbb
// cbbb
//
// zbbb
// abbb ,, 我不和 a？？ 的换，    也不和 ?bbb 的 换，  其他都可以。

//- ("coffee", "donuts"): The company name created is "doffee conuts".
//- ("donuts", "coffee"): The company name created is "conuts doffee".
//. .. shunxu...

    long long distinctNames(vector<string>& ideas)
    {
        long long ans = 0LL;
        unordered_map<char, int> map2;
        unordered_map<string, int> map3;
        unordered_set<string> set2(begin(ideas), end(ideas));

        for (string& s : ideas)
        {
            map2[s[0]]++;
            string s2 = s.substr(1);
            map3[s2]++;
        }

        #ifdef __test
        for (auto& p : map2)
        {
            cout<<p.first<<" : "<<p.second<<endl;
        }
        cout<<" ---------- "<<endl;
        for (auto& p : map3)
        {
            cout<<p.first<<" -> "<<p.second<<endl;
        }
        cout<<" -======"<<endl;
        #endif // __test

        int sz1 = ideas.size();
        for (int i = 0; i < ideas.size(); ++i)
        {
            string& s = ideas[i];
            char ch = s[0];
            string s2 = s.substr(1);
            for (char c = 'a'; c <= 'z'; ++c)
            {
                if (c == ch)
                    continue;

                s[0] = c;
                if (map2.find(c) == map2.end())
                    continue;

                if (set2.find(s) == set2.end())
                {

//                    ans += (sz1 - 1 - map2[ch] - map3[s2] + 1 + 1);
                    ans += map2[c];
                }
            }
            s[0] = ch;

//            string& s = ideas[i];
//            char ch = s[0];
//            string s2 = s.substr(1);
//            ans += (sz1 - 1 - map2[ch] - map3[s2] + 1 + 1);     // coffee + time -> toffee
//
//            #ifdef __test
//            cout<<i<<", "<<ch<<", "<<s2<<", "<<map2[ch]<<", "<<map3[s2]<<" ,,,,, "<<(sz1 - 1 - map2[ch] - map3[s2] + 1 + 1)<<endl;
//            #endif // __test
//
//            for (char c = 'a'; c <= 'z'; ++c)
//            {
//                if (c == ch)
//                    continue;
//
//                s2[0] = c;
//
//            }

        }

        return ans;
    }


// tle 输一半 / 赢一半。。。
// ok . i know it ...  swap first char ,, but there are only 26 chars [a-z] .. not for (all other ideas) { }
// both new name are not found . ..还是得 for for 啊。
// 先来个 tle ... return long long ... wo ++ +dao jishi ....
    long long distinctNamesa(vector<string>& ideas)
    {
        long long ans = 0LL;
        unordered_set<string> set2(begin(ideas), end(ideas));
        unordered_map<char, vector<string>> map2;

        for (string& s : ideas)
        {
            map2[s[0]].push_back(s);
        }

        for (int i = 0; i < ideas.size(); ++i)
        {
            string s2 = ideas[i];
            char ori = s2[0];
            for (char ch = 'a'; ch <= 'z'; ++ch)
            {
                if (ori == ch)
                    continue;

                s2[0] = ch;
                if (set2.find(s2) != set2.end())
                    continue;

                vector<string>& vs = map2[ch];

                for (int j = 0; j < vs.size(); ++j)
                {
                    string s3 = vs[j];
                    s3[0] = ori;
                    if (set2.find(s3) == set2.end())
                    {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }


};

int main()
{

    LT6094 lt;

    vector<string> vs = {"coffee","donuts","time","toffee"};
//    vector<string> vs = {"lack","back"};

    cout<<lt.distinctNames(vs)<<endl;

    return 0;
}
