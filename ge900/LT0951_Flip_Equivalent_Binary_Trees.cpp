
#include "../header/myheader.h"

class LT0951
{
public:


// D D
//        if(!root1 && !root2)
//            return true;
//        if(!root1 || !root2 || root1->val!=root2->val)
//            return false;
//        bool flip = flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left);
//        bool same = flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);
//        return flip || same;


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Flip Equivalent Binary Trees.
//Memory Usage: 12.2 MB, less than 52.35% of C++ online submissions for Flip Equivalent Binary Trees.

    bool lt0951b(TreeNode* root1, TreeNode* root2)
    {
        if (root1 == nullptr || root2 == nullptr)           // ...
            return root2 == root1;

        if (root1->val != root2->val)
            return false;
        bool ans = dfsb1(root1, root2);
        return ans;
    }

    bool dfsb1(TreeNode* n1, TreeNode* n2)
    {
        if (n1->left == nullptr && n1->right == nullptr)
        {
            return n2->left == nullptr && n2->right == nullptr;
        }
        if (n1->left == nullptr ^ n1->right == nullptr)
        {
            if (n1->left == nullptr)
            {
                if (n2->left != nullptr)
                {
                    n2->right = n2->left;
                    n2->left = nullptr;
                }
                if (n2->right == nullptr || n1->right->val != n2->right->val)
                    return false;
            }
            else
            {
                if (n2->right != nullptr)
                {
                    n2->left = n2->right;
                    n2->right = nullptr;
                }
                if (n2->left == nullptr || n1->left->val != n2->left->val)
                    return false;
            }
        }
        else
        {
            if (n2->left == nullptr || n2->right == nullptr)            // ...
                return false;
            if (n1->left->val != n2->left->val)
            {
                TreeNode* t3 = n2->left;
                n2->left = n2->right;
                n2->right = t3;
            }

            if (n1->left->val != n2->left->val || n1->right->val != n2->right->val)
                return false;
        }
        return (n1->left == nullptr || dfsb1(n1->left, n2->left)) && (n1->right == nullptr || dfsb1(n1->right, n2->right));
    }


// .... error..
    bool lt0951a(TreeNode* root1, TreeNode* root2)
    {
        bool ans = dfsa1(root1, root2);
        return ans;
    }

    bool dfsa1(TreeNode* n1, TreeNode* n2)
    {
        if (n1 == nullptr || n2 == nullptr)
        {
            return n1 == n2;
        }
        if (n1->val != n2->val)
            return false;

        bool ans = dfsa1(n1->left, n2->right);
        if (!ans)
            return false;
        ans = dfsa1(n1->right, n2->left);
        return ans;
    }

};

int main()
{

    int arr1[] = {1,2,3,4,5,6,-1,-1,-1,7,8};
    int arr2[] = {1,3,2,-1,6,4,5,-1,-1,-1,-1,-1,-1,8,7};

    TreeNode* n1 = convert2TreeNode(arr1);
    TreeNode* n2 = convert2TreeNode(arr2);

    showTreeNode(n1, 3);
    showTreeNode(n2, 3);

    LT0951 lt;

    cout<<lt.lt0951b(n1, n2)<<endl;

    return 0;
}
