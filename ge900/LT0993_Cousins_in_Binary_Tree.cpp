
#include "../header/myheader.h"

class LT0993
{
public:



//Runtime: 4 ms, faster than 78.84% of C++ online submissions for Cousins in Binary Tree.
//Memory Usage: 11.1 MB, less than 54.60% of C++ online submissions for Cousins in Binary Tree.
    bool lt0993a(TreeNode* root, int x, int y)
    {
        queue<TreeNode*> que1;
        bool arr[101] = {false};
        arr[root->val] = true;
        que1.push(root);
        while (!que1.empty())
        {
            int sz1 = que1.size();
            while (sz1-- > 0)
            {
                TreeNode* p = que1.front();
                que1.pop();
                arr[p->val] = true;
                if (p->left != nullptr)
                {
                    que1.push(p->left);
                }
                if (p->right != nullptr)
                {
                    que1.push(p->right);
                }
                if (p->left != nullptr && p->right != nullptr && ((p->left->val == x && p->right->val == y) || (p->right->val == x && p->left->val == y)))
                {
                    return false;
                }
            }
            if (arr[x] || arr[y])
            {
                return arr[x] && arr[y];
            }
        }
        return false;
    }


};

int main()
{

//    int arr[] = {1,2,3,4,-1,-1,-1};
//    int x = 4, y = 3;

    int arr[] = {1,2,3,-1,4,-1,5};
    int x = 4, y = 5;

    TreeNode* root = convert2TreeNode(arr);

    showTreeNode(root, 3);

    LT0993 lt;

    cout<<endl<<lt.lt0993a(root, x, y)<<endl;

    return 0;
}
