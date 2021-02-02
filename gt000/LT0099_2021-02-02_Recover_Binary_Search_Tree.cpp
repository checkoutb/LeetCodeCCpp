
#include "../header/myheader.h"

class LT0099
{
public:

// D D


// 28ms
//public:
//    void recoverTree(TreeNode* root) {
//        pre = first = second = NULL;
//        traverse(root);
//        int tmp = first -> val;
//        first -> val = second -> val;
//        second -> val = tmp;
//    }
//
//private:
//    TreeNode *first, *second, *pre;
//    void traverse(TreeNode* root){
//        if(root == nullptr){
//            return;
//        }
//        traverse(root -> left);
//        if(pre != nullptr && first == nullptr && pre -> val >= root -> val){
//            first = pre;
//        }
//        if(pre != nullptr && first != nullptr && pre -> val >= root -> val){
//            second = root;
//        }
//        pre = root;
//        traverse(root -> right);
//    }


// 20ms 的 太长了。




//    TreeNode firstElement = null;
//    TreeNode secondElement = null;
//    // The reason for this initialization is to avoid null pointer exception in the first comparison when prevElement has not been initialized
//    TreeNode prevElement = new TreeNode(Integer.MIN_VALUE);
//
//    public void recoverTree(TreeNode root) {
//
//        // In order traversal to find the two elements
//        traverse(root);
//
//        // Swap the values of the two nodes
//        int temp = firstElement.val;
//        firstElement.val = secondElement.val;
//        secondElement.val = temp;
//    }
//
//    private void traverse(TreeNode root) {
//
//        if (root == null)
//            return;
//
//        traverse(root.left);
//
//        // Start of "do some business",
//        // If first element has not been found, assign it to prevElement (refer to 6 in the example above)
//        if (firstElement == null && prevElement.val >= root.val) {
//            firstElement = prevElement;
//        }
//
//        // If first element is found, assign the second element to the root (refer to 2 in the example above)
//        if (firstElement != null && prevElement.val >= root.val) {
//            secondElement = root;
//        }
//        prevElement = root;
//
//        // End of "do some business"
//
//        traverse(root.right);
//    }



// 没有 const TreeNode*& p1
//Runtime: 44 ms, faster than 43.69% of C++ online submissions for Recover Binary Search Tree.
//Memory Usage: 58.7 MB, less than 19.59% of C++ online submissions for Recover Binary Search Tree.
// 只能dfs，根据 本结点 和 左子树最大值， 右子树最小值，来判断 本结点是否正确， 当本结点不正确时， 可能是  本结点的问题，也可能是 最大值/最小值的问题。
// 如果是上下互换，应该是 最高的节点 和 最低的节点。
// 如果是 左右互换。。
// 3个方向都是错的，说明这个 结点是换的。
// discuss title.
// in order, 会出现2个 无序的数，
// 怎么找 无序的数。。。
// ... 直接组建一个bst，， 就是 inorder 找到值，然后排序，然后再 inorder 给每个node 赋值。。。
    void lt0099a(TreeNode* root)
    {
        vector<TreeNode*> vt;
        inorder(root, vt);
        vector<TreeNode*> vt2(begin(vt), end(vt));
        sort(begin(vt2), end(vt2), [](const TreeNode* p1, const TreeNode* p2) { return p1->val < p2->val; });
        vector<int> vi;
        for (int i = 0; i < vt2.size(); ++i)
        {
            if (vt[i]->val != vt2[i]->val)
            {
                vi.push_back(i);
            }
        }
        int t1 = vt[vi[0]]->val;
        int t2 = vt[vi[1]]->val;
        vt[vi[0]]->val = t2;
        vt[vi[1]]->val = t1;
    }
    void inorder(TreeNode* node, vector<TreeNode*>& vt)
    {
        if (node == nullptr)
            return;
        inorder(node->left, vt);
        vt.push_back(node);
        inorder(node->right, vt);
    }

};

int main()
{
//    int arr[] = {1,3,-1,-1,2};
    int arr[] = {3,1,4,-1,-1,2};

    TreeNode* r = convert2TreeNode(arr);

    showTreeNode(r, 5);

    LT0099 lt;

    lt.lt0099a(r);

    showTreeNode(r, 5);

    return 0;
}
