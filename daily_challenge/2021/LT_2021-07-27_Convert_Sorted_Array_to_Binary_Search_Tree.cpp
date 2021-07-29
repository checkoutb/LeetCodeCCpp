
#include "../../header/myheader.h"

class LT
{
public:

// D D

//int mid = (low + high) >>> 1

//    void recursiveFunc( vector<int>& nums, TreeNode* node, int &low, int &mid, int &high )
//    {
//        if ( mid > low )
//        {
//            int lmid = low + ( ( mid - low ) / 2 );
//            TreeNode *tempNode = new TreeNode;
//            tempNode -> val = nums[lmid - 1];
//            node->left = tempNode;
//            int t1 = mid - 1;
//            recursiveFunc(nums, tempNode, low, lmid, t1);
//        }
//        if ( mid < high )
//        {
//            int rmid = mid + ( ( high - mid + 1 ) / 2 );
//            TreeNode *tempNode2 = new TreeNode;
//            tempNode2 -> val = nums[rmid - 1];
//            node->right = tempNode2;
//            int t2 = mid + 1;
//            recursiveFunc(nums, tempNode2, t2, rmid, high);
//        }
//    }




// AC
    TreeNode* lta(vector<int>& nums)
    {
        return dfsa1(nums, 0, nums.size() - 1);
    }

    TreeNode* dfsa1(vector<int>& vi, int st, int en)
    {
        if (st > en)
            return nullptr;
        int mid = (st + en) / 2;
        TreeNode* p = new TreeNode(vi[mid]);            // return new TreeNode(vi[(st+en)/2], dfsa1(), dfsa1());
        p->left = dfsa1(vi, st, mid - 1);
        p->right = dfsa1(vi, mid + 1, en);
        return p;
    }

};

int main()
{
    myvi v = {-10,-3,0,5,9};

    LT lt;

    TreeNode* p = lt.lta(v);

    showTreeNode(p, 5);

    deleteTreeNode(p);

    return 0;
}
