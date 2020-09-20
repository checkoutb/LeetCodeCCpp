
#include "../header/myheader.h"

class LT0559
{
public:



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



// D D

// dfs level-order/bfs

//        if (root == nullptr) return 0;
//        int depth = 0;
//        for (auto child : root->children) depth = max(depth, maxDepth(child));
//        return 1 + depth;

// dfs, 2种， 上面， max(子树深度)，返回 max+1。
// lt0559a, 深度传给子树，当子树为子结点时，判断 深度是否最深。


//        while (!q.empty()) {
//            depth += 1;
//            int breadth = q.size();
//            for (int _ = 0; _ < breadth; ++_) {
//                auto node = q.front(); q.pop();
//                for (auto child : node->children) if (child) q.push(child);
//            }
//        }
// _...


//Runtime: 32 ms, faster than 89.30% of C++ online submissions for Maximum Depth of N-ary Tree.
//Memory Usage: 10.9 MB, less than 37.34% of C++ online submissions for Maximum Depth of N-ary Tree.
    int lt0559a(Node* root)
    {
        if (root == nullptr)
            return 0;

        int ans = 0;
        dfsa1(ans, root, 0);
        return ans;
    }

    void dfsa1(int& depth, Node* node, int now)
    {
        if (node == nullptr)
        {
            if (now > depth)
                depth = now;
            return;
        }
        if (node -> children.empty())
        {
            if (now + 1 > depth)
                depth = now + 1;
            return;
        }
        for (Node* p : node -> children)
        {
            dfsa1(depth, p, now + 1);
        }
    }

};

int main()
{

    LT0559 lt;


    return 0;
}
