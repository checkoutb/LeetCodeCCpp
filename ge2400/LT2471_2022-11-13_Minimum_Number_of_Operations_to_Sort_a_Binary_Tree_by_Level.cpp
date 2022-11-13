
#include "../header/myheader.h"

class LT2471
{
public:

    // D D


    // CycleSort


    //int count(vector<int>& v) {
    //    vector<int> v2 = v;
    //    sort(v2.begin(), v2.end());
    //    unordered_map<int, int> location;
    //    int n = v.size();
    //    int ret = 0;
    //    for (int i = 0; i < n; ++i) {
    //        location[v2[i]] = i;
    //    }
    //    for (int i = 0; i < n; ++i) {
    //        int loc = location[v[i]];
    //        if (loc != i) {
    //            swap(v[i], v[loc]);
    //            ret++;
    //            --i;
    //        }
    //    }
    //    return ret;
    //}




    // after solution...

    //Runtime308 ms
    //    Beats
    //    100 %
    //    Memory126 MB
    //    Beats
    //    50 %
    int lt2471b(TreeNode* root)
    {
        queue<TreeNode*> que1;
        que1.push(root);
        int ans = 0;

        while (!que1.empty())
        {
            vector<pair<int, int>> vp;
            for (int i = 0, sz1 = que1.size(); i < sz1; ++i)
            {
                TreeNode* node = que1.front();
                que1.pop();
                vp.push_back(make_pair(node->val, i));
                if (node->left != nullptr)
                    que1.push(node->left);
                if (node->right != nullptr)
                    que1.push(node->right);

            }
            sort(begin(vp), end(vp));
            for (int i = 0; i < vp.size(); ++i)
            {
                while (vp[i].second != i)               // ? 和 if 的差别是什么？ .... 因为 vp[vp[i].second].second 不一定等于 i， 所以要执行多次 ，直到等于。
                {
                    int t2 = vp[i].second;
                    swap(vp[t2], vp[i]);
                    ans++;
                }
            }
        }
        return ans;
    }



    // tle
    int lt2471a(TreeNode* root)
    {
        queue<TreeNode*> que1;
        que1.push(root);
        int ans = 0;

        vector<int> vi;
        while (!que1.empty())
        {
            vi.clear();
            for (int i = que1.size(); i > 0; --i)
            {
                TreeNode* node = que1.front();
                que1.pop();
                vi.push_back(node->val);
                if (node->left != nullptr)
                    que1.push(node->left);
                if (node->right != nullptr)
                    que1.push(node->right);
            }
            ans += selecta1(vi);
        }
        return ans;
    }

    int selecta1(vector<int>& vi)
    {
        int ans = 0;
        for (int i = 0; i < vi.size(); ++i)
        {
            int smidx = i;
            for (int j = i + 1; j < vi.size(); ++j)
            {
                if (vi[smidx] > vi[j])
                {
                    smidx = j;
                }
            }
            if (smidx != i)
            {
                swap(vi[smidx], vi[i]);
                ++ans;
            }
        }
        return ans;
    }

};

int main()
{

    LT2471 lt;


    return 0;
}
