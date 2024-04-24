
#include "../header/myheader.h"

class LT1719
{
public:



    // g

    // one line
    // when it is in line, must contain all
    // degree ,, degree == 1 is leaf, from leaf, up up up . no.
    // example 2 is circle, so ans is 2, no
    // 出现多少次，就是 第几层。   no
    // 出现最多的，必然是 root。 ！！！！！！  然后把 root 删除， 继续， 出现最多的，必然是 subtree 的root。
    //    root 和其他 所有点 都有 pair。
    // node 是 1-n， 还是中间可以 空开几个点？ 按前者算
    // 相同最多，那么是 list？  list 就是 2
    // 个数 - 深度 就是 子树的
    int checkWays(vector<vector<int>>& pairs)
    {
        std::sort(begin(pairs), end(pairs), [](const vector<int>& v1, const vector<int>& v2){
            return v1[1] > v2[1];
        });
        int n = pairs[0][1];  // max node, node' count      // 1-n
        vector<vector<int>> vvi(n + 1);
        for (vector<int>& p : pairs)
        {
            vvi[p[0]].push_back(p[1]);
            vvi[p[1]].push_back(p[0]);
        }

    }
};

int main()
{

    LT1719 lt;


    return 0;
}
