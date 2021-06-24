
#include "../header/myheader.h"

class LT0127
{
public:

// D D

// 68ms
// begin + end + list 转为 unordered_set， 组个queue{for i<qsize} 然后 每个位置26个字符替换， 去set里找，找到就erase。






//Runtime: 392 ms, faster than 42.94% of C++ online submissions for Word Ladder.
//Memory Usage: 28.4 MB, less than 18.93% of C++ online submissions for Word Ladder.
    int lt0127a(string beginWord, string endWord, vector<string>& wordList)
    {
        int sz1 = wordList.size();
        unordered_map<string, vector<string>> map2;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = i + 1; j < sz1; ++j)
            {
                if (isDifferOnea1(wordList[i], wordList[j]))
                {
                    map2[wordList[i]].push_back(wordList[j]);
                    map2[wordList[j]].push_back(wordList[i]);
                }
            }
        }
//        bitset<5000>
//        vector<bool> visit(sz1, false);
        unordered_set<string> visit;
        vector<string> vs;
        if (map2.find(beginWord) != map2.end())
        {
            vs = map2[beginWord];
            for (int i = 0; i < vs.size(); ++i)
            {
                if (vs[i] == endWord)
                    return 2;
            }
        }
        else
        {
            for (int i = 0; i < sz1; ++i)
            {
                if (isDifferOnea1(beginWord, wordList[i]))
                {
                    if (wordList[i] == endWord)
                        return 2;
                    vs.push_back(wordList[i]);
                }
            }
        }
        int cnt = 2;

        while (!vs.empty())
        {
            cnt++;
            vector<string> vs2;
            for (string& s : vs)
            {
                for (string& ss : map2[s])
                {
                    if (visit.insert(ss).second)
                    {
                        if (ss == endWord)
                            return cnt;
                        vs2.push_back(ss);
                    }
//                    if (!visit[])
                }
            }

            swap(vs, vs2);
        }

        return 0;
    }

    bool isDifferOnea1(string& s1, string& s2)
    {
        int diff = 0;
        for (int i = 0; i < s1.size(); ++i)
        {
            if (s1[i] != s2[i])
            {
                if (diff != 0)
                {
                    return false;
                }
                diff++;
            }
        }
        return diff == 1;
    }

};

int main()
{

//    string st = "hit";
//    string en = "cog";
//    vector<string> vs = {"hot","dot","dog","lot","log"};

    string st = "a";
    string en = "c";
    vector<string> vs = {"a","b","c"};

    LT0127 lt;

    cout<<lt.lt0127a(st, en, vs);

    return 0;
}
