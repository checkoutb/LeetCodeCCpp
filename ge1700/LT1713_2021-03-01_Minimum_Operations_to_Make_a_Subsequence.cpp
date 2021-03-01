
#include "../header/myheader.h"

class LT1713
{
public:

// D


// LIS, longest increasing subsequence

//"You are given an array target that consists of distinct integers"
//
//So there is an order for elements in the target.
//For element in A, if it's not in target, we ignore it.
//If it's in target, we want find the sequence ending with lower order.
// 把 自然顺序，改成 下标的顺序。。。。

//        unordered_map<int, int> h;
//        int n = A.size();
//        for (int i = 0; i < target.size(); ++i)
//            h[target[i]] = i;
//
//        vector<int> stack;
//        for (int a : A) {
//            if (h.find(a) == h.end()) continue;           // arr 中元素不在 target中。
//            if (stack.empty() || h[a] > stack.back()) {
//                stack.push_back(h[a]);                        // 只可能在这里增加stack的长度
//                continue;
//            }
//            int left = 0, right = stack.size() - 1, mid;
//            while (left < right) {
//                mid = (left + right) / 2;
//                if (stack[mid] < h[a])                // h[a] 是 arr中的元素 在 target中的下标。
//                    left = mid + 1;
//                else
//                    right = mid;
//            }                                 // left 应该是 大于等于 h[a]的 下标。
//            stack[left] = h[a];                           // 插入(更新)到哪里，感觉唯一有用的是 left 是 最后一个元素。
//        }
//        return target.size() - stack.size();
// 看懂了，但估计 永远写不出。。。算了，没看懂。
// lis， 通过更新stack[left]，保证 这个是 最小的， 后续才有可能 push_back.



//    unordered_map<int, int> m;
//    vector<int> stack;
//    for (auto t : target)
//        m[t] = m.size();
//    for (auto n : arr) {
//        auto it = m.find(n);
//        if (it != end(m)) {
//            if (stack.empty() || stack.back() < it->second)
//                stack.push_back(it->second);
//            else
//                *lower_bound(begin(stack), end(stack), it->second) = it->second;
//        }
//    }
//    return target.size() - stack.size();



// tle.
// arr中最长的 subseq of target.
    int lt1713a(vector<int>& target, vector<int>& arr)
    {
        int sz1 = arr.size();
        int szt = target.size();
        vector<int> vi(sz1 + 1);
        for (int i = 1; i <= szt; ++i)
        {
            vector<int> v2(sz1 + 1);
            for (int j = 1; j <= sz1; ++j)
            {
                if (target[i - 1] == arr[j - 1])
                {
                    v2[j] = vi[j - 1] + 1;
                }
                else
                {
                    v2[j] = max(vi[j], v2[j - 1]);
                }
            }
            std::swap(vi, v2);
            #ifdef __test
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
            #endif // __test
        }
        return target.size() - vi[sz1];
    }

};

int main()
{
//    myvi t = {5,1,3};
//    myvi v = {9,4,2,3,4};

    myvi t = {6,4,8,1,3,2};
    myvi v = {4,7,6,2,3,8,6,1};

    LT1713 lt;

    cout<<lt.lt1713a(t, v)<<endl;

    return 0;
}
