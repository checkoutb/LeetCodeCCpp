
#include "../header/myheader.h"

class LT1846
{
public:

// D D

//    for (auto i = 1; i < arr.size(); ++i)
//        if (arr[i] > res)
//            ++res;

//        for (int& a : A)
//            pre = min(pre + 1, a);


//Runtime: 84 ms, faster than 100.00% of C++ online submissions for Maximum Element After Decreasing and Rearranging.
//Memory Usage: 51.2 MB, less than 83.33% of C++ online submissions for Maximum Element After Decreasing and Rearranging.
    int lt1846a(vector<int>& arr)
    {
        std::sort(begin(arr), end(arr));        // all >= 1
        int t2 = 1;
        for (int i = 0; i < arr.size(); ++i)
        {
            t2 = min(t2, arr[i]) + 1;
        }
        return t2 - 1;

//        priority_queue<int, vector<int>, std::greater<int>> priq;
//        for (int i : arr)
//            priq.push(i);
//        int ans = 0;
//        int t2 = 0;
//        while (!priq.empty())
    }

};

int main()
{
//    myvi v = {2,2,1,2,1};
//    myvi v = {100,1,1000};
    myvi v = {1,2,3,4,5};

    LT1846 lt;

    cout<<lt.lt1846a(v)<<endl;

    return 0;
}
