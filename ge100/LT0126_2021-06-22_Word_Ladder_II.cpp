
#include "../header/myheader.h"

class LT0126
{
public:

// D










// tle....
    // 那就 dfs吧
    vector<vector<string>> lt0126b(string beginWord, string endWord, vector<string>& wordList)
    {
        vector<vector<string>> ans;
        unordered_set<string> set2(begin(wordList), end(wordList));
        if (set2.find(endWord) == set2.end())
            return ans;

        int cnt = 1;
        queue<string> que1;
        que1.push(beginWord);
//        int len = 0;
        while (!que1.empty())
        {
            cnt++;
            int szq = que1.size();
            while (szq-- > 0)
            {
                string ss = que1.front();
                que1.pop();
                for (int i = 0; i < ss.size(); ++i)
                {
                    char orich = ss[i];
                    for (char ch = 'a'; ch <= 'z'; ch++)
                    {
                        if (ch == orich)
                            continue;
                        ss[i] = ch;
                        if (ss == endWord)
                            goto AAA;
                        if (set2.find(ss) == set2.end())
                            continue;
                        que1.push(ss);
                    }
                    ss[i] = orich;
                }
            }
        }
        return ans;

        AAA:
        #ifdef __test
        cout<<cnt<<endl;
        #endif // __test

        unordered_set<string> all(begin(wordList), end(wordList));
        unordered_set<string> vis;
        ans = dfsb1(all, vis, cnt, beginWord, endWord, cnt);

        #ifdef __test
        cout<<"ans.... "<<ans.size()<<endl;
        #endif // __test

        return ans;
    }

    vector<vector<string>> dfsb1(unordered_set<string>& all, unordered_set<string>& vis, int depth, string& s, string& tar, int cnt)
    {
        if (depth == 1)
        {
            if (s == tar)
            {
                #ifdef __test
                cout<<"got"<<endl;
                #endif // __test
                vector<vector<string>> ans(1, vector<string>(cnt));
                ans[0][cnt - depth] = tar;
                return ans;
            }
            return vector<vector<string>>();
//            return nullptr;       // connot convert
        }
        vector<vector<string>> ans;
        string origs = s;
        for (int i = 0; i < s.size(); ++i)
        {
            char orich = s[i];
            for (char ch = 'a'; ch <= 'z'; ++ch)
            {
                if (orich == ch)
                    continue;
                s[i] = ch;
                if (all.find(s) == all.end())
                {
                    continue;
                }
                if (vis.find(s) != vis.end())
                {
                    continue;
                }
                vis.insert(s);
                vector<vector<string>> vvs = dfsb1(all, vis, depth - 1, s, tar, cnt);
                if (!vvs.empty())
                {
                    for (vector<string>& vs : vvs)
                    {
                        vs[cnt - depth] = origs;
                        ans.push_back(vs);              // move ? emplace_back ?
                    }
                }
                vis.erase(s);
            }
            s[i] = orich;
        }
        return ans;
    }


// tle...
// bfs的话， 需要map<string, order> 而且感觉数据量会很大。。 不过长度是5.。。
// 更想： Word Ladder 计算出 最短长度，  然后dfs， 如果可以就 return vector<int>  不能就return nullptr。 外层再根据 内层的返回 决定是否 把自己加进去。
    vector<vector<string>> lt0126a(string beginWord, string endWord, vector<string>& wordList)
    {
        vector<vector<string>> ans;
        unordered_set<string> set2(begin(wordList), end(wordList));
        if (set2.find(endWord) == set2.end())
            return ans;

        int cnt = 1;
        queue<pair<string, unordered_map<string, int>>> que1;
//        unordered_map<string, int>
//        que1.push(std::make_pair(beginWord, unordered_map<string, int>({beginWord, 1})));

        unordered_map<string, int> msi = {{beginWord, 1}};
        que1.push(std::make_pair(beginWord, msi));

        bool got = false;
        while (!que1.empty() && !got)
        {
            cnt++;
            int szq = que1.size();
            while (szq-- > 0)
            {
                auto p = que1.front();
                que1.pop();
                string ss = p.first;
                unordered_map<string, int> map4 = p.second;
                for (int i = 0; i < ss.size(); ++i)
                {
                    string sss = ss;
                    for (char ch = 'a'; ch <= 'z'; ++ch)
                    {
                        if (ss[i] == ch)
                            continue;
                        sss[i] = ch;
                        if (sss == endWord)
                        {
                            got = true;
                            vector<string> vs(map4.size() + 1);
                            for (auto& p : map4)
                            {
//                                cout<<p.first<<", "<<p.second<<endl;
                                vs[p.second - 1] = p.first;
                            }
                            vs[vs.size() - 1] = sss;
                            ans.push_back(vs);
                        }
                        if (!got)
                        {
                            if (set2.count(sss) == 0)       // 必须==0, 估计size_type转bool 的原因。
                                continue;
                            if (map4.find(sss) != map4.end())
                                continue;
                            unordered_map<string, int> map5(begin(map4), end(map4));
                            map5[sss] = cnt;
                            que1.push(std::make_pair(sss, map5));
                        }
                    }
                }
            }

        }

        return ans;
    }

};

int main()
{
    string st = "hit";
    string en = "cog";
    vector<string> vs = {"hot","dot","dog","lot","log","cog"};

    LT0126 lt;

    vector<vector<string>> vvs = lt.lt0126b(st, en, vs);

    for (vector<string>& vs : vvs)
    {
        for (string& s : vs)
            cout<<s<<" -> ";
        cout<<endl;
    }

    return 0;
}
