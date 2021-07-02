
#include "../../header/myheader.h"

class LT
{
public:

// D D


//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if (root == NULL || root == p || root == q)
//            return root;
//        TreeNode* left = lowestCommonAncestor(root->left, p, q);
//        TreeNode* right = lowestCommonAncestor(root->right, p, q);
//        if (left == NULL)
//            return right;
//        else
//            return (right == NULL)? left:root;
// !! p是q的子结点也行。 因为是 left != null && right != null 才会返回当前结点。 这种情况最多出现一次。  没有出现就是p是q的子结点。
// 都可以用这种逻辑， 就是： 左边和右边 都非null，就返回自己; 然后 优先返回非空的。


//def lowest_common_ancestor(root, p, q)
//    return root if [nil, p, q].index root
//    left = lowest_common_ancestor(root.left, p, q)
//    right = lowest_common_ancestor(root.right, p, q)
//    left && right ? root : left || right
//end
// ruby的， 想起来， nullptr就是0,  c++也能2个指针 || 吧。


//def lowestCommonAncestor(self, root, p, q):
//    if root in (None, p, q): return root
//    subs = [self.lowestCommonAncestor(kid, p, q)
//            for kid in (root.left, root.right)]
//    return root if all(subs) else max(subs)
// c++ 也能 指针比较大小。。





// AC
    TreeNode* lta(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        pair<int, TreeNode*> p3 = dfsa1(root, p, q);
        return p3.second;
    }
    // 0: not find either,  1:find p; 2: find q; 3: find both
    pair<int, TreeNode*> dfsa1(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if (node == nullptr)
            return {0, nullptr};
        int t2 = 0;
        if (node == p)
            t2 = 1;
        if (node == q)
            t2 = 2;

        pair<int, TreeNode*> p2 = dfsa1(node->left, p, q);
        if (p2.first == 3)
            return p2;
        t2 |= p2.first;
        if (t2 == 3)
            return {3, node};

        pair<int, TreeNode*> p3 = dfsa1(node->right, p, q);
        if (p3.first == 3)
            return p3;
        t2 |= p3.first;
        return {t2, node};
    }

};

int main()
{
    int arr[] = {3,5,1,6,2,0,8,-1,-1,7,4};

    TreeNode* r = convert2TreeNode(arr);
//    TreeNode* p = r->left;
//    TreeNode* q = r->left->right->right;
    TreeNode* p = r->left;
    TreeNode* q = r->right;

//    int arr[] = {1,2};
//    TreeNode* r = convert2TreeNode(arr);
//    TreeNode* p = r;
//    TreeNode* q = r->left;

//    int arr[] = {};

    LT lt;

    TreeNode* ans = lt.lta(r,p,q);
    cout<<ans->val<<endl;

    deleteTreeNode(r);

    string s = "asdasd";
    string* ps = &s;
    string* pi = nullptr;
//    int* pi = nullptr;
//    cout<<*(ps | pi)<<endl;      // invalid... 不过 operator| 写一下就应该可以了。。
    long p2 = (long long) ps;
    long p3 = (long) pi;

    cout<<p2<<", "<<p3<<";;; "<<ps<<", "<<pi<<", "<<(long long) ps<<endl;

    p2 |= p3;       // +

    string* p5 = (string*) p2;
    cout<<*p5<<endl;

    return 0;
}
