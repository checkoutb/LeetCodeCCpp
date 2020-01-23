
#include "../header/myheader.h"

class LT0543
{
public:



//Runtime: 8 ms, faster than 92.38% of C++ online submissions for Diameter of Binary Tree.
//Memory Usage: 19.8 MB, less than 88.89% of C++ online submissions for Diameter of Binary Tree.

    int ans = 0;
    int lt0543a(TreeNode* root)
    {
        dfsa1(root);
        return ans;
    }

    int dfsa1(TreeNode* node)
    {
        if (node == NULL)
        {
            return 0;
        }
        int l = dfsa1(node->left);
        int r = dfsa1(node->right);
        ans = max(ans, (l + r));
        return max(l, r) + 1;
    }
};

int main()
{
    int arr2[] = {1,2,3,4,5};
    TreeNode* r = convert2TreeNode(arr2);

    LT0543 lt;

    cout<<lt.lt0543a(r)<<endl;

    return 0;
}
