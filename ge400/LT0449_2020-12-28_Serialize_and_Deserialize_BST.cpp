
#include "../header/myheader.h"

class LT0449
{
public:



};

// D D

// 只需要后面加一个 字符就可以了。




//Runtime: 52 ms, faster than 21.18% of C++ online submissions for Serialize and Deserialize BST.
//Memory Usage: 35.1 MB, less than 16.11% of C++ online submissions for Serialize and Deserialize BST.
// N(l((ll)(lr)))(r)
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return dfsa1(root);
    }

    string dfsa1(TreeNode* node)
    {
        if (node == nullptr)
            return "";
        string str = std::to_string(node->val);
        str += "(" + dfsa1(node->left) + ")(" + dfsa1(node->right) + ")";
        return str;
    }

// 2(1()())(3()());
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        idx = 0;
        TreeNode* ans = dfsa2(data);
        return ans;
    }
    int idx = 0;
    TreeNode* dfsa2(string& str)
    {
        if (idx >= str.size() || str[idx] == ')')
        {
            idx++;
            return nullptr;
        }
        int val = 0;
        while (std::isdigit(str[idx]))
        {
            val *= 10;
            val += str[idx] - '0';
            idx++;
        }
        TreeNode* ans = new TreeNode(val);
        idx++;
        ans->left = dfsa2(str);
        idx++;
        ans->right = dfsa2(str);
        idx++;
        return ans;
    }

};



int main()
{
//    int arr[] = {2,1,3};
//
//    TreeNode* r = convert2TreeNode(arr);
//
//    showTreeNode(r, 5);

    TreeNode* r = nullptr;

    Codec c;
    string str = c.serialize(r);
    cout<<"str : "<<str<<endl;

    TreeNode* r2 = c.deserialize(str);

    showTreeNode(r2, 5);

    LT0449 lt;


    return 0;
}
