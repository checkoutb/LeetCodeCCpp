
#include "../../header/myheader.h"

class LT
{
public:


// 看了 LT0164 2021-2-3, 上次就是heap。。 这次还是 heap。

// 想到了桶排序， 但是没有想到 基数排序。 基数排序 是线性的， 还有2种，LSD(低位优先排序)，MSD(高位优先排序)，

// int gap = (int)Math.ceil((double)(max - min)/(num.length - 1));


// gg

// 排序不可能线性(桶排序不算)
// 桶排序的话， 0 <= nums[i] <= 10^9
// set 也不是线性吧。 priority_queue...
// 这种感觉 heap 最快。  priority_queue 是不是 heap 实现的？
//1.priority_queue是适配器，它默认使用的底层数据结构是vector。而为了让这个vector表现得像一个堆，它必须借助heap算法。
//2.实现堆使用的是完全二叉树，这个完全二叉树每个节点的键值都大于（或者小于）孩子节点的键值。
// 但是，cpp有heap吗？ 不都是 下面的吗。。。
//c++中的make_heap(), pop_heap()的头文件为algorithm。作用与priority_queue中的成员函数相同，可以单独使用。
//make_heap
//在容器范围内，就地建堆，保证最大值在所给范围的最前面，其他值的位置不确定
//pop_heap
//将堆顶(所给范围的最前面)元素移动到所给范围的最后，并且将新的最大值置于所给范围的最前面
//push_heap
//当已建堆的容器范围内有新的元素插入末尾后，应当调用push_heap将该元素插入堆中。

//You must write an algorithm that runs in linear time and uses linear extra space.
// make_heap 可以原地， 所以 不需要额外的空间。 但是 时间应该是 nlogn ?
// 先快速排序，分成几个小部分，然后再heap， 会不会更快？ 就是 heap在 大量数据，和少量数据的情况下，。。。 不了，heap的pop操作是logn的，够快了,不值得快排。
// 记得是 把 最后一个元素放到 第一个(就是堆顶)，然后 这个元素下降下去，这样这个堆就符合最大/最小堆了。 主要是这个底层是vector，树结点的旋转很耗操作。
// 如果是 二叉树的话，直接。。。好像。。
// 为什么不是 结点上浮呢，  顶去掉后， 2个子树的root比较，然后不停的。。
// ？？好像也不对， 如果 最后一个元素放到顶上，然后下降，如果保证是一棵 完全二叉树呢？
// 。。。。。。。。。。。。。 下降只是互换元素值，所以不改变结构， 所以 是完全二叉树的。
// 而 上浮的话，反而会破坏 完全二叉树的结构，   旋转也会破坏 完全二叉树。。。
    int lta(vector<int>& nums)
    {

    }

};

int main()
{

    LT lt;


    return 0;
}
