#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

#include "myheader.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode() { cout<<".,"; }       // 这行不加，在stl_construct.h中报错，没有符合的TreeNode()方法。
                                    // 是因为下面用到了vector<> arr2(len)，没有初始化，所以需要默认的无参初始化。不用len了。
    ~TreeNode() { cout<<"~~"; }
};

int treeNode2String(TreeNode n)
{
//    if (n == NULL)
//        return "nil";
    return n.val;
}


template<class T>
TreeNode& convert2TreeNode2_(T& arr)
{
    int len = sizeof(arr) / sizeof(arr[0]);
    vector<TreeNode> arr2;
    for (int i = 0; i < len; i++)
    {
        TreeNode n1(arr[i]);
//        arr2.push_back(new struct TreeNode(arr[i]));
        arr2.push_back(n1);
    }

    TreeNode result = arr2[0];
    cout<<(int) &result<<endl;
    return result;
}


// wocao, tai tmd nan l ba.
template<class T>
TreeNode* convert2TreeNode_(T& arr)
{
    int len = sizeof(arr) / sizeof(arr[0]);
    struct TreeNode head(-1);
    TreeNode& node = head;
//    TreeNode arr2[] = new TreeNode[len] {};     // = {} 是错的。.。长度需要 const。。new {} 说没有默认方法。可能是上面的无参构造器？yes
    vector<TreeNode> arr2;
//    for (int i = 0; i < len; i++)
//    {
//        cout<<treeNode2String(arr2[i])<<"..";
//    }

    for (int i = 0; i < len; i++)
    {
////        TreeNode* n2 = new TreeNode(arr[i]);      // 这个也可以的。push的时候*n2.
//        TreeNode n2(arr[i]);
//        n2.left = NULL;
//        n2.right = NULL;
//        arr2.push_back(n2);
//        cout<<n2.val<<"..."<<arr2[i].val;
        TreeNode* n2 = new TreeNode(arr[i]);
//        cout<<".........."<<(int) n2->left;           // 0
//        n2->left = NULL;
//        n2->right = NULL;
        cout<<(int) n2<<endl;
        arr2.push_back(*n2);
    }

//    cout<<(int) arr2.begin()<<endl;       // @@@
    cout<<(int) &arr2<<endl;

//    for (int i = 0; i < len; i++)
//    {
//        cout<<arr2[i].val<<",,,";
//    }

    for (int i = 0; i < len / 2; i++)
    {
        if (arr[i] != -1)
        {
//            cout<<"..."<<arr[i]<<"<<<";
//            node = arr2[i];               // &只能用一次么？用这个的话，arr2[i].left 是 null。。
            TreeNode& node = arr2[i];
            if (i * 2 + 1 < len)
            {
                TreeNode n5 = arr2[i * 2 + 1];
                node.left = &n5;
//                cout<<node.left->val<<",,";
//                cout<<(int) arr2[i].left<<"::";
                cout<<n5.val<<".,.";
                cout<<(int) &n5<<"-";
                cout<<arr2[i].left->val<<"..";
                cout<<(int) arr2[i].left<<"./.";           // 这个是vector的地址，不是实际对象的。。。
            }
            if (i * 2 + 2 < len)
            {
                TreeNode n6 = arr2[i * 2 + 2];
                node.right = &n6;
                cout<<n6.val<<".,.";
//                cout<<node.right->val<<"[[";
                cout<<arr2[i].right->val<<",,";
                cout<<(int) arr2[i].right;
            }
        }
        cout<<endl;
    }

//    cout<<endl<<"..........."<<endl;

    for (int i = 0; i < len / 2; i++)
    {
        cout<<arr2[i].val<<"; ";
        if (arr[i] != -1)
        {
            cout<<arr2[i].left->val<<".."<<arr2[i].right->val<<"..";
        }
        cout<<endl;
    }

    return &arr2[0];
}


// 那么的难，却又那么的简单。。。& ne ?
template<class T>
TreeNode* convert2TreeNode(T& arr)
{
    int len = sizeof(arr) / sizeof(arr[0]);
    TreeNode* arr2[len];
    int k = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == -1)
            continue;
//        arr2[i].val = arr[i];     // 没用，出方法就析构了。所以得用指针数组。.
        arr2[i] = new struct TreeNode(arr[i]);
        if ((k = (i + 1) / 2 - 1) >= 0)
        {
            if (i % 2 == 0)
            {
                arr2[k]->right = arr2[i];
            }
            else
            {
                arr2[k]->left = arr2[i];
            }
        }
    }

//    // test
//    for (int i = 0; i < len - 1; i++)
//    {
//        arr2[i]->left = arr2[i + 1];
//    }
//
//    for (int i = 0; i < len - 1; i++)
//    {
//        cout<<arr2[i]->val<<","<<arr2[i]->left->val<<"....";
//    }
//    cout<<endl;
    return arr2[0];
}


// 应该用默认参数。还有宽度，null.toString.
void showTreeNode(TreeNode* node, int lvs)
{
    cout<<"show treeNode 2.."<<endl;
    queue<TreeNode*> que;
    que.push(node);
    bool flag = false;
    TreeNode* np = NULL;
    int k = (int) pow(2, lvs) * 3 / 2;
    while (!que.empty() && !flag)
    {
        flag = true;
        int sz1 = que.size();
        int i = 0;
        while (i < sz1)
        {
            i++;
            np = que.front();
            int j = 0;
            while (j < k)
            {
                cout<<" ";
                j++;
            }
            if (np->val < 0)
            {
                cout<<"Nil";
            }
            else
            {
                cout<<np->val<<", ";
            }
            que.pop();
            que.push(np->left == nullptr ? new TreeNode(-1) : np->left);
            que.push(np->right == NULL ? new TreeNode(-2) : np->right);
            flag = np->left == NULL && np->right == NULL;
        }
        cout<<endl;
        k >>= 1;
    }
}

void showTreeNode(TreeNode* node)
{
    cout<<"show treeNode"<<endl;
    queue<TreeNode*> que;
    que.push(node);
    bool flag = true;
    struct TreeNode* n = NULL;
    while (!que.empty())
    {
        flag = true;
        int sz1 = que.size();
        int i = 0;
        while (i < sz1)
        {
            i++;
            n = que.front();
            cout<<n->val<<", ";
            que.pop();
            if (n->left == NULL)
            {
                que.push(new TreeNode(-1));     // &?
            }
            else
            {
                flag = false;
                que.push(n->left);
            }
            if (n->right == NULL)
            {
                que.push(new TreeNode(-2));
            }
            else
            {
                flag = false;
                que.push(n->right);
            }
        }
        cout<<endl;
        if (flag)
            break;
    }
}


#endif // TREENODE_H_INCLUDED
