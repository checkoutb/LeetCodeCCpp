
#include "../header/myheader.h"

class LT0943
{
public:


// size<=12, brute force ?  但是hard。。
// 就是要找一种 排列， 这种排列 中 重叠部分最多。
// 就是memo，2个string的重叠部分，然后 dfs？  12!
// 贪心？  不是其他word的substring
    string lt0943a(vector<string>& words)
    {
        int sz1 = words.size();
        if (sz1 == 1)
            return words[0];
        vector<vector<int>> vvi(sz1, vector<int>(sz1, 0));
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz1; ++j)
            {
                if (i == j)
                    continue;
                int t2 = min(words[i].size(), words[j].size());
                int k = t2 - 2;
                int sz3 = words[i].size() - 1;
                for (; k >= 0; --k)
                {
                    if (words[i][sz3 - k] == words[j][0])
                    {
                        for (int a = k - 1; a >= 0; --a)
                        {
                            if (words[i][sz3 - a] != words[j][k - a])
                            {
                                goto BBB;
                            }
                        }
                        goto AAA;
                    }
                    BBB:
                    continue;
                }
                AAA:
                vvi[i][j] = k + 1;

                // ... 这个是回文。。。
//                if (i == j)
//                    continue;
//                int t2 = min(words[i].size(), words[j].size());
//                int k = t2 - 2;     // 0,1 's 1
//                int sz3 = words[i].size() - 1;
//                for (; k >= 0; --k)
//                {
//                    cout<<words[i]<<"\n"<<words[j]<<"\n"<<(sz3-k)<<", "<<k<<endl;
//                    if (words[i][sz3 - k] == words[j][k])
//                    {
//                        for (int a = k - 1; a >= 0; --a)
//                        {
//                            if (words[i][sz3 - a] != words[j][a])
//                            {
//                                goto BBB;
//                            }
//                        }
//                        goto AAA;       // all char equal
//                    }
//                    BBB:
//                    continue;
//                }
//                AAA:
//                vvi[i][j] = k + 1;
            }
        }
        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test

        string ans;

        return ans;
    }

//    string dfsa1()
//    {
//
//    }

};

int main()
{
//    vector<string> vs = {"alex","loves","leetcode"};
    vector<string> vs = {"catg","ctaagt","gcta","ttca","atgcatc"};
//    vector<string> vs = {"catg","atgcatc"};

    LT0943 lt;

    cout<<lt.lt0943a(vs)<<endl;

    return 0;
}
