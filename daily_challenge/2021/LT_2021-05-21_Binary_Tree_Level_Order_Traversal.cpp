
#include "../../header/myheader.h"

class LT
{
public:

// D

//        while(!q.empty())
//        {
//            int n = q.size();
//            for(int i=0;i<n;i++)


//void buildVector(TreeNode *root, int depth)
//{
//    if(root == NULL) return;
//    if(ret.size() == depth)
//        ret.push_back(vector<int>());
//
//    ret[depth].push_back(root->val);
//    buildVector(root->left, depth + 1);
//    buildVector(root->right, depth + 1);
//}


// AC
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)            // The number of nodes in the tree is in the range [0, 2000].....
            return ans;
        queue<TreeNode*> que1;
        que1.push(root);
        vector<int> vi;
        while (!que1.empty())
        {
            vi.clear();
            queue<TreeNode*> que2;
            while (!que1.empty())
            {
                TreeNode* np = que1.front();
                que1.pop();
                vi.push_back(np->val);
                if (np->left != nullptr)
                    que2.push(np->left);
                if (np->right != nullptr)
                    que2.push(np->right);
            }
            ans.push_back(vi);
            std::swap(que1, que2);

////            vi.clear();
//            vector<int> vi;
//            TreeNode* np = que1.front();
//            que1.pop();
//            vi.push_back(np->val);
//            if (np->left)
//                que1.push(np->left);
//            if (np->right)
//                que1.push(np->right);
//            ans.push_back(vi);
        }
        return ans;
    }

};

int main()
{
    myvi vi = {3,9,20,-1,-1,15,7};

    TreeNode* root = convert2TreeNode(vi);

    showTreeNode(root, 5);

    LT lt;

    myvvi vv = lt.levelOrder(root);

    for (myvi& v : vv)
    {
        showVectorInt(v);
    }

    cout<<"======"<<endl;

    deleteTreeNode(root);           // .....疯狂memory leak。。。忘记这个了。。

    return 0;
}
