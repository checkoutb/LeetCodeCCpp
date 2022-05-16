
#include "../../header/myheader.h"

class LT
{
public:


// D D

//        while (q.size()) {
//            for (i = q.size() - 1, res = 0; i >= 0; --i) {
//                TreeNode* node = q.front(); q.pop();
//                res += node->val;
//                if (node->right) q.push(node->right);
//                if (node->left)  q.push(node->left);
//            }
//        }





//......
//Runtime: 160 ms, faster than 24.59% of C++ online submissions for Deepest Leaves Sum.
//Memory Usage: 59.8 MB, less than 76.70% of C++ online submissions for Deepest Leaves Sum.
//Runtime: 103 ms, faster than 86.79% of C++ online submissions for Deepest Leaves Sum.
//Memory Usage: 59.7 MB, less than 94.15% of C++ online submissions for Deepest Leaves Sum.
//Runtime: 184 ms, faster than 12.60% of C++ online submissions for Deepest Leaves Sum.
//Memory Usage: 59.7 MB, less than 76.70% of C++ online submissions for Deepest Leaves Sum.
    int ltd(TreeNode* root)
    {
        int mxdepth = -1;
        int ans = 0;
        dfsd1(root, mxdepth, ans, 0);
        return ans;
    }

    void dfsd1(TreeNode* node, int& mxdepth, int& ans, int depth)
    {
        if (node == nullptr)
            return;
        if (depth > mxdepth)
        {
            mxdepth = depth;
            ans = node->val;
        }
        else if (depth == mxdepth)
        {
            ans += node->val;
        }
        dfsd1(node->left, mxdepth, ans, depth + 1);
        dfsd1(node->right, mxdepth, ans, depth + 1);
    }




//Runtime: 120 ms, faster than 65.25% of C++ online submissions for Deepest Leaves Sum.
//Memory Usage: 59.8 MB, less than 53.52% of C++ online submissions for Deepest Leaves Sum.
    int ltc(TreeNode* root)
    {
        int arr[10001] = {0};
        int dep = dfsc1(root, arr, 0);
        return arr[dep];
    }

    // return max depth
//    int dfsc1(TreeNode* node, int* arr, int depth)            // ok
    int dfsc1(TreeNode* node, int (&arr)[10001], int depth)
    {
        if (node == nullptr)
            return depth - 1;
        arr[depth] += node->val;
        int t2 = dfsc1(node->left, arr, depth + 1);
        int t3 = dfsc1(node->right, arr, depth + 1);
        return max(t2, t3);
    }



//Runtime: 108 ms, faster than 81.84% of C++ online submissions for Deepest Leaves Sum.
//Memory Usage: 59.9 MB, less than 53.52% of C++ online submissions for Deepest Leaves Sum.
    int ltb(TreeNode* root)
    {
        vector<int> vi;
        dfsb1(root, vi, 0);
        return vi.back();
    }

    void dfsb1(TreeNode* node, vector<int>& vi, int depth)
    {
        if (node == nullptr)
            return;
        if (vi.size() == depth)
        {
            vi.push_back(node->val);
        }
        else
        {
            vi[depth] += node->val;
        }
        dfsb1(node->left, vi, depth + 1);
        dfsb1(node->right, vi, depth + 1);
    }



//Runtime: 199 ms, faster than 7.86% of C++ online submissions for Deepest Leaves Sum.
//Memory Usage: 59.8 MB, less than 76.70% of C++ online submissions for Deepest Leaves Sum.
    int lta(TreeNode* root)
    {
        map<int, int> map2;
        dfsa1(root, map2, 1);
        return map2.rbegin()->second;
    }

    void dfsa1(TreeNode* node, map<int, int>& map2, int depth)
    {
        if (node == nullptr)
            return;
        map2[depth] += node->val;
        dfsa1(node->left, map2, depth + 1);
        dfsa1(node->right, map2, depth + 1);
    }

};

int main()
{

    LT lt;


    return 0;
}
