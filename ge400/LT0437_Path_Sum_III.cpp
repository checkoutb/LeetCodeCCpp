
#include "../header/myheader.h"

class LT0437
{
    int ans = 0;
    int tar = 0;
    set<string> set2;
public:



// 慢在vector<int> path...dfs可以用引用。dfs一开始就是push_back,return前pop_back
// detail中dfs是有返回值的，返回本节点可以组成sum的个数，+ 2个子节点return的值。
// 还有int& num 传递结果的累加。
// 还看到一种递归，dfs，以本节点为开始，开始dfs2计算累加值，dfs(子女节点)。。。dfs2嵌套在dfs中。不过比单独dfs的慢一点点。
// 这种递归也可以单个的。
//    int pathSumRoot(TreeNode* root, int sum)
//    {
//        if(root==NULL)  return 0;
//        int res = (root->val==sum) ;
//        res+= pathSumRoot(root->left,sum-root->val);
//        res+= pathSumRoot(root->right,sum-root->val);
//        return res;
//    }
//
//        return pathSum(root->left,sum) + pathSum(root->right,sum)
//            + pathSumRoot(root,sum);


//Runtime: 40 ms, faster than 11.63% of C++ online submissions for Path Sum III.
//Memory Usage: 63.3 MB, less than 6.45% of C++ online submissions for Path Sum III.

    int lt0437c(TreeNode* root, int sum)
    {
        tar = sum;
        vector<int> val;
        dfsc(root, val);
        return ans;
    }

    void dfsc(TreeNode* node, vector<int> path)
    {
        if (!node)
            return;
        path.push_back(node->val);

        int sum = 0;
        for (int i = path.size() - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == tar)
                ans++;
        }

        dfsc(node->left, path);
        dfsc(node->right, path);
    }

    // error
    int lt0437b(TreeNode* root, int sum)
    {
        tar = sum;
        vector<int> path;
        vector<int> path2;
        path2.push_back(1);
        dfsb(root, path, path2);
        return ans;
    }

    void dfsb(TreeNode* node, vector<int> path, vector<int> path2)
    {
        if (!node)
            return;

        path.push_back(node->val);
        if (!node->left && !node->right)
        {

            #ifdef __test
            cout<<endl<<"this is end ... "<<path.size()<<endl;
            for_each(path.begin(), path.end(), fun_cout);
            cout<<endl<<" ------      -------- -- - -"<<endl;
            #endif // __test


            int sz1 = path.size();
            int t1 = 0;
            string str2 = "";
            for (int i = 0; i < sz1; i++)
            {
                string str = str2 + to_string(path2[i]);
                str2 = str;
                t1 = path[i];
                if (t1 == tar)
                {
                    if (set2.find(str) == set2.end())
                    {
                        set2.insert(str);
                        ans++;
                    }
                }
                for (int j = i + 1; j < sz1; j++)
                {
                    str += to_string(path2[j]);
                    t1 += path[j];
                    if (t1 == tar)
                    {
                        if (set2.find(str) == set2.end())
                        {
                            #ifdef __test
                            cout<<"...str : "<<str<<endl;
                            #endif // __test

                            set2.insert(str);
                            ans++;
                        }
                    }

                    #ifdef __test
//                    cout<<t1<<", ";
                    #endif // __test
                }
            }
        }
        else
        {
            path2.push_back(1);
            dfsb(node->left, path, path2);
            path2.pop_back();
            path2.push_back(2);
            dfsb(node->right, path, path2);
        }

    }


    // error
    int lt0437a(TreeNode* root, int sum)
    {
        tar = sum;
        queue<int> path;
        dfs(root, 0, path);
        return ans;
    }

    int dfs(TreeNode* node, int sum, queue<int> path)
    {
        if (node == NULL)
            return -1;
        path.push(node->val);
        sum += node->val;
        if (sum == tar)
        {
            ans++;          // if child.val is zero.
            dfs(node->left, sum, path);
            dfs(node->right, sum, path);
        }
        else
        {
            while (sum > tar && !path.empty())
            {
                sum -= path.front();
                path.pop();
            }
            if (sum == tar && !path.empty())
            {
                ans++;
            }
            dfs(node->left, sum, path);
            dfs(node->right, sum, path);
        }
        return 1;
    }
};

int main()
{
    int arr[] = {10,5,  -3,3,2,-1,11,3,  -2,-1,1};
    int sum = 8;
//
//    int arr[] = {0,1,1};
//    int sum = 1;

    TreeNode* root = convert2TreeNode(arr);
    showTreeNode(root, 3);
    cout<<endl<<"-----------------"<<endl;
//    cout<<endl<<root->left->left->right->val<<endl;

    LT0437 lt;
    cout<<endl<<"result : "<<lt.lt0437c(root, sum)<<endl;

    return 0;
}
