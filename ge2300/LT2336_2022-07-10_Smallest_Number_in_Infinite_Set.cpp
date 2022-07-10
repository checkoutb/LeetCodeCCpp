
#include "../header/myheader.h"

class LT2336
{
public:



};


// D D

// priority queue
// set



// 或许可以记录下 最小值，如果pop掉，那么下次 pop 就从 这个最小值开始找， 如果addBack 的小于 最小值，那么刷新最小值。
//Runtime: 151 ms, faster than 100.00 % of C++ online submissions for Smallest Number in Infinite Set.
//Memory Usage : 35.1 MB, less than 100.00 % of C++ online submissions for Smallest Number in Infinite Set.
class SmallestInfiniteSet {
    //vector<int> vi(1001)

    bitset<1001> notExist;      // [0,0,0...]

public:
    SmallestInfiniteSet() {

    }

    int popSmallest() {
        for (int i = 1; i < 1001; ++i)
        {
            if (!notExist[i])
            {
                notExist.set(i);
                return i;
            }
        }
        return -1;
    }

    void addBack(int num) {
        notExist.reset(num);
    }
};



int main()
{

    LT2336 lt;


    return 0;
}
