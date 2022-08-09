
#include "../../header/myheader.h"

class LT
{
public:



};

    // D D


//	 * Example: given an array a[0]...a[7], we use a array BIT[9] to
//	 * represent a tree, where index [2] is the parent of [1] and [3], [6]
//	 * is the parent of [5] and [7], [4] is the parent of [2] and [6], and
//	 * [8] is the parent of [4]. I.e.,
//	 *
//	 * BIT[] as a binary tree:
//	 *            ______________*
//	 *            ______*
//	 *            __*     __*
//	 *            *   *   *   *
//	 * indices: 0 1 2 3 4 5 6 7 8
//	 *
//	 * BIT[i] = ([i] is a left child) ? the partial sum from its left most
//	 * descendant to itself : the partial sum from its parent (exclusive) to
//	 * itself. (check the range of "__").

//	 * Thus, to update a[1]=BIT[2], we shall update BIT[2], BIT[4], BIT[8],
//	 * i.e., for current [i], the next update [j] is j=i+(i&-i) //double the
//	 * last 1-bit from [i].



// 我这个是 segment tree
//Runtime: 1026 ms, faster than 5.01% of C++ online submissions for Range Sum Query - Mutable.
//Memory Usage: 186.3 MB, less than 6.60% of C++ online submissions for Range Sum Query - Mutable.
// segment tree, bit, skip array
struct Node {
    int st;
    int en;         // st <= idx <= en
    int val;
    bool chg;       // useless
    Node* lft;
    Node* rgh;
    Node(int v, int s, int e) : val(v), st(s), en(e), chg(false), lft(nullptr), rgh(nullptr) {}
};

class NumArray {

    Node* root;

    Node* generatea1(vector<int>& nums, int st, int en)
    {
        if (st == en)
        {
            return new Node(nums[st], st, en);
        }

        Node* n = new Node(-1, st, en);
        int md = (st + en) / 2;
        Node* l = generatea1(nums, st, md);
        Node* r = generatea1(nums, md + 1, en);

        n->lft = l;
        n->rgh = r;
        n->val = l->val + r->val;

        return n;
    }

    int updatea1(Node* node, int idx, int val)
    {
        if (node->st <= idx && node->en >= idx)
        {
            //node->chg = true;
            if (node->st == node->en)
            {
                node->val = val;
                return val;
            }
            else
            {
                node->val = updatea1(node->lft, idx, val) + updatea1(node->rgh, idx, val);
                return node->val;
            }
        }
        return node->val;
    }

    int querya1(Node* node, int st2, int en2)
    {
        if (node->st >= st2 && node->en <= en2)
            return node->val;

        if (node->en < st2 || node->st > en2)
            return 0;

        return querya1(node->lft, st2, en2) + querya1(node->rgh, st2, en2);
    }


public:
    NumArray(vector<int>& nums) {
        this->root = generatea1(nums, 0, nums.size() - 1);
    }

    void update(int index, int val) {
        this->updatea1(this->root, index, val);
    }

    int sumRange(int left, int right) {
        return this->querya1(this->root, left, right);
    }

    void deleteaaaa() {
        queue<Node*> que;
        que.push(this->root);
        while (!que.empty())
        {
            Node* r = que.front();
            que.pop();
            if (r->lft)
                que.push(r->lft);
            if (r->rgh)
                que.push(r->rgh);
            delete r;
        }
    }
    void showaaaa() {
        queue<Node*> que;
        que.push(this->root);
        while (!que.empty())
        {
            Node* r = que.front();

            cout<<r->st<<" - "<<r->en<<" = "<<r->val<<endl;

            que.pop();
            if (r->lft)
                que.push(r->lft);
            if (r->rgh)
                que.push(r->rgh);
        }
    }
};

int main()
{

    LT lt;

    myvi v = {1,3,5};

    NumArray numArray(v);
    numArray.showaaaa();
    cout<<endl<<numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
    numArray.update(1, 2);   // nums = [1, 2, 5]
    numArray.showaaaa();
    cout<<endl<<numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8

    numArray.deleteaaaa();

    return 0;
}
