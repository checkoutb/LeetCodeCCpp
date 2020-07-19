
#include "../header/myheader.h"

class LT0876
{
public:

// D D
//        ListNode *slow = head, *fast = head;
//        while (fast && fast->next)
//            slow = slow->next, fast = fast->next->next;


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Middle of the Linked List.
//Memory Usage: 6.7 MB, less than 38.83% of C++ online submissions for Middle of the Linked List.
    ListNode* lt0876a(ListNode* head)
    {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != nullptr)
        {
            fast = (fast->next ? fast->next->next : nullptr);
            slow = slow->next;
        }
        return slow;
    }

};

int main()
{

    int arr[] = {1,2,3,4,5,6};

    LT0876 lt;

    ListNode* head = convertArray(arr);

    cout<<lt.lt0876a(head)->val<<endl;

    return 0;
}
