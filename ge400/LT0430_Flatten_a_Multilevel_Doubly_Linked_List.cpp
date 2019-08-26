
#include "../header/myheader.h"

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/

input
{"$id":"1","child":null,"next":{"$id":"2","child":null,"next":{"$id":"3","child":
    {"$id":"7","child":null,"next":{"$id":"8","child":
        {"$id":"11","child":null,"next":{"$id":"12","child":null,"next":null,"prev":{"$ref":"11"},"val":12},"prev":null,"val":11},
        "next":{"$id":"9","child":null,"next":{"$id":"10","child":null,"next":null,"prev":{"$ref":"9"},"val":10},"prev":{"$ref":"8"},"val":9},
        "prev":{"$ref":"7"},"val":8},"prev":null,"val":7},"next":{"$id":"4","child":null,"next":{"$id":"5","child":null,"next":{"$id":"6","child":null,"next":null,"prev":{"$ref":"5"},"val":6},
        "prev":{"$ref":"4"},"val":5},"prev":{"$ref":"3"},"val":4},"prev":{"$ref":"2"},"val":3},"prev":{"$ref":"1"},"val":2},"prev":null,"val":1}
1-2-3-4-5-6
    \7-8-9-10
       \11-12
mine wrong
{"$id":"1","child":null,"next":{"$id":"2","child":null,"next":{"$id":"3","child":null,"next":
    {"$id":"4","child":null,"next":{"$id":"5","child":null,"next":{"$id":"6","child":null,"next":
        {"$id":"7","child":null,"next":{"$id":"8","child":null,"next":{"$id":"9","child":null,"next":
            {"$id":"10","child":null,"next":{"$id":"11","child":null,"next":{"$id":"12","child":null,"next":null,"prev":
                {"$ref":"11"},"val":6},"prev":{"$ref":"10"},"val":5},"prev":{"$ref":"9"},"val":4},
                "prev":{"$ref":"8"},"val":10},"prev":{"$ref":"7"},"val":9},"prev":{"$ref":"6"},"val":12},

                "prev":null,"val":11},"prev":{"$ref":"4"},"val":8},"prev":null,"val":7},"prev":{"$ref":"2"},

                "val":3},"prev":{"$ref":"1"},"val":2},"prev":null,"val":1}

1-2-3-4-5


right
{"$id":"1","child":null,"next":{"$id":"2","child":null,"next":{"$id":"3","child":null,"next":
    {"$id":"4","child":null,"next":{"$id":"5","child":null,"next":{"$id":"6","child":null,"next":
        {"$id":"7","child":null,"next":{"$id":"8","child":null,"next":{"$id":"9","child":null,"next":
            {"$id":"10","child":null,"next":{"$id":"11","child":null,"next":{"$id":"12","child":null,"next":null,"prev":
                {"$ref":"11"},"val":6},"prev":{"$ref":"10"},"val":5},"prev":{"$ref":"9"},"val":4},
                "prev":{"$ref":"8"},"val":10},"prev":{"$ref":"7"},"val":9},"prev":{"$ref":"6"},"val":12},

                "prev":{"$ref":"5"},"val":11},"prev":{"$ref":"4"},"val":8},"prev":{"$ref":"3"},"val":7},

                "prev":{"$ref":"2"},"val":3},"prev":{"$ref":"1"},"val":2},"prev":null,"val":1}

...???。。应该是123-78-1112-910-456 吧。怎么都是123456789101112.。。
。。。ID != val..................
1-2-3
  \4
4的prev是null，而不是2...图上有这种规则。。


class LT0430
{
public:


// details
//        if (!head) return head;
//        Node* cur = head;
//        while (cur) {
//            if (!cur->child) cur = cur->next;
//            else {
//                // Find the tail of the child
//                Node* tmp = cur->child;
//                while (tmp->next) tmp = tmp->next;
//
//                Node* next = cur->next;
//                cur->next = cur->child;
//                cur->child->prev = cur;
//                cur->child = nullptr;
//
//                if (next) {
//                    tmp->next = next;
//                    next->prev = tmp;
//                }
//
//                cur = cur->next;
//            }
//        }
//        return head;
// tmp是child的尾巴，
// 如果有child，那么就把child整体直接加入到cur后面，然后cur++，处理第一个child。不需要关心child的child。因为加入到cur后，child的child就变成了child。会被处理到。

//    for (Node* h = head; h; h = h->next)
//    {
//        if(h->child)
//        {
//            Node* next = h->next;
//            h->next = h->child;
//            h->next->prev = h;
//            h->child = NULL;
//            Node* p = h->next;
//            while (p->next) p = p->next;
//            p->next = next;
//            if (next) next->prev = p;
//        }
//    }
//    return head;
// 。。和上面一样的


// discuss
//        Node curt = head;
//        Stack<Node> stack = new Stack<>(); // store curt.next when curt.child is not null
//
//        while(curt != null) {
//            if(curt.child != null) {
//                stack.push(curt.next); // might be null
//                curt.next = curt.child;
//                if(curt.next != null) curt.next.prev = curt;
//                curt.child = null;
//            } else if(curt.next == null && !stack.isEmpty()) { // reach of tail of child, reconnet the next of parent
//                curt.next = stack.pop();
//                if(curt.next != null) curt.next.prev = curt;
//            }
//
//            curt = curt.next;
//        }
//
//        return head;
// stack 保存child遍历完后，后继Node，


//        if (head == NULL) return NULL;
//        stack<Node*> stck;
//        stck.push(head);
//        Node* curr=NULL, *prev=NULL, *newhead=NULL;
//        while (!stck.empty()) {
//            prev=curr;
//            curr=stck.top(); stck.pop();
//            if (curr->next) stck.push(curr->next);
//            if (curr->child) stck.push(curr->child);
//            curr->child=NULL;
//            curr->prev=prev;
//            if (prev) prev->next=curr;
//            else newhead=curr;
//        }
//        return newhead;
// stack保存下一个Node，并且next优先入栈，后出栈，这样child优先被处理。



//Runtime: 92 ms, faster than 84.13% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
//Memory Usage: 31.1 MB, less than 50.00% of C++ online submissions for Flatten a Multilevel Doubly Linked List.


    Node* lt0430a(Node* head)
    {
        Node* ans = head;
        dfsa1(head);
        return ans;
    }

    Node* dfsa1(Node* head)
    {
        Node* ans = NULL;
        while (head != NULL)
        {
            if (head->child != NULL)
            {
                Node* next = head->next;
                head->next = head->child;
                head->child->prev = head;
                Node* tail = dfsa1(head->child);
                head->child = NULL;
                tail->next = next;
                if (next != NULL)
                    next->prev = tail;
                head = tail;
            }
            ans = head;
            head = head->next;
        }
        return ans;
    }
};
