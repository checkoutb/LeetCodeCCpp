
#include "../header/myheader.h"

class LT0072
{
public:


// D

//dp[i][j] to be the minimum number of operations to convert word1[0..i) to word2[0..j)



// gg
// 优先 replace， 然后 remove/insert
// word1 的 subsequence == word2的 subsequence。
// word1的 每个char 出现或者不出现。 选择一种出现最多的 subseq， 不，后续呢， 距离的问题，有些是删除的，
// dfs 每层3种选择。 或者bfs更好？ 毕竟需要 最少操作。 3^500 抗不住的。
// 必须是substr，
// discuss 的 title  都是 DP 。。
    int lt0072a(string word1, string word2)
    {
        int sz1 = word1.size();
        int sz2 = word2.size();
        unordered_map<char, vector<int>> map2;
        for (int i = 0; i < sz2; ++i)
        {
            map2[word2[i]].push_back(i);
        }
//        vector<>
        int arr1[3] = {0};      // replace, remove, insert
        int arr2[3] = {0};      // 匹配的 word2的下标。
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (word1[i] == word2[arr2[j]])
                {

                }
                else
                {
                    switch (j)
                    {
                    case 0:
                        arr1[0]++;      // replace to word2[arr2[j]]
                        arr2[0]++;
                        break;
                    case 1:
                        arr1[1]++;      // remove word1[i]
                        break;
                    case 2:
                        arr1[2]++;      // insert
                        arr2[2]++;
                        break;
                    }
                }
            }
        }
    }



};

int main()
{

    LT0072 lt;


    return 0;
}
