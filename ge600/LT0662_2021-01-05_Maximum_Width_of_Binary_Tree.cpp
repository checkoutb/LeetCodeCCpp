
#include "../header/myheader.h"

class LT0662
{
public:

// D

//Queue<Pair<TreeNode, Integer>> queue = new LinkedList<>();
// bfs, 层级遍历，最左侧赋值为0,


//        while(!q.empty()) {
//            int len=q.size();
//            int first=q.front().second, last;
//            for(int i=0;i<len;i++) {
//                auto pr=q.front(); q.pop();
//                auto n=pr.first;
//                last=pr.second;
//                if(n->left)  q.push({n->left,  (pr.second-first)*2+0});
//                if(n->right) q.push({n->right, (pr.second-first)*2+1});
//            }
//            maxWidth= max(maxWidth,last-first+1);
//        }


//        while (!v.empty()) {
//            vector<pair<unsigned long long,TreeNode*>> cur;
//            res = max(v.back().first - v.front().first + 1, res);
//
//            for (auto [idx, p] : v) {
//                if (p->left)
//                    cur.push_back({idx*2, p->left});
//                if (p->right)
//                    cur.push_back({idx*2+1, p->right});
//            }
//            swap(cur, v);
//        }



//Runtime: 12 ms, faster than 42.56% of C++ online submissions for Maximum Width of Binary Tree.
//Memory Usage: 16.5 MB, less than 99.65% of C++ online submissions for Maximum Width of Binary Tree.
// after discuss
    int lt0662b(TreeNode* root)
    {
        queue<TreeNode*> que1;
        root->val = 0;
        int ans = 1;
        que1.push(root);
        while (!que1.empty())
        {
            while (!que1.empty())
            {
                TreeNode* n = que1.front();
                if (n->left == nullptr && n->right == nullptr)
                    que1.pop();
                else
                    break;
            }
            int sz1 = que1.size();
            if (sz1 == 0)
                break;
            int t2 = que1.front()->val;
            TreeNode* n = nullptr;
            TreeNode* lst = nullptr;
            while (sz1-- > 0)
            {
                n = que1.front();
                que1.pop();
                if (n->left != nullptr)
                {
                    lst = n->left;
                    lst->val = (n->val - t2) * 2;
                    que1.push(lst);
                }
                if (n->right != nullptr)
                {
                    lst = n->right;
                    lst->val = (n->val - t2) * 2 + 1;
                    que1.push(lst);
                }
            }
            if (!que1.empty())
                ans = max(ans, lst->val - que1.front()->val + 1);
        }
        return ans;
    }


// signed integer overflow: 9223372036854775807 * 2 cannot be represented in type 'long'
    int lt0662a(TreeNode* root)
    {
        dfsa1(root, 1, 0);
        int ans = 0;
        for (auto& p : mnmap)
        {
            int k = p.first;
            int mn = p.second;
            int mx = mxmap[k];
            ans = max(ans, mx - mn + 1);
        }
        return ans;
    }
    unordered_map<int, long> mnmap;
    unordered_map<int, long> mxmap;
    void dfsa1(TreeNode* node, int lv, long idx)
    {
        if (node == nullptr)
            return;
        if (mnmap.find(lv) == mnmap.end())
        {
            mxmap[lv] = idx;
            mnmap[lv] = idx;
        }
        else
        {
            mnmap[lv] = min(mnmap[lv], idx);
            mxmap[lv] = max(mxmap[lv], idx);
        }
        idx *= 2;
        dfsa1(node->left, lv + 1, idx);
        dfsa1(node->right, lv + 1, idx + 1);
    }

};

int main()
{
    int arr[] = {1,3,2,5,3,-1,9};

    TreeNode* r = convert2TreeNode(arr);

    LT0662 lt;

    cout<<lt.lt0662b(r);

    return 0;
}
