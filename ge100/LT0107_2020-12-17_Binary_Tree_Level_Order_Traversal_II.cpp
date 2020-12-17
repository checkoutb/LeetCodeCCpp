
#include "../header/myheader.h"

class LT0107
{
public:

// D D

//        public List<List<Integer>> levelOrderBottom(TreeNode root) {
//            List<List<Integer>> wrapList = new LinkedList<List<Integer>>();
//            levelMaker(wrapList, root, 0);
//            return wrapList;
//        }
//
//        public void levelMaker(List<List<Integer>> list, TreeNode root, int level) {
//            if(root == null) return;
//            if(level >= list.size()) {
//                list.add(0, new LinkedList<Integer>());
//            }
//            levelMaker(list, root.left, level+1);
//            levelMaker(list, root.right, level+1);
//            list.get(list.size()-level-1).add(root.val);
//        }
// dfs




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Level Order Traversal II.
//Memory Usage: 13.1 MB, less than 37.89% of C++ online submissions for Binary Tree Level Order Traversal II.
    vector<vector<int>> lt0107a(TreeNode* root)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> que1;
        que1.push(root);
        while (!que1.empty())
        {
            int sz1 = que1.size();
            vector<int> vi;
            while (sz1-- > 0)
            {
                TreeNode* fnt = que1.front();
                que1.pop();
                vi.push_back(fnt->val);
                if (fnt->left)
                    que1.push(fnt->left);
                if (fnt->right)
                    que1.push(fnt->right);
            }
            ans.push_back(vi);
        }
        reverse(begin(ans), end(ans));              // or use stack save vi
        return ans;
    }

};

int main()
{
    int arr[] = {3,9,20,-1,-1,15,7};

    TreeNode* r = convert2TreeNode(arr);
    LT0107 lt;

    myvvi vv = lt.lt0107a(r);

    for (myvi& vi : vv)
    {
        for (int i : vi)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
