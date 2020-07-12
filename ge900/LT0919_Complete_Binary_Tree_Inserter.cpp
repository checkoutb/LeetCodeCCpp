
#include "../header/myheader.h"

class LT0919
{
public:



};


// D D

//cout<<std::log2(10)<<endl;
//TreeNode* test2 = new TreeNode{5};
//int a {5};
// ... ? 20ms..


//        if (N % 2)
//            tree[(N - 1) / 2]->left = node;
//        else
//            tree[(N - 1) / 2]->right = node;




//Runtime: 44 ms, faster than 25.77% of C++ online submissions for Complete Binary Tree Inserter.
//Memory Usage: 14.3 MB, less than 99.30% of C++ online submissions for Complete Binary Tree Inserter.
class CBTInserter {
public:
    CBTInserter(TreeNode* root) {
        r_ = root;
        TreeNode* head = r_;
        while (head != nullptr)
        {
            lvl++;
            head = head->left;
        }
        lvl--;
        int total = cnta1(r_);
        int t2 = 1;
        while (total >= t2)
        {
            total -= t2;
            t2 *= 2;
        }
        nexti = total;
        if (nexti == 0)
            lvl++;
        #ifdef __test
        cout<<lvl<<", "<<nexti<<endl;
        #endif // __test
    }

    int insert(int v) {
        int ans = find_insert(r_, v, nexti, 0);
        nexti++;
        if (1 << lvl == nexti)
        {
            lvl++;
            nexti = 0;
        }
        #ifdef __test
        cout<<lvl<<" + "<<nexti<<endl;
        #endif // __test
        return ans;
    }

    TreeNode* get_root() {
        return r_;
    }


    int nexti = 0;
    int lvl = 0;
    TreeNode* r_;
    int find_insert(TreeNode* n, int v, int num, int lv)
    {

        #ifdef __test
        cout<<n->val<<", "<<v<<", "<<num<<", "<<lv<<endl;
        #endif // __test

        if (lv + 1 == lvl)
        {
            if (num == 0)
            {
                n->left = new TreeNode(v);
            }
            else
            {
                n->right = new TreeNode(v);
            }
            return n->val;
        }
        else
        {
            int t2 = 1 << (lvl - lv - 1);
            if (t2 <= num)
            {
                return find_insert(n->right, v, num - t2, lv + 1);
            }
            else
            {
                return find_insert(n->left, v, num, lv + 1);
            }
        }
        return -1;
    }
    int cnta1(TreeNode* n)
    {
        if (n == nullptr)
            return 0;
        else
            return 1 + cnta1(n->left) + cnta1(n->right);
    }
};


int main()
{
    cout<<std::log2(10)<<endl;
    int a {5};
    cout<<a<<endl;

    TreeNode* test2 = new TreeNode{5};
    cout<<test2->val<<endl;

    int arr[] = {1};
//    int arr[] = {1,2,3,4,5,6};

    TreeNode* n = convert2TreeNode(arr);
    showTreeNode(n, 3);

    CBTInserter ins(n);

    cout<<ins.insert(7)<<endl;;

    showTreeNode(ins.get_root(), 3);

    ins.insert(8);

    n = ins.get_root();

    showTreeNode(n, 3);


    LT0919 lt;


    return 0;
}
