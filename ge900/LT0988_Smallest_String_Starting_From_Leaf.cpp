
#include "../header/myheader.h"

class LT0988
{
public:


// D
// 不必保存每个，只需要保存最小的就可以了， string& ans


//Runtime: 52 ms, faster than 6.13% of C++ online submissions for Smallest String Starting From Leaf.
//Memory Usage: 20.3 MB, less than 20.35% of C++ online submissions for Smallest String Starting From Leaf.
    string lt0988b(TreeNode* root)
    {
        vector<string> vs;
//        string s(1, (char) (root->val + 'a'));
        string s = "";
        cout<<s<<endl<<endl;
        dfsb1(root, s, vs);
        std::sort(vs.begin(), vs.end());
        return vs[0];
    }

    void dfsb1(TreeNode* node, string s, vector<string>& vs)
    {
        cout<<s<<endl;
        if (node->left == nullptr && node->right == nullptr)
        {
            s += (char) (node->val + 'a');
            std::reverse(s.begin(), s.end());
            vs.push_back(s);
        }
        if (node->left != nullptr)
        {
            dfsb1(node->left, s + (char) (node->val + 'a'), vs);
        }
        if (node->right != nullptr)
        {
            dfsb1(node->right, s + (char) (node->val + 'a'), vs);
        }
    }


// error
    string lt0988a(TreeNode* root)
    {
        return dfsa1(root);
    }

    string dfsa1(TreeNode* node)
    {
        string s1 = "{";        // 'z' + 1 == '{'
        string s2 = "{";

        if (node->left != nullptr)
            s1 = dfsa1(node->left) + (char) (node->val + 'a');
        if (node->right != nullptr)
            s2 = dfsa1(node->right) + (char) (node->val + 'a');
        string s3 = getSmall(s1, s2);
        if (s3 == "")
            s3 += (char) (node->val + 'a');
        return s3;
    }

    string getSmall(string s1, string s2)
    {
        if (s1 == "{" && s2 == "{")
            return "";
        int sz1 = min(s1.size(), s2.size());
        for (int i = 0; i < sz1; i++)
        {
            if (s1[i] < s2[i])
            {
                return s1;
            }
            if (s1[i] > s2[i])
            {
                return s2;
            }
        }
        if (s1.size() == sz1)
        {
            return s1;
        }
        else
        {
            return s2;
        }
    }

};

int main()
{

//    int arr[] = {25,1,3,1,3,0,2};
//    int arr[] = {0,1,2,3,4,3,4};

//    int arr[] = {0, 1};

    int arr[] = {25,1,-1,0,0,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,0};

//    int arr[] = {4,0,1,1};

    TreeNode* node = convert2TreeNode(arr);

    showTreeNode(node, 3);
    cout<<"=================="<<endl;

    LT0988 lt;

    cout<<lt.lt0988b(node)<<endl;

    return 0;
}
