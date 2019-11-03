
#include "../header/myheader.h"

class LT0513
{
public:

// d d
// 遍历时增加一个depth，而且优先左边，这样相同的depth，保存的就是最左的。

// queue，push是优先右子女结点，这样最后一个元素就是最左的。
//    queue.add(root);
//    while (!queue.isEmpty()) {
//        root = queue.poll();
//        if (root.right != null)
//            queue.add(root.right);
//        if (root.left != null)
//            queue.add(root.left);
//    }
// 一个循环while(!empty)

//        if(root!=NULL){
//            if(res.size()<l){
//                res.push_back(root->val);
//            }
//            func(root->left,res,l+1);
//            func(root->right,res,l+1);
//        }
// 这个res保存了每层的最左。

// len3 可以用 que2.size 代替。

//Runtime: 16 ms, faster than 63.09% of C++ online submissions for Find Bottom Left Tree Value.
//Memory Usage: 20.7 MB, less than 100.00% of C++ online submissions for Find Bottom Left Tree Value.

    int lt0513a(TreeNode* root)
    {
        int ans = root->val;
        int len2 = 1;
        queue<TreeNode*> que2;
        que2.push(root);
        int len3 = 0;
        while (!que2.empty())
        {
            len3 = 0;
            TreeNode* p = que2.front();
            ans = p->val;
            while (len2 > 0)
            {
                len2--;
                p = que2.front();
                que2.pop();
                if (p->left != NULL)
                {
                    que2.push(p->left);
                    len3++;
                }
                if (p->right != NULL)
                {
                    que2.push(p->right);
                    len3++;
                }
            }
            len2 = len3;
        }
        return ans;
    }
};

int main()
{
    int arr[] = {1,2,3,4,-1,5,6,-1,-1,-1,-1,7};
    TreeNode* n = convert2TreeNode(arr);

//    showTreeNode(n, 5);

    LT0513 lt;
    cout<<lt.lt0513a(n)<<endl;
    return 0;
}
