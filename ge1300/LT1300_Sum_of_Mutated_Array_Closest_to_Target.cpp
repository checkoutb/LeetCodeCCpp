
#include "../header/myheader.h"

class LT1300
{
public:


// D D

//        sort(A.begin(), A.end());
//        int n = A.size(), i = 0;
//        while (i < n && target > A[i] * (n - i))
//            target -= A[i++];
//        return i == n ? A[n - 1] : int(round((target - 0.0001) / (n - i)));


// 其他的，基本都是  二分 直接得到答案的。。我这个就。。。


// 二分没有想象的简单。。。
//Runtime: 36 ms, faster than 50.84% of C++ online submissions for Sum of Mutated Array Closest to Target.
//Memory Usage: 13.1 MB, less than 10.43% of C++ online submissions for Sum of Mutated Array Closest to Target.
    int lt1300a(vector<int>& arr, int target)
    {
        vector<int> vs(arr.size());
        sort(arr.begin(), arr.end());
        int sum2 = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            sum2 += arr[i];
            vs[i] = sum2;
        }

        #ifdef __test
        for (int i : arr)
            cout<<i<<", ";
        cout<<endl;
        for (int i : vs)
            cout<<i<<", ";
        cout<<endl;

        #endif // __test

        if (vs[arr.size() - 1] <= target)
            return arr[arr.size() - 1];

        int l = target / arr.size();
        int r = arr[arr.size() - 1];
        int ans = 0;
        int ansdiff = target;
        int sz2 = arr.size();
        int mx = 0;
        int mn = INT_MAX;
        while (l < r)
        {
            int mid = (r + l) / 2;
            if (mid <= arr[0])
            {
                sum2 = sz2 * mid;
            }
            else
            {
                vector<int>::iterator it = std::lower_bound(begin(arr), end(arr), mid);
                int idx = it - begin(arr);
//                cout<<idx<<endl;
                sum2 = vs[idx - 1] + (sz2 - idx) * mid;
            }
            if (sum2 >= target)
                mn = min(mn, mid);
            else
                mx = max(mx, mid);

//            cout<<l<<", "<<mid<<", "<<r<<", "<<sum2<<", "<<endl;
            if (sum2 == target)
                l = r = mid;
            else if (sum2 > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        int diff = INT_MAX;

        for (int i = mx; i <= mn; ++i)
        {
            int t2 = 0;
            if (i <= arr[0])
            {
                t2 = abs(target - sz2 * i);
            }
            else
            {
                vector<int>::iterator it = std::lower_bound(begin(arr), end(arr), i);
                int idx = it - begin(arr);
                t2 = abs(target - vs[idx - 1] - (sz2 - idx) * i);
            }
            if (t2 < diff)
            {
                diff = t2;
                ans = i;
            }
        }
        return ans;

//        int diff = 0;
//        if (l <= arr[0])
//        {
//            diff = abs(target - sz2 * l);
////            cout<<"zzz"<<endl;
//        }
//        else
//        {
//            vector<int>::iterator it = std::lower_bound(begin(arr), end(arr), l);
//            int idx = it - begin(arr);
//            diff = abs(target - vs[idx - 1] - (sz2 - idx) * l);
//        }
//
//        int diff2 = 0;
//        if ((l + 1) <= arr[0])
//        {
//            diff2 = abs(target - sz2 * (l + 1));
////            cout<<"zasda"<<endl;
//        }
//        else
//        {
//            vector<int>::iterator it = std::lower_bound(begin(arr), end(arr), l + 1);
//            int idx = it - begin(arr);
//            diff2 = abs(target - vs[idx - 1] - (sz2 - idx) * (l + 1));
//        }

//        idx = std::distance(begin(arr), std::lower_bound(begin(arr), end(arr), l + 1));

//        cout<<l<<endl;
//        cout<<"  "<<idx<<endl;
//        cout<<diff<<", "<<(target - vs[idx] - (sz2 - idx - 1) * (l + 1))<<endl;

//    cout<<diff<<" , "<<diff2<<endl;

//        return diff > diff2 ? l + 1 : l;

//        if (diff > abs(target - vs[idx] - (sz2 - idx - 1) * (l + 1)))
//            return l + 1;
//        else
//            return l;
    }



};

int main()
{

//    vector<int> arr = {4,9,3};
//    int t = 10;

//    vector<int> arr = {2,3,5};
//    int t = 10;

    vector<int> arr = {60864,25176,27249,21296,20204};
    int t = 56803;

//    vector<int> arr = {1547,83230,57084,93444,70879};       // 17442
//    int t = 71237;


    LT1300 lt;

    cout<<lt.lt1300a(arr, t);

    return 0;
}
