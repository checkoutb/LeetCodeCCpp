
#include "../header/myheader.h"

class LT1255
{
public:

// D D

//int dfs(vector<string>& ws, vector<int> &cnt, vector<int> &score, int i) {
//    if (i >= ws.size()) return 0;
//    auto skipGain = dfs(ws, cnt, score, i + 1), gain = 0, formed = 1;
//    vector<int> cnt1(begin(cnt), end(cnt));
//    for (auto ch : ws[i]) {
//        if (--cnt1[ch - 'a'] < 0) formed = 0;
//        gain += score[ch - 'a'];
//    }
//    return max(skipGain, formed ?
//        gain + dfs(ws, cnt1, score, i + 1) : 0);
//}
//





//Runtime: 8 ms, faster than 64.63% of C++ online submissions for Maximum Score Words Formed by Letters.
//Memory Usage: 10 MB, less than 62.48% of C++ online submissions for Maximum Score Words Formed by Letters.
    int lt1255a(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        vector<int> vc(26, 0);
        for (char ch : letters)
            vc[ch - 'a']++;
        vector<vector<int>> vvi(words.size(), vector<int>(26, 0));
        for (int i = 0; i < words.size(); ++i)
        {
            for (char ch : words[i])
            {
                vvi[i][ch - 'a']++;
            }
        }
        return dfsa1(vvi, 0, vc, score, 0);
    }
    int dfsa1(vector<vector<int>>& vvi, int idx, vector<int>& vi, vector<int>& score, int got)
    {
        #ifdef __test
//        cout<<"  "<<got<<endl;
        #endif // __test
        if (idx == vvi.size())
            return got;
        int ans = got;
        int t2 = 0;
        for (int i = idx; i < vvi.size(); ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                if (vvi[i][j] > vi[j])
                    goto AAA;
            }
            t2 = 0;         // goto 到 AAA 内不能新声明变量。
            for (int j = 0; j < 26; ++j)
            {
                vi[j] -= vvi[i][j];
                t2 += vvi[i][j] * score[j];
            }
            ans = max(dfsa1(vvi, i + 1, vi, score, got + t2), ans);
            #ifdef __test
//            cout<<ans<<endl;
            #endif // __test
            for (int j = 0; j < 26; ++j)
            {
                vi[j] += vvi[i][j];
            }

            AAA:
            continue;
        }
        return ans;
    }

//    int dfsa1(vector<string>& vs, int idx, vector<char>& vc, vector<int>& score, int got)
//    {
//        if (idx == vs.size())
//            return got;
//        for (int i = idx; i < vs.size(); ++i)
//        {
//            for (int j = 0; j < vs[i].size(); ++j)
//            {
//                if (vs[i][j])
//            }
//
//            AAA:
//            continue;
//        }
//    }

};

int main()
{
//    vector<string> vs = {"dog","cat","dad","good"};
//    vector<string> vtemp = {"a","a","c","d","d","d","g","o","o"};
//    vector<int> score = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};

//    vector<string> vs = {"xxxz","ax","bx","cx"};
//    vector<string> vtemp = {"z","a","b","c","x","x","x"};
//    vector<int> score = {4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10};

//    vector<string> vs = {"leetcode"};
//    vector<string> vtemp = {"l","e","t","c","o","d"};
//    vector<int> score = {0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0};

    vector<string> vs = {"azb","ax","awb","ayb","bpppp"};       // 14
    vector<string> vtemp = {"z","a","w","x","y","b","p","p","p"};
    vector<int> score = {10,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,3,2,3,3};


    vector<char> vc(vtemp.size());
    for (int i = 0; i < vtemp.size(); ++i)
    {
        vc[i] = vtemp[i][0];
    }

    LT1255 lt;

    cout<<lt.lt1255a(vs, vc, score);

    return 0;
}
