
#include "../../header/myheader.h"

class LT6154
{
public:




    // AC
    int amountOfTime(TreeNode* root, int start)
    {
        int ans = 0;
        dfsa1(root, 0, ans, start);
        return ans;
    }

    // infection?, distance
    pair<bool, int> dfsa1(TreeNode* node, int t2, int& ans, int st)
    {
        if (node == nullptr)
            return {false, 0};

        pair<bool, int> p1 = dfsa1(node->left, t2, ans, st);
        pair<bool, int> p2 = dfsa1(node->right, t2, ans, st);

        if (p1.first)
        {
            ans = max(ans, p1.second + p2.second);
            return std::make_pair(true, p1.second + 1);
        }
        else
        {
            if (p2.first)
            {
                ans = max(ans, p1.second + p2.second);
                return std::make_pair(true, p2.second + 1);
            }
            else
            {
                if (node->val == st)
                {
                    ans = max(ans, max(p1.second, p2.second));
                    return {true, 1};
                }
                else
                {
                    return { false, max(p1.second, p2.second) + 1 };
                }
            }
        }

    }

};

int main()
{

    LT6154 lt;

    //int arr[] = { 1,5,3,-1,4,10,6,-1,-1,9,2 };
    //int st = 3;

    int arr[] = { 1 };
    int st = 1;

    TreeNode* r = convert2TreeNode(arr);

    showTreeNode(r, 5);

    cout << lt.amountOfTime(r, st) << endl;

    return 0;
}
