
#include "../header/myheader.h"

class LT0707
{
public:



};




class Node
{
public:
    int val;
    Node* next;
    Node(int v = -1): val(v), next(NULL) {}

    void addNext(int nextv)
    {
        Node* next2 = new Node(nextv);
        next2->next = this->next;
        this->next = next2;
    }

};




//Runtime: 44 ms, faster than 90.41% of C++ online submissions for Design Linked List.
//Memory Usage: 19.2 MB, less than 77.78% of C++ online submissions for Design Linked List.

class MyLinkedList {

    Node* root;

    Node* getByIndex(int index)
    {
        if (index == -6)
        {
            Node* n = root;
            while (n->next != NULL)
                n = n->next;
            return n;
        }
        else
        {
            Node* n = root;
            for (int i = 0; i <= index && n != NULL; i++)
                n = n->next;
            return n;
        }
    }

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        root = new Node(-2);
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        Node* n = getByIndex(index);
        return n == NULL ? -1 : n->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        root->addNext(val);
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* tail = getByIndex(-6);
        tail->addNext(val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        Node* n = getByIndex(index - 1);
        if (n != NULL)
            n->addNext(val);
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        Node* n = getByIndex(index - 1);
        if (n->next != NULL)
        {
            n->next = n->next->next;
        }
    }

    void showList()
    {
        Node* n = root;
        while (n != NULL)
        {
            cout<<n->val<<", ";
            n = n->next;
        }
        cout<<endl;
    }

};





int main()
{

    LT0707 lt;

//    ["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
//    [[],[1],[3],[1,2],[1],[0],[0]]
//    [null,null,null,null,2,null,2]

    MyLinkedList lst;
    lst.addAtHead(1);
    lst.addAtTail(3);
    lst.addAtIndex(1,2);

    lst.showList();

    cout<<lst.get(1)<<endl;
    lst.deleteAtIndex(0);               // 内部就变成-1了， 之前-1是遍历到尾巴。。

    lst.showList();

    cout<<lst.get(0)<<endl;




//    MyLinkedList linkedList;      // Initialize empty LinkedList
//    linkedList.addAtHead(1);
//    linkedList.addAtTail(3);
//    linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
//
//    linkedList.showList();
//
//    cout<<linkedList.get(1)<<endl;            // returns 2
//    linkedList.deleteAtIndex(1);  // now the linked list is 1->3
//
//    linkedList.showList();
//
//    cout<<linkedList.get(1)<<endl;            // returns 3

    return 0;
}
