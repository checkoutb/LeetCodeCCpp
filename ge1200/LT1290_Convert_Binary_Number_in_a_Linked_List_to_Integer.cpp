
#include "../header/myheader.h"

class LT1290
{
public:


// D D

//            ans = (ans << 1) | head.val;
//            head = head.next;



//Runtime: 4 ms, faster than 44.39% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
//Memory Usage: 8.6 MB, less than 82.11% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
    int lt1290a(ListNode* head)
    {
        int ans = 0;
        while (head != nullptr)
        {
            ans *= 2;
            ans += head->val;
            head = head->next;
        }
        return ans;
    }

};

int main()
{
    int arr[] = {1,0,0,1,0,0,1,1,1,0,0,0,0,0,0};
    ListNode* n = convertArray(arr);

    LT1290 lt;

    cout<<lt.lt1290a(n)<<endl;

    return 0;
}
