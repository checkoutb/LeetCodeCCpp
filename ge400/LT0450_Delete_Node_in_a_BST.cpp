
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

class LT0450
{
public:


// if (root.val > key) root.left = deleteNode(root.left, key);
// else if (root.val < key) root.right = deleteNode(root.right, key);

// if (!root->left)




//Runtime: 44 ms, faster than 7.26% of C++ online submissions for Delete Node in a BST.
//Memory Usage: 12.6 MB, less than 91.89% of C++ online submissions for Delete Node in a BST.
// ..
    TreeNode* lt0450c(TreeNode* root, int key)
    {
        if (root != NULL && root->val == key)
        {
            TreeNode* n = root;
            if (root->right == NULL)
            {
                root = root->left;
            }
            else
            {
                TreeNode* g = nextGreaterc1(root->right, root);
                g->left = root->left;
                g->right = root->right;
                root = g;
            }
            n->left == NULL;
        }
        else
        {
            dfsc1(root, key, NULL, false);
        }
        return root;
    }
    void dfsc1(TreeNode* n, int k, TreeNode* p, bool leftChild)
    {
        if (n == NULL)
            return;
        if (n->val == k)
        {
            if (n->right == NULL)
            {
                if (leftChild)
                {
                    p->left = n->left;
                }
                else
                {
                    p->right = n->left;
                }
                n->left = NULL;
            }
            else
            {
                TreeNode* g = nextGreaterc1(n->right, n);
                g->left = n->left;
                g->right = n->right;
                if (leftChild)
                {
                    p->left = g;
                }
                else
                {
                    p->right = g;
                }
                n->left = NULL;
                n->right = NULL;
            }
        }
        else if (n->val > k)
        {
            dfsc1(n->left, k, n, true);
        }
        else
        {
            dfsc1(n->right, k, n, false);
        }
    }
    TreeNode* nextGreaterc1(TreeNode* n, TreeNode* p)
    {
        bool tag1 = true;
        while (n->left != NULL)
        {
            tag1 = false;
            p = n;
            n = n->left;
        }
        if (tag1)
        {
            p->right = n->right;
        }
        else
        {
            p->left = n->right;
        }
        n->right = NULL;
        return n;
    }


    // 47/85 wrong
    TreeNode* r;
    TreeNode* lt0450b(TreeNode* root, int key)
    {
        r = root;
        dfsb1(root, key, NULL);
        return r;
    }
    void dfsb1(TreeNode* n, int k, TreeNode* p)
    {
        if (n == NULL)
            return;
        if (n->val == k)
        {
            if (n->right == NULL)
            {
                if (p == NULL)
                {
                    n->left == NULL;
                    r = n->left;
                }
                else
                {
                    if (p->left == n)
                    {
                        p->left = n->left;
                    }
                    else
                    {
                        p->right = n->left;
                    }
                }
            }
            else
            {
                TreeNode* node = n->right;
                TreeNode* parent = p;
                while (node->left != NULL)
                {
                    parent = node;
                    node = node->left;
                }
//                parent.left = NULL;
                if (node->right != NULL && parent != NULL)
                {
                    parent->left = node->right;
                }
                if (parent == NULL)
                {
                    node->left = n->left;
                    if (n->right != node)
                        node->right = n->right;
//                    else
//                        node->right = NULL;
                    r = node;
                }
                else
                {
                    node->left = n->left;
                    if (n->right != node)
                        node->right = n->right;
//                    else
//                        node->right = NULL;
                    if (n == p->left)
                    {
                        p->left = node;
                    }
                    else
                    {
                        p->right = node;
                    }
                }
            }
        }
        else
        {
            dfsb1(n->left, k, n);
            dfsb1(n->right, k, n);
        }
    }


    // ... unfinished...
    TreeNode* lt0450a(TreeNode* root, int key)
    {
        TreeNode* n = dfsa1(root, key, NULL);
        if (root->val == key)
            root = n;
        return root;
    }
    TreeNode* dfsa1(TreeNode* node, int k, TreeNode* parent)
    {
        if (node == NULL)
            return NULL;
        if (node->val == k)
        {
            TreeNode* n = findMina1(node->right, parent);
            if (n == NULL)
            {

            }
            if (parent == NULL)
            {
                n->left = node->left;
                n->right = node->right;
                return n;
            }
            if (node == parent->left)
            {
                parent->left = n;
            }
            else
            {
                parent->right = n;
            }
        }
        else
        {
            TreeNode* node2 = dfsa1(node->left, k, node);
            TreeNode* node3 = dfsa1(node->right, k, node);
        }
    }
    TreeNode* findMina1(TreeNode* node, TreeNode* parent)
    {
        if (node == NULL)
            return NULL;
//        TreeNode* prev = NULL;
        while (node->left != NULL)
        {
            parent = node;
            node = node->left;
        }
        parent->left = NULL;
        if (node->right != NULL)
        {
            parent->left = node->right;
        }
        return node;
    }
};

int main()
{
//    int tree[] = {5,3,6,2,4,-1,7};
//    int k = 3;

//    int tree[] = {5,3,6,2,4,-1,7};
//    int k = 5;

//    int tree[] = {43,10,44,3,12,-1,47,1,7,11,21,-1,-1,46,48};
//    int k = 47;

    int tree[] = {1,-1,2};
    int k = 2;

    TreeNode* root = convert2TreeNode(tree);
    showTreeNode(root);
    cout<<endl<<endl<<endl<<endl;
    LT0450 lt;
    TreeNode* ans = lt.lt0450c(root, k);
    showTreeNode(ans);
    return 0;
}
