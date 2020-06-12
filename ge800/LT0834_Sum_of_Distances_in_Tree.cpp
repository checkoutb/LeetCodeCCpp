
#include "../header/myheader.h"

class LT0834
{
public:


// Discuss
// 后序，计算结点到所有子结点的长度和。  不， 反正是一个后续+一个先序。。


// 只会暴力dfs。。。
// 树也是图。树，一分为二。一侧到另一侧的长度和就是一侧到root的长度*另一侧结点数+root到另一侧结点的长度和
// 找到一个点，这个点将图一分为2，计算每个点到这个点的长度。
// 没说0是不是root。。估计是。无所谓，无环的无向连通图 任何结点都可以作为树的根。
// 但是同侧的呢。靠最近的公共父结点？ 那就bfs。
    vector<int> lt0834a(int N, vector<vector<int>>& edges)
    {
        return vector<int>(1, -1);
    }

};

int main()
{

    LT0834 lt;


    return 0;
}
