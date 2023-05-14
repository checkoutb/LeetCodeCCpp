
#include "../header/myheader.h"

class LT2641
{
public:

// D D

//                if(curr->left && curr->right){
//                    int sum = curr->left->val + curr->right->val;
//                    temp_sum += (curr->left->val + curr->right->val);
// 遍历当前层的时候，计算下一层的sum。


//    Runtime764 ms
//    Beats
//    51.85%
//    Memory295.1 MB
//    Beats
//    58.28%
    TreeNode* lt2641a(TreeNode* root)
    {
        //queue<pair<TreeNode*, int>> que1{{root, root->val}};
        vector<pair<TreeNode*, int>> vp{{root, root->val}};

        while(!vp.empty())
        {
            int sz1 = vp.size();
            int sum2 = 0;
            for (int i = 0; i < sz1; ++i)
            {
                sum2 += vp[i].first->val;
            }
            vector<pair<TreeNode*, int>> vp2;
            int t2 = 0;
            for (int i = 0; i < sz1; ++i)
            {
                vp[i].first->val = sum2 - vp[i].second;
                t2 = (vp[i].first->left == nullptr ? 0 : vp[i].first->left->val) + (vp[i].first->right == nullptr ? 0 : vp[i].first->right->val);
                if (vp[i].first->left != nullptr)
                    vp2.push_back(std::make_pair(vp[i].first->left, t2));
                if (vp[i].first->right != nullptr)
                    vp2.push_back(std::make_pair(vp[i].first->right, t2));
            }
            swap(vp2, vp);
        }
        return root;
    }

};

int main()
{

    LT2641 lt;


    return 0;
}
