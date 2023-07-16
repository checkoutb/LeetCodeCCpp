
#include "../../header/myheader.h"

class LT6924
{
public:



// substr ... feichang kuai.

    // 1811 / 24477	Ouha 	11	0:20:44	0:02:58 	0:10:52 	0:20:44

    // TLE. * 3

    // ganjue kending tle.. dan xiangbuchu a
    int longestValidSubstring(string word, vector<string>& forbidden)
    {
//        set<long long> set2;
//        int mxsz = 0;
//        vector<set<long long>> vsll(11);
//        for (string& s : forbidden)
//        {
//            if (s.size() > mxsz)
//                mxsz = s.size();
//
//            long long t2 = 0LL;
//            for (int i = 0; i < s.size(); ++i)
//            {
//                t2 *= 27;
//                t2 += (s[i] - 'a' + 1);
//            }
//            vsll[s.size()].insert(t2);
//        }
        int sz1 = word.size();
//        vector<long long> vll(mxsz + 1);
//        vll[0] = 1LL;
//        for (int i = 1; i < vll.size(); ++i)
//        {
//            vll[i] = 27LL * vll[i - 1];
//        }
        long long t2 = 0LL;
        vector<pair<int, int>> vp;
//        for (int i = 0; i < sz1; ++i)
//        {
//            t2 *= 27LL;
//            t2 += word[i] - 'a' + 1;
//            t2 %= vll[vll.size() - 1];
////            for (int j = mxsz; j >= 1; --j)
//            for (int j = 1; j <= mxsz; ++j)
//            {
//                if (vsll[j].find(t2 % vll[j]) != vsll[j].end())
//                {
//                    vp.push_back(std::make_pair(i - j + 1, i));      // forbid [st, en]
//                }
//            }
//        }

        sort(begin(forbidden), end(forbidden));

//        for (string& s : forbidden)
        for (int i = 0; i < forbidden.size(); ++i)
        {
            if (i != 0)
            {
                if (forbidden[i].find(forbidden[i - 1]) == 0)
                    continue;
            }
            string& s = forbidden[i];
            int st = 0;
            while (st < word.size())
            {
                st = word.find(s, st);
                if (st == std::string::npos)
                    break;

                vp.push_back(std::make_pair(st, st + s.size() - 1));
                ++st;
            }
        }

        if (vp.empty())
        {
            return sz1;
        }

        sort(begin(vp), end(vp), [](pair<int, int>& p1, pair<int, int>& p2){
            if (p1.first == p2.first)
            {
                return p1.second > p2.second;
            }
            else
            {
                return p1.first < p2.first;
            }
        });
        #ifdef __test
        for (auto& p : vp)
        {
            cout<<p.first<<" : "<<p.second<<endl;
        }
        #endif // __test

        vector<int> vi(vp.size());
        vi[vi.size() - 1] = vp[vp.size() - 1].second;

        for (int i = vp.size() - 2; i >= 0; --i)
        {
            vi[i] = min(vi[i + 1], vp[i].second);
        }

        int ans = 0;
        int en = -1;
        for (int i = 0; i < vp.size(); ++i)
        {

            t2 = vi[i] - en - 1;
            if (t2 > ans)
                ans = t2;

            if (vp[i].first > en)
                en = vp[i].first;
        }
        ans = max(ans, sz1 - en - 1);
        return ans;
    }

};

int main()
{

    LT6924 lt;

//    string w = "cbaaaabc";
//    vector<string> vs = {"aaa","cb"};

//    string w = "leetcode";
//    vector<string> vs = {"de","le","e"};

//    string w = "bcbcb";
//    vector<string> vs = {"cbbbb","bcbcb", "cbc", "bcb"};        // 2

    string w = "a";
    vector<string> vs = {"n"};

    cout<<lt.longestValidSubstring(w, vs)<<endl;

    return 0;
}
