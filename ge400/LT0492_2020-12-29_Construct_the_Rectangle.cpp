
#include "../header/myheader.h"

class LT0492
{
public:

// D D



// .. 好吧，，10^7， sqrt下 也就 10^4 不到。
//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Construct the Rectangle.
//Memory Usage: 6.6 MB, less than 5.24% of C++ online submissions for Construct the Rectangle.
// 估计有个 大质数。
    vector<int> lt0492a(int area)
    {
        int sq = (int) std::sqrt(area);
        for (int i = sq; i >= 1; --i)
        {
            if (area % i == 0)
                return {area / i, i};
        }
        return {-1, -1};
    }

};

int main()
{
    int a = 37;

    LT0492 lt;

    vector<int> vi = lt.lt0492a(a);
    cout<<vi[0]<<", "<<vi[1]<<endl;

    return 0;
}
