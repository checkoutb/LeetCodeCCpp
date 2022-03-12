
#include "../header/myheader.h"

class LT2181
{
public:

// D D

//        while(temp!=NULL){
//            int temp_sum=0;
//            while(temp->val!=0){
//                temp_sum+=temp->val;
//                temp=temp->next;
//            }


//Use zero nodes to store the sum of merged nodes, remove the last zero node, which is unused.


//Runtime: 680 ms, faster than 86.83% of C++ online submissions for Merge Nodes in Between Zeros.
//Memory Usage: 274.6 MB, less than 43.41% of C++ online submissions for Merge Nodes in Between Zeros.
    ListNode* lt2181a(ListNode* head)
    {
        ListNode* ans = new ListNode(0, nullptr);
        ListNode* p = ans;
        head = head->next;
        int t2 = 0;
        while (head != nullptr)
        {
            if (head->val == 0)
            {
//                p->next = new ListNode(t2, new ListNode(0, nullptr));
                p->next = new ListNode(t2, nullptr);
                p = p->next;
                t2 = 0;
            }
            else
            {
                t2 += head->val;
            }
            head = head->next;
        }

        return ans->next;
    }

};

int main()
{

    LT2181 lt;


    return 0;
}
