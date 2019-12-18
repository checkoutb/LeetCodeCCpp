
#include "../header/myheader.h"

class LT0480
{
public:





// auto mid = next(window.begin(), k / 2);
// medians.push_back((double(*mid) + *prev(mid, 1 - k%2)) / 2);
// it++/-- N 次？

// 单个multiset，直接初始化 multiset<int> window(nums.begin(), nums.begin() + k);
// mid指向中间。
// 窗口右移一位，那么 window.erase(window.lower_bound(nums[i-k]));
// 插入的数据是nums[i]，和*mid 比较，就能知道mid 左还是右移。



//    Comparator<Integer> comparator = (a, b) -> nums[a] != nums[b] ? Integer.compare(nums[a], nums[b]) : a - b;
//    TreeSet<Integer> left = new TreeSet<>(comparator.reversed());
//    TreeSet<Integer> right = new TreeSet<>(comparator);
//
//    Supplier<Double> median = (k % 2 == 0) ?
//        () -> ((double) nums[left.first()] + nums[right.first()]) / 2 :
//        () -> (double) nums[right.first()];
//
//    // balance lefts size and rights size (if not equal then right will be larger by one)
//    Runnable balance = () -> { while (left.size() > right.size()) right.add(left.pollFirst()); };
//
//    double[] result = new double[nums.length - k + 1];
//
//    for (int i = 0; i < k; i++) left.add(i);
//    balance.run(); result[0] = median.get();
//
//    for (int i = k, r = 1; i < nums.length; i++, r++) {
//        // remove tail of window from either left or right
//        if(!left.remove(i - k)) right.remove(i - k);
//
//        // add next num, this will always increase left size
//        right.add(i); left.add(right.pollFirst());
//
//        // rebalance left and right, then get median from them
//        balance.run(); result[r] = median.get();
//    }
//
//    return result;
// 不知道纯函数式是什么样子的。应该更cooooool。
// 另外一种是 内部方法。

// 2个优先队列或2个红黑树，作为2个堆。一个最大堆保存小数，一个最小堆保存大数。
// median 是 最大堆的第一个，或 (最大堆第一+最小堆第一) / 2。
// add, remove 2个方法，根据 值 和 median对比，找到 值所在的堆，然后 删除 或 add。
// 删除或add之后，根据2个堆的数量，做一个平衡。






// 怀念 java.util.LinkedHashMap.removeEldestEntry(Entry<K, V>)

//Runtime: 1432 ms, faster than 5.11% of C++ online submissions for Sliding Window Median.
//Memory Usage: 15.7 MB, less than 42.86% of C++ online submissions for Sliding Window Median.

    vector<double> lt0480c(vector<int>& nums, int k)
    {
        vector<double> ans;
        if (k > nums.size())
            return ans;
        queue<int> que1;
        multiset<int> win1;

        int i = 0;
        while (i < k)
        {
            que1.push(nums[i]);
            win1.insert(nums[i]);
            i++;
        }
        while (i < nums.size())
        {
            double d2 = 0;
            if (k % 2 == 0)
            {
                int t2 = k / 2 - 1;
                auto p = win1.begin();
                while (t2-- > 0)
                    p++;
                d2 = ((double) *p);
                p++;
                d2 = (d2 + *p) / 2;
            }
            else
            {
                int t2 = k / 2;
                auto p = win1.begin();
                while (t2-- > 0)
                    p++;
                d2 = *p;
            }
            ans.push_back(d2);
//            ans.push_back((k%2==0) ? (((double) *(win1.begin() + (k / 2 - 1))) + *(win1.begin() + (k / 2)) / 2) : *(win1.begin() + (k / 2)));
            int t1 = que1.front();
            que1.pop();
            win1.erase(lower_bound(win1.begin(), win1.end(), t1));
            que1.push(nums[i]);
            win1.insert(nums[i]);
            i++;
        }
//        ans.push_back((k%2==0) ? (((double) *(win1.begin() + (k / 2 - 1))) + *(win1.begin() + (k / 2)) / 2) : *(win1.begin() + (k / 2)));

        double d2 = 0;
        if (k % 2 == 0)
        {
            int t2 = k / 2 - 1;
            auto p = win1.begin();
            while (t2-- > 0)
                p++;
            d2 = ((double) *p);
            p++;
            d2 = (d2 + *p) / 2;
        }
        else
        {
            int t2 = k / 2;
            auto p = win1.begin();
            while (t2-- > 0)
                p++;
            d2 = *p;
        }
        ans.push_back(d2);

        return ans;
    }


    vector<double> lt0480b(vector<int>& nums, int k)
    {
        multimap<int, int> map2;
        int i = 0;
        while(i++ < k)
        {
            map2.insert(std::make_pair(nums[i], i));
        }
        vector<double> ans;
        while (i++ < nums.size())
        {
//            ans.insert((k % 2 == 0) ? ((double) map2.begin() +1) : (1));

            int j = INT_MAX;
            auto x = NULL;
            for (auto p : map2)
            {
                if (p.second < j)
                {
                    j = p.second;
                }
            }

        }
//        ans.insert();
        return ans;
    }



// 32 / 42 .. tle..
    vector<double> lt0480a(vector<int>& nums, int k)
    {
        vector<int> win2;
        deque<int> que2;

        int i = 0;
        for (; i < k; i++)
        {
            adda1(win2, que2, nums, i, k);
        }
        vector<double> ans;
//        cout<<"-----------"<<endl;

        while (i < nums.size())
        {
            ans.push_back(getMedian(win2));
            adda1(win2, que2, nums, i, k);
            i++;
        }
        ans.push_back(getMedian(win2));
        return ans;
    }

    void adda1(vector<int>& win2, deque<int>& que2, vector<int>& nums, int i, int k)
    {
//        int v = win2[i];
        if (i >= k)
        {
            win2.erase(win2.begin() + que2.front());
            int t5 = que2.front();
            que2.pop_front();
            for (deque<int>::iterator it5 = que2.begin(); it5 != que2.end(); it5++)
            {
                if ((*it5) >= t5)
                    (*it5) = (*it5) - 1;
            }
        }
        vector<int>::iterator itwin2 = upper_bound(win2.begin(), win2.end(), nums[i]);
        int t3 = itwin2 - win2.begin();
        for (deque<int>::iterator it5 = que2.begin(); it5 != que2.end(); it5++)
        {
            if ((*it5) >= t3)
                (*it5) = (*it5) + 1;
        }
        que2.push_back(itwin2 - win2.begin());
        win2.insert(itwin2, nums[i]);
        #ifdef __test
        cout<<endl;
        for_each(win2.begin(), win2.end(), fun_cout);
        cout<<endl;
        for_each(que2.begin(), que2.end(), fun_cout);
        cout<<endl;
        #endif // __test
    }

    double getMedian(vector<int>& win2)
    {
        #ifdef __test
        cout<<endl;
        for_each(win2.begin(), win2.end(), fun_cout);
        cout<<endl;
        #endif // __test
        return (win2.size() % 2 == 0) ? ((((double) (win2[win2.size() / 2 - 1]) + win2[win2.size() / 2])) / 2) : (win2[win2.size() / 2]);
    }

};

int main()
{
    vector<int> v1 = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    LT0480 lt;

    vector<double> r = lt.lt0480c(v1, k);
    cout<<endl<<endl;
    for_each(r.begin(), r.end(), fun_cout);
    cout<<endl<<endl;
    return 0;
}
