
#include "../header/myheader.h"

class LT0968
{
public:


// D D
//Return 0 if it's a leaf.
//Return 1 if it's a parent of a leaf, with a camera on this node.
//Return 2 if it's coverd, without a camera on this node.

//    int res = 0;
//    int minCameraCover(TreeNode* root) {
//        return (dfs(root) < 1 ? 1 : 0) + res;
//    }
//
//    int dfs(TreeNode* root) {
//        if (!root) return 2;
//        int left = dfs(root->left), right = dfs(root->right);
//        if (left == 0 || right == 0) {
//            res++;
//            return 1;
//        }
//        return left == 1 || right == 1 ? 2 : 0;
//    }


//Runtime: 16 ms, faster than 63.92% of C++ online submissions for Binary Tree Cameras.
//Memory Usage: 21.3 MB, less than 71.60% of C++ online submissions for Binary Tree Cameras.
    int lt0968a(TreeNode* root)
    {
        int ans = 0;
        int t2 = dfsa1(root, ans);
        if (t2 == 0)
            ans++;
        return max(ans, 1);
    }

    // 0: (没相机)没有被拍，
    // 1: 没相机，被拍了
    // 2: 有相机
    int dfsa1(TreeNode* node, int& ans)
    {
        int t1 = 3;
        int t2 = -1;
        if (node->left != nullptr)
        {
            int t3 = dfsa1(node->left, ans);
            t1 = min(t1, t3);
            t2 = max(t1, t3);
        }
        if (node->right != nullptr)
        {
            int t3 = dfsa1(node->right, ans);
            t1 = min(t1, t3);
            t2 = max(t2, t3);
        }
        if (t1 == 0)        // 只要有一个子结点 没有被拍到，那么 自己必须有相机
        {
            ans++;
            return 2;
        }
        if (t2 == 2)        // 如果子结点都被拍到了， 并且有一个子结点 有相机，那么自己 就已经被拍照了，且 自己不需要相机。
        {
            return 1;
        }
        if (t1 == 1)        // 子结点都被拍到了，但是子结点都没有相机，那么 自己没有被拍到，也没有相机。
        {
            return 0;
        }
        if (t1 == 2)        // 这个应该和 t2 == 2 重复了。
        {
            return 1;
        }
        return 0;
    }

};

int main()
{

//    int arr[] = {0,0,-1,0,0,-1,-1};
//
//    int arr[] = {0,0,0,-1,-1,-1,0};

//[0,0,null,null,0,0,null,null,0,0]
//     1
//   1
//  0 1
//   1 0
//  0 1
//   1
//
//    int arr[] = {0,0,-1,-1,0,-1,-1,-1,-1,0,-1,-1,-1,-1,-1,}


//[0, 0,0 ,null,0,0,null   ,null,0]


//    int arr[] = {0,0,0,-1,0,0,-1,-1,-1,-1,0};
//

    int arr[] = {0,0,0,-1,-1,-1,0};

    TreeNode* node = convert2TreeNode(arr);


//    int arr[] = {0,0,0,0,0};
//    TreeNode* node = new TreeNode(0);
//    TreeNode* n2 = node;
//    for (int i = 0; i < 5; i++)
//    {
//        n2->left = new TreeNode(0);
//        n2 = n2->left;
//    }

    showTreeNode(node, 3);
    cout<<endl<<endl;

    LT0968 lt;

    cout<<lt.lt0968a(node)<<endl;

    return 0;
}
