
#include "../header/myheader.h"

class LT1367
{
public:

    // D D

//    map<pair<ListNode*, TreeNode*>, bool> m;
// memo + dfs == dp


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



//    bool isSubPath(ListNode* head, TreeNode* root) {
//        return dfsa1(head, root, head);
//    }
//
//    bool dfsa1(ListNode* ln, TreeNode* tn, ListNode* head)            // listnode, treenode, listhead
//    {
//        if (ln == nullptr)
//            return true;
//        if (tn == nullptr)
//            return false;
//        if (ln->val != tn->val)
//            ln = head;
//        if (ln->val == tn->val)
//            ln = ln->next;
//        bool ans = dfsa1(ln, tn->left, head) || dfsa1(ln, tn->right, head);           // dfs
//        if (ln != head && (ans == false))
//            ans = dfsa1(head, tn->left, head) || dfsa1(head, tn->right, head);    // 如果上面的dfs 用的不是 head，且没有找到，那么使用head 来尝试。
//        return ans;
//    }
// 一年半前，tle的。 有点无法理解，为什么 本次可以，这个就不行。



//Runtime: 47 ms, faster than 54.96% of C++ online submissions for Linked List in Binary Tree.
//Memory Usage: 32.1 MB, less than 65.75% of C++ online submissions for Linked List in Binary Tree.
    bool lt1367a(ListNode* head, TreeNode* root)
    {
        return dfsa1(head, root);
    }

    bool dfsa1(ListNode* l, TreeNode* t)
    {
        if (t == nullptr)
            return false;

        if (t->val == l->val)
        {
            if (dfsa2(l, t))
                return true;
        }
        return dfsa1(l, t->left) || dfsa1(l, t->right);
    }

    bool dfsa2(ListNode* l, TreeNode* t)
    {
        if (l == nullptr)
            return true;
        if (t == nullptr)
            return false;

        if (l->val != t->val)
            return false;

        return dfsa2(l->next, t->left) || dfsa2(l->next, t->right);
    }

};

int main()
{

    LT1367 lt;


    return 0;
}
