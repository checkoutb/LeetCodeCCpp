
#include "../header/myheader.h"

class LT0958
{
public:


// D D
//        deque<TreeNode *> q{root};
//        while (!q.empty()) {
//            auto cur = q.front();
//            q.pop_front();
//            if (cur) {
//                q.push_back(cur->left);
//                q.push_back(cur->right);
//            } else {
//                break;
//            }
//        }
//        for (auto node : q) if (node) return false;
//        return true;

//        queue.add(root);
//        while(!queue.isEmpty()) {
//            TreeNode cur = queue.poll();
//            if(cur == null) end = true;
//            else{
//                if(end) return false;
//                queue.add(cur.left);
//                queue.add(cur.right);
//            }
//        }
//        return true;


//Runtime: 12 ms, faster than 11.16% of C++ online submissions for Check Completeness of a Binary Tree.
//Memory Usage: 10.3 MB, less than 98.93% of C++ online submissions for Check Completeness of a Binary Tree.

    int depth1 = 0;
    int depth2 = -1;
    bool lt0958a(TreeNode* root)
    {
        TreeNode* n = root;
        while (n != nullptr)
        {
            depth1++;
            n = n->left;
        }
        return dfsa1(root, 0);
    }

    bool dfsa1(TreeNode* n, int d)
    {
        if (n == nullptr)
        {
            if (depth2 == -1)
            {
                if (d == depth1)
                {
                    return true;
                }
                else
                {
                    if (d + 1 == depth1)
                    {
                        depth2 = d;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                return d == depth2;
            }
        }
        d++;
        bool ans = dfsa1(n->left, d);
        if (!ans)
            return false;
        ans = dfsa1(n->right, d);
        return ans;
    }

};

int main()
{

    int arr[] = {1,2,3,4,5,-1,6};

    TreeNode* r = convert2TreeNode(arr);
    showTreeNode(r, 3);

    LT0958 lt;

    cout<<lt.lt0958a(r)<<endl;

    return 0;
}
