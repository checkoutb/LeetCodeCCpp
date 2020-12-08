
#include "../header/myheader.h"

class LT1609
{
public:

// D D




//Runtime: 352 ms, faster than 72.92% of C++ online submissions for Even Odd Tree.
//Memory Usage: 152.7 MB, less than 63.88% of C++ online submissions for Even Odd Tree.
    bool lt1609a(TreeNode* root)
    {
        queue<TreeNode*> que1;
        que1.push(root);
        bool inc = false;
        while (!que1.empty())
        {
            inc = !inc;
            int sz1 = que1.size();
            int lst = inc ? -1 : INT_MAX;
            while (sz1-- > 0)
            {
                TreeNode* np = que1.front();
                que1.pop();
                if ((inc != (np->val > lst)) || (np->val == lst) || inc != (np->val % 2))
                {
                    return false;
                }
                if (np->left)
                    que1.push(np->left);
                if (np->right)
                    que1.push(np->right);
                lst = np->val;
            }
        }
        return true;
    }

};

int main()
{
//    int arr[] = {1,10,4,3,-1,7,9,12,8,-1,-1,6,-1,-1,2};
//    int arr[] = {5,4,2,3,3,7};
    int arr[] = {5,9,1,3,5,7};


    TreeNode* r = convert2TreeNode(arr);
    showTreeNode(r, 5);
    LT1609 lt;

    cout<<lt.lt1609a(r)<<endl;

    return 0;
}
