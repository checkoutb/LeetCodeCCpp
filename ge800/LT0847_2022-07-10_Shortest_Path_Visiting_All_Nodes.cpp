
#include "../header/myheader.h"

class LT0847
{
public:

    // D

    // bfs/dfs, 1<<node 做dp ，如果全部访问就return。



    // g

    // dfs 有一个问题： 1-2-3-4-5-6-7-8-9,  1-11-8-9 , 存在这2条路径时，如果 走前面那条，得出的结果并不正确。 不，好像是一样的。。
    // 但是应该 奇数度的点 开始比较好？ 虽然 偶数度开始的话，最终会结束在奇数度上，但是可以先剔除一些开始节点
    // 如果都是 偶数度，那么是环，应该是 度最大的开始？
    int lt0847a(vector<vector<int>>& graph)
    {

    }

};

int main()
{

    LT0847 lt;


    return 0;
}
