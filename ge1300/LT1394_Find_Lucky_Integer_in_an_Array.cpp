
#include "../header/myheader.h"

class LT1394
{
public:

// D D

//        for (int i = 500; i > 0; --i) {
//            if (nums[i] == i) return i;
//        }

//    for (int i = 1; i < arr.size(); ++i) {
//        if (arr[i] == arr[i - 1])
//            ++cnt;
//        else {
//            if (arr[i - 1] == cnt)
//                return cnt;
//            cnt = 1;
//        }
//    }

//    make_heap(begin(arr), end(arr));
//    int cnt = 1, last = -1;
//    for (int i = 0; i < arr.size(); ++i) {
//        if (arr.front() == last)
//            ++cnt;
//        else {
//            if (last == cnt)
//                return cnt;
//            last = arr.front();
//            cnt = 1;
//        }
//        pop_heap(arr.begin(), arr.end() - i);
//    }
//    return arr.front() == cnt ? cnt : - 1;


//Runtime: 8 ms, faster than 94.49% of C++ online submissions for Find Lucky Integer in an Array.
//Memory Usage: 10.5 MB, less than 75.73% of C++ online submissions for Find Lucky Integer in an Array.
    int lt1394a(vector<int>& arr)
    {
        int arr2[501] = {0};
        for (int i : arr)
            arr2[i]++;
        int ans = -1;
        for (int i = 1; i < 501; ++i)
        {
            if (arr2[i] == i)
                ans = i;
        }
        return ans;
    }

};

int main()
{

    vector<int> v = {2,2,3,4};

    LT1394 lt;

    cout<<lt.lt1394a(v)<<endl;

    return 0;
}
