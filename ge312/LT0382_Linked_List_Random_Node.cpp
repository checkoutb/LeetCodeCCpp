
#include "../header/myheader.h"


// discuss
//        while(i--) {
//            cur = cur->next;
//        }

// java
//Random randomGenerator = null;
//this.randomGenerator = new Random();
//randomGenerator.nextInt(n) == 0

// 初始化列表
//    Solution(ListNode* head) : head(head) {}
//
//    int getRandom() {
//        ListNode *node = head, *buffer[100], *pick;
//        for (int before=0; node; before+=100) {
//            int now = 0;
//            while (node && now < 100) {
//                buffer[now++] = node;
//                node = node->next;
//            }
//            int r = rand() % (now + before);
//            if (r < now)
//                pick = buffer[r];
//        }
//        return pick->val;
//    }
// 这个一次100的跳。把while放到 r<now中更快，不过这有问题，就是now不满100的情况下，需要再rand一遍。



// details
//        int rval = 0;
//        curr = orihead;
//        idx = 1;
//
//        while (curr)
//        {
//            int res = rand() % idx;
//
//            if (res == 0)
//            {
//                rval = curr->val;
//            }
//
//            curr = curr->next;
//            idx++;
//        }
//        return rval;
// orihead 应该是 original head
// 每次增加一个node，新增加的node被选中几率是 1/size
// 1个节点，100%
// 2个节点，第二个50%，所以第一个是50% * 100% == 50%
// 3个节点，第3个33.3%, 由于前面2个是等可能的，所以前面2个平分66.6%,都是33.3%
//      或者说，第3个节点加入的时候，前面2个节点都贡献了它们各自的1/3概率出来，1/3*2*50%. 就是1/3



//Runtime: 52 ms, faster than 14.18% of C++ online submissions for Linked List Random Node.
//Memory Usage: 16.2 MB, less than 91.44% of C++ online submissions for Linked List Random Node.


// 构造器中计算下list长度。
// 超长list，本想，前进rand()%100, 但是这样的话，100以后的node，在第一次调用时，必然不会被返回。或者rand()%INT_MAX ？

class Solution {
    int sz2;
    ListNode* head2;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        sz2 = 0;
        head2 = head;
        ListNode* h3 = head2;
        while (h3 != NULL)
        {
            sz2++;
            h3 = h3->next;
        }
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode* h3 = head2;
        int t1 = rand() % sz2;
        for (int i = 0; i < t1; i++)
        {
            h3 = h3->next;
        }
        return h3->val;
    }
};
