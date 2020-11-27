
#include "../header/myheader.h"

class LT1503
{
public:

// D D





// 不科学，， 都差不多的代码， 别人就30-40。。。
//Runtime: 72 ms, faster than 11.41% of C++ online submissions for Last Moment Before All Ants Fall Out of a Plank.
//Memory Usage: 23.1 MB, less than 47.91% of C++ online submissions for Last Moment Before All Ants Fall Out of a Plank.
// 。。。不管蚂蚁的编号，只看蚂蚁路径，等于没有回头。
    int lt1503a(int n, vector<int>& left, vector<int>& right)
    {
        int minr = right.empty() ? n : *std::min_element(begin(right), end(right));
        int maxl = left.empty() ? 0 : *std::max_element(begin(left), end(left));
        return max(n - minr, maxl);
    }

};

int main()
{

    LT1503 lt;


    return 0;
}
