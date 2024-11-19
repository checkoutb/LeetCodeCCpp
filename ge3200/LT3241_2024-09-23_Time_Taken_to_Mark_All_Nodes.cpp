
#include "../header/myheader.h"

class LT3241
{
public:


    // D
    // 也是2个最远的， 细节不知道，代码太长了。


    // hint2 就是， 每个结点保存2个最远的， 但是 没看懂hint3 是什么意思。


    // 结点赋权，偶数下标的结点的 权是2，奇数下标 权是1，然后 dfs找到 权和最大的路径。
    // 问题就是，对每个点dfs，必然tle。
    // 从度为1的结点开始， 不行
    // 每个节点保存2个值，最远，次远。 dp， 但是还是好麻烦的。
    vector<int> timeTaken(vector<vector<int>>& edges) {
        
    }


};

int main()
{

    LT3241 lt;


    return 0;
}
