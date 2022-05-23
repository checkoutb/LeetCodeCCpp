
#include "../header/myheader.h"

class LT2279
{
public:

// D D

//    transform(begin(c), end(c), begin(r), begin(c), [](int c, int r){ return c - r; });
//    sort(begin(c), end(c));
//    int i = 0;
//    for (; i < c.size() && c[i] <= additionalRocks; ++i)
//        additionalRocks -= c[i];
//    return i;





//Runtime: 245 ms, faster than 66.67% of C++ online submissions for Maximum Bags With Full Capacity of Rocks.
//Memory Usage: 84.7 MB, less than 33.33% of C++ online submissions for Maximum Bags With Full Capacity of Rocks.
// greedy
    int lt2279a(vector<int>& capacity, vector<int>& rocks, int additionalRocks)
    {
        for (int i = 0; i < rocks.size(); ++i)
        {
            capacity[i] -= rocks[i];
        }
        std::sort(begin(capacity), end(capacity));
        int ans = 0;
        for (int i = 0; i < rocks.size() && (capacity[i] <= additionalRocks); ++i)
        {
            additionalRocks -= capacity[i];
            ++ans;
        }
        return ans;
    }

};

int main()
{

    LT2279 lt;


    return 0;
}
