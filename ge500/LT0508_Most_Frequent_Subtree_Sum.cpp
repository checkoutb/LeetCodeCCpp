
#include "../header/myheader.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class LT0508
{

public:

// d &&ｄ
// maxCount = max(maxCount, ++count[s]);
// dfs中计算maxCount，。。count是map。

// unordered_map
// 最后只要1个for，if (second > max) {ans.clear} else {ans+first}

//Runtime: 24 ms, faster than 57.37% of C++ online submissions for Most Frequent Subtree Sum.
//Memory Usage: 24.7 MB, less than 33.33% of C++ online submissions for Most Frequent Subtree Sum.
// map<int, int, decltype(comp)> map2(comp); ???怎么弄才行。。主要是dfsa1的map比较时会报错。auto放外面又是non-static
    vector<int> lt0508a(TreeNode* root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
//        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2){ return p1.second > p2.second; };
//        map<int, int, decltype(comp)> map2(comp);

        map<int, int> map2;
        dfsa1(root, map2);

        #ifdef __test
//        for (auto p : map2)
//            cout<<p.first<<" : "<<p.second<<endl;
        #endif // __test

        int m2 = map2.begin()->second;

        for (auto p : map2)
        {
            m2 = std::max(m2, p.second);
        }
        for (auto p : map2)
        {
            if (p.second == m2)
            {
                ans.push_back(p.first);
            }
        }
        return ans;
    }

    int dfsa1(TreeNode* node, auto& map2)
    {
        if (node == NULL)
            return 0;
        int left = dfsa1(node->left, map2);
        int right = dfsa1(node->right, map2);
        int val = left + right + node->val;
        map2[val] = map2[val] + 1;
        return val;
    }
};

int main()
{
    int arr[] = {5,2,-5};
    TreeNode* n = convert2TreeNode(arr);

    LT0508 lt;
    vector<int> v = lt.lt0508a(n);

    for_each(v.begin(), v.end(), fun_cout);
    cout<<endl;

    return 0;
}
