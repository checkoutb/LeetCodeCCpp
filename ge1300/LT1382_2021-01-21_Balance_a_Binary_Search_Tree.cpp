
#include "../header/myheader.h"

class LT1382
{
public:

// D D

//int makeVine(TreeNode *grand, int cnt = 0) {
//  auto n = grand->right;
//  while (n != nullptr) {
//    if (n->left != nullptr) {
//      auto old_n = n;
//      n = n->left;
//      old_n->left = n->right;
//      n->right = old_n;
//      grand->right = n;
//    }
//    else {
//        ++cnt;
//        grand = n;
//        n = n->right;
//    }
//  }
//  return cnt;
//}
//void compress(TreeNode *grand, int m) {
//  auto n = grand->right;
//  while (m-- > 0) {
//    auto old_n = n;
//    n = n->right;
//    grand->right = n;
//    old_n->right = n->left;
//    n->left = old_n;
//    grand = n;
//    n = n->right;
//  }
//}
//TreeNode* balanceBST(TreeNode *root) {
//  TreeNode grand;
//  grand.right = root;
//  auto cnt = makeVine(&grand);
//  int m = pow(2, int(log2(cnt + 1))) - 1;
//  compress(&grand, cnt - m);
//  for (m = m / 2; m > 0; m /= 2)
//    compress(&grand, m);
//  return grand.right;
//}



//Runtime: 96 ms, faster than 99.42% of C++ online submissions for Balance a Binary Search Tree.
//Memory Usage: 47 MB, less than 95.35% of C++ online submissions for Balance a Binary Search Tree.
    TreeNode* lt1382a(TreeNode* root)
    {
        vector<TreeNode*> vt;
        dfsa1(root, vt);
        TreeNode* ans = relation(vt, 0, vt.size() - 1);
        return ans;
    }
    void dfsa1(TreeNode* n, vector<TreeNode*>& vt)
    {
        if (n == nullptr)
            return;
        dfsa1(n->left, vt);
        vt.push_back(n);
        dfsa1(n->right, vt);
        n->left = nullptr;
        n->right = nullptr;
    }
    TreeNode* relation(vector<TreeNode*>& vt, int st, int en)
    {
        if (st > en)
            return nullptr;
        int ans = (st + en + 1) / 2;
        TreeNode* lft = relation(vt, st, ans - 1);
        TreeNode* rht = relation(vt, ans + 1, en);
        vt[ans]->left = lft;
        vt[ans]->right = rht;
        return vt[ans];
    }

    // deprecated
    // 当左子树空，右子树是满二叉树，怎么平衡。  右子树 左节点 为新的 右子树 root，  新root的原左子数 作为 原root的 右子树。
    // 就是 深的子数的root 作为新root。
    // return <root, depth>
    pair<TreeNode*, int> dfsa1a(TreeNode* n)
    {
        if (n == nullptr)
            return {nullptr, 0};
        pair<TreeNode*, int> pl = dfsa1a(n->left);
        pair<TreeNode*, int> pr = dfsa1a(n->right);
        TreeNode* ans = n;
        if (std::abs(pl.second - pr.second) > 1)
        {
            if (pl.second > pr.second)
            {
                ans = pl.first;
            }
            else
            {
                ans = pr.first;
            }
        }
        return {ans, -1};
    }

};

int main()
{

    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);

    n1->right = n2;
    n2->right = n3;
    n3->right = n4;


    LT1382 lt;

    TreeNode* ans = lt.lt1382a(n1);

    showTreeNode(ans, 5);

    return 0;
}
