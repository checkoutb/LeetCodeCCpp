
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //for (int j = i; j <= ssize - len; j += len) {
    //    string curr = s.substr(j, len);
    //
    //    if (freq.find(curr) != freq.end()) {
    //        tmp[curr]++;
    //        found++;
    // 
    // .....



    // 把 word 当作一个char ，开始 sliding window
    
    // 存在 不存在于 words中的，直接跳到后面




//Runtime: 564 ms, faster than 41.46 % of C++ online submissions for Substring with Concatenation of All Words.
//Memory Usage : 71.5 MB, less than 38.45 % of C++ online submissions for Substring with Concatenation of All Words.
    // .. 应该是trie。
    // [0,25] * 26 ^ {0-29}    < (2^5)^29  2^(5*29) ...
    vector<int> lta(string s, vector<string>& words)
    {
        if (s.size() < (words.size() * words[0].size()))
            return {};
        const long long MOD = 1e9 + 7;
        unordered_map<long long, vector<string>> map2;            // multimap...
        unordered_map<string, int> map3;
        int sz1 = words[0].size();
        for (string& ww : words)
        {
            map3[ww]++;
            if (map3[ww] > 1)
                continue;
            long long p = 31;
            long long key = 0LL;
            for (int i = 0; i < sz1; ++i)
            {
                key = (key + (ww[i] - 'a') * p) % MOD;
                p = (p * 31) % MOD;
            }
            map2[key].push_back(ww);
        }

#ifdef __test
        for (auto& p : map2)
        {
            cout << p.first << " : [";
            for (string& sa : p.second)
                cout << sa << ", ";
            cout << "]" << endl;
        }
#endif

        long long key = 0LL;
        long long p = 31;
        for (int i = s.size() - sz1; i < s.size(); ++i)
        {
            key = (key + (s[i] - 'a') * p) % MOD;
            p = (p * 31) % MOD;
        }
        vector<long long> vll(s.size());
        vll[s.size() - sz1] = key;
        for (int i = s.size() - sz1 - 1; i >= 0; --i)
        {
            key = (key + (s[i] - 'a')) * 31 % MOD;
            key = (key - (s[i + sz1] - 'a') * p % MOD + MOD) % MOD;
            vll[i] = key;
        }

#ifdef __test
        for (int i = 0; i < vll.size(); ++i)
        {
            cout << i << " - " << vll[i] << endl;
        }
#endif

        vector<int> ans;
        for (int i = 0; i <= (int) s.size() - int (words.size() * sz1); ++i)            // size_t(1) - size_t(2) > INT_MAX
        {
            unordered_map<string, int> map5;
            for (int j = 0; j < words.size(); ++j)
            {
                int st = i + j * sz1;
                long long key = vll[st];


                vector<string>& vs = map2[key];
                string ss = getsa1(vs, s, st);
#ifdef __test
                cout << i << ", " << j << " - " << st << " - " << key << " . " << vs.size() << " -- " << ss << endl;
#endif
                if (ss.empty())
                    goto AAA;

                map5[ss]++;
                if (map5[ss] > map3[ss])
                    goto AAA;
            }

            ans.push_back(i);

            AAA:
            continue;
        }
        return ans;
    }

    string getsa1(vector<string>& vs, string& s, int st)
    {
        if (vs.empty())
            return "";
        int sz1 = vs[0].size();
        vector<int> vi(vs.size());
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < vi.size(); ++j)
            {
                if (s[st + i] == vs[j][vi[j]])
                {
                    vi[j]++;
                }
            }
        }

#ifdef __test
        cout << " ---------------" << endl;
        for (int i : vi)
            cout << i << " --- ";
        cout << vs[0] << " ？ " << s << " -- " << st << endl;
        cout << " =======" << endl;
#endif

        for (int i = 0; i < vi.size(); ++i)
        {
            if (vi[i] == sz1)
                return vs[i];
        }
        return "";
    }
};

int main()
{

    LT lt;

    //string s = "barfoothefoobarman";
    //vector<string> vs = { "foo","bar" };

    //string s = "wordgoodgoodgoodbestword";
    //vector<string> vs = { "word","good","best","word" };

    //string s = "barfoofoobarthefoobarman";
    //vector<string> vs = {"foo","bar","the"};

    string s = "a";
    vector<string> vs = { "a", "a" };

    myvi v = lt.lta(s, vs);

    showVectorInt(v);

    cout << s.size() - vs.size() << endl;

    return 0;
}
