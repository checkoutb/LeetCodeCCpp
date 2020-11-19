
#include "../header/myheader.h"

class LT1387
{
public:

// D D

//        std::vector<std::pair<int, int>> powers(hi-lo+1);
//        std::generate(powers.begin(), powers.end(), [&i]() {
//            auto p = std::make_pair<int, int>(std::move(i), gen(i));
//            ++i;
//            return p;
//        });


//int comp[1001] = { 0, 0, 0 };
//class Solution {
//    int compute(int i) {
//    return i < 2 ? 0 :
//        1 + (i % 2 ? compute(i * 3 + 1) : compute(i / 2));
//    }
//public:
//    int getKth(int lo, int hi, int k) {
//        if (comp[2] == 0)
//            for (auto i = 2; i <= 1000; ++i)
//                comp[i] = compute(i);
//        vector<int> sorted(hi - lo + 1);
//        iota(begin(sorted), end(sorted), lo);
//        nth_element(begin(sorted), begin(sorted) + k - 1, end(sorted), [](int i, int j) {
//            return comp[i] == comp[j] ? i < j : comp[i] < comp[j]; });
//        return sorted[k - 1];
//    }
//};


// memo 反而慢。。。




//Runtime: 496 ms, faster than 7.30% of C++ online submissions for Sort Integers by The Power Value.
//Memory Usage: 46.4 MB, less than 27.82% of C++ online submissions for Sort Integers by The Power Value.
    int lt1387a(int lo, int hi, int k)
    {
        unordered_map<int, int> memo;
        memo[1] = 0;
        vector<int> arr;
        for (int i = lo; i <= hi; ++i)
        {
            dfsa1(memo, i);
            arr.push_back(i);
        }

        sort(begin(arr), end(arr), [&memo](const int a, const int b) { return memo[a] == memo[b] ? a < b : memo[a] < memo[b]; });
        return arr[k - 1];
    }

    int dfsa1(unordered_map<int, int>& memo, int val)
    {
        if (memo.find(val) == memo.end())
        {
            if (val % 2)
            {
                memo[val] = dfsa1(memo, val * 3 + 1) + 1;
            }
            else
            {
                memo[val] = dfsa1(memo, val / 2) + 1;
            }
        }
        return memo[val];
    }


};

int main()
{
//    int a{12}, b{15}, c{2};
//    int a{1},b{1},c{1};
//    int a{7},b{11},c{4};
//    int a{10},b{20},c{5};
    int a{1},b{1000},c{777};

    LT1387 lt;

    cout<<lt.lt1387a(a,b,c);

    return 0;
}
