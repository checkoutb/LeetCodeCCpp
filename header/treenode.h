#ifndef TREENODE_H_INCLUDED
#define TREENODE_H_INCLUDED

#include "myheader.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
//    TreeNode() { cout<<".,"; }       // 这行不加，在stl_construct.h中报错，没有符合的TreeNode()方法。
//                                    // 是因为下面用到了vector<> arr2(len)，没有初始化，所以需要默认的无参初始化。不用len了。
//    ~TreeNode() { cout<<"~~"; }
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
    vector<TreeNode> arr2;          // new vector ,, 指针无法赋给普通变量
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
        n2->left == nullptr;
        n2->right == nullptr;           //.....
        arr2.push_back(*n2);
    }

//    cout<<(int) arr2.begin()<<endl;       // @@@
//    cout<<(int) &arr2<<endl;

    for (int i = 0; i < len; i++)
    {
        cout<<arr2[i].val<<",,,";
    }
    cout<<endl;

    for (int i = 0; i < len / 2; i++)
    {
        if (arr[i] != -1)
        {
//            cout<<"..."<<arr[i]<<"<<<";
//            node = arr2[i];               // &只能用一次么？用这个的话，arr2[i].left 是 null。。
            TreeNode& node = arr2[i];
            cout<<endl<<node.val<<" : ";

            if (i * 2 + 1 < len)
            {
                TreeNode n5 = arr2[i * 2 + 1];
                TreeNode ntest = arr2[i * 2 + 1];
                cout<<"     l "<<n5.val;
                cout<<"..p.."<<&ntest<<".."<<&arr2[i * 2];
                cout<<".p."<<&n5<<".."<<&arr2[i * 2 + 1];     // &n5没有改变。并且2者差距较大，0x22fxxxx,0x3dxxxxx,所以可能 n5在栈，arr2在堆？
                                                            // 直接<<n5是错误的，没有operator<<操作。说明n5不是一个指针。但是栈中只会保存基本类型和堆区指针吧？no
                                                        // 又f9了几次，，n5的地址始终是0x22f，，但是arr2的地址0x2e，0x60 都出现过，能证明一个栈，一个堆吧。
                                                        // 看网上，非静态局部变量是保存在栈的，
                                                        // new出来的，需要程序员delete的是在堆， 系统自己维护的是在栈。
//                                                如果对象是函数内的非静态局部变量，则对象，对象的成员变量保存在栈区。
//
//                                                如果对象是全局变量，则对象，对象的成员变量保存在静态区。
//
//                                                如果对象是函数内的静态局部变量，则对象，对象的成员变量保存在静态区。
//
//                                                如果对象是new出来的，则对象，对象的成员变量保存在堆区。
                                    // ，。。。多了个静态区。。
                                    // 栈区增长，地址变小，
                                    // 堆区增长，地址变大。
                                    // 栈区是的，ntest（xxxa0） 比 n5(xxxac) 小。。
                                    // 堆区是的，i*2 的地址 比 i*2+1 的地址 小。
                                    // 结合栈区0x22f, 堆区0x30，0x60.。栈区和堆区 背靠背，然后反向增长。

//                                     栈区：由编译器自动分配释放，存放函数的参数值、返回值和局部变量，在程序运行过程中实时分配和释放，栈区由操作系统自动管理，无须程序员手动管理。
//                        堆区：堆是由malloc()函数分配的内存块，使用free()函数来释放内存，堆的申请释放工作由程序员控制，容易产生内存泄漏。


//
//　　栈，就是那些由编译器在需要的时候分配，在不需要的时候自动清除的变量的存储区。里面的变量通常是局部变量、函数参数等。
//　　堆，就是那些由new分配的内存块，他们的释放编译器不去管，由我们的应用程序去控制，一般一个new就要对应一个delete。如果程序员没有释放掉，那么在程序结束后，操作系统会自动回收。
//　　自由存储区，就是那些由malloc等分配的内存块，他和堆是十分相似的，不过它是用free来结束自己的生命的。
//　　全局/静态存储区，全局变量和静态变量被分配到同一块内存中，在以前的C语言中，全局变量又分为初始化的和未初始化的，在C++里面没有这个区分了，他们共同占用同一块内存区（未初始化的变量都被初始化成0或空串，C中也一样）。
//　　常量存储区，这是一块比较特殊的存储区，他们里面存放的是常量，不允许修改（当然，你要通过非正当手段也可以修改，而且方法很多）。
//生长方向：对于堆来讲，生长方向是向上的，也就是向着内存地址增加的方向；对于栈来讲，它的生长方向是向下的，是向着内存地址减小的方向增长。


                if (n5.val != -1)
                    node.left = &arr2[i * 2 + 1];       // 之前这里是  &n5,,LT0404时，发现root的左右子节点被刷新成了最后一个父节点的左右子节点。
                                                        // 应该是n5，arr2[i*2+1] 的地址不同。n5的地址没有变过，且 root的子节点指向了n5
                                                        // 所以最终是最后一个父节点的左子节点。
                else
                    node.left = nullptr;
//                cout<<node.left->val<<",,";
//                cout<<(int) arr2[i].left<<"::";
//                cout<<n5.val<<".,.";
//                cout<<(int) &n5<<"-";
//                cout<<arr2[i].left->val<<"..";
//                cout<<(int) arr2[i].left<<"./.";           // 这个是vector的地址，不是实际对象的。。。
            }
            if (i * 2 + 2 < len)
            {
                TreeNode n6 = arr2[i * 2 + 2];
                cout<<"     r "<<n6.val;
                if (n6.val != -1)
                    node.right = &arr2[i * 2 + 2];
                else
                    node.right = nullptr;
//                cout<<n6.val<<".,.";
////                cout<<node.right->val<<"[[";
//                cout<<arr2[i].right->val<<",,";
//                cout<<(int) arr2[i].right;
            }
        }
        cout<<endl;
    }

//    cout<<endl<<"..........."<<endl;

    for (int i = 0; i < len / 2; i++)
    {
        cout<<arr2[i].val<<"; "<<arr[i]<<": ";
        if (arr[i] != -1)
        {
//            cout<<arr2[i].left->val<<".."<<arr2[i].right->val<<"..";
            if (arr2[i].left != nullptr)
                cout<<arr2[i].left->val;
            cout<<" | ";
            if (arr2[i].right != nullptr)
                cout<<arr2[i].right->val;
        }
        cout<<endl;
    }

    // arr2作用域只在这个方法中。。主要是arr2里的元素只能在这个方法中。
    vector<TreeNode*>* arr3 = new vector<TreeNode*>();
    for (int i = 0; i < len; i++)
    {
//        if (arr[i] == -1)
//            continue;
//        TreeNode* tn = new TreeNode(arr2[i].val, arr2[i].left, arr2[i].right);
//        arr3->push_back(tn);
        arr3->push_back(new TreeNode(arr2[i].val));
    }
    for (int i = 1; i < len; i++)
    {
        if (arr[i] != -1)
        {
            if (i % 2 == 0)     // r
            {
                (*arr3)[(i - 1) / 2]->right = (*arr3)[i];
            }
            else
            {
                (*arr3)[(i - 1) / 2]->left = (*arr3)[i];
            }
        }
    }

    return arr3->operator[](0);         // arr3->front()
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
            if (np->val < INT_MIN + 2)
            {
                cout<<"Nil";
            }
            else
            {
                cout<<np->val<<", ";
            }
            que.pop();
            que.push(np->left == nullptr ? new TreeNode(INT_MIN) : np->left);
            que.push(np->right == NULL ? new TreeNode(INT_MIN + 1) : np->right);
            flag &= np->left == NULL && np->right == NULL;
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
