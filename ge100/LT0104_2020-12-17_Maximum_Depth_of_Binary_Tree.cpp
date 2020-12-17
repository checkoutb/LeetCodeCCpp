
#include "../header/myheader.h"

class LT0104
{
public:

// D D

//        if(!root){
//            return 0;
//        }
//        return 1+max(maxDepth(root->left), maxDepth(root->right));




//Runtime: 16 ms, faster than 22.46% of C++ online submissions for Maximum Depth of Binary Tree.
//Memory Usage: 19.4 MB, less than 65.49% of C++ online submissions for Maximum Depth of Binary Tree.
    int lt0104a(TreeNode* root)
    {
        dfsa1(root, 0);
        return ans;
    }
    int ans = 0;
    void dfsa1(TreeNode* node, int lv)
    {
        if (node == nullptr)
        {
            ans = max(ans, lv);
            return;
        }
        dfsa1(node->left, lv + 1);
        dfsa1(node->right, lv + 1);
    }

};

int main()
{

    LT0104 lt;


    return 0;
}
