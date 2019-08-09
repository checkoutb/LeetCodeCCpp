
#include "../header/myheader.h"


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class LT0429
{
public:



//Runtime: 156 ms, faster than 45.86% of C++ online submissions for N-ary Tree Level Order Traversal.
//Memory Usage: 34.8 MB, less than 44.44% of C++ online submissions for N-ary Tree Level Order Traversal.

// 大部分140 - 164ms 之间
// queue保存指针，会更快吧，我这种会调用复制构造函数？是的，2个不同的地址。

//    vector<vector<int>> lt0429a(Node* root)
//    {
//        vector<vector<int>> ans;
//        if (root == NULL)
//            return ans;
//
//        int cnt = 0;
//        queue<Node> que;
//        que.push(*root);
//        while (!que.empty())
//        {
//            vector<int> v2;
//            int sz1 = que.size();
//            while (sz1-- > 0)
//            {
//                Node node = que.front();
//                que.pop();
//                v2.push_back(node.val);
//                for(auto& p : node.children)
//                {
//                    que.push(*p);
//                }
//            }
//            ans.push_back(v2);
//        }
//
//        return ans;
//    }
};

class Node
{
public:
    int val;
};

int main()
{
    Node n;
    n.val = 103;
    cout<<&n<<", "<<n.val<<endl;

    queue<Node> que1;
    Node* np = &n;
    que1.push(*np);
    Node n2 = que1.front();
    cout<<&n2<<", "<<n2.val<<endl;
}
