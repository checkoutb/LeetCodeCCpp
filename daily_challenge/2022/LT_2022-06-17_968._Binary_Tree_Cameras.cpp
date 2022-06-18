
#include "../../header/myheader.h"

class LT
{
public:

    // D D


    //If we set a camera at the leaf, the camera can cover the leafand its parent.
    //    If we set a camera at its parent, the camera can cover the leaf, its parentand its sibling.
    //
    //    We can see that the second plan is always better than the first.
    //    Now we have only one option, set up camera to all leaves' parent.
    // 
    //    Here is our greedy solution :
    //      Set cameras on all leaves' parents, thenremove all covered nodes.
    //      Repeat step 1 until all nodes are covered.
    // 
    //Apply a recusion function dfs.
    //    Return 0 if it's a leaf.
    //    Return 1 if it's a parent of a leaf, with a camera on this node.
    //    Return 2 if it's coverd, without a camera on this node.

    //int res = 0;
    //int minCameraCover(TreeNode* root) {
    //    return (dfs(root) < 1 ? 1 : 0) + res;
    //}

    //int dfs(TreeNode* root) {
    //    if (!root) return 2;
    //    int left = dfs(root->left), right = dfs(root->right);
    //    if (left == 0 || right == 0) {
    //        res++;
    //        return 1;
    //    }
    //    return left == 1 || right == 1 ? 2 : 0;
    //}



    //#define NO_CAMERA       0
    //#define HAS_CAMERA      2
    //#define NOT_NEEDED      1
    //int ans = 0;
    //int dfs(TreeNode* root) {
    //    if (!root) return NOT_NEEDED;
    //    int l = dfs(root->left);
    //    int r = dfs(root->right);
    //    if (l == NO_CAMERA || r == NO_CAMERA) {
    //        ans++;
    //        return HAS_CAMERA;
    //    }
    //    else if (l == HAS_CAMERA || r == HAS_CAMERA) {
    //        return NOT_NEEDED;
    //    }
    //    else {
    //        return NO_CAMERA;
    //    }
    //}
    //int minCameraCover(TreeNode* root) {
    //    if (dfs(root) == NO_CAMERA) ans++;
    //    return ans;
    //}


    //enum { NOT_NEEDED = -1, NO_CAMERA = 0, HAS_CAMERA = 1 };




//Runtime: 21 ms, faster than 33.50 % of C++ online submissions for Binary Tree Cameras.
//Memory Usage : 21.3 MB, less than 23.37 % of C++ online submissions for Binary Tree Cameras.
    int ltb(TreeNode* root)
    {
        tuple<bool, bool, int> tp = dfsb1(root);
        return std::get<2>(tp) + (!std::get<1>(tp));
    }


    // is camera ? is watched ? camera num
    tuple<bool, bool, int> dfsb1(TreeNode* n)
    {
        if (n == nullptr)
            return { false, true, 0 };
        if (n->left == nullptr && n->right == nullptr)
            return std::make_tuple(false, false, 0);

        bool lb1, lb2;
        int ln;
        std::tie(lb1, lb2, ln) = dfsb1(n->left);

        tuple<bool, bool, int> tup2 = dfsb1(n->right);
        int rb1 = std::get<0>(tup2);
        int rb2 = std::get<1>(tup2);
        int rn = std::get<int>(tup2);

        tuple<bool, bool, int> ans;

        if (lb1)
        {
            if (rb2)
            {
                ans = { false, true, rn + ln };     // 左相机，右可见
            }
            else
            {
                ans = { true, true, rn + ln + 1 };      // 左相机，右不可见
            }
        }
        else
        {
            if (lb2)
            {
                if (rb1)
                {
                    ans = { false, true, rn + ln };     // 左可见，右相机
                }
                else
                {
                    if (rb2)
                        ans = { false, false, rn + ln };        // 左可见，右可见
                    else
                        ans = { true, true, rn + ln + 1 };      // 左可见，右不可见。
                }
            }
            else
            {
                ans = { true, true, rn + ln + 1 };      // 左不可见。
            }
        }
#ifdef __test
        cout << n->val << " : [" << get<0>(ans) << ", " << get<1>(ans) << ", " << get<2>(ans) << "]" << endl;
#endif
        return ans;
    }

    //int dfsb1(TreeNode* n)
    //{
    //    if (n == nullptr)
    //        return 0;
    //    if (n->left == nullptr && n->right == nullptr)          // leaf node
    //        return 0;

    //    int l = dfsb1(n->left);
    //    int r = dfsb1(n->right);

    //    if (l > 0)          // i am watched
    //    {
    //        if (r > 0)      // left, right are camera
    //        {
    //            return -(l + r);
    //        }
    //        else
    //        {

    //        }
    //    }
    //    else
    //    {
    //        if (r > 0)      // i am watched
    //        {

    //        }
    //        else
    //        {

    //        }
    //    }

    //}


    // error
    int lta(TreeNode* root)
    {
        //unordered_map<TreeNode*, int> map2;
        int ans = 0;
        ans = dfsa1(root);
        return max(1, abs(ans));
    }


    // +:you(caller) are be watched, -:you are not.    number: how many camera
    // +:node (be called) is camera.
    int dfsa1(TreeNode* n)
    {
        //if (n -> left == nullptr && n -> right == nullptr)
        //    return 0;
        if (n == nullptr)
            return 0;
        if (n->left == nullptr && n->right == nullptr)
        {
            return 0;
        }

        int l = dfsa1(n->left);
        int r = dfsa1(n->right);

#ifdef __test
        cout << (n->val) << " - " << l << ", " << r << endl;
#endif
        if (l > 0 && r > 0)         // not ||   ... child is null ...
        {
            return -(abs(l) + abs(r));
        }
        return abs(l) + abs(r) + 1;
    }


    // 父节点不是camera，本节点也可以不是。  所以是 父节点 有没有被覆盖， 没有，则本节点必须camera。
    // 而且，感觉任何时候 都是 安装得 越高越好。。  所以是： 子节点有没有被监控，没有，本节点就需要一个camera。。。？

    //// return : first: node is camera,min ans,    second: node is not camera,min ans
    //pair<int, int> dfsa1(TreeNode* n, bool p)     // bool p: is parent camera ?
    //{
    //    if (n == nullptr)
    //        return 0;

    //    if (p)      // parent is camera, i can install camera or not.
    //    {

    //    }
    //    else
    //    {
    //                // parent is not camera, i must install camera

    //        dfsa1(n->left, )
    //    }
    //}

    


};

int main()
{

    LT lt;

    // 1
    //int arr[] = { 1,2,-1,3,4 };

    // 2
    //int arr[] = { 1,2,-1,3,-1,-1,-1,4,-1,-1,-1,-1,-1,-1,-1,-1,5 };


    // [0, 0, 0, null, null, null, 0]   2
    //int arr[] = { 1,2,3,-1,-1,-1,4 };

    // [0,0,null,null,0,0,null,null,0,0]   2
    TreeNode* arr[6] = {};
    for (int i = 0; i < 6; ++i)
    {
        arr[i] = new TreeNode(i + 1);
    }
    //arr[0]->left = arr[1];
    //arr[1]->right = arr[2];
    //arr[2]->left = arr[3];
    //arr[3]->right = arr[4];
    //arr[4]->left = arr[5];

    arr[0]->left = arr[1];
    arr[1]->left = arr[2];
    arr[2]->left = arr[3];
    arr[3]->left = arr[4];
    arr[4]->left = arr[5];

    TreeNode* r = arr[0];

    // TreeNode* r = convert2TreeNode(arr);

    showTreeNode(r, 4);

    cout << lt.ltb(r) << endl;

    return 0;
}
