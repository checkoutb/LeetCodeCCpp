
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //for (int i = 0; i < inorder.size(); i++) {
    //    mpp[inorder[i]] = i;
    //}
    // 后序遍历：  node.左子树 + node.右子树 + node



    //Runtime61 ms
    //    Beats
    //    11.69 %
    //    Memory26.1 MB
    //    Beats
    //    78.64 %
    // BIT, range max idx in postorder
    TreeNode* lta(vector<int>& inorder, vector<int>& postorder)
    {
        int sz1 = inorder.size();
        int arr[6001] = { 0 };
        for (int i = 0; i < sz1; ++i)
        {
            arr[postorder[i] + 3000] = i;
        }

        return dfsa1(inorder, 0, sz1 - 1, arr);
    }

    TreeNode* dfsa1(vector<int>& vin, int st, int en, int arr[])
    {
        if (st > en)
            return nullptr;
        int idx = -1;
        int mxi = -1;
        for (int i = st; i <= en; ++i)
        {
            if (arr[vin[i] + 3000] > mxi)
            {
                mxi = arr[vin[i] + 3000];
                idx = i;
            }
        }

        TreeNode* node = new TreeNode(vin[idx]);
        node->left = dfsa1(vin, st, idx - 1, arr);
        node->right = dfsa1(vin, idx + 1, en, arr);
        return node;
    }

};

int main()
{

    LT lt;


    return 0;
}
