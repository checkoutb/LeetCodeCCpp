
#include "../header/myheader.h"

class LT2415
{
public:

// D D

//    vector<TreeNode*> q{root};
//    while (!q.empty() && q[0]->left != nullptr) {
//        vector<TreeNode*> q1;
//        for (auto n : q)
//            q1.insert(end(q1), {n->left, n->right});
//        if (++level % 2)
//            for (int i = 0, j = q1.size() - 1; i < j; ++i, --j)
//                swap(q1[i]->val, q1[j]->val);
//        swap(q, q1);
//    }


//    public TreeNode reverseOddLevels(TreeNode root) {
//        // We call the function from lvl 0, and everything starts from lvl 1
//        traverse(root.left, root.right, 1);
//        return root;
//    }
//
//    public void traverse(TreeNode node1, TreeNode node2, int lvl) {
//        if (node1 == null || node2 == null) return;
//
//        if (lvl % 2 == 1){
//            int temp = node1.val;
//            node1.val = node2.val;
//            node2.val = temp;
//        }
//
//        traverse(node1.left, node2.right, lvl + 1);
//        traverse(node1.right, node2.left, lvl + 1);
//    }
//
// 最左 和 最右 匹配， 所以 一侧选left  一侧选right。



//Runtime: 289 ms, faster than 88.97% of C++ online submissions for Reverse Odd Levels of Binary Tree.
//Memory Usage: 73.2 MB, less than 72.83% of C++ online submissions for Reverse Odd Levels of Binary Tree.
    TreeNode* lt2415a(TreeNode* root)
    {
        vector<TreeNode*> vt;
        vt.push_back(root);
        int lvl = 0;
        while (vt[0]->left != nullptr)
        {
            ++lvl;
            vector<TreeNode*> vt2(vt.size() * 2);

            for (int i = 0; i < vt.size(); ++i)
            {
                vt2[i * 2] = vt[i]->left;
                vt2[i * 2 + 1] = vt[i]->right;
            }

            if (lvl % 2)
            {
                for (int i = 0; i < vt.size(); ++i)
                {
                    swap(vt2[i]->val, vt2[vt2.size() - 1 - i]->val);
                }
            }
            swap(vt, vt2);
        }

        return root;

        //dfsa1(root, 0);
        //return root;
    }

    // ...
    void dfsa1(TreeNode* node, int lvl)
    {
        if (node == nullptr)
            return;

        if (lvl % 2)
        {
            ;
        }
        else
        {
            TreeNode* t2 = node->left;
            node->left = node->right;
            node->right = t2;
        }

        dfsa1(node->left, lvl + 1);
        dfsa1(node->right, lvl + 1);

    }

};

int main()
{

    LT2415 lt;


    return 0;
}
