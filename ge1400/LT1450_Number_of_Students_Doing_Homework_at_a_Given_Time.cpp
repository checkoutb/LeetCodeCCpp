
#include "../header/myheader.h"

class LT1450
{
public:

// D D



//Runtime: 8 ms, faster than 34.37% of C++ online submissions for Number of Students Doing Homework at a Given Time.
//Memory Usage: 11.3 MB, less than 15.02% of C++ online submissions for Number of Students Doing Homework at a Given Time.
    int lt1450a(vector<int>& startTime, vector<int>& endTime, int queryTime)
    {
        int ans = 0;
        for (int i = 0; i < startTime.size(); ++i)
        {
            if (queryTime >= startTime[i] && queryTime <= endTime[i])
                ans++;
        }
        return ans;
    }

};

int main()
{
    vector<int> st = {9,8,7,6,5,4,3,2,1};
    vector<int> en = {10,10,10,10,10,10,10,10,10};
    int q{5};

    LT1450 lt;

    cout<<lt.lt1450a(st,en,q);

    return 0;
}
