
#include "../header/myheader.h"

class LT2096
{
public:

    // D D

    // LCA



//    apply LCA to get a new root.
//    get the Path from the new root to start and dest.
//    concate startPath and destPath, note that we need to replace startPath's char to 'U'

//    TreeNode* lca(TreeNode *root, int startValue, int destValue) {
//        if(!root) return NULL;
//        if(root->val == startValue) return root;
//        if(root->val == destValue) return root;
//        auto l = lca(root->left, startValue, destValue);
//        auto r = lca(root->right, startValue, destValue);
//        if(l && r) return root;
//        return l ? l : r;
//    }
//    bool getPath(TreeNode *root, int value, string &path) {
//        if(!root) return false;
//        if(root->val == value) return true;
//        path += 'L';
//        auto res = getPath(root->left, value, path);
//        if(res) return true;
//        path.pop_back();
//        path += 'R';
//        res = getPath(root->right, value, path);
//        if(res) return true;
//        path.pop_back();
//        return false;
//    }
//    string getDirections(TreeNode* root, int startValue, int destValue) {
//        root = lca(root, startValue, destValue);
//        string p1, p2;
//        getPath(root, startValue, p1);
//        getPath(root, destValue, p2);
//        for(auto &c : p1) c = 'U';
//        return p1 + p2;
//    }



//bool find(TreeNode* n, int val, string &path) {
//    if (n->val == val)
//        return true;
//    if (n->left && find(n->left, val, path))
//        path.push_back('L');
//    else if (n->right && find(n->right, val, path))
//        path.push_back('R');
//    return !path.empty();
//}
//string getDirections(TreeNode* root, int startValue, int destValue) {
//    string s_p, d_p;
//    find(root, startValue, s_p);
//    find(root, destValue, d_p);
//    while (!s_p.empty() && !d_p.empty() && s_p.back() == d_p.back()) {
//        s_p.pop_back();
//        d_p.pop_back();
//    }
//    return string(s_p.size(), 'U') + string(rbegin(d_p), rend(d_p));
//}


    // 内存也是差不多炸了。
//Runtime: 390 ms, faster than 23.82% of C++ online submissions for Step-By-Step Directions From a Binary Tree Node to Another.
//Memory Usage: 218.3 MB, less than 5.81% of C++ online submissions for Step-By-Step Directions From a Binary Tree Node to Another.
    string lt2096b(TreeNode* root, int startValue, int destValue)
    {
        vector<string> vst;
        vector<string> ven;

        dfsb2(root, startValue, destValue, vst, ven, true);

        //string ans(' ', int(vst.size()) + int(ven.size()));
        string ans(vst.size() + ven.size() - (vst[0].empty()) - (ven[0].empty()), '-');

        #ifdef __test
        for (string& s : vst)
            cout<<s;
        cout<<endl;
        for (string& s : ven)
            cout<<s;
        cout<<endl;

        cout<<" ======== "<<vst.size()<<", "<<ven.size()<<endl;
        cout<<" ?? "<<ans.size()<<endl;
        #endif // __test


        for (int i = 0; i < vst.size(); ++i)
            if (vst[i] != "")
                ans[i] = vst[i][0];

        for (int i = 0; i < ven.size(); ++i)
            if (ven[i] != "")
                ans[ans.size() - 1 - i] = ven[i][0];

        return ans;
    }

    // 0:none, 1:st, 2:en, 3:both
    int dfsb2(TreeNode* node, int st, int en, vector<string>& vst, vector<string>& ven, bool isL)
    {
        if (node == nullptr)
            return 0;

        int lft = dfsb2(node->left, st, en, vst, ven, true);

        if (lft == 3)
            return 3;

        int rht = dfsb2(node->right, st, en, vst, ven, false);
        if (rht == 3)
            return 3;

        if ((lft | rht) == 3)
            return 3;

        if (node->val == st)
        {
            if (lft == 2 || rht == 2)
            {
                vst.push_back("");
                return 3;
            }
            else
            {
                vst.push_back("U");
                return 1;
            }
        }
        else if (node->val == en)
        {
            if (lft == 1 || rht == 1)
            {
                ven.push_back("");
                return 3;
            }
            else
            {
                ven.push_back(isL ? "L" : "R");
                return 2;
            }
        }
        else
        {
            if ((lft | rht) & 1)
            {
                vst.push_back("U");
                return 1;
            }
            if ((lft | rht) & 2)
            {
                ven.push_back(isL ? "L" : "R");
                return 2;
            }
        }
        return 0;
    }




// Memory Limit Exceeded
    string lt2096a(TreeNode* root, int startValue, int destValue)
    {
        pair<int, string> p = dfsa1(root, startValue, destValue, true);
        return p.second;
    }

    // 0:got none, 1:got st, 2:got en, 3:got both
    pair<int, string> dfsa1(TreeNode* node, int st, int en, bool isL)
    {
        if (node == nullptr)
        {
            return {0, ""};
        }

        pair<int, string> p1 = dfsa1(node->left, st, en, true);
        pair<int, string> p2 = dfsa1(node->right, st, en, false);

        if (p1.first == 3)
            return p1;
        if (p2.first == 3)
            return p2;

        if (p1.first == 1)
        {
            if (p2.first == 2)
            {
                return {3, p1.second + p2.second};
            }
            else
            {
                if (node->val == en)
                {
                    return {3, p1.second};
                }
                else
                {
                    return {1, p1.second + ("U")};
                }
            }
        }
        else if (p1.first == 2)
        {
            if (p2.first == 1)
            {
                return {3, p2.second + p1.second};
            }
            else
            {
                if (node->val == st)
                {
                    return {3, p1.second};          // p2.second ==== ""
                }
                else
                {
                    #ifdef __test
                    if (node->val == 2)
                    {
                        cout<<" 222 "<<((isL ? "L" : "R") + p2.second)<<endl;
                    }
                    #endif // __test
                    return {2, (isL ? "L" : "R") + p1.second};
                }
            }
        }
        else        // p1 = 0
        {
            if (p2.first == 1)
            {
                if (node->val == en)
                {
                    return {3, p2.second};
                }
                return {1, p2.second + "U"};
            }
            else if (p2.first == 2)
            {
                if (node->val == st)
                {
                    return {3, p2.second};
                }
                return {2, (isL ? "L" : "R") + p2.second};
            }
            else        // p1 = 0, p2 = 0
            {
                if (node->val == st)
                {
                    return {1, "U"};
                }
                else if (node->val == en)
                {
                    #ifdef __test
                    cout<<"got en "<<(isL ? "L" : "U")<<endl;
                    #endif // __test
                    return {2, (isL ? "L" : "R")};
                }
            }
        }
        return {0, ""};
    }

};

int main()
{

    LT2096 lt;

//    int arr[] = {5,1,2,3,-1,6,4};       // uurl
//    int st = 3, en = 6;

//    int arr[] = {2,1};
//    int st = 2, en = 1;       // l

//[7,8,3,1,null,4,5,6,null,null,null,null,null,null,2]
//7
//5
// RR

    int arr[] = {7,8,3,1,-1,4,5,6,-1,-1,-1,-1,-1,-1,-1,-1,2};
    int st = 7, en = 5;

    TreeNode* r = convert2TreeNode(arr);

    showTreeNode(r, 5);

    cout<<lt.lt2096b(r, st, en)<<endl;

    deleteTreeNode(r);

    return 0;
}
