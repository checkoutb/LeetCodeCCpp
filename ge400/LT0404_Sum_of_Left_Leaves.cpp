
#include "../header/myheader.h"

class LT0404
{
public:

//    Runtime: 4 ms, faster than 89.71% of C++ online submissions for Sum of Left Leaves.
//    Memory Usage: 13.3 MB, less than 84.88% of C++ online submissions for Sum of Left Leaves.

    int lt0404a(TreeNode* root)
    {
        int ans = dfsa1(root);
        return ans;
    }

    int dfsa1(TreeNode* node, bool isLeft = false)
    {
        #ifdef __test
        cout<<node->val<<endl;
        system("pause");
        #endif // __test
        if (node == nullptr)
            return 0;
        if (node->left == node->right)
        {
            return isLeft ? node->val : 0;
        }
        else
        {
            int ans = dfsa1(node->left, true) + dfsa1(node->right, false);
            return ans;
        }
    }
};

int main()
{
    int arr1[] = {3,9,20,-1,-1,15,7};
    TreeNode* root = convert2TreeNode_(arr1);

    cout<<endl<<endl<<"--------------=======----------"<<endl;
    cout<<root->val<<endl;
    system("pause");

    LT0404 lt;
    cout<<endl<<lt.lt0404a(root)<<endl;

    return 0;
}
