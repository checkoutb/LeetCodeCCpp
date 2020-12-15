
#include "../header/myheader.h"

class LT0023
{
public:

// D D

//priority_queue<ListNode *, vector<ListNode *>, compare> q;

//make_heap(v.begin(), v.end(), heapComp); //vector -> heap data strcture
//    while(v.size()>0){
//        curNode->next=v.front();
//        pop_heap(v.begin(), v.end(), heapComp);
//        v.pop_back();
//        curNode = curNode->next;
//        if(curNode->next) {
//            v.push_back(curNode->next);
//            push_heap(v.begin(), v.end(), heapComp);
//        }
//    }

//        multimap<int, ListNode*> mp;  //a new multimap<val, head> to store data
//        for (auto p : lists) {
//            if (p != NULL) { //every List , <val, ListHead>, if ListHead != NULL
//                mp.insert(make_pair(p->val, p));
//            }
//        }


//ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
//    if(l1 == nullptr){
//        return l2;
//    }
//    if(l2 == nullptr){
//        return l1;
//    }
//    if(l1->val <= l2->val){
//        l1->next = mergeTwoLists(l1->next, l2);
//        return l1;
//    }
//    else{
//        l2->next = mergeTwoLists(l1, l2->next);
//        return l2;
//    }
//}
// 不停地对 2个 List 合并。




// 时代变了，狗蛋。time has changed, goudan.
//Runtime: 36 ms, faster than 76.25% of C++ online submissions for Merge k Sorted Lists.
//Memory Usage: 13.7 MB, less than 64.29% of C++ online submissions for Merge k Sorted Lists.

//12/08/2017 15:55	Time Limit Exceeded	N/A	N/A	java
//12/08/2017 15:48	Time Limit Exceeded	N/A	N/A	java
//12/08/2017 15:16	Wrong Answer	N/A	N/A	java
//12/08/2017 15:05	Runtime Error	N/A	N/A	java
//12/08/2017 14:48	Runtime Error	N/A	N/A	java
//12/08/2017 14:45	Runtime Error	N/A	N/A	java
//12/08/2017 14:23	Time Limit Exceeded	N/A	N/A	java
//12/08/2017 14:14	Time Limit Exceeded	N/A	N/A	java
//12/08/2017 14:13	Time Limit Exceeded	N/A	N/A	java
//12/08/2017 14:04	Time Limit Exceeded	N/A	N/A	java
//12/08/2017 14:03	Runtime Error	N/A	N/A	java
//12/08/2017 14:01	Runtime Error	N/A	N/A	java
// 我日，当时也太猛了。。但是看起来好像挺简单的，虽然是 hard，通过率也有41.6。。不知道当时发生了什么。。

// heap，但没有用过，就是std提供的几个方法来组成heap的操作，。。先手动吧。
// 之前想的是 vector<>，每次找最小。 但是 后来想到了set的有序，然后 priority_queue。
// 感觉可以 map<value, count> 。。
    ListNode* lt0023a(vector<ListNode*>& lists)
    {
        auto comp = [](const ListNode* p1, const ListNode* p2){ return p1->val > p2->val; };        // 不能 *& p1
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> que1(comp);
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        for (ListNode*& lnp : lists)
        {
            if (lnp)
                que1.push(lnp);
        }
        while (!que1.empty())
        {
            ListNode* lp = que1.top();
            que1.pop();
            temp->next = lp;
            temp = temp->next;
            if (lp->next)
                que1.push(lp->next);
        }
        return ans->next;
    }

};

int main()
{
//    myvvi vv = {{1,4,5},{1,3,4},{2,6}};
    myvvi vv = {{}};

    vector<ListNode*> vl;

//    cout<<typeid(vv).name()<<endl;
//    cout<<typeid(vv[0]).name()<<endl;
//    cout<<typeid(vl).name()<<endl;
////    cout<<typeid(vv).name()<<endl;
//    cout<<typeid(vector<vector<int>>).name()<<endl;
//
//    cout<<typeid(int[]).name()<<endl;
//    cout<<typeid(double[]).name()<<endl;
//    cout<<typeid(set<int>).name()<<endl;

    for (vector<int>& vi : vv)
    {
        vl.push_back(convertArray(vi));
        showListNode(vl.back());
    }

    LT0023 lt;

    ListNode* ans = lt.lt0023a(vl);

    showListNode(ans);

    return 0;
}
