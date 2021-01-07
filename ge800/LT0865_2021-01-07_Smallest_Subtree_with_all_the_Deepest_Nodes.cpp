
#include "../header/myheader.h"

class LT0865
{
public:

// D D

//class Result {
//    public:
//    TreeNode *node;
//    int dist;
//
//    Result(TreeNode *n,int d){
//        node=n;
//        dist=d;
//    }
//};



//int depth(TreeNode *root) {
//    return !root ? 0 : max(depth(root->left), depth(root->right)) + 1;
//}
//
//TreeNode* subtreeWithAllDeepest(TreeNode* root) {
//    int d = depth(root->left) - depth(root->right);
//    return !d ? root : subtreeWithAllDeepest(d > 0 ? root->left : root->right);
//}


//    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
//        return deep(root).second;
//    }
//
//    pair<int, TreeNode*> deep(TreeNode* root) {
//        if (!root) return {0, NULL};
//        pair<int, TreeNode*> l = deep(root->left), r = deep(root->right);
//
//        int d1 = l.first, d2 = r.first;
//        return {max(d1, d2) + 1, d1 == d2 ? root : d1 > d2 ? l.second : r.second};
//    }





//Runtime: 8 ms, faster than 48.26% of C++ online submissions for Smallest Subtree with all the Deepest Nodes.
//Memory Usage: 14.9 MB, less than 73.58% of C++ online submissions for Smallest Subtree with all the Deepest Nodes.
    TreeNode* lt0865a(TreeNode* root)
    {
        dfsa1(root, 1);
        return ans;
    }
    int mxdep = 0;
    TreeNode* ans = nullptr;
    int dfsa1(TreeNode* n, int dep)
    {
        if (n == nullptr)
        {
            mxdep = max(mxdep, dep - 1);
            return dep - 1;
        }
        int dl = dfsa1(n->left, dep + 1);
        int dr = dfsa1(n->right, dep + 1);
        if (dr == dl && dr == mxdep)
            ans = n;
        return max(dr, dl);
    }

};

int main()
{

//    int arr[] = {3,5,1,6,2,0,8,-1,-1,7,4};
//    int arr[] = {1};
    int arr[] = {0,1,3,-1,2};

    TreeNode* r = convert2TreeNode(arr);
    LT0865 lt;

    TreeNode* n = lt.lt0865a(r);

    showTreeNode(n, 5);
    return 0;
}
