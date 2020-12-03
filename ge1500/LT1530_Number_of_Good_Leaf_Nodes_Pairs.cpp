
#include "../header/myheader.h"

class LT1530
{
public:





//Runtime: 68 ms, faster than 96.73% of C++ online submissions for Number of Good Leaf Nodes Pairs.
//Memory Usage: 35.9 MB, less than 60.82% of C++ online submissions for Number of Good Leaf Nodes Pairs.
    int lt1530a(TreeNode* root, int distance)
    {
        vector<int> v(10);
        dfsa1(root, v, distance);
        return ans;
    }
    int ans = 0;
    void dfsa1(TreeNode* node, vector<int>& v, int dis)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            v[0] = 1;
            return;
        }
        vector<int> vl(10, 0);
        if (node->left != nullptr)
        {
            dfsa1(node->left, vl, dis);
        }
        vector<int> vr(10, 0);
        if (node->right != nullptr)
        {
            dfsa1(node->right, vr, dis);
        }
        for (int i = 0; i < 9; i++)
        {
            int t2 = dis - 2 - i;
            for (int j = 0; j <= t2; j++)
                ans += vl[i] * vr[j];
            v[i + 1] = vl[i] + vr[i];
        }
    }

};

int main()
{

//    int arr[] = {1,2,3,-1,4};
////    int arr[] = {1,2,3,4,5,6,7};
//    int dis = 3;

//    int arr[] = {100};
//    int dis{1};

    int arr[] = {1,1,1};
    int dis{2};

    TreeNode* r = convert2TreeNode(arr);
    LT1530 lt;

    cout<<lt.lt1530a(r, dis);

    return 0;
}
