
#include "../header/myheader.h"

class LT0987
{
public:

// D D

//    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
//public:
//    void traverse(TreeNode* root, int col, int row){
//        if(!root) return;
//        pq.push({col, row, root->val});
//        traverse(root->left, col-1, row+1);
//        traverse(root->right, col+1, row+1);
//    }
//
//    vector<vector<int>> verticalTraversal(TreeNode* root) {
//        vector<vector<int>> ans;
//        int temp = INT_MIN, col, val;
//        traverse(root, 0, 0);
//        while(!pq.empty()){
//            col = pq.top()[0];
//            val = pq.top()[2];
//            pq.pop();
//            if(temp != col) ans.push_back(vector<int>{});
//            temp = col;
//            ans[ans.size()-1].push_back(val);
//        }
//        return ans;
//    }



//    vector<vector<int>> verticalTraversal(TreeNode* root) {
//        traverse( root, 0, 0 );
//        for(auto it = mp.begin(); it!= mp.end(); ++it) {
//            vector<int> vertical;
//            for(auto it1 = it->second.begin(); it1 != it->second.end(); ++it1) {
//                for(auto it2 = it1->second.begin(); it2 != it1->second.end(); ++it2) {
//                    vertical.push_back(*it2);
//                }
//            }
//            ans.push_back(vertical);
//        }
//        return ans;
//    }
//
//private:
//    map<int, map <int, multiset<int> > > mp;
//    vector<vector<int> > ans;
//
//    void traverse(TreeNode* root, int level, int distFromCentre) {
//        if(root == NULL) {return;}
//        mp[distFromCentre][level].insert(root->val);
//        traverse( root->left, level + 1,  distFromCentre - 1 );
//        traverse( root->right, level + 1,  distFromCentre + 1 );
//        return;
//    }



//Runtime: 4 ms, faster than 79.74% of C++ online submissions for Vertical Order Traversal of a Binary Tree.
//Memory Usage: 12.9 MB, less than 64.65% of C++ online submissions for Vertical Order Traversal of a Binary Tree.
// sort. 还有，root.llll不一定是 最左的。。。。。 same row same col 才sort。。
// node node.left.right node.right.left    in same column
// root.left.l.l.l...l is the 0th column
    vector<vector<int>> lt0987a(TreeNode* root)
    {
        int l = 0;
        int r = 0;
//        TreeNode* n = root;
//        while (n != nullptr)
//        {
//            l++;
//            n = n->left;
//        }
//        n = root;
//        while (n != nullptr)
//        {
//            r++;
//            n = n->right;
//        }

        dfsa2(root, l, r, 0);

        vector<vector<pair<int, int>>> ans(r - l + 1);

        dfsa1(root, ans, 0 - l, 0);

        for (vector<pair<int, int>>& vi : ans)
            std::sort(begin(vi), end(vi));

        vector<vector<int>> ans2(ans.size());
        for (int i = 0; i < ans.size(); ++i)
        {
            for (pair<int, int>& pii : ans[i])
            {
                ans2[i].push_back(pii.second);
            }
        }

        return ans2;
    }
    void dfsa2(TreeNode* node, int& l, int& r, int col)
    {
        if (node == nullptr)
            return;
        l = min(col, l);
        r = max(col, r);
        dfsa2(node->left, l, r, col - 1);
        dfsa2(node->right, l, r, col + 1);
    }
//    void dfsa1(TreeNode* node, int& r, int col)
//    {
//
//    }
    void dfsa1(TreeNode* node, vector<vector<pair<int, int>>>& ans, int col, int row)
    {
        if (node == nullptr)
            return;
        ans[col].emplace_back(std::make_pair(row, node->val));
        dfsa1(node->left, ans, col - 1, row + 1);
        dfsa1(node->right, ans, col + 1, row + 1);
    }

};

int main()
{
//    int arr[] = {3,9,20,-1,-1,15,7};
//    int arr[] = {1,2,3,4,5,6,7};
//    int arr[] = {1,2,3,4,6,5,7};
    int arr[] = {3,1,4,0,2,2};          // [[0],[1],[3,2,2],[4]]


    TreeNode* r = convert2TreeNode(arr);
    showTreeNode(r, 5);

    LT0987 lt;

    myvvi vv = lt.lt0987a(r);
    for (myvi& v : vv)
    {
        for (int i : v)
        {
            cout<<i<<", ";
        }
        cout<<endl;
    }

    return 0;
}
