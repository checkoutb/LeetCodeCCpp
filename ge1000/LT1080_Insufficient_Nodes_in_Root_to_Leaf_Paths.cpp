
#include "../header/myheader.h"

class LT1080
{
public:


// D D

//        if (root->left == root->right)
//            return root->val < limit ? NULL : root;
//        if (root->left)
//            root->left = sufficientSubset(root->left, limit - root->val);
//        if (root->right)
//            root->right = sufficientSubset(root->right, limit - root->val);
//        return root->left == root->right ? NULL : root;

// nb. ==.






//Runtime: 48 ms, faster than 98.21% of C++ online submissions for Insufficient Nodes in Root to Leaf Paths.
//Memory Usage: 34.3 MB, less than 5.15% of C++ online submissions for Insufficient Nodes in Root to Leaf Paths.
    TreeNode* lt1080a(TreeNode* root, int limit)
    {
        bool ans = dfsa1(root, 0, limit);
        if (!ans)
            return nullptr;
        return root;
    }

    // true: contain sum>=limit
    bool dfsa1(TreeNode* node, int sum, int limit)
    {
        if (node == nullptr)
            return false;
        sum += node->val;
        if (node->left == nullptr && node->right == nullptr)
        {
            if (sum >= limit)
                return true;
            else
                return false;
        }
        bool ans = dfsa1(node->left, sum, limit);
        if (!ans)
            node->left = nullptr;
        bool ans2 = dfsa1(node->right, sum, limit);
        if (!ans2)
            node->right = nullptr;

        return ans || ans2;
    }

};

int main()
{
//    int lmt = 1;
//    int arr[] = {1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14};

//    int lmt = 22;
//    int arr[] = {5,4,8,11,-1,17,4,7,1,-1,-1,-1,-1,5,3};

    int lmt = 22;
    int arr[] = {10,5,10};


    TreeNode* node = convert2TreeNode(arr);

    showTreeNode(node, 5);
    cout<<endl<<" =======  "<<endl;

    LT1080 lt;

    TreeNode* n = lt.lt1080a(node, lmt);

    showTreeNode(n, 5);

    return 0;
}
