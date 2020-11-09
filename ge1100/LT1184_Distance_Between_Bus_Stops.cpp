
#include "../header/myheader.h"

class LT1184
{
public:

// D D




//Runtime: 8 ms, faster than 59.08% of C++ online submissions for Distance Between Bus Stops.
//Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Distance Between Bus Stops.
    int lt1184a(vector<int>& distance, int start, int destination)
    {
        int sum = 0;
        int len = 0;
        int mn = min(start, destination);
        destination = max(start, destination);
        start = mn;
        for (int i = 0; i < distance.size(); ++i)
        {
            sum += distance[i];
            if (i >= start && i < destination)
            {
                len += distance[i];
            }
        }
        return min(len, sum - len);
    }

};

int main()
{

    LT1184 lt;


    return 0;
}
