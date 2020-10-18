
#include "../header/myheader.h"

class LT1008
{
public:


// D D

// stack

//            TreeNode node = new TreeNode(preorder[i]);
//            if (preorder[i] < stack.peek().val) {
//                stack.peek().left = node;
//            } else {
//                TreeNode parent = stack.peek();
//                while (!stack.isEmpty() && preorder[i] > stack.peek().val) {
//                    parent = stack.pop();
//                }
//                parent.right = node;
//            }
//            stack.push(node);


//    int i = 0;
//    TreeNode* bstFromPreorder(vector<int>& A, int bound = INT_MAX) {
//        if (i == A.size() || A[i] > bound) return NULL;
//        TreeNode* root = new TreeNode(A[i++]);
//        root->left = bstFromPreorder(A, root->val);
//        root->right = bstFromPreorder(A, bound);
//        return root;
//    }
// don't need mn



//Runtime: 8 ms, faster than 47.07% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
//Memory Usage: 14.1 MB, less than 6.25% of C++ online submissions for Construct Binary Search Tree from Preorder Traversal.
    TreeNode* lt1008a(vector<int>& preorder)
    {
        int i = 0;
        TreeNode* ans = recursiona1(preorder, i, true, 0, 1E8 + 1);
        return ans;
    }

    TreeNode* recursiona1(vector<int>& pre, int& i, bool isLeft, int mn, int mx)
    {
        if (i == pre.size())
            return nullptr;
        if (pre[i] > mx || pre[i] < mn)
            return nullptr;
//        if (isLeft)
//        {
//            if (pre[i] > mx || pre[i] < mn)
//                return nullptr;
//            return new TreeNode(pre[i]);
            int val = pre[i];
            TreeNode* node = new TreeNode(pre[i]);
            i++;
            node->left = recursiona1(pre, i, true, mn, val);
            node->right = recursiona1(pre, i, false, val, mx);
            return node;
//        }
//        else
//        {
////            return pre[i] < parentVal ? nullptr : new TreeNode(pre[i]);
////            if (pre[i] < parentVal)
////                return nullptr;
//            int val = pre[i];
//            TreeNode* node = new TreeNode(pre[i]);
//            i++;
//            node->left = recursiona1(pre, i, true, mn, val);
//            node->right = recursiona1(pre, i, false, val, mx);
//            return node;
//        }
    }
};

int main()
{

    vector<int> v = {8,5,1,7,10,12};

    LT1008 lt;

    TreeNode* n = lt.lt1008a(v);

    showTreeNode(n, 5);

    deleteTreeNode(n);

    return 0;
}
