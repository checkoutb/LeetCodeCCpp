
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        istringstream in(preorder);
//        vector<string> v;
//        string t = "";
//        int cnt = 0;
//        while (getline(in, t, ',')) v.push_back(t);


//The capacity is the number of node that can be put in the tree. The initial value is 1, which means there can be a root.
//When adding a node, capacity--;
//When adding a non-NULL node, it means we obtains two more leafs, then capacity +=2.
//The final capacity should be equal to 0






// AC
// 每个非null 结点都有2个结点(可以全null(#)).  null不能有子结点。
// 感觉最简单的是 根据preorder 造一棵树。 not allowed
// 或者dfs，模仿遍历。dfs。
    bool lta(string preorder)
    {
        string str = "";
        for (int i = 0; i < preorder.size(); ++i)
        {
            if (preorder[i] == ',')
                str += preorder[i - 1];
        }
        str += preorder[preorder.size() - 1];

        int idx = 0;
        bool ans = dfsa1(str, idx);
        return ans && idx == str.size();
    }

    // is ok?
    bool dfsa1(string preorder, int& idx)
    {
        if (idx >= preorder.size())
            return false;
        char ch = preorder[idx++];
        if (ch == '#')
            return true;
        if (!dfsa1(preorder, idx))
            return false;
        return dfsa1(preorder, idx);
    }

};

int main()
{

//    string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
//    string s = "1,#";
    string s = "9,#,#,111111111111111";

    LT lt;

    cout<<lt.lta(s)<<endl;

    return 0;
}
