
#include "../header/myheader.h"

class LT0654
{
public:

// D D


//    We scan numbers from left to right, build the tree one node by one step;
//    We use a stack to keep some (not all) tree nodes and ensure a decreasing order;
//    For each number, we keep pop the stack until empty or a bigger number; The bigger number (if exist, it will be still in stack) is current number's root, and the last popped number (if exist) is current number's left child (temporarily, this relationship may change in the future); Then we push current number into the stack.

//        vector<TreeNode*> stk;
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            TreeNode* cur = new TreeNode(nums[i]);
//            while (!stk.empty() && stk.back()->val < nums[i])
//            {
//                cur->left = stk.back();
//                stk.pop_back();
//            }
//            if (!stk.empty())
//                stk.back()->right = cur;
//            stk.push_back(cur);
//        }
//        return stk.front();




//Runtime: 116 ms, faster than 43.74% of C++ online submissions for Maximum Binary Tree.
//Memory Usage: 44.4 MB, less than 27.21% of C++ online submissions for Maximum Binary Tree.
    TreeNode* lt0654a(vector<int>& nums)
    {
        TreeNode* ans = builda1(nums, 0, nums.size());
        return ans;
    }

    // [st, en)
    TreeNode* builda1(vector<int>& nums, int st, int en)
    {
        if (st == en)
            return nullptr;
        int mxi = st;
        int mx = nums[st];
        for (int i = st; i < en; i++)
        {
            if (nums[i] > mx)
            {
                mx = nums[i];
                mxi = i;
            }
        }
        TreeNode* ans = new TreeNode(mx);
        ans->left = builda1(nums, st, mxi);
        ans->right = builda1(nums, mxi + 1, en);
        return ans;
    }
};

int main()
{

    vector<int> arr = {3,2,1,6,0,5};

    LT0654 lt;

    TreeNode* n = lt.lt0654a(arr);

    showTreeNode(n, 4);

    deleteTreeNode(n);
    return 0;
}
