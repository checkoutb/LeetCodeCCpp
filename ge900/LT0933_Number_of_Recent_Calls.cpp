
#include "../header/myheader.h"





// ...queue is enough.  deq2.size()>0 && deq2.front() < t3
//Runtime: 344 ms, faster than 33.33% of C++ online submissions for Number of Recent Calls.
//Memory Usage: 57.6 MB, less than 50.24% of C++ online submissions for Number of Recent Calls.
class RecentCounter {
    deque<int> deq2;
public:
    RecentCounter() {

    }

    int ping(int t) {
        int t3 = t - 3000;
        while (deq2.size() > 0)
        {
            int fnt2 = deq2.front();
            if (fnt2 < t3)
            {
                deq2.pop_front();
            }
            else
            {
                break;
            }
        }
        deq2.push_back(t);
        return deq2.size();
    }
};

class LT0933
{
public:



};

int main()
{

    LT0933 lt;


    return 0;
}
