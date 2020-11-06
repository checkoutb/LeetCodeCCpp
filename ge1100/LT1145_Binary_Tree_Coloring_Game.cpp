
#include "../header/myheader.h"

class LT1145
{
public:

// D D

// 先 find到 x结点，然后计算 x.left 和 x.right 的子树结点数.


// sumx = sumxl+1+sumxr ，所以不必保存。

// 要堵x结点，一共有3个地方可以堵。



//Runtime: 4 ms, faster than 82.89% of C++ online submissions for Binary Tree Coloring Game.
//Memory Usage: 11.3 MB, less than 5.09% of C++ online submissions for Binary Tree Coloring Game.

// 感觉就是 变换树，变成x 为根，然后层级遍历，当层级遍历 某一层只有一个点，(是否需要：此时还没有遍历一半)，那么就肯定会输。
// 两个点不太可能，因为p2 也是从一个点扩散，所以 没有办法 跨子树的。
// x为根，不做 rotate， 会是一个 三叉树。
// 感觉 直接p2 选 x.parent 就可以了。 不行就是不行。。。对，如果p2选择x的子孙结点，肯定输。  只能选 祖父，祖父里最可能赢的就是 直接父结点，还有root这个情况。
// 那就是，以x为根的子树能不能占到一半，
// 不，还有一/N种情况， x不是root，但x子树占了99%的结点，并且 x子树的右子树 占了x子树的99%，那么player2选 x的右子结点 是必赢的。
// 话说，n是奇数有什么用？you name yidiandian yong
    bool lt1145a(TreeNode* root, int n, int x)
    {
        dfsa1(root, x);
        int half = n / 2;
        return sumx <= half || sumxl > half || sumxr > half;
    }
    int sumx = 0;
    int sumxl = 0;
    int sumxr = 0;
    bool done = false;

    int dfsa1(TreeNode* node, int x)
    {
        if (done || node == nullptr)
            return 0;
        int l = dfsa1(node->left, x);
        int r = dfsa1(node->right, x);
        if (node->val == x)
        {
            sumx = l + r + 1;
            sumxl = l;
            sumxr = r;
            done = true;
        }
        return l + r + 1;
    }

};

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11};
    int n = 11;
    int x = 2;

    TreeNode* r = convert2TreeNode(arr);

    LT1145 lt;

    cout<<lt.lt1145a(r, n, x);

    return 0;
}
