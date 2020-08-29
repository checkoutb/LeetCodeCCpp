
#include "../header/myheader.h"

class LT0865
{
public:


// gg
// 本想获得 最低层的 最左，最右，然后反推 根，但是2^500...
    TreeNode* lt0865a*(TreeNode* root)
    {
        map<int, vector<int>> map2;
        filla1(root, map2, 0, 1);
        int lvl = map2.rbegin()->first;
        vector<int>& v2 = map2.rbegin()->second;
        int i1 = v2[0];
        int i2 = v2[v2.size() - 1];
        int lvl = map2.rbegin()->first;


    }

    void filla1(TreeNode* n, map<int, vector<int>>& map2, int lvl, int cnt)
    {
        if (n->left == nullptr && n->right == nullptr)
        {
            map2[lvl].push_back(cnt);
        }
        if (n->left != nullptr)
            filla1(n->left, map2, lvl + 1, cnt * 2 - 1);
        if (n->right != nullptr)
            filla1(n->right, map2, lvl + 1, cnt * 2);
    }

};

int main()
{

    LT0865 lt;


    return 0;
}
