
#include "../header/myheader.h"




// d && d
// min heap


// 我感觉有点？？？
// LeetCode 不会这么？？？
// 3/10 的那个，在 details看到了类似的，
// 36ms：
//class KthLargest {
//public:
//    priority_queue< int, vector<int>, greater<int> > pq;
//    int K;
//    KthLargest(int k, vector<int>& nums) {
//        K = k;
//        for(int i=0; i<nums.size(); i++){
//            pq.push(nums[i]);
//            if(pq.size() > K){
//                pq.pop();
//            }
//        }
//    }
//
//    int add(int val) {
//        pq.push(val);
//        if(pq.size() > K){
//            pq.pop();
//        }
//        return pq.top();
//    }
//};

// 然后3/10 又试了下，还是3/10 tle？？？？？？？？？？？？？？？？？？？？？？？
// 而且 本地,vector<int> v = {},  v.size() 不是 随机数了。。。发生了什么？？？？我。。。


//        q.push(-1*val);
//        while(q.size() > k) q.pop();
//        return -1*q.top();
// 。。。。！
// 只在add中删除，构造期不需要删除数据。并且可以用std::priority_queue<int> que2; 不需要 指明写比较器。




//Runtime: 596 ms, faster than 5.15% of C++ online submissions for Kth Largest Element in a Stream.
//Memory Usage: 20.7 MB, less than 10.00% of C++ online submissions for Kth Largest Element in a Stream.

class KthLargest {

    list<int> list2;
    int min2 = INT_MAX;                 // ... 这个忘记初始化了，一会儿45588，一会儿34555。。。。md，zz。
    int k2;

    int insert2(int v) {
        if (list2.size() < k2) {
            list2.push_back(v);
            min2 = std::min(v, min2);
        } else {
            if (v > min2) {
                for (list<int>::iterator it = list2.begin(); it != list2.end(); it++) {
                    if (*it == min2) {
                        list2.erase(it);
                        break;
                    }
                }
                list2.push_back(v);
                min2 = INT_MAX;
                for (int i : list2) {
                    min2 = min(min2, i);
                }
            }
        }
        return min2;
    }

public:
    KthLargest(int k, vector<int>& nums) {
        k2 = k;
        for (int n : nums) {
            insert2(n);
        }
    }

    int add(int val) {
        return insert2(val);
    }
};



// 3/10 tle..........
class KthLargest2 {

    std::priority_queue<int, vector<int>, greater<int>> que2;
    int k2;
public:
    KthLargest2(int k, vector<int>& nums) {
        k2 = k;
        if (!nums.empty()) {
            for (int i : nums)
                que2.push(i);
            for (int i = 0; i < nums.size() - k; i++)
                que2.pop();
        }
    }

    int add(int val) {
        que2.push(val);
        if (que2.size() > k2)               // ....
            que2.pop();
        return que2.top();
    }
};

int main()
{

//    vector<int> v = {4,5,8,2};
//    int k = 3;
//    int arr2[] = {3,5,10,9,4};

    vector<int> v = {};             // ... v.size() 是一个随机数。。。。。得用 empty()....
    int k = 1;
    int arr2[] = {-3,-2,-4,0,4};

    KthLargest lt(k, v);

    for (int i : arr2)
    {
        cout<<lt.add(i)<<endl;
    }


    vector<int> v2 = {};
    cout<<v2.size()<<endl;

    return 0;
}
