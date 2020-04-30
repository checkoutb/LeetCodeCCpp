
#include "../header/myheader.h"

class LT0746
{
public:

// discuss
//        auto [a, b] = tie(A[0], A[1]);
//        for (auto i=2; i < A.size(); ++i, a=b, b=c)
//            c = A[i] + min(a, b);
//        return min(a, b);


//Runtime: 4 ms, faster than 97.34% of C++ online submissions for Min Cost Climbing Stairs.
//Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Min Cost Climbing Stairs.
    int lt0746a(vector<int>& cost)
    {
        int sz1 = cost.size();
        int arr[sz1];
        arr[0] = cost[0];
        arr[1] = cost[1];
        for (int i = 2; i < sz1; i++)
        {
            arr[i] = min(arr[i - 1], arr[i - 2]) + cost[i];
        }
        return min(arr[sz1 - 1], arr[sz1 - 2]);
    }

};

int main()
{

    vector<int> vv = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    LT0746 lt;

    cout<<lt.lt0746a(vv);

    return 0;
}
