
#include "../header/myheader.h"

class LT1367
{
public:

// D

//    bool isSubPath(ListNode* head, TreeNode* root) {
//        if (!head) return true;
//        if (!root) return false;
//        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
//    }
//
//    bool dfs(ListNode* head, TreeNode* root) {
//        if (!head) return true;
//        if (!root) return false;
//        return head->val == root->val && (dfs(head->next, root->left) || dfs(head->next, root->right));
//    }
// 感觉差不多啊，怎么我的就tle了。。可能是 优先全部 dfs(root), 然后 isSubPath(left) ， 而不是 dfs的时候 就 isSubPath。
// 毕竟 后者的几率小。。
// 好像差的挺多的， 这里是 假设root是 head的起始， 然后开始 dfs，碰到 val 不相等 就直接退出。 然后 假设 root->left 是 起始。
// 所以只需要遍历一遍树， 每次遍历树的结点的时候，最多可能 再遍历 链表 长度 层。

// 我的是，遍历一遍树，每次遍历结点的时候，会再新建一个遍历，把当前结点作为head的父结点。 所以膨胀得很快。特别是碰到43的 全1。数量级感觉是2^n。n是深度。


// dp + dfs
// ...


// 61 error,  43 tle.
    bool lt1367a(ListNode* head, TreeNode* root)
    {
        return dfsa1(head, root, head);
    }

    bool dfsa1(ListNode* ln, TreeNode* tn, ListNode* head)
    {
        if (ln == nullptr)
            return true;
        if (tn == nullptr)
            return false;
        if (ln->val != tn->val)
            ln = head;
        if (ln->val == tn->val)
            ln = ln->next;
        bool ans = dfsa1(ln, tn->left, head) || dfsa1(ln, tn->right, head);
//                    || dfsa1(head, tn->left, head) || dfsa1(head, tn->right, head);
        if (ln != head && (ans == false))
            ans = dfsa1(head, tn->left, head) || dfsa1(head, tn->right, head);
        return ans;
    }

};

int main()
{
    int arr[] = {4,2,8};
    int arr2[] = {1,4,4,-1,2,2,-1,-1,-1,1,-1,6,8};

    ListNode* head = convertArray(arr);
    TreeNode* root = convert2TreeNode(arr2);

    showListNode(head);
    showTreeNode(root, 3);

    LT1367 lt;

    cout<<lt.lt1367a(head, root);

    return 0;
}
