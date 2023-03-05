
#include "../header/myheader.h"

class LT2583
{
public:

    // D D





    //Runtime203 ms
    //    Beats
    //    100 %
    //    Sorry, there are not enough accepted submissions to show data
    //    Memory118.8 MB
    //    Beats
    //    100 %
    long long lt2583a(TreeNode* root, int k)
    {
        vector<long long> vi;
        dfsa1(root, vi, 1);

        if (k > vi.size())
            return -1LL;

        std::nth_element(begin(vi), begin(vi) + k - 1, end(vi), std::greater<long long>());

        return vi[k - 1];
    }

    void dfsa1(TreeNode* node, vector<long long>& vi, int depth)
    {
        if (node == nullptr)
            return;

        if (vi.size() < depth)
            vi.push_back(node->val);
        else
            vi[depth - 1] += node->val;

        dfsa1(node->left, vi, depth + 1);
        dfsa1(node->right, vi, depth + 1);
    }

};

int main()
{

    LT2583 lt;


    return 0;
}
