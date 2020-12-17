
#include "../header/myheader.h"

class LT0108
{
public:

// D D





//Runtime: 24 ms, faster than 61.96% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
//Memory Usage: 26.1 MB, less than 47.10% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
    TreeNode* lt0108a(vector<int>& nums)
    {
        TreeNode* ans = dfsa1(nums, 0, nums.size() - 1);
        return ans;
    }
    TreeNode* dfsa1(vector<int>& nums, int st, int en)
    {
        if (st > en)
            return nullptr;
        int mid = (st + en) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        TreeNode* l = dfsa1(nums, st, mid - 1);
        TreeNode* r = dfsa1(nums, mid + 1, en);
        node->left = l;
        node->right = r;
        return node;
    }

};

int main()
{
    vector<int> v = {-10,-3,0,5,9};

    LT0108 lt;

    TreeNode* r = lt.lt0108a(v);

//    cout<<(r == nullptr)<<endl;
//    cout<<". "<<r->val;
    showTreeNode(r, 5);

    return 0;
}
