
#include "../header/myheader.h"

class LT0140
{
public:

    // D D

    //unordered_map<int, vector<string>> memo{ {s.size(), {""}} };
    //function<vector<string>(int)> sentences = [&](int i) {
    //    if (!memo.count(i))
    //        for (int j = i + 1; j <= s.size(); j++)
    //            if (wordDict.count(s.substr(i, j - i)))
    //                for (string tail : sentences(j))
    //                    memo[i].push_back(s.substr(i, j - i) + (tail == "" ? "" : ' ' + tail));
    //    return memo[i];
    //};
    //return sentences(0);


    //// DFS function returns an array including all substrings derived from s.
    //List<String> DFS(String s, Set<String> wordDict, HashMap<String, LinkedList<String>>map) {
    //    if (map.containsKey(s))
    //        return map.get(s);


//Runtime: 3 ms, faster than 44.50 % of C++ online submissions for Word Break II.
//Memory Usage : 7.1 MB, less than 95.36 % of C++ online submissions for Word Break II.
    // ”≤À„£¨Trie£¨dp(?)
    vector<string> lt0140a(string s, vector<string>& wordDict)
    {
        unordered_set<string> set2(begin(wordDict), end(wordDict));
        vector<int> vidx;
        vector<string> ans;
        dfsa1(s, 0, set2, ans, vidx);
        return ans;
    }

    void dfsa1(string& s, int idx, unordered_set<string>& set2, vector<string>& ans, vector<int>& vidx)
    {
        if (idx == s.size())
        {
            string s2 = s;
            int st = 0;
//#ifdef __test
//            cout << &s2 << ", " << &s << endl;
//            showVectorInt(vidx);
//#endif
            for (int i = 0; i < vidx.size() - 1; ++i)
            {
                st = vidx[i] + i;
                s2.insert(st, " ", 1);
                st++;
            }
            ans.push_back(s2);
            return;
        }
        for (int i = idx + 1; i <= s.size(); ++i)
        {
            string sub = s.substr(idx, (i - idx));
            if (set2.find(sub) != end(set2))
            {
                vidx.push_back(i);          // .
                dfsa1(s, i, set2, ans, vidx);
                vidx.pop_back();
            }
        }
    }

};

int main()
{

    LT0140 lt;

    string s = "catsanddog";
    vector<string> vs = { "cat","cats","and","sand","dog" };

    vector<string> ans = lt.lt0140a(s, vs);

    for (string& s : ans)
        cout << s << endl;

    return 0;
}
