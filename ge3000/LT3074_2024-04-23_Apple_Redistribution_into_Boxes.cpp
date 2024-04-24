
#include "../header/myheader.h"

class LT3074
{
public:




// Runtime
// 14ms
// Beats8.38%of users with C++
// Memory
// 33.46MB
// Beats9.52%of users with C++
    int minimumBoxes(vector<int>& apple, vector<int>& capacity)
    {
        int sum2 = std::accumulate(begin(apple), end(apple), 0);
        std::sort(rbegin(capacity), rend(capacity));

        for (int i = 0; i < capacity.size(); ++i)
        {
            sum2 -= capacity[i];
            if (sum2 <= 0)
                return i + 1;
        }

        return -1;
    }
};

int main()
{

    LT3074 lt;


    return 0;
}
