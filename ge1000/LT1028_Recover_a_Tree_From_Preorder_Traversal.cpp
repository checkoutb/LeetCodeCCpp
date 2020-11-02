
#include "../header/myheader.h"

class LT1028
{
public:


// D D

//    int index = 0;
//    public TreeNode recoverFromPreorder(String S) {
//        return helper(S, 0);
//    }
//
//    public TreeNode helper(String s, int depth) {
//        int numDash = 0;
//        while (index + numDash < s.length() && s.charAt(index + numDash) == '-') {
//            numDash++;
//        }
//        if (numDash != depth) return null;                            // !!!!!
//        int next = index + numDash;
//        while (next < s.length() && s.charAt(next) != '-') next++;
//        int val = Integer.parseInt(s.substring(index + numDash, next));
//        index = next;
//        TreeNode root = new TreeNode(val);
//        root.left = helper(s, depth + 1);
//        root.right = helper(s, depth + 1);
//        return root;
//    }
// index, 所以 第一个helper的时候，就把  left子树 全部遍历完了。  接下来 就是 right子树的 根结点。

//        vector<TreeNode*> stack;
//        for (int i = 0, level, val; i < S.length();) {
//            for (level = 0; S[i] == '-'; i++)
//                level++;
//            for (val = 0; i < S.length() && S[i] != '-'; i++)
//                val = val * 10 + S[i] - '0';
//            TreeNode* node = new TreeNode(val);
//            while (stack.size() > level) stack.pop_back();                    // !!!!!
//            if (!stack.empty())
//                if (!stack.back()->left) stack.back()->left = node;
//                else stack.back()->right = node;
//            stack.push_back(node);
//        }
//        return stack[0];
// 尾递归 == stack。


// zheshi wo jianguo de zui jiandan de hard...xx.
//Runtime: 28 ms, faster than 74.51% of C++ online submissions for Recover a Tree From Preorder Traversal.
//Memory Usage: 20.4 MB, less than 8.73% of C++ online submissions for Recover a Tree From Preorder Traversal.
// 先序，所以 目前构建的tree的最右 侧 是 本node的位置。
    TreeNode* lt1028a(string S)
    {
        int i = 0;
        int n = std::stoi(S.substr(0, i = S.find('-')));            // not string:: .....
        TreeNode* root = new TreeNode(n);

        for (; i < S.size();)
        {
            int lv = 0;
            int val = 0;
            while (S[i] == '-')
            {
                lv++;
                i++;
            }
            while (i < S.size() && S[i] != '-')
            {
                val *= 10;
                val += (S[i] - '0');
                i++;
            }
            setNode(val, lv, root);
        }

        return root;
    }

    void setNode(int val, int lv, TreeNode* root)
    {
        TreeNode* node = root;
        while (lv-- > 1)
        {
            node = node->right == nullptr ? node->left : node->right;
        }
        if (node->left == nullptr)
            node->left = new TreeNode(val);
        else
            node->right = new TreeNode(val);
    }

};

int main()
{

//    string s = "1-2--3--4-5--6--7";
//    string s = "1-2--3---4-5--6---7";
    string s = "1-401--349---90--88";

    LT1028 lt;

    TreeNode* node = lt.lt1028a(s);

    showTreeNode(node, 5);

    return 0;
}
