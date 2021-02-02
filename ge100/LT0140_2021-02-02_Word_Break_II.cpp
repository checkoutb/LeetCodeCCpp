
#include "../header/myheader.h"

class LT0140
{
public:

// D

//Using DFS directly will lead to TLE, so I just used HashMap to save the previous results to prune duplicated branches, as the following:
// List<String> DFS(String s, Set<String> wordDict, HashMap<String, LinkedList<String>>map)
//    for (String word : wordDict) {
//        if (s.startsWith(word)) {
//            List<String>sublist = DFS(s.substring(word.length()), wordDict, map);
//            for (String sub : sublist)
//                res.add(word + (sub.isEmpty() ? "" : " ") + sub);
//        }
//    }

//    unordered_map<int, vector<string>> memo {{s.size(), {""}}};
//    function<vector<string>(int)> sentences = [&](int i) {
//        if (!memo.count(i))
//            for (int j=i+1; j<=s.size(); j++)
//                if (wordDict.count(s.substr(i, j-i)))
//                    for (string tail : sentences(j))
//                        memo[i].push_back(s.substr(i, j-i) + (tail=="" ? "" : ' ' + tail));
//        return memo[i];
//    };
//    return sentences(0);


// tle.
    vector<string> lt0140b(string s, vector<string>& wordDict)
    {
        unordered_map<char, unordered_map<int, unordered_set<string>>> map2;      // substr[0] : <wordDict[?]'s length : wordDicts>
        for (string& word : wordDict)
            map2[word[0]][word.size()].insert(word);
        vector<int> vi;
        vi.push_back(0);
        dfsb1(s, vi, 0, map2);
        return ans2;
    }
    vector<string> ans2;
    void dfsb1(string& s, vector<int>& vi, int idx, unordered_map<char, unordered_map<int, unordered_set<string>>>& map2)
    {
        if (idx == s.size())
        {
            string ss;
            for (int i = 0; i < vi.size() - 1; ++i)
            {
                if (i != 0)
                    ss += " ";
                ss += s.substr(vi[i], vi[i + 1] - vi[i]);
            }
            ans2.push_back(ss);
            return;
        }
        unordered_map<int, unordered_set<string>>& map3 = map2[s[idx]];
        for (unordered_map<int, unordered_set<string>>::iterator it = map3.begin(); it != map3.end(); it++)
        {
            int len = it->first;
            string subs = s.substr(idx, len);
            if (it->second.find(subs) != it->second.end())
            {
                vi.push_back(idx + len);
                dfsb1(s, vi, idx + len, map2);
                vi.pop_back();
            }
        }
    }



// tle....  "aaaaaaa...aa"  {"a","aaa","aaaaa"...}
// Trie, but ...
    vector<string> lt0140a(string s, vector<string>& wordDict)
    {
        unordered_set<string> set2(begin(wordDict), end(wordDict));
        vector<int> vi;
        vi.push_back(0);
        dfsa1(s, vi, 0, set2);

        return ans;
    }
    vector<string> ans;

    void dfsa1(string s, vector<int>& vi, int idx, unordered_set<string>& words)
    {
        if (idx == s.size())
        {
            vi.push_back(s.size());
            string ss;
            for (int i = 0; i < vi.size() - 2; ++i)
            {
                if (i != 0)
                    ss += " ";
                ss += s.substr(vi[i], vi[i + 1] - vi[i]);
            }
            vi.pop_back();
            ans.push_back(ss);
            return;
        }
        for (int i = 1; i <= s.size() - idx; ++i)
        {
            string ss = s.substr(idx, i);
            if (words.find(ss) != words.end())
            {
                vi.push_back(idx + i);
                dfsa1(s, vi, idx + i, words);
                vi.pop_back();
            }
        }
    }

};

int main()
{

//    string s{"catsanddog"};
//    vector<string> vs = {"cat", "cats", "and", "sand", "dog"};

//    string s{"pineapplepenapple"};
//    vector<string> vs = {"apple", "pen", "applepen", "pine", "pineapple"};

    string s{"catsandog"};
    vector<string> vs = {"cats", "dog", "sand", "and", "cat"};

    LT0140 lt;

    vector<string> vs2 = lt.lt0140b(s, vs);
    for (string& s : vs2)
        cout<<s<<","<<endl;

    return 0;
}
