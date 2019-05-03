
#include "../header/myheader.h"

class LT0331
{
public :


//Runtime: 8 ms, faster than 79.39% of C++ online submissions for Verify Preorder Serialization of a Binary Tree.
//Memory Usage: 9.2 MB, less than 34.54% of C++ online submissions for Verify Preorder Serialization of a Binary Tree.

// discuss

// 单独一个深度。。x，#叶子节点的个数必然比 非叶子节点个数多一个。而且，中间不可能出现负值。是不是只要满足这个条件，必然是一个树的先序遍历？
// 不过这段代码下面有人说是错的？。。4.4k views，才5个回复。。。应该没有问题。
// 应该是上面的 叶子节点+1 == 非叶子节点。。但那人只有代码，没有任何的理由。。
//        while (i < strs.length - 1) {
//            if (strs[i++].equals("#")) {
//                if (depth == 0) return false;
//                else depth--;
//            }
//            else depth++;
//        }
//        if (depth != 0) return false;
//        return strs[strs.length - 1].equals("#");


// 有个用出度，入度的。。最终出度==入度，所以diff==0
//    int diff = 1;
//    for (String node: nodes) {
//        if (--diff < 0) return false;
//        if (!node.equals("#")) diff += 2;
//    }
//    return diff == 0;





    // 用一个stack保存从根到现在节点的路径(左还是右子树)
    bool lt0331a(string preorder)
    {
        int sz1 = preorder.size();
        if (sz1 == 1)
            return preorder[0] == '#';
        if (sz1 > 1 && preorder[0] == '#')              // .............
            return false;

        char ch;
//        int row = 0, col = 0;
//        stack<int> st1;
//        stack<int> st2;
        stack<bool> bst;            // true:left, false:right....top: this node is parent's left/right node。
        bool right = false;
        bool left = true;
        bool end = false;
        bool b;
        int i = 0;
        int j = 0;

        bst.push(true);
        for (i = preorder.find_first_of(',') + 1; i != -1; j = preorder.find_first_of(',', i), i = (j == -1 ? -1 : j + 1))
        {

#ifdef __test
            cout<<".."<<i<<"..ch..."<<preorder[i]<<endl;
            stack<bool> bst2;
            bool ba1;
            cout<<"                   ";
            while (!bst.empty())
            {
                ba1 = bst.top();
                cout<<ba1<<",,,,";
                bst.pop();
                bst2.push(ba1);
            }
            cout<<endl;
            while (!bst2.empty())
            {
                ba1 = bst2.top();
                bst2.pop();
                bst.push(ba1);
            }
#endif // __test

            if (bst.empty())
            {
#ifdef __test
                cout<<"...."<<i<<endl;
#endif // __test
                return false;
            }
            ch = preorder[i];
            if (ch == '#')      // leaf node
            {
                b = bst.top();
                bst.pop();
                if (b)      // this ch is left child, next ch is this ch's parent's right child.
                {
                    bst.push(right);     // .
                }
                else
                {
//                    // parent's
//                    b = bst.top();      // this leaf node is right child, next ch is this ch's parent' parent' .... 'parent....'s right child
//                    while (!b)  // parent is its parent's right child.
//                    {
//                        bst.pop();
//                        if (bst.empty())
//                        {
//                            return preorder.find_first_of(',', i) == -1;
//                        }
//                        b = bst.top();
//                    }
//                    do{
//                        bst.pop();
//                        if (bst.empty())
//                        {
//                            #ifdef __test
//                            cout<<".pop.."<<i<<endl;
//                            #endif // __test
//                            return preorder.find_first_of(',', i) == -1;
//                        }
//                        b = bst.top();
//                    }
//                    while(!b);
                    if (bst.empty())
                    {
                        return preorder.find_first_of(',', i) == -1;
                    }
                    b = bst.top();
                    while (!b)
                    {
                        bst.pop();
                        if (bst.empty())
                        {
                            return preorder.find_first_of(',', i) == -1;
                        }
                        b = bst.top();
                    }
                    bst.pop();      // this is left child.
                    bst.push(right);
                }
                continue;
            }
            else
            {
                bst.push(left);        // not leaf node, next node must be a left child.
                continue;
            }
        }

        #ifdef __test
        cout<<",,,,,,,,,"<<bst.empty()<<"...size...."<<bst.size()<<endl;
        #endif // __test

        return bst.empty();
    }

//    int recursiona1(string s, int i)
//    {
//        char ch = s[i];
//        if (ch == '#')
//        {
//            return i;
//        }
//        else
//        {
//            int t1 = recursiona1(string s, i + 1);
//            if (t1 == i + 1)
//            {
//                return i;
//            }
//            else
//            {
//
//            }
//        }
//    }
};

int main()
{
//    string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
//    string s = "1,#,#,1";
//    string s = "#";

    string s = "#,#,#";

    bool a = true;
//    stack<bool> st;
//    st.push(a);
//    st.push(a);
//    st.push(a);
//    cout<<st.size()<<endl;

    LT0331 lt;

    cout<<endl<<lt.lt0331a(s)<<endl;

    return 0;
}
