
#include "../header/myheader.h"

class LT1539
{
public:

// D D

//        while (k > 0 && j < arr.size()) {
//            ++i;
//            if (arr[j] == i) {
//                ++j;
//            } else {
//                --k;
//            }
//        }
//        return i + k;


//    for (int n = 1, i = 0; n <= 1000; ++n) {
//        if (i < arr.size() && arr[i] == n)
//            ++i;
//        else if (--k == 0)
//            return n;
//    }
//    return 1000 + k;


//        int l = 0, r = arr.length;
//        while (l < r) {
//            int mid = l + (r - l) / 2;
//            if (arr[mid] - (mid + 1) >= k) r = mid;  //missed more or equal than k numbers, left side;
//            else l = mid + 1;   // missed less than k numbers, must be in the right side;
//        }
//        return l + k;


//        while (l < r) {
//            m = (l + r) / 2;
//            if (A[m] - 1 - m < k)
//                l = m + 1;
//            else
//                r = m;
//        }
//        return l + k;


//Runtime: 8 ms, faster than 73.23% of C++ online submissions for Kth Missing Positive Number.
//Memory Usage: 9.8 MB, less than 74.21% of C++ online submissions for Kth Missing Positive Number.
    int lt1539a(vector<int>& arr, int k)
    {
        int sz1 = arr.size();
        int miss = 0;
        int lst = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (arr[i] != lst + 1)
            {
                miss += arr[i] - lst - 1;
                if (miss >= k)
                {
                    return arr[i] - miss + k - 1;
                }
            }
            lst = arr[i];
        }
        return arr[sz1 - 1] + k - miss;
    }

};

int main()
{
    myvi v = {2,3,4,7,11};
    int k{5};

//    myvi v = {1,2,3,4};
//    int k{2};

//    myvi v = {2};
//    int k{1};

    LT1539 lt;

    cout<<lt.lt1539a(v, k);

    return 0;
}
