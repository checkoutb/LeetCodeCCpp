
#include "../header/myheader.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class LT0445
{
public:



// details
// 18ms, 是reverse，相加，再reverse。。竟然这么快，不过他的reverse，相加，都是while循环，不是递归的。
// 12ms，用2个stack保存val。。正好从后面开始计算。。


// discuss
//            int sum = 0;
//            if( n1 >= n2 ){ sum += curr1->val; curr1=curr1->next; n1--;}
//            if( n2 > n1 ){ sum += curr2->val; curr2=curr2->next; n2--;}
// 。。。可以跳过前面部分。


//Runtime: 24 ms, faster than 74.59% of C++ online submissions for Add Two Numbers II.
//Memory Usage: 9.9 MB, less than 92.59% of C++ online submissions for Add Two Numbers II.

    ListNode* lt0445a(ListNode* l1, ListNode* l2)
    {
        int sz1 = 0;
        int sz2 = 0;
        ListNode* n = l1;
        while (n != NULL)
        {
            sz1++;
            n = n->next;
        }
        n = l2;
        while (n != NULL)
        {
            sz2++;
            n = n->next;
        }

        int diff = abs(sz1 - sz2);
        if (sz1 > sz2)
        {
            int t1 = dfsa(l1, l2, diff);
            if (t1 > 0)
            {
                ListNode* n2 = new ListNode(t1);
                n2->next = l1;
                l1 = n2;
            }
            return l1;
        }
        else
        {
            int t1 = dfsa(l2, l1, diff);
            if (t1 > 0)
            {
                ListNode* n2 = new ListNode(t1);
                n2->next = l2;
                l2 = n2;
            }
            return l2;
        }
    }

    int dfsa(ListNode* long1, ListNode* short1, int length_diff)
    {
        if (long1 == NULL)
            return 0;
        if (length_diff > 0)
        {
            int t1 = dfsa(long1->next, short1, length_diff - 1);
            t1 += (long1->val);
            long1->val = (t1 % 10);
            return t1 / 10;
        }
        else
        {
            int t1 = dfsa(long1->next, short1->next, 0);
            t1 += (long1->val + short1->val);
            long1->val = (t1 % 10);
            return t1 / 10;
        }
    }

};

int main()
{
    int arr1[] = {7,2,4,3};
    int arr2[] = {5,6,3,4};

    ListNode* l1 = convertArray(arr1);
    ListNode* l2 = convertArray(arr2);

    cout<<"list1 : ";
    showListNode(l1);

    cout<<"list2 : ";
    showListNode(l2);

    LT0445 lt;

    ListNode* ans = lt.lt0445a(l1, l2);
    cout<<endl<<"result : ";
    showListNode(ans);

    return 0;
}
