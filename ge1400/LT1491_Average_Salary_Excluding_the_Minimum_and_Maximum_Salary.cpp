
#include "../header/myheader.h"

class LT1491
{
public:

// D D

//    return (accumulate(begin(s), end(s), 0.) - *min_element(begin(s), end(s))
//        - *max_element(begin(s), end(s))) / (s.size() - 2);




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Average Salary Excluding the Minimum and Maximum Salary.
//Memory Usage: 7.5 MB, less than 13.96% of C++ online submissions for Average Salary Excluding the Minimum and Maximum Salary.
    double lt1491a(vector<int>& salary)
    {
//        std::sort(begin(salary), end(salary));
//        int sum2 = std::accumulate(begin(salary))
        int sum2 = 0;
        int mx = -1;
        int mn = INT_MAX;
        for (int i : salary)
        {
            sum2 += i;
            mx = max(mx, i);
            mn = min(mn, i);
        }
        return ((double) (sum2 - mx - mn)) / (salary.size() - 2);
    }

};

int main()
{

    LT1491 lt;


    return 0;
}
