
#include "../header/myheader.h"

class LT0965
{
public:


// D D
//bool isUnivalTree(TreeNode* r, int v = -1) {
//  return r == nullptr || ((v == -1 || r->val == v) &&
//    isUnivalTree(r->left, r->val) && isUnivalTree(r->right, r->val));
//}

//        bool left = root->left == NULL || root->left->val == root->val && isUnivalTree(root->left);
//        bool right = root->right == NULL || root->right->val == root->val && isUnivalTree(root->right);
//        return left && right;

//        if (root == NULL) return true;
//        return (root->left ? root->left->val == root->val : true) &&
//            (root->right ? root->right->val == root->val : true) &&
//            isUnivalTree(root->left) && isUnivalTree(root->right);


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Univalued Binary Tree.
//Memory Usage: 10 MB, less than 61.92% of C++ online submissions for Univalued Binary Tree.
    bool isUnivalTree(TreeNode* root) {
        bool ans = true;
        if (root->left != nullptr)
        {
            if (root->val != root->left->val)
            {
                return false;
            }
            ans = ans && isUnivalTree(root->left);
        }
        if (!ans)
            return ans;
        if (root->right != nullptr)
        {
            if (root->val != root->right->val)
            {
                return false;
            }
            ans = ans && isUnivalTree(root->right);
        }
        return ans;
    }


};

int main()
{

    LT0965 lt;


    return 0;
}
