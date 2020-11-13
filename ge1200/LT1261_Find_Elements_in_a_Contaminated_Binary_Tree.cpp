
#include "../header/myheader.h"

class LT1261
{
public:



};


// D D

// .. 用set保存。。

// 转成二进制，可以看到 后面加0是左子树， 后面加1是右子树。




//Runtime: 56 ms, faster than 73.60% of C++ online submissions for Find Elements in a Contaminated Binary Tree.
//Memory Usage: 23.2 MB, less than 60.47% of C++ online submissions for Find Elements in a Contaminated Binary Tree.
//          0
//      1       2
//   3   4    5     6
// 7  8 9 10,11 12,13 14
class FindElements {

    void dfsinita1(TreeNode* node, int val)
    {
        node->val = val;
        if (node->left)
            dfsinita1(node->left, 2 * val + 1);
        if (node->right)
            dfsinita1(node->right, 2 * val + 2);
    }

    TreeNode* rt;

public:
    FindElements(TreeNode* root) {
        rt = root;
        dfsinita1(rt, 0);
    }

    bool find(int target) {
        vector<int> v;
        while (target > 0)
        {
            v.push_back(target % 2);        // 0:right, 1:left
            target -= (target % 2 == 0 ? 2 : 1);
            target /= 2;
        }
        TreeNode* node = rt;
        #ifdef __test
//        showVectorInt(v);
        #endif // __test
        for (int i = v.size() - 1; i >= 0; --i)
        {
            if (v[i] == 0)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
            if (node == nullptr)
                return false;
        }
        return true;
    }
};


int main()
{

//["FindElements","find","find","find"]
//[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
    int arr[] = {1,1,1,1,1};

    TreeNode* node = convert2TreeNode(arr);
    showTreeNode(node);

    FindElements fe(node);
    showTreeNode(node, 3);

    cout<<" = = = ="<<endl;
    cout<<endl<<fe.find(1)<<endl;
    cout<<" = = == === "<<endl;
    cout<<endl<<fe.find(3)<<endl;
    cout<<" = = == === "<<endl;
    cout<<endl<<fe.find(5)<<endl;
    cout<<" = = == === "<<endl;

    LT1261 lt;


    return 0;
}
