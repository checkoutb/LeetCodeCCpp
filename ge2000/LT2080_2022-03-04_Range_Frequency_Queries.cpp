
#include "../header/myheader.h"

class LT2080
{
public:



};

// D D

//    int query(int left, int right, int value) {
//        auto upper = upper_bound(mp[value].begin(), mp[value].end(), right);
//        auto lower = lower_bound(mp[value].begin(), mp[value].end(), left);
//
//        return upper - lower;
//    }
// iterator . operator-()


//List<Integer>[] ids = new ArrayList[10001];
//Function<Integer, Integer> lower_bound = (pos) -> pos < 0 ? ~pos : pos;
//public RangeFreqQuery(int[] arr) {
//    for (int i = 0; i < ids.length; ++i)
//        ids[i] = new ArrayList<>();
//    for (int i = 0; i < arr.length; ++i)
//        ids[arr[i]].add(i);
//}
//public int query(int l, int r, int v) {
//    return lower_bound.apply(Collections.binarySearch(ids[v], r + 1)) - lower_bound.apply(Collections.binarySearch(ids[v], l));
//}

// 。。 lower_bound.apply(Collections.binarySearch(ids[v], r + 1)) - lower_bound.apply(Collections.binarySearch(ids[v], l)); 这个是什么操作。 反过来写我还能理解。。
// ..看错了， 以为 lower_bound 是 二分搜索的 comparator 了。。 结果只是一个 对 二分后的返回值 进行处理，，但是这个处理。。 ～：bit取反。。 binarySearch 返回的是什么？ -1 ？


// TreeMap


//vector<int> ids[10001] = {};
//RangeFreqQuery(vector<int>& arr) {
//    for (int i = 0; i < arr.size(); ++i)
//        ids[arr[i]].push_back(i);
//}
//int query(int left, int right, int v) {
//    return upper_bound(begin(ids[v]), end(ids[v]), right) -
//        lower_bound(begin(ids[v]), end(ids[v]), left);
//}



//Runtime: 1135 ms, faster than 24.85% of C++ online submissions for Range Frequency Queries.
//Memory Usage: 235.7 MB, less than 100.00% of C++ online submissions for Range Frequency Queries.
// hint： Use a hash table that stored for each value, the indices where that value appeared.
class RangeFreqQuery {
    unordered_map<int, vector<int>> mapv;
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i)
        {
            mapv[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        vector<int>& vi = mapv[value];
        auto pr = std::upper_bound(begin(vi), end(vi), right);
        if (pr == begin(vi))
            return 0;
        auto pl = std::lower_bound(begin(vi), end(vi), left);
        #ifdef __test
        #endif // __test
        return std::distance(pl, pr);
    }
};



// 确实 构造器慢，10^5 个数字，最差情况下(没有重复值)，vmap[sz1 - 1] 要 insert 10^5 个数字。。。
// 。。。这个tle了。。query 肯定不会有问题的，那就是构造器的 for for？
// 最开始想到 BIT/binary indexed tree，Fenwick tree，Segment tree的，但是。 而且，这个 只需要 尾巴减去 头 就可以了。。
class RangeFreqQuery2 {
    vector<unordered_map<int, int>> vmap;
public:
    RangeFreqQuery2(vector<int>& arr) {
        this->vmap = vector<unordered_map<int, int>>(arr.size(), unordered_map<int, int>());
        vmap[0][arr[0]]++;
        for (int i = 1; i < arr.size(); ++i)
        {
//            for (unordered_map<int, int>::iterator it = begin(vmap[i - 1]); it != end(vmap[i - 1]); it++)
//            {
//                vmap[i][it->first] = it->second;
//            }
            vmap[i].insert(begin(vmap[i - 1]), end(vmap[i - 1]));           // 还是tle。
            vmap[i][arr[i]]++;
        }
    }

    int query(int left, int right, int value) {
        if (left == 0)
        {
            return vmap[right][value];
        }
        return vmap[right][value] - vmap[left - 1][value];
    }
};


int main()
{

    LT2080 lt;

    myvi v = {12, 33, 4, 56, 22, 2, 34, 33, 22, 12, 34, 56};

    RangeFreqQuery rfq(v);

    cout<<rfq.query(1,2,4)<<endl;
    cout<<rfq.query(0,11,33)<<endl;

    cout<<(~-12)<<endl;

    return 0;
}
