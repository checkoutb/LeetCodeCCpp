
#include "../header/myheader.h"

class LT0501
{
public:



//Runtime: 36 ms, faster than 18.19% of C++ online submissions for Find Mode in Binary Search Tree.
//Memory Usage: 27.9 MB, less than 14.29% of C++ online submissions for Find Mode in Binary Search Tree.

// bst有什么用。
// 用于快速获得相同val的node的数量？。。这里想的是利用bst来搜索相同val，而非中序遍历。。。

// discuss。。。中序遍历。。。
// 类属性来保存previous。

    vector<int> lt0501a(TreeNode* root)
    {
//        vector<int> ans;
        map<int, int> map2;
        set<int> set2;
        int max = 0;

        dfsa1(root, map2);

        for (map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            if (it->second > max)
            {
                max = it->second;
                set2.clear();
                set2.insert(it->first);
            }
            else if (it->second == max)
            {
                set2.insert(it->first);
            }
        }
        vector<int> ans(set2.begin(), set2.end());
        return ans;
    }

    void dfsa1(TreeNode* node, map<int, int>& map2)
    {
        if (node == NULL)
            return;
        map2[node->val] = map2[node->val] + 1;
        dfsa1(node->left, map2);
        dfsa1(node->right, map2);
    }
};

int main()
{
    int arr[] = {1,-1,2,-1,-1,2};
    TreeNode* root = convert2TreeNode(arr);

    LT0501 lt;
    vector<int> v = lt.lt0501a(root);

    for_each(v.begin(), v.end(), fun_cout);

    return 0;
}
