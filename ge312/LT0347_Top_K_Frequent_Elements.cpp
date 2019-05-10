
#include "../header/myheader.h"

class LT0347
{
public:


// discuss
// bucket sort
// 用map获得 num 以及它的 次数
// List<Integer>[] bucket = new List[nums.length+1];
// bucket 下标是 次数，不可能出现0次的数字 且一共 nums.length个数字，所以 下标/次数 范围[1, nums.length]
// 出现次数可能相同，所以数组元素是 List。

// 最后从后往前遍历，addAll 直到result的数量满足为止。
// 而且代码用addAll的话会导致数量>k。下面也有人提到了。但是也有人回复了，这种case 不会出现。
//nums = { 1, 1, 2, 2, 3, 3, 4, 4 } and k =2
//returned res is [1,2,3,4]

// max heap
// 也是map获得 num 及其对应的 次数
//PriorityQueue<Map.Entry<Integer, Integer>> maxHeap =
//                         new PriorityQueue<>((a,b)->(b.getValue()-a.getValue()));
// 优先队列来完成最大堆。

// c++ 好像没有类似Map.Entry的。。..you.....


// 红黑树
//TreeMap<Integer, List<Integer>> freqMap = new TreeMap<>();
// 次数，List<num>
//    Map.Entry<Integer, List<Integer>> entry = freqMap.pollLastEntry();
//    res.addAll(entry.getValue());






// 别人提交的代码
// count 就是 <num 次数> 的 无序map.  count[nums[i]]++;  ..pq是优先队列
//        for(auto it= count.begin(); it!=count.end();it++){
//            pq.push(make_pair(it->second,it->first));
//            if(pq.size() > count.size() -k){
//                res.push_back(pq.top().second);
//                pq.pop();
//            }
//        }

// pq.size() > count.size() -k....count.size 代表有多少种数字，，当这个不等式成立的时候，pq.top必然是res的一员。
// 而且 是foreach count，所以 不等式 必然会 成立 k次。


//        unordered_map<int, int> m;
//        multiset<pair<int, int> > s;
//        for (int n : nums)
//            m[n]++;
//        for (auto p : m) {
//            s.insert({p.second, p.first});
//            if (s.size() > k) s.erase(s.begin());
//        }
//        vector<int> result;
//        for (auto i : s)
//            result.push_back(i.second);
//        return result;

// set是有序的，pair是怎么比较的。。看来是根据第一个来比较。

//std::pair is a struct template that provides a way to store two heterogeneous objects as a single unit. A pair is a specific case of a std::tuple with two elements.
// std的。。。
//3) If lhs.first<rhs.first, returns true. Otherwise, if rhs.first<lhs.first, returns false. Otherwise, if lhs.second<rhs.second, returns true. Otherwise, returns false.
// pair 是 从前往后 开始比较的。



//Runtime: 52 ms, faster than 6.33% of C++ online submissions for Top K Frequent Elements.
//Memory Usage: 11.3 MB, less than 58.56% of C++ online submissions for Top K Frequent Elements.
// 速度好慢。。。想不出了。。。

// 想到一个，map作为num 与 计数排序下标 之间的 映射。好像没什么用。。


    // map
    // 计数排序。。和map一样的。。没办法根据 次数排序。
    // map可以传Compare进去。。Compare是对key的，
    // sort，对线性容器排序
    // map + priorityQueue 吧。no，优先队列没法用。除非自己新建一个struct或class，但是那样的话，直接在map里排序就可以了。
    // nlogn 好像还真可以，map，hash很快，最多就是处理冲突，nlogn肯定可以的，
    // 排序算法，找一个快一点的算法，nlogn 也没问题。或者不排序，直接每次找最大？
    // 新建struct，然后借助sort排序。
    vector<int> lt0347a(vector<int>& nums, int k)
    {
        vector<int> result(k);
        map<int, int> map2;
        for (int i : nums)
        {
            map2[i] = map2[i] + 1;
        }

        int m1 = 0;
        int k1 = 0;
        for (int i = 0; i < k; i++)
        {
            m1 = 0;
            k1 = 0;
            for (map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
            {
                if (m1 < it->second)
                {
                    m1 = it->second;
                    k1 = it->first;
                }
            }
            map2.erase(map2.find(k1));
            result[i] = k1;
        }
        return result;
    }
};

int main()
{
    vector<int> v = {1,1,1,2,3,2};
    int k = 2;
    LT0347 lt;
    v = lt.lt0347a(v, k);

    cout<<endl<<endl;
    for_each(v.begin(), v.end(), fun_cout);
    return 0;
}
