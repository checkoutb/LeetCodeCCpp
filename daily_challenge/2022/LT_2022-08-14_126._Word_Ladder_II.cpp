
#include "../../header/myheader.h"

class LT
{
public:

    // D


    // 不知道为什么tle， 看discuss中的 都差不多。。 bfs + dfs.   for('a' - 'z') 寻找diff 1.





    // tle
    vector<vector<string>> ltc(string beginWord, string endWord, vector<string>& wordList)
    {
        int sz1 = beginWord.size();
        int sz2 = wordList.size();
        int stidx = -1;
        int endidx = -1;

        for (int i = 0; i < sz2; ++i)
        {
            if (wordList[i] == beginWord)
            {
                stidx = i;
            }
            else if (wordList[i] == endWord)
            {
                endidx = i;
            }
        }
        if (stidx == -1)
        {
            wordList.push_back(beginWord);
            stidx = sz2++;
        }

        unordered_map<int, vector<int>> map2;

        for (int i = 1; i < sz2; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (isdiff1(wordList[i], wordList[j]))
                {
                    map2[i].push_back(j);
                    map2[j].push_back(i);
                }
            }
        }
        queue<int> que1;
        que1.push(stidx);

#ifdef __test
        cout << stidx << " .. " << endidx << endl;
        for (auto& p : map2)
        {
            cout << wordList[p.first] << ": [";
            for (int i : p.second)
                cout << wordList[i] << ", ";
            cout << endl;
        }
#endif
        
        int tm = 1;
        //unordered_map<string, int> map3;
        vector<int> vst(sz2, 0);
        //map3[beginWord] = tm;
        vst[stidx] = tm;
        bool notFind = true;
        unordered_map<int, vector<int>> map3;       // next string
        unordered_set<int> set5;

        while ((!que1.empty()) & notFind)
        {
            ++tm;
            set5.clear();
            for (int a = que1.size(); a > 0; --a)
            {
                int si = que1.front();
                if (si == endidx)
                {
                    notFind = false;
                    break;
                }
                que1.pop();
                for (int idx : map2[si])
                {
                    if (vst[idx] == 0 || vst[idx] == tm)
                    {
                        if (set5.find(si * 1000 + idx) != set5.end())
                            continue;
                        set5.insert(si * 1000 + idx);

                        vst[idx] = tm;
                        map3[si].push_back(idx);
                        que1.push(idx);
                    }
                }
            }
        }

#ifdef __test

        showVectorInt(vst);

        cout << " ========= " << endl;
        for (auto& p : map3)
        {
            cout << wordList[p.first] << " nxt:[";
            for (int v : p.second)
                cout << wordList[v] << ", ";
            cout << endl;
        }
#endif

        vector<vector<int>> ans = dfsc1(map3, wordList, stidx, endidx);

        //cout << ans.size() << endl;

        vector<vector<string>> vvs;
        for (vector<int>& vi : ans)
        {
            reverse(begin(vi), end(vi));

#ifdef __test
            cout << " ?????? " << endl;
            showVectorInt(vi);
#endif

            vector<string> vs(vi.size());
            for (int i = 0; i < vi.size(); ++i)
            {
                vs[i] = wordList[vi[i]];
            }
            vvs.push_back(vs);
        }
        return vvs;
    }

    vector<vector<int>> dfsc1(unordered_map<int, vector<int>>& map2, vector<string>& vs, int idx, int endidx)
    {
        if (map2.find(idx) == map2.end())
        {
            if (idx == endidx)
            {
#ifdef __test
                cout << idx << " =================== " << endl;
#endif
                return { {idx} };
            }
            return {};
        }
        vector<vector<int>> ans;
        for (int nxt : map2[idx])
        {
            vector<vector<int>> vvs = dfsc1(map2, vs, nxt, endidx);
            for (vector<int>& vs : vvs)
            {
                vs.push_back(idx);
                ans.push_back(vs);
            }
        }

#ifdef __test
        cout << idx << "        , " << ans.size() << endl;
#endif

        return ans;
    }

    bool isdiff1(string& s, string& t)
    {
        int df = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != t[i])
            {
                if (df == 1)
                    return false;
                df++;
            }
        }
        return df == 1;
    }



    // tle。。。
    vector<vector<string>> ltb(string beginWord, string endWord, vector<string>& wordList)
    {
        int sz1 = beginWord.size();
        int sz2 = wordList.size();

        unordered_set<string> set2(begin(wordList), end(wordList));

        unordered_map<string, pair<int, vector<string>>> map2;

        queue<string> que1;
        que1.push(beginWord);
        int tm = 0;
        if (set2.find(beginWord) != set2.end())
        {
            //vector<int> vi;
            map2[beginWord].first = tm++;
            map2[beginWord].second = {};
        }
        bool notFind = true;
        unordered_set<string> set5;
        while (!que1.empty() && notFind)
        {
            ++tm;
            set5.clear();
            for (int a = 0, mxa = que1.size(); a < mxa; ++a)
            {
                string s = que1.front();
                if (s == endWord)
                {
                    notFind = false;
                    break;
                }
                que1.pop();
                string s2 = s;
                for (int i = 0; i < sz1; ++i)
                {
                    char ch = s[i];
                    for (char j = 'a'; j <= 'z'; ++j)
                    {
                        if (j == ch)
                            continue;
                        s[i] = j;
                        if (set2.find(s) != set2.end())
                        {
                            if (map2.find(s) == map2.end() || map2[s].first == tm)
                            {
                                if (set5.find(s + "-" + s2) != set5.end())
                                    continue;

                                map2[s].first = tm;
                                map2[s].second.push_back(s2);
                                que1.push(s);

                                set5.insert(s + "-" + s2);
                            }
                        }
                    }
                    s[i] = ch;
                }

            }
        }
        if (notFind)
            return { };

        unordered_map<string, vector<string>> map5;
        for (auto& p : map2)
        {
            for (string& s : p.second.second)
            {
                map5[s].push_back(p.first);
            }
        }

        vector<vector<string>> ans = dfsb1(map5, beginWord, endWord);
        for (vector<string>& vs : ans)
            std::reverse(begin(vs), end(vs));
        return ans;
    }

    vector<vector<string>> dfsb1(unordered_map<string, vector<string>>& map5, string& s, string& en)
    {
        if (map5.find(s) == map5.end())
        {
            if (s == en)
                return { {s} };
            return {};
        }

        vector<vector<string>> ans;

        for (string& s2 : map5[s])
        {
            vector<vector<string>> vvs = dfsb1(map5, s2, en);
            for (vector<string>& vs : vvs)
            {
                vs.push_back(s);
                ans.push_back(vs);
            }
        }
        return ans;
    }


    // 5 * 25 .
    vector<vector<string>> lta(string beginWord, string endWord, vector<string>& wordList)
    {
        int sz1 = beginWord.size();
        int sz2 = wordList.size();

        //unordered_set<string>  set2(begin(wordList), end(wordList));

        unordered_map<string, int> map3;
        for (int i = 0; i < sz2; ++i)
        {
            map3[wordList[i]] = i;
        }

        unordered_map<int, pair<int, vector<int>>> map2;            // <idx, <time, last word>>

        queue<string> que1;
        que1.push(beginWord);
        
        if (map3.find(beginWord) != map3.end())
            map2[map3[beginWord]];


    }


};

int main()
{

    LT lt;

    string st = "hit";
    string en = "cog";
    vector<string> vs = { "hot","dot","dog","lot","log","cog" };

    //string st = "a";
    //string en = "c";
    //vector<string> vs = { "a", "b", "c" };

    //string st = "red";
    //string en = "tax";
    //vector<string> vs = { "ted", "tex", "red", "tax", "tad", "den", "rex", "pee" };


    vector<vector<string>> vvs = lt.ltc(st, en, vs);

    cout << vvs.size() << endl;
    for (vector<string>& vs : vvs)
    {
        for (string& s : vs)
            cout << s << " + ";
        cout << endl;

    }

    return 0;
}
