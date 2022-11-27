
#include "../header/myheader.h"

class LT2476
{
public:






    //Runtime872 ms
    //    Beats
    //    30.73 %
    //    Memory148.3 MB
    //    Beats
    //    31.37 %
    vector<vector<int>> lt2476b(TreeNode* root, vector<int>& queries)
    {
        int sz1 = queries.size();
        vector<vector<int>> vvi(sz1, vector<int>(2));

        vector<int> vi;

        dfsa1(root, &vi);

        for (int i = 0; i < sz1; ++i)
        {
            int t2 = queries[i];

            // >=
            vector<int>::iterator it = std::lower_bound(begin(vi), end(vi), t2);

            if (it == vi.end())
            {
                vvi[i][0] = *prev(it);
                vvi[i][1] = -1;
            }
            else if (it == vi.begin())
            {
                vvi[i][0] = (*it == t2 ? t2 : -1);
                vvi[i][1] = *it;
            }
            else
            {
                vvi[i][0] = (*it == t2 ? t2 : *prev(it));
                vvi[i][1] = *it;
            }

        }
        return vvi;
    }

    // pre-order
    void dfsa1(TreeNode* node, vector<int>* vi)
    {
        if (node == nullptr)
            return;

        dfsa1(node->left, vi);

        vi->push_back(node->val);

        dfsa1(node->right, vi);
    }


    // µ¥Á´±í tle¡£
    vector<vector<int>> lt2476a(TreeNode* root, vector<int>& queries)
    {
        int sz1 = queries.size();

        vector<vector<int>> vvi(sz1, vector<int>(2));

        for (int i = 0; i < sz1; ++i)
        {
            vvi[i][0] = findless(root, queries[i]);
            vvi[i][1] = findbigger(root, queries[i]);
        }

        return vvi;
    }

    // biggest small
    int findless(TreeNode* node, int tar)
    {
        if (node == nullptr)
            return -1;

        if (node->val == tar)
            return tar;

        if (node->val > tar)
        {
            return findless(node->left, tar);
        }
        else
        {
            int ans = findless(node->right, tar);
            if (ans == -1 || ans < node->val)
                ans = node->val;

            return ans;
        }
    }

    int findbigger(TreeNode* node, int tar)
    {
        if (node == nullptr)
            return -1;

        if (node->val == tar)
            return tar;

        if (node->val > tar)
        {
            int ans = findbigger(node->left, tar);
            if (ans == -1 || ans > node->val)
                ans = node->val;

            return ans;
        }
        else
        {
            return findbigger(node->right, tar);
        }
    }

};

int main()
{

    LT2476 lt;


    return 0;
}
