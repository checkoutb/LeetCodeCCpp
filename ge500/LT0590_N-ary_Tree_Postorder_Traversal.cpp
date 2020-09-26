
#include "../header/myheader.h"

class LT0590
{
public:


// D D
// 双stack， 利用 一个额外的stack 来反序。





//Runtime: 36 ms, faster than 98.16% of C++ online submissions for N-ary Tree Postorder Traversal.
//Memory Usage: 11.4 MB, less than 28.46% of C++ online submissions for N-ary Tree Postorder Traversal.
// stack,children 反向push，最后 reverse,,由于stack，所以反而是正向遍历push
// stack. 第一次不出栈，第二次才出栈。
// queue是层级遍历才用到
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<Node*> stk1;
        stk1.push(root);
        while (!stk1.empty())
        {
            Node* node = stk1.top();
            stk1.pop();
            ans.push_back(node->val);
            for (Node* n : node->children)
            {
                stk1.push(n);
            }
        }
        std::reverse(begin(ans), end(ans));
        return ans;
    }

};

int main()
{

    LT0590 lt;


    return 0;
}
