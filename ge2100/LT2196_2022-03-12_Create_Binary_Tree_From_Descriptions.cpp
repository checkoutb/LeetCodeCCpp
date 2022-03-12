
#include "../header/myheader.h"

class LT2196
{
public:

// D D


//        children = set()
//        m = {}
//        for p,c,l in descriptions:
//            np = m.setdefault(p, TreeNode(p))
//            nc = m.setdefault(c, TreeNode(c))
//            if l:
//                np.left = nc
//            else:
//                np.right = nc
//            children.add(c)
//        root = (set(m) - set(children)).pop()
//        return m[root]




//Runtime: 920 ms, faster than 93.10% of C++ online submissions for Create Binary Tree From Descriptions.
//Memory Usage: 290.8 MB, less than 48.13% of C++ online submissions for Create Binary Tree From Descriptions.
// 生成 parent->child, 找到root
    TreeNode* lt2196a(vector<vector<int>>& descriptions)
    {
        unordered_map<int, vector<int>> map2;       // <parent, [left, right]>
//        unordered_map<int, TreeNode*> map3;
        unordered_map<int, int> map3;       // <child, parent>
        for (vector<int>& vi : descriptions)
        {
            int parent = vi[0];
            int child = vi[1];
            #ifdef __test
//            cout<<child<<", "<<parent<<endl;
            #endif // __test

            map3[child] = parent;
//            cout<<"..."<<", "<<map3[child]<<endl;
            if (map2.find(parent) == map2.end())
            {
                map2[parent] = {-1, -1};
            }
            map2[parent][1 - vi[2]] = child;
        }
        int root2 = descriptions[0][0];
        while (map3.find(root2) != map3.end())
            root2 = map3[root2];

        TreeNode* root = new TreeNode(root2, nullptr, nullptr);
        queue<TreeNode*> que1;
        que1.push(root);
        while (!que1.empty())
        {
            TreeNode* p = que1.front();
            que1.pop();
//            cout<<(p->val)<<endl;
            if (map2.find(p->val) == map2.end())
                continue;
            int lft = map2[p->val][0];
            int rht = map2[p->val][1];
            if (lft != -1)
            {
                TreeNode* node = new TreeNode(lft);
                p->left = node;
                que1.push(node);
            }
            if (rht != -1)
            {
                TreeNode* node = new TreeNode(rht);
                p->right = node;
                que1.push(node);
            }
        }
        return root;
    }

};

int main()
{

    LT2196 lt;

//    myvvi vv = {{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}};
    myvvi vv = {{1,2,1},{2,3,0},{3,4,1}};

    TreeNode* r = lt.lt2196a(vv);

    showTreeNode(r, 5);

    deleteTreeNode(r);

    return 0;
}
