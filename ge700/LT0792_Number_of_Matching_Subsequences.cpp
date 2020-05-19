
#include "../header/myheader.h"

class LT0792
{
public:


// D D

// StefanPochmann
// https://leetcode.com/problems/number-of-matching-subsequences/discuss/117634/Efficient-and-simple-go-through-words-in-parallel-with-explanation
//    vector<const char*> waiting[128];
//    for (auto &w : words)
//        waiting[w[0]].push_back(w.c_str());
//    for (char c : S) {
//        auto advance = waiting[c];
//        waiting[c].clear();
//        for (auto it : advance)
//            waiting[*++it].push_back(it);
//    }
//    return waiting[0].size();
// 还有java ruby python
// 。。好强。。*++it，，it是char*.. 并且后移了一位。   ！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！


// 我还以为会： S全w， words是w.* ...
//Runtime: 428 ms, faster than 40.94% of C++ online submissions for Number of Matching Subsequences.
//Memory Usage: 36 MB, less than 100.00% of C++ online submissions for Number of Matching Subsequences.
    int lt0792b(string S, vector<string>& words)
    {
        int ans = 0;
        map<string, int> map1;
        for (string w : words)
        {
            map1[w]++;
        }
        for (map<string, int>::iterator it = map1.begin(); it != map1.end(); it++)
        {
            string w = it->first;
            int cnt = it->second;
            int wi = 0;
            int si = 0;
            while (si < S.size() && wi < w.size())
            {
                if (S[si] == w[wi])
                {
                    si++;
                    wi++;
                }
                else
                {
                    si++;
                }
            }
            if (wi == w.size())
                ans += cnt;

        }
        return ans;
    }


// 42/49 tle... S全w，words全wp。。。
// sort words.
// trie树，
    int lt0792a(string S, vector<string>& words)
    {
        int ans = 0;

        for (string w : words)
        {
            int wi = 0;
            int si = 0;
            while (si < S.size() && wi < w.size())
            {
                if (S[si] == w[wi])
                {
                    si++;
                    wi++;
                }
                else
                {
                    si++;
                }
            }
            if (wi == w.size())
                ans++;
        }

        return ans;
    }

};

int main()
{

    string s = "abcde";
//    string ws[] = {"a", "bb", "acd", "ace"};
    vector<string> ws = {"a", "bb", "acd", "ace"};

    LT0792 lt;

    cout<<lt.lt0792a(s, ws)<<endl;

    return 0;
}
