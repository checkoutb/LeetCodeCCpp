
#include "../header/myheader.h"

class LT0971
{
public:

// D D
// stack dfs

//        if (!node) return true;
//        if (node->val != v[i++]) return false;
//        if (node->left && node->left->val != v[i]) {
//            res.push_back(node->val);
//            return dfs(node->right, v) && dfs(node->left, v);
//        }
//        return dfs(node->left, v) && dfs(node->right, v);
// swap 后的比较就交给 第二行了。


// tuxue...
//Runtime: 8 ms, faster than 52.50% of C++ online submissions for Flip Binary Tree To Match Preorder Traversal.
//Memory Usage: 13.2 MB, less than 81.41% of C++ online submissions for Flip Binary Tree To Match Preorder Traversal.
    vector<int> lt0971a(TreeNode* root, vector<int>& voyage)
    {
        bool can = true;
        vector<int> ans;
        int i = 0;

        if (root->val != voyage[i++])
        {
            ans.push_back(-1);
            return ans;
        }

        dfsa1(root, true, voyage, i, can, ans);
        dfsa1(root, false, voyage, i, can, ans);

        if (!can)
            return vector<int>(1, -1);

        return ans;
    }

    void dfsa1(TreeNode* parent, bool isLeft, vector<int>& v, int& i, bool& can, vector<int>& ans)
    {
        if (parent == nullptr || !can || i >= v.size() || (isLeft ? parent->left : parent->right) == nullptr)
            return;
        if (parent->left == nullptr && parent->right == nullptr)
        {
            return;
        }
        int tar = v[i++];

        int val = getVala1(parent, isLeft);
        if (parent->left == nullptr || parent->right == nullptr)
        {
            val = getVala1(parent, parent->left != nullptr);
            if (tar != val)
            {
                can = false;
                return;
            }
            dfsa1(parent->left != nullptr ? parent->left : parent->right, true, v, i, can, ans);
            dfsa1(parent->left != nullptr ? parent->left : parent->right, false, v, i, can, ans);
        }
        else
        {
            if (tar != val)
            {
                if (!isLeft)
                {
                    can = false;
                    return;
                }
                swapa1(parent);
                val = getVala1(parent, isLeft);
                if (val != tar)
                {
                    can = false;
                    return;
                }
                ans.push_back(parent->val);
            }
            dfsa1(isLeft ? parent->left : parent->right, true, v, i, can, ans);
            dfsa1(isLeft ? parent->left : parent->right, false, v, i, can, ans);
        }

    }

    int getVala1(TreeNode* parent, bool isLeft)
    {
        if (isLeft)
        {
            if (parent->left == nullptr)
                return -1;
            return parent->left->val;
        }
        else
        {
            if (parent->right == nullptr)
                return -1;
            return parent->right->val;
        }
    }

    void swapa1(TreeNode* node)
    {
        TreeNode* t2 = node->left;
        node->left = node->right;
        node->right = t2;
    }

};

int main()
{

//    int arr[] = {1,2};
//    vector<int> v = {1,2};

//    int arr[] = {1,-1,2,-1,-1,-1,3};
//    vector<int> v = {1,2,3};

    int arr[] = {2,1,4,5,-1,3};
    vector<int> v = {2,4,3,1,5};


    TreeNode* root = convert2TreeNode(arr);
    showTreeNode(root, 3);
    cout<<endl<<endl;

    LT0971 lt;

    vector<int> v2 = lt.lt0971a(root, v);

    for_each(begin(v2), end(v2), fun_cout);
    cout<<endl;

    return 0;
}
