
#include "../header/myheader.h"

class LT3043
{
public:

// D D

    // for (int len = to_string(x).length(); len > res; x /= 10, --len) {



    // unordered_set<int> s1;
    // for (int i : arr1)
    //     for (; i; i /= 10)
    //         s1.insert(i);
    // int ans = 0;
    // for (int i : arr2)
    //     for (; i; i /= 10)
    //         if (s1.count(i))
    //             ans = max(ans, (int)log10(i) + 1), s1.erase(i);
    // return ans;


    // use set.insert()'s result  to  replace !set2.contains(),  will faster?



    // thanks, hint.

// Runtime
// 386ms
// Beats50.00%of users with C++
// Memory
// 139.16MB
// Beats12.50%of users with C++


    // hint 1&2
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2)
    {
        std::set<int> set2;
        int sz1 = arr1.size();
        int sz2 = arr2.size();
        for (int n : arr1)
        {
            while (n > 0 && !set2.contains(n))
            {
                set2.insert(n);
                n /= 10;
            }
        }
        // int ans = 0;
        // int t2 = 0;
        int mx = 0;
        std::sort(rbegin(arr2), std::rend(arr2));
        for (int n : arr2)
        {
            while (n > mx)
            {
                if (set2.contains(n))
                {
                    mx = n;
                }
                n /= 10;
            }
        }
        int ans = 0;
        while (mx > 0)
        {
            ++ans;
            mx /= 10;
        }
        return ans;
    }
};

int main()
{

    LT3043 lt;


    return 0;
}
