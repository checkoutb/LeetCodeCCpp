
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //String next = sb.deleteCharAt(i).toString();

    //string pre = w.substr(0, i) + w.substr(i + 1);

    //for (int size = 16; size > 0; --size) {
    //    for (int word_i : w[size]) {
    //        dp[word_i] = 1;
    //        for (int word_j : w[size + 1]) {
    //            if (words_differ_by_one(words[word_i], words[word_j])) {
    //                dp[word_i] = max(dp[word_i], 1 + dp[word_j]);
    //                ans = max(ans, dp[word_i]);
    //            };
    //        }
    //    }
    //}




//Runtime: 105 ms, faster than 74.46 % of C++ online submissions for Longest String Chain.
//Memory Usage : 24.9 MB, less than 25.27 % of C++ online submissions for Longest String Chain.
    // sz, sort, str
    int lta(vector<string>& words)
    {
        unordered_map<string, vector<string>> map2;
        map<int, vector<string>> map3;
        for (int i = 0; i < words.size(); ++i)
        {
            string s = words[i];
            sort(begin(s), end(s));
            map2[s].push_back(words[i]);
            map3[(int)s.size()].push_back(s);
        }
        //vector<int> vi(words.size());
        unordered_map<string, int> map5;
        for (map<int, vector<string>>::iterator it = map3.begin(); it != map3.end(); it++)
        {
            int k = it->first;
            vector<string>& v = it->second;
            vector<string>& vn = map3[k - 1];
            if (!vn.empty())
                for (string& s : v)
                {
                    for (string sn : vn)
                    {
#ifdef __test
                        //cout << sn << ", " << s << endl;
#endif
                        if (predecessor(sn, s))
                        {
                            for (string& ss1 : map2[s])
                            {
                                for (string& ss2 : map2[sn])
                                {
                                    if (predecessor(ss2, ss1))
                                        map5[ss1] = max(map5[ss1], map5[ss2] + 1);
                                }
                            }
                            //map5[s] = max(map5[s], map5[sn] + 1);
                        }
                    }
                }
        }
        int ans = 0;
        for (auto& p : map5)
        {
            ans = max(ans, p.second);
        }
        return ans + 1;
    }
    bool predecessor(string& pre, string& nxt)
    {
        bool skip = false;
        int i = 0;
        for (int pi = 0; pi < pre.size(); ++i, ++pi)
        {
            if (pre[pi] != nxt[i])
            {
                if (skip)
                    return false;
                skip = true;
                pi--;
            }
        }
        return true;

        //bool skip = false;
        //int pi = 0;
        //for (int i = 0; i < nxt.size(); ++i. ++pi)
        //{
        //    if (pre[pi] != nxt[i])
        //    {
        //        if (skip)
        //            return false;
        //        skip = true;
        //        pi--;
        //    }
        //}
        //return skip;
    }

};

int main()
{

    LT lt;

    vector<string> vs = { "a","b","ba","bca","bda","bdca" };

    //vector<string> vs = { "xbc","pcxbcf","xb","cxbc","pcxbc" };

    //vector<string> vs = { "abcd","dbqca" };

    cout << lt.lta(vs) << endl;

    return 0;
}
