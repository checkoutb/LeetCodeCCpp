
#include "../header/myheader.h"

class LT1457
{
public:

// D D

//v1=v1^(1<<root->val-1);
//((v1&v1-1)==0)
// 只需要知道 奇数 还是偶数，所以 用int的 位来表示。


//    int dfs(TreeNode* root, int count) {
//        if (!root) return 0;
//        count ^= 1 << (root->val - 1);
//        int res = dfs(root->left, count) + dfs(root->right, count);
//        if (root->left == root->right && (count & (count - 1)) == 0) res++;
//        return res;
//    }



//Runtime: 196 ms, faster than 83.70% of C++ online submissions for Pseudo-Palindromic Paths in a Binary Tree.
//Memory Usage: 108.8 MB, less than 95.98% of C++ online submissions for Pseudo-Palindromic Paths in a Binary Tree.
// 看起来，path 必然从 root 开始。  而且 似乎也是必然 停止在 叶子结点？               yes
    int lt1457a(TreeNode* root)
    {
        vector<int> arr(10);
        int ans = dfsa1(root, arr);
        return ans;
    }

    int dfsa1(TreeNode* node, vector<int>& arr)
    {
        if (node == nullptr)
            return 0;
        arr[node->val]++;
        if (node->left == nullptr && node->right == nullptr)
        {
            bool hasOdd = false;
            for (int i = 1; i < 10; ++i)
            {
                if (arr[i] % 2 == 1)
                {
                    if (hasOdd)
                    {
                        arr[node->val]--;
                        return 0;
                    }
                    hasOdd = true;
                }
            }
            arr[node->val]--;
            return 1;
        }
        else
        {
            int ans = dfsa1(node->left, arr) + dfsa1(node->right, arr);
            arr[node->val]--;
            return ans;
        }
    }

};

int main()
{
//    int arr[] = {2,3,1,3,1,-1,1};
    int arr[] = {9};

    TreeNode* r = convert2TreeNode(arr);
    LT1457 lt;

    cout<<lt.lt1457a(r);

    return 0;
}
