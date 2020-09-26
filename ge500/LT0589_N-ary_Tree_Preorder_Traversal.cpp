
#include "../header/myheader.h"

class LT0589
{
public:



//Runtime: 36 ms, faster than 98.13% of C++ online submissions for N-ary Tree Preorder Traversal.
//Memory Usage: 11.1 MB, less than 74.24% of C++ online submissions for N-ary Tree Preorder Traversal.
    vector<int> preorder(Node* root) {
        stack<Node*> stk1;
        stk1.push(root);
        vector<int> ans;
        while (!stk1.empty())
        {
            Node* node = stk1.top();
            stk1.pop();
            if (node == nullptr)
                continue;
            ans.push_back(node->val);
            for (int i = node->children.size() - 1; i >= 0; i--)
            {
                stk1.push(node->children[i]);
            }
        }
        return ans;
    }

};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

int main()
{

    LT0589 lt;


    return 0;
}
