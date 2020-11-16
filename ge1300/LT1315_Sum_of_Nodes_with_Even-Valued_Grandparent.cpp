
#include "../header/myheader.h"

class LT1315
{
public:

// D D

// bfs,自己是偶数，把 孙子 加进来。


//    int sumEvenGrandparent(TreeNode* root, int p = 1, int gp = 1) {
//        return root ? sumEvenGrandparent(root->left, root->val, p)
//               + sumEvenGrandparent(root->right, root->val, p)
//               + (gp % 2 ? 0 : root->val)  : 0;
//    }


//Runtime: 56 ms, faster than 61.19% of C++ online submissions for Sum of Nodes with Even-Valued Grandparent.
//Memory Usage: 38.8 MB, less than 70.07% of C++ online submissions for Sum of Nodes with Even-Valued Grandparent.
    int lt1315a(TreeNode* root)
    {
        dfsa1(root, 1, 1);
        return ans;
    }
    int ans = 0;
    void dfsa1(TreeNode* node, int parent, int gp)
    {
        if (node == nullptr)
            return;
        if (gp % 2 == 0)
            ans += node->val;
        dfsa1(node->left, node->val, parent);
        dfsa1(node->right, node->val, parent);
    }

};

int main()
{

    LT1315 lt;


    return 0;
}
