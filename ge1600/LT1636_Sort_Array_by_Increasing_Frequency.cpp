
#include "../header/myheader.h"

class LT1636
{
public:

// D D

// vector<pair<int, int>> temp;
// vector<int> countNums(201, 0) 代替map， 生成temp， sort temp， 而且temp的信息 足够生成 结果。


//    int cnt[201] = {};
//    for (auto n : nums)
//        ++cnt[n + 100];
//    sort(begin(nums), end(nums), [&](int a, int b) {
//       return cnt[a + 100] == cnt[b + 100] ? a > b : cnt[a + 100] < cnt[b + 100];
//    });





//Runtime: 24 ms, faster than 27.44% of C++ online submissions for Sort Array by Increasing Frequency.
//Memory Usage: 11.7 MB, less than 59.50% of C++ online submissions for Sort Array by Increasing Frequency.
    vector<int> lt1636a(vector<int>& nums)
    {
        unordered_map<int, int> map2;
        for (int& i : nums)
            map2[i]++;
        sort(begin(nums), end(nums), [&map2](const int& a, const int& b) { return map2[a] == map2[b] ? a > b : map2[a] < map2[b]; });
        return nums;
    }

};

int main()
{

    myvi v = {5,-1,4,4,-6,-6,1,1,1};

    LT1636 lt;

    vector<int> vi = lt.lt1636a(v);
    showVectorInt(vi);

    return 0;
}
