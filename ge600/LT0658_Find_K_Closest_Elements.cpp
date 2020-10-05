
#include "../header/myheader.h"

class LT0658
{
public:


// D D

//        int lo = 0;
//		int hi = arr.length - 1;
//		while (hi - lo >= k) {
//			if (Math.abs(arr[lo] - x) > Math.abs(arr[hi] - x)) {
//				lo++;
//			} else {
//				hi--;
//			}
//		}


//    int lo = 0, hi = arr.size() - k;
//    while (lo < hi) {
//        int mid = (lo + hi) / 2;
//        if (x - arr.get(mid) > arr.get(mid+k) - x)            // mid + k...!!!
//            lo = mid + 1;
//        else
//            hi = mid;
//    }
//    return arr.subList(lo, lo + k);



//def find_closest_elements(arr, k, x)
//  arr[(0..arr.size).bsearch { |i| x - arr[i] <= (arr[i+k] || 1/0.0) - x }, k]
//end
// ruby






//Runtime: 108 ms, faster than 52.17% of C++ online submissions for Find K Closest Elements.
//Memory Usage: 31.2 MB, less than 79.63% of C++ online submissions for Find K Closest Elements.
    vector<int> lt0658b(vector<int>& arr, int k, int x)
    {
        vector<int>::iterator it = std::upper_bound(begin(arr), end(arr), x);
        vector<int> ans;
        if (it != arr.begin() && it != arr.end())
        {
            int t1 = *(it - 1);
            int t2 = *it;
            if (t2 - x >= x - t1)
            {
                it--;
            }
        }
        else if (it == arr.end())
        {
            it--;
        }
        int l{(int) (it - arr.begin())}, r{(int) (it - arr.begin())};
        while (r - l + 1 < k)
        {
            int tl = l - 1 < 0 ? INT_MIN / 2 : arr[l - 1];
            int tr = r + 1 >= arr.size() ? INT_MAX / 2 : arr[r + 1];
            if (tr - x >= x - tl)
            {
                l--;
            }
            else
            {
                r++;
            }
        }
        ans = vector<int>(arr.begin() + l, arr.begin() + r + 1);
        return ans;
    }


    vector<int> findClosestElements(vector<int>& arr, int k, int x)
    {
        vector<int>::iterator it = std::upper_bound(begin(arr), end(arr), x);
        if (it != arr.begin() && it != arr.end())
        {
            int t1 = *it;
            int t2 = *--it;
            if (t1 - x < x - t2)
            {
                it++;
            }
        }
//        cout<<*it<<endl;
        int mid = it - arr.begin() - 1;
        int ll = (k - 1) / 2 + (k - 1) % 2;
        int rl = (k - 1) / 2;
        if (mid < ll)
        {
            return vector<int>(arr.begin(), arr.begin() + k);
        }
        else if (mid > arr.size() - rl)
        {
            return vector<int>(arr.begin() + arr.size() - k, arr.end());
        }
        else
        {
            return vector<int>(arr.begin() + mid - ll, arr.begin() + mid + rl + 1);
        }
    }

};

int main()
{
//    vector<int> v = {1,2,3,4,5};
//    int k{4}, x{10};

    vector<int> v = {1,1,1,10,10,10};
    int k{3}, x{9};

    LT0658 lt;

    vector<int> v2 = lt.lt0658b(v,k,x);

    for_each(begin(v2), end(v2), fun_cout);
    cout<<endl;

    return 0;
}
