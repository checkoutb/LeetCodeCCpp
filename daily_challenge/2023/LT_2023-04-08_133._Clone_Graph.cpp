
#include "../../header/myheader.h"

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class LT
{
public:



    //Runtime7 ms
    //    Beats
    //    61.34 %
    //    Memory8.7 MB
    //    Beats
    //    65.38 %
    Node* ltb(Node* node)
    {
        if (node == nullptr)
            return node;

        vector<Node*> vp(101, nullptr);
        vector<Node*> v2(101, nullptr);
        dfsb1(node, vp, v2);

        for (int i = 1; i < 101; ++i)
        {
            if (vp[i] != nullptr)
            {
                for (Node* nxt : v2[i]->neighbors)
                {
                    vp[i]->neighbors.push_back(vp[nxt->val]);
                }
            }
        }
        return vp[node->val];
    }
    
    void dfsb1(Node* node, vector<Node*>& vp, vector<Node*>& v2)
    {
        if (vp[node->val] != nullptr)
            return;

        v2[node->val] = node;
        vp[node->val] = new Node(node->val);

        for (Node* nxt : node->neighbors)
        {
            dfsb1(nxt, vp, v2);
        }

    }


    //  vector<Node*>& vp 少了个 &。 写得爆炸了。
    // 
    //Runtime0 ms
    //    Beats
    //    100 %
    //    Memory8.9 MB
    //    Beats
    //    34.83 %
    // error
    // val is unique, and <= 100
    Node* lta(Node* node)
    {
        if (node == nullptr)
            return node;

        //Node* arr[101] = { nullptr };
        vector<Node*> vp(101, nullptr);

        return dfsa1(node, vp);
    }

    Node* dfsa1(Node* node, vector<Node*>& vp)
    {
        if (vp[node->val] != nullptr)
            return vp[node->val];

        vp[node->val] = new Node(node->val);

        for (Node* nxt : node->neighbors)
        {
            vp[node->val]->neighbors.push_back(dfsa1(nxt, vp));
            //dfsa1(nxt, vp);
        }
        //for (Node* nxt : node->neighbors)
        //{
        //    vp[node->val]->neighbors.push_back(vp[nxt->val]);
        //}
        return vp[node->val];
    }

};

void show(Node* node, vector<bool>& vb)
{
    if (vb[node->val])
        return;
    cout << "{ " << node << ", " << node->val << ", " << node->neighbors[0]->val << ", " << node->neighbors[1]->val << "}, ";
    vb[node->val] = true;
    for (Node* nxt : node->neighbors)
        show(nxt, vb);
}

int main()
{

    LT lt;

    //Node* n1 = new Node(1);
    //Node* n2 = new Node(2);
    //Node* n3 = new Node(3);
    //n1->neighbors.push_back(n2);
    //n1->neighbors.push_back(n3);
    //n2->neighbors.push_back(n1);
    //n2->neighbors.push_back(n3);
    //n3->neighbors.push_back(n1);
    //n3->neighbors.push_back(n2);

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n4);
    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n3);
    n3->neighbors.push_back(n2);
    n3->neighbors.push_back(n4);
    n4->neighbors.push_back(n1);
    n4->neighbors.push_back(n3);

    Node* ans = lt.ltb(n1);
    vector<bool> vb(101, false);
    show(n1, vb);
    cout << "\n\n=============\n\n";
    vector<bool> v2(101, false);
    show(ans, v2);

    cout << ans << " - " << n1 << endl;

    return 0;
}
