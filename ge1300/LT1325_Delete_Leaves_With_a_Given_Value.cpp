
#include "../header/myheader.h"

class LT1325
{
public:

// D D

//    if (r == nullptr) return nullptr;
//    r->left = removeLeafNodes(r->left, target);
//    r->right = removeLeafNodes(r->right, target);
//    return (r->left == r->right && r->val == target) ? nullptr : r;


//Runtime: 20 ms, faster than 83.89% of C++ online submissions for Delete Leaves With a Given Value.
//Memory Usage: 22.6 MB, less than 26.97% of C++ online submissions for Delete Leaves With a Given Value.
    TreeNode* lt1325a(TreeNode* root, int target)
    {
        bool b = dfsa1(root, target);
        return b ? nullptr : root;
    }

    // true: should remove n2
    bool dfsa1(TreeNode* n2, int tar)
    {
        if (n2 == nullptr)
            return true;
        bool bl = dfsa1(n2->left, tar);
        bool rl = dfsa1(n2->right, tar);
        if (bl)
            n2->left = nullptr;
        if (rl)
            n2->right = nullptr;
        if (bl & rl)
        {
            if (n2->val == tar)
                return true;
        }
        return false;
    }

};

int main()
{

//    int arr[] = {1,2,3,2,-1,2,4};
//    int t{2};

//    int arr[] = {1,3,3,3,2};
//    int t{3};

//    int arr[] = {1,1,1};
//    int t{1};

    int arr[] = {1,2,3};
    int t{1};

    TreeNode* r = convert2TreeNode(arr);
    showTreeNode(r, 3);
    LT1325 lt;

    TreeNode* n = lt.lt1325a(r, t);
    cout<<"==========="<<endl;
    cout<<(n == nullptr)<<endl;
    showTreeNode(n, 3);

    return 0;
}
