
#include "../header/myheader.h"

class LT1481
{
public:

// D D

//    unordered_map<int, int> counts;
//    vector<int> heap;
//    for (auto n : arr)
//        ++counts[n];
//    for (auto &p: counts)
//        heap.push_back(p.second);
//    make_heap(begin(heap), end(heap), greater<int>());
//    while (k > 0) {
//        k -= heap.front();
//        pop_heap(begin(heap), end(heap), greater<int>());
//        if (k >= 0)
//            heap.pop_back();
//    }
//    return heap.size();
// heap.......


//        List<Integer> l = new ArrayList<>(map.keySet());
//        Collections.sort(l, (a, b) -> map.get(a) - map.get(b));
// or PriorityQueue


// map,  vector(map.values) . sort


//Runtime: 348 ms, faster than 72.46% of C++ online submissions for Least Number of Unique Integers after K Removals.
//Memory Usage: 60.5 MB, less than 95.25% of C++ online submissions for Least Number of Unique Integers after K Removals.
    int lt1481a(vector<int>& arr, int k)
    {
        int sz1 = arr.size();
        unordered_map<int, int> map2;       // val : count
        map<int, int> map3;             // count : count of count...
        for (int i = 0; i < sz1; ++i)
            map2[arr[i]]++;
        for (auto& p : map2)
            map3[p.second]++;
        int ans = map2.size();
        while (k > 0)
        {
            int cnt = map3.begin()->first;
            int ccnt = map3.begin()->second;
            if (k >= cnt * ccnt)
            {
                map3.erase(map3.begin());
                k -= cnt * ccnt;
                ans -= ccnt;
            }
            else
            {
                ans -= k / cnt;
                k = 0;
            }
        }
        return ans;
    }

};

int main()
{

//    vector<int> v = {5,5,4};
//    int k{1};

//    vector<int> v = {4,3,1,1,3,3,2};
//    int k{3};

    vector<int> v = {2,4,1,8,3,5,1,3};
    int k{3};


    LT1481 lt;

    cout<<lt.lt1481a(v, k);

    return 0;
}
