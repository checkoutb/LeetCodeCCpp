
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //ListNode* slow = head, * fast = head;

    //while (fast != end && fast->next != end) {
    //    slow = slow->next;
    //    fast = fast->next->next;
    //}




    //Runtime20 ms
    //    Beats
    //    94.68 %
    //    Memory28.2 MB
    //    Beats
    //    92.35 %
    // 快慢指针找中点，然后递归
    // 获得长度后，做一个完全二叉树。但
    TreeNode* lta(ListNode* head)
    {
        return dfsa1(head, nullptr);
    }

    TreeNode* dfsa1(ListNode* head, ListNode* en)
    {
        if (head == en)
            return nullptr;

        ListNode* fst = head->next;
        ListNode* slw = head;

        while (fst != en)
        {
            slw = slw->next;
            fst = fst->next;
            fst = fst == en ? fst : fst->next;
        }

        TreeNode* node = new TreeNode(slw->val);
        node->left = dfsa1(head, slw);
        node->right = dfsa1(slw->next, en);
        return node;
    }

};

int main()
{

    LT lt;

//    vector<int> vi = { 1,2,3,4,5 };
    int vi[] = { 1,2,3,4,5 };

    ListNode* n = convertArray(vi);

    TreeNode* r = lt.lta(n);

    showTreeNode(r, 4);

    return 0;
}
