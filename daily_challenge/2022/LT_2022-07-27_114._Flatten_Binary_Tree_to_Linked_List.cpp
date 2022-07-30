
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //TreeNode* prev = NULL;
    //void flatten(TreeNode* root) {
    //    if (root == NULL) return;
    //    flatten(root->right);
    //    flatten(root->left);
    //    root->right = prev;
    //    root->left = NULL;
    //    prev = root;
    //}


    //TreeNode* now = root;
    //while (now)
    //{
    //    if (now->left)
    //    {
    //        //Find current node's prenode that links to current node's right subtree
    //        TreeNode* pre = now->left;
    //        while (pre->right)
    //        {
    //            pre = pre->right;
    //        }
    //        pre->right = now->right;
    //        //Use current node's left subtree to replace its right subtree(original right 
    //        //subtree is already linked by current node's prenode
    //        now->right = now->left;
    //        now->left = NULL;
    //    }
    //    now = now->right;
    //}
    // �� now->right ���ص� now->left->right->r-..->r ��ȥ�� ���� ���������ʱ�� ������ԭ�ȵ� now->left �� ���ô��� ԭ�ȵ� now->right











//Runtime: 15 ms, faster than 24.78 % of C++ online submissions for Flatten Binary Tree to Linked List.
//Memory Usage : 12.6 MB, less than 78.06 % of C++ online submissions for Flatten Binary Tree to Linked List.
    void lta(TreeNode* root)
    {
        if (root == nullptr)
            return;

        TreeNode* t2 = root;
        TreeNode* t2r = root->right;
        if (root->left != nullptr)
        {
            t2 = dfsa1(root->left, t2);
            root->left = nullptr;
        }
        if (t2r != nullptr)
            t2 = dfsa1(t2r, t2);

    }

    TreeNode* dfsa1(TreeNode* node, TreeNode* pre)
    {
        pre->right = node;
        TreeNode* t2 = node;
        TreeNode* t2r = node->right;
        if (node->left != nullptr)
        {
            t2 = dfsa1(node->left, t2);
            node->left = nullptr;
        }
        if (t2r != nullptr)
        {
            t2 = dfsa1(t2r, t2);
        }
        return t2;
    }

};

int main()
{

    LT lt;

    int arr[] = { 1,2,5,3,4,-1,6 };


    TreeNode* r = convert2TreeNode(arr);

    showTreeNode(r, 5);

    lt.lta(r);

    showTreeNode(r, 5);

    return 0;
}
