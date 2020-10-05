
#include "../header/myheader.h"

class LT0662
{
public:





// long long ye bei bao le...
    int lt0662c(TreeNode* root)
    {
        unordered_map<int, long long> mxp;
        unordered_map<int, long long> mnp;
        dfsc1(root, mxp, mnp, 0, 0);
        int ans = 0;
        for (auto& p : mxp)
        {
            ans = max(ans, (int) (p.second - mnp[p.first]));
        }
        return ans + 1;
    }

    void dfsc1(TreeNode* node, unordered_map<int, long long>& mxp, unordered_map<int, long long>& mnp, int depth, long long index)
    {
        if (node == nullptr)
            return;
        mxp[depth] = index;
        if (mnp.find(depth) == mnp.end())
            mnp[depth] = index;
        dfsc1(node->left, mxp, mnp, depth + 1, index * 2);
        dfsc1(node->right, mxp, mnp, depth + 1, index * 2 + 1);
    }


// tle...
// 3000Node连成线，内存会爆炸。。。
    int lt0662b(TreeNode* root)
    {
        deque<TreeNode*> deq;
        deq.push_back(root);
        int ans = 0;
        while (!deq.empty())
        {
            int sz1 = deq.size();
            ans = max(ans, sz1);
            for (int i = 0; i < sz1; i++)
            {
                TreeNode* np = deq.front();
                deq.pop_front();
                deq.push_back(np == nullptr ? nullptr : np->left);
                deq.push_back(np == nullptr ? nullptr : np->right);
            }
            while (!deq.empty() && deq.front() == nullptr)
                deq.pop_front();
            while (!deq.empty() && deq.back() == nullptr)
                deq.pop_back();
        }
        return ans;
    }

// ...
    int lt0662a(TreeNode* root)
    {
        queue<TreeNode*> que1;
        que1.push(root);
        int ans = 0;
        while (!que1.empty())
        {
            int sz1 = que1.size();
            ans = max(ans, sz1);
            bool start;
            for (int i = 0; i < sz1; i++)
            {
                TreeNode* np = que1.front();
                que1.pop();
                if (np->left != nullptr)
                    que1.push(np->left);
                if (np->right != nullptr)
                    que1.push(np->right);
            }
        }
        return ans;
    }

};

int main()
{
    int arr[] = {1,3,2,4,-1,-1,5,4};

    TreeNode* n = convert2TreeNode(arr);
    LT0662 lt;

    cout<<lt.lt0662c(n)<<endl;

    deleteTreeNode(n);
    return 0;
}
