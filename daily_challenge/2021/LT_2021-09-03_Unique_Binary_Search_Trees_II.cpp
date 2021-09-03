
#include "../../header/myheader.h"

class LT
{
public:

// D D

//map<pair<int,int>,vector<TreeNode*> > m;






// divide
// insert
    vector<TreeNode*> lta(int n)
    {
        vector<TreeNode*> ans = dfsa1(1, n);
        return ans;
    }

    vector<TreeNode*> dfsa1(int st, int en)
    {
//        if (st == en)
//        {
//            TreeNode* n = new TreeNode(st);
//            return {n};
//        }
        if (st > en)
        {
            return {nullptr};
        }
        vector<TreeNode*> ans;
        for (int i = st; i <= en; ++i)
        {
            vector<TreeNode*> vl = dfsa1(st, i - 1);
            vector<TreeNode*> vr = dfsa1(i + 1, en);
            for (TreeNode* l : vl)
            {
                for (TreeNode* r : vr)
                {
                    TreeNode* n = new TreeNode(i);
                    n->left = l;
                    n->right = r;
                    ans.push_back(n);
                }
            }
        }
        return ans;
    }

};

int main()
{
//    int n = 3;
    int n = 1;

    LT lt;

    vector<TreeNode*> vt = lt.lta(n);

    cout<<vt.size()<<endl;
    for (TreeNode* n : vt)
    {
//        cout<<n<<endl;
        showTreeNode(n, 5);
        deleteTreeNode(n);
        cout<<n<<endl;
        cout<<(n == nullptr)<<endl;         // false..  now true..
//        cout<<((*n) == nullptr)<<endl;        // no operator== for TreeNode and nullptr ...
    }

    return 0;
}
