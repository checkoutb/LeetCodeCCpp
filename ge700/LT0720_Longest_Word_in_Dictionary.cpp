
#include "../header/myheader.h"

class LT0720
{
public:



// discuss
// sort, new set, 遍历words，如果长度为1或 new set 中包含word[0:-1]，加入到new set，判断word的长度是否大于ans.length。

// static class TrieNode {  java static inner class...


// return string{};
// word_set.find(word.substr(0, i)) == word_set.end()
// 自定义排序：长度降序，相同长度则字典顺序升序。for循环，每个word，i从size-1->1. 如果都存在，就return word。




// std::basic_string  starts_with (C++20)



//Runtime: 252 ms, faster than 5.07% of C++ online submissions for Longest Word in Dictionary.
//Memory Usage: 21.3 MB, less than 60.00% of C++ online submissions for Longest Word in Dictionary.
    string lt0720b(vector<string>& words)
    {
        sort(words.begin(), words.end());

        #ifdef __test
        for_each(words.begin(), words.end(), fun_cout_s);
        cout<<endl;
        #endif // __test

        map<int, vector<string>> map2;
        queue<string> que2;
//        int maxsz1 = 0;
        string ans;
        int anssz1 = -1;
        for (string s : words)
        {
            map2[s.size()].push_back(s);
//            maxsz1 = std::max(maxsz1, (int) s.size());
            if (s.size() == 1)
            {
                if (anssz1 == -1)           // =-1....
                {
                    anssz1 = 1;
                    ans = s;
                }
                que2.push(s);
            }
        }

        while (!que2.empty())
        {
            string& s = que2.front();

            #ifdef __test
            cout<<". "<<s<<endl;
            #endif // __test

            int i = s.size();
            vector<string>& vs2 = map2[i + 1];
            if (vs2.empty())
            {
                que2.pop();
                break;
            }
            for (string& s2 : vs2)
            {
                int j = 0;
                for (; j < i; j++)
                {
                    if (s2[j] != s[j])
                        break;
                }
                if (j == i)
                {
                    #ifdef __test
                    cout<<".    "<<s2<<", "<<i<<", "<<anssz1<<endl;
                    #endif // __test
                    que2.push(s2);
                    if (i + 1 > anssz1)
                    {
                        #ifdef __test
                        cout<<" .  "<<ans<<", "<<s2<<endl;
                        #endif // __test
                        anssz1 = i + 1;
                        ans = s2;
                    }
                }
            }
            que2.pop();         // 在 #endif 后面 直接pop，会错报：head-use-after-free。
        }
        return ans;
    }


// 得用trie，只要构建出trie，最深的第一个就是结果。
    string lt0720a(vector<string>& words)
    {
        map<int, vector<string>> map2;
        for (string s : words)
        {
            map2[s.size()].push_back(s);
        }

    }

    string dfsa1(map<int, vector<string>>& map2, string word)
    {
        vector<string>& vs2 = map2[word.size() + 1];
        for (string& s : vs2)
        {

        }
    }


};

int main()
{

// 字典顺序
//    vector<string> vs1 = {"abcde","bbcde","abcdef","abcd","a"};
//    sort(vs1.begin(), vs1.end());
//    for_each(vs1.begin(), vs1.end(), fun_cout_s);
//    cout<<endl;

//    vector<string> vs = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
//    vector<string> vs = {"w","wo","wor","worl", "world"};
//    vector<string> vs = {"ts","e","x","pbhj","opto","xhigy","erikz","pbh","opt","erikzb","eri","erik","xlye","xhig","optoj","optoje","xly","pb","xhi","x","o"};
    vector<string> vs = {"htncv","htncvn","b","mvaqrm","mv","mvaqr","mva","ht","mvaq","i","h","htnc"};

    LT0720 lt;

    cout<<lt.lt0720b(vs)<<endl;

    return 0;
}
