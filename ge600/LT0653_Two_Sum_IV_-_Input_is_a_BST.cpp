
#include "../header/myheader.h"

class LT0653
{
public:

// D D

// dfs 遍历时，看下set里有没有合适的，再保存自己到set。

// 中序遍历出 vector， 双指针逼近

// dfs时， 二叉搜索bst。


//        Stack<TreeNode> stackL = new Stack<TreeNode>();  // iterator 1 that gets next smallest value
//        Stack<TreeNode> stackR = new Stack<TreeNode>();  // iterator 2 that gets next largest value
//
//        for(TreeNode cur = root; cur != null; cur = cur.left)
//            stackL.push(cur);
//        for(TreeNode cur = root; cur != null; cur = cur.right)
//            stackR.push(cur);
//
//        while(stackL.size() != 0 && stackR.size() != 0 && stackL.peek() != stackR.peek()){
//            int tmpSum = stackL.peek().val + stackR.peek().val;
//            if(tmpSum == k)  return true;
//            else if(tmpSum < k)
//                for(TreeNode cur = stackL.pop().right; cur != null; cur = cur.left)
//                    stackL.push(cur);
//            else
//                for(TreeNode cur = stackR.pop().left; cur != null; cur = cur.right)
//                    stackR.push(cur);
//        }
//
//        return false;
// 差不多也算双指针吧。



//Runtime: 76 ms, faster than 29.04% of C++ online submissions for Two Sum IV - Input is a BST.
//Memory Usage: 36.8 MB, less than 48.99% of C++ online submissions for Two Sum IV - Input is a BST.
// 不知道有没有人用双指针 来逼近k。。。
    bool lt0653a(TreeNode* root, int k)
    {
        stack<TreeNode*> stk1;
        stk1.push(root);
        while (!stk1.empty())
        {
            TreeNode* np = stk1.top();
            stk1.pop();
            int tar = k - np->val;
            if (tar >= -10000 && tar <= 10000)
            {
                if (finda1(root, k - np->val, np))
                    return true;
            }
            if (np->left != nullptr)
                stk1.push(np->left);
            if (np->right != nullptr)
                stk1.push(np->right);
        }
        return false;
    }

    bool finda1(TreeNode* node, int target, TreeNode*& np)
    {
        if (node == nullptr)
            return false;
        if (node->val == target)            // 有没有 2个相同val 的不同结点。。bst应该没吧。
            return node != np;
        if (node->val > target)
            return finda1(node->left, target, np);
        else
            return finda1(node->right, target, np);
    }

};

int main()
{

    LT0653 lt;


    return 0;
}
