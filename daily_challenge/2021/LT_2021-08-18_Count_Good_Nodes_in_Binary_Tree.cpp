
#include "../../header/myheader.h"

class LT
{
public:


// D D
//    int goodNodes(TreeNode* r, int ma = -10000) {
//        return r ? goodNodes(r->left, max(ma, r->val)) + goodNodes(r->right, max(ma, r->val)) + (r->val >= ma) : 0;
//    }



// AC
    int lta(TreeNode* root)
    {
        dfsa1(root, INT_MIN);
        return ans;
    }
    int ans = 0;
    void dfsa1(TreeNode* node, int val)
    {
        if (node == nullptr)
            return;
        if (node->val >= val)
        {
            val = node->val;
            ans++;
        }
        dfsa1(node->left, val);
        dfsa1(node->right, val);
    }

};

int main()
{

    LT lt;


    return 0;
}
