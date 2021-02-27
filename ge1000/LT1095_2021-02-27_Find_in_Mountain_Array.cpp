
#include "../header/myheader.h"

//class MountainArray;
//{
//public:
//    int get(int index);
//    int length();
//};

class MountainArray
{
    myvi v;

public:
    int get(int index)
    {
        return v[index];
    }
    int length()
    {
        return v.size();
    }
    MountainArray(vector<int> vi)
    {
        v = vi;
    }
};

class LT1095
{
public:

// D D

//        while (l <= r) {
//            m = (l + r) / 2;
//            if (A.get(m) < target)
//                l = m + 1;
//            else if (A.get(m) > target)
//                r = m - 1;
//            else
//                return m;
//        }


//        left = peak;
//        right = A.length() - 1;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (A.get(mid) < target) {
//                right = mid - 1;
//            } else if (A.get(mid) > target) {
//                left = mid + 1;
//            } else {
//                return mid;
//            }
//        }


//int findInMountainArray(int t, MountainArray& arr) {
//  auto peak = 0, r = arr.length() - 1;
//  while (peak < r) {
//    int m = (peak + r) / 2;
//    if (arr.get(m) > arr.get(m + 1)) r = m;
//    else peak = m + 1;
//  }
//  auto i = bSearch(arr, t, 0, peak);
//  return i != -1 ? i : bSearch(arr, t, peak + 1, arr.length() - 1, false);
//}
//int bSearch(MountainArray& arr, int t, int l, int r, bool asc = true) {
//  while (l <= r) {
//    int m = (l + r) / 2;
//    auto val = arr.get(m);
//    if (val == t) return m;
//    if (asc == val < t) l = m + 1;
//    else r = m - 1;
//  }
//  return -1;
//}




//Runtime: 4 ms, faster than 87.91% of C++ online submissions for Find in Mountain Array.
//Memory Usage: 7.1 MB, less than 48.99% of C++ online submissions for Find in Mountain Array.

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

// 先找山顶，然后分成2部分， 还是 直接硬算。。
// 先找一个 大于 target 的点， 划分成 2部分。
    int lt1095a(int target, MountainArray &mountainArr)
    {
        int sz1 = mountainArr.length();
        int l = 0;
        int r = sz1;
        int sz4 = -1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            int val = getVala1(mountainArr, mid);
            if (val >= target)
            {
                sz4 = mid;
                break;
            }
            else
            {
                int t2 = getVala1(mountainArr, mid + 1);
                if (t2 >= target)
                {
                    sz4 = mid + 1;
                    break;
                }
                if (t2 > val)       // mid之前 必然不可能有 target. 可以记录下来，来缩减时间。
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
        }
        if (sz4 == -1)          // ....
            return -1;
        l = 0;
        r = sz4;
        #ifdef __test
        cout<<". sz4 : "<<sz4<<endl;
        #endif // __test
        while (l <= r)              // ==
        {
            int mid = (l + r + 1) / 2;
            #ifdef __test
            cout<<l<<" . "<<r<<" . . "<<mid<<endl;
            #endif // __test
            int val = getVala1(mountainArr, mid);
            if (target == val)
            {
                return mid;         // 严格递增递减，所以不可能前面有相同的。
            }
            else if (target > val)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        l = sz4;
        r = sz1 - 1;
        while (l <= r)
        {
            int mid = (l + r + 1) / 2;
            #ifdef __test
            cout<<l<<" 22. "<<r<<" . . "<<mid<<endl;
            getchar();
            #endif // __test
            int val = getVala1(mountainArr, mid);
            if (target == val)
            {
                return mid;
            }
            else if (target > val)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return -1;
    }
    unordered_map<int, int> map2;
    int getVala1(MountainArray &mountainArr, int idx)
    {
        #ifdef __test
        cout<<".idx "<<idx<<endl;
        #endif // __test
        if (map2.find(idx) != map2.end())
        {
            return map2[idx];
        }
        int val = mountainArr.get(idx);
        map2[idx] = val;
        return val;
    }

};



int main()
{
//    myvi v = {1,2,3,4,5,3,1};
////    myvi v = {0,1,2,4,2,1};
//    int t = 3;

//    myvi v = {1,5,2};
//    int t = 5;

//    myvi v = {1,5,2};
//    int t = 0;

    myvi v = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2};
    int t = 22;


    MountainArray ma(v);

    LT1095 lt;

    cout<<lt.lt1095a(t, ma)<<endl;

    return 0;
}
