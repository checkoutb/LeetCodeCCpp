
#include "../header/myheader.h"

class LT1287
{
public:


// D D

//        for(const auto& x:{arr[n/4],arr[n/2],arr[n*3/4]}){
//            if(distance(lower_bound(arr.cbegin(),arr.cend(),x),upper_bound(arr.cbegin(),arr.cend(),x))*4>arr.size()){
//                return x;
//            }
//        }

//    for (int i : {n/4, n/2, n*3/4}) {
//        auto p = equal_range(arr.begin(), arr.end(), arr[i]);
//        if (p.second - p.first > n / 4)
//            return arr[i];
//    }
// equal_range ...



//Runtime: 24 ms, faster than 66.34% of C++ online submissions for Element Appearing More Than 25% In Sorted Array.
//Memory Usage: 12.8 MB, less than 34.36% of C++ online submissions for Element Appearing More Than 25% In Sorted Array.
    int lt1287a(vector<int>& arr)
    {
        int sz1 = arr.size();
        int last = arr[0] - 1;
        int step = sz1 / 4;
        step = max(1, step);
        int ans = last;
        vector<int> vi;
        for (int i = 0; i < sz1; i += step)
        {
            if (arr[i] == last)
            {
                ans = last;
                return ans;
            }
            last = arr[i];
            vi.push_back(arr[i]);
        }

        for (int i : vi)
        {
            auto p1 = std::lower_bound(begin(arr), end(arr), i);
            auto p2 = std::upper_bound(begin(arr), end(arr), i);
            if ((p2 - p1) > (sz1 / 4))
                return i;
        }

        return -1;
    }

};

int main()
{

    vector<int> v = {1,2,2,6,6,6,6,7,10};

    LT1287 lt;

    cout<<lt.lt1287a(v)<<endl;

    return 0;
}
