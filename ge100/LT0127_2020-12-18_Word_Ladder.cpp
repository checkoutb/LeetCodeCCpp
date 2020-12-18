
#include "../header/myheader.h"

class LT0127
{
public:

// D D

//                for (int i = 0; i < word.size(); ++i){
//                    string newWord = word;
//                    for (char ch = 'a'; ch <= 'z'; ++ch){
//                        newWord[i] = ch;
//                        if (wordSet.count(newWord) && newWord != word){
//                            q.push(newWord);
//                            wordSet.erase(newWord);
//                        }
//                    }
//                }
// ... zhe...
// 100ms ..  构建map3 这么耗时么， 可能是测试案例中  不在转换序列 中的 string 太太太多了。。






//Runtime: 836 ms, faster than 19.33% of C++ online submissions for Word Ladder.
//Memory Usage: 19.8 MB, less than 27.05% of C++ online submissions for Word Ladder.
    int lt0127a(string beginWord, string endWord, vector<string>& wordList)
    {
//        vector<int> v(wordList.size());
        unordered_map<string, int> map2;
        unordered_map<string, vector<int>> map3;
        bool hasEnd = false;
        bool hasBegin = false;
        for (string& s : wordList)
        {
            if (s == beginWord)
            {
                hasBegin = true;
                break;
            }
        }
        if (!hasBegin)
            wordList.push_back(beginWord);              //
        for (int i = 0; i < wordList.size(); ++i)
        {
            string& s1 = wordList[i];
            if (s1 == endWord)
                hasEnd = true;
            for (int j = i + 1; j < wordList.size(); ++j)
            {
                if (isDiff1a1(s1, wordList[j]))
                {
                    map3[s1].push_back(j);
                    map3[wordList[j]].push_back(i);
                }
            }
        }
        #ifdef __test
        for (auto& p : map3)
        {
            cout<<p.first<<" : ";
            for (int i : p.second)
                cout<<wordList[i]<<", ";
            cout<<endl;
        }
        #endif // __test

        if (!hasEnd)
            return 0;

        queue<string> que1;
        que1.push(beginWord);
        map2[beginWord] = 0;
        int ans = 0;
        int ans2 = 0;
        while (!que1.empty())
        {
            ans++;
            int sz1 = que1.size();
            while (sz1-- > 0)
            {
                string s = que1.front();
                que1.pop();
                if (s == endWord)
                {
                    ans2 = ans;
                    goto AAA;
                }
                vector<int> nxt = map3[s];
                for (int i : nxt)
                {
                    if (map2.find(wordList[i]) == map2.end())
                    {
                        map2[wordList[i]] = 0;
                        que1.push(wordList[i]);
                    }
                }
            }
        }
        AAA:
        return ans2;
    }
    bool isDiff1a1(string& s1, string& s2)
    {
        int cnt = 0;
        for (int i = 0; i < s1.size(); ++i)
        {
            cnt += (s1[i] != s2[i]);
        }
        return cnt == 1;
    }

};

int main()
{
    string s{"hit"}, e{"cog"};
    vector<string> vs = {"hot","dot","dog","lot","log","cog"};

    LT0127 lt;

    cout<<lt.lt0127a(s,e,vs);

    return 0;
}
