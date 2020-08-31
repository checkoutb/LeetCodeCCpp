
#include "../header/myheader.h"

class LT0556
{
public:


// D D
//    auto digits = to_string(n);
//    next_permutation(begin(digits), end(digits));
//    auto res = stoll(digits);
//    return (res > INT_MAX || res <= n) ? -1 : res;


//    bool nextPermutation(string& nums) {
//        if(nums.empty()) return false;
//        int i=nums.size()-1;
//        while(i>=1 && nums[i]<=nums[i-1]) i--;
//        if(i==0) return false; // no next permutation, i.e. already largest
//
//        int j=nums.size()-1;
//        while(nums[j]<=nums[i-1]) j--;
//        swap(nums[i-1],nums[j]);
//
//        reverse(nums.begin()+i,nums.end());
//        return true;
//    }



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Next Greater Element III.
//Memory Usage: 6 MB, less than 46.40% of C++ online submissions for Next Greater Element III.
    int lt0556d(int n)
    {
        map<int, int> map2;
        long n2 = n;
        while (n2 > 0)
        {
            int t2 = n2 % 10;
            map2[t2]++;
            auto p = map2.upper_bound(t2);      // .
            if (p != map2.end())
            {
                p->second--;
                n2 += p->first - t2;
                break;
            }
            n2 /= 10;
        }
        for (auto p = begin(map2); p != end(map2); p++)
        {
            while (p->second > 0)
            {
                n2 *= 10;
                n2 += p->first;
                p->second--;
            }
        }
        return n2 <= INT_MAX && n2 > n ? (int) n2 : -1;
    }


    // error..
    int lt0556c(int n)
    {
        vector<int> v;
        int n2 = n;
        while (n > 0)
        {
            v.push_back(n % 10);
            n /= 10;
        }
        #ifdef __test
        for_each(begin(v), end(v), fun_cout);   cout<<endl;
        #endif // __test
        int mx = v[0];
        int mxi = 0;
        int t2 = -1;
        for (int i = 0; i < v.size(); i++)
        {
            if (mx > v[i])
            {
                t2 = i;
                v[mxi] = v[i];
                v[i] = mx;
                break;
            }
            else
            {
                mxi = i;
                mx = v[i];
            }
        }
        if (t2 == -1)
            return -1;
        std::sort(begin(v), end(v) + t2);
        long ans = 0;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            ans *= 10;
            ans += v[i];
        }
        return ans <= INT_MAX && ans > n2 ? (int) ans : -1;
    }


// error 12443322
    int lt0556b(int n)
    {
        int arr[10] = {0};
        int n2 = n;
        int pow2 = 1;
        int imax = -1;
        for (int i = 0; i < 10; i++)
        {
            arr[i] = n / pow2;
            if (arr[i] >= 10)
            {
                arr[i] %= 10;
            }
            else
            {
                imax = i;
                break;
            }
            pow2 *= 10;
        }

//        for_each(begin(arr), end(arr), fun_cout);
//        cout<<endl<<imax<<endl;

//        priority_queue<int> pri(std::greater<int>(), vector<int>());      // 这个是new的，需要用-> ？
        std::priority_queue<int, vector<int>, std::greater<int>> pri;
        int t3 = -10;
//        pri.push(arr[0]);
        for (int i = 0; i < imax; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                pri.push(arr[i + 1]);
                arr[i + 1] = arr[i];
                t3 = i + 1;
                break;
            }
            else
            {
                pri.push(arr[i]);
            }
        }
        long ans = 0;

        pow2 = 1;
        if (t3 == -10)
            return -1;
//        cout<<t3<<endl;
        for (int i = imax; i >= t3; i--)
        {
            ans *= 10;
            ans += arr[i];
        }

//        cout<<"pei.size : "<<pri.size()<<endl;

        while (!pri.empty())
        {
            ans *= 10;
            ans += pri.top();
//            cout<<" . "<<pri.top()<<endl;
            pri.pop();
//            pow2 *= 10;
            #ifdef __test
            cout<<ans<<endl;
            #endif // __test
        }
//        if (t3 != -10)
//        {
//            for (; t3 <= imax; t3++)
//            {
//                ans *= 10;
//                ans += arr[t3];
////                pow2 *= 10;
//            }
//        }
        #ifdef __test
        cout<<ans<<endl;
        #endif // __test
        return ans <= INT_MAX && ans > n2 ? (int) ans : -1;
    }


// 230241       error
    int lt0556a(int n)
    {
        long n2 = n;
        int pow2 = 1;
        for (int i = 0; pow2 < (INT_MAX >> 3); i++)     // >>3 == /8...
        {
            int p3 = pow2 * 10;
            int t1 = n % p3 / pow2;
            int t2 = n % (p3 * 10) / p3;        // .
            if (n / p3 == 0)
                break;
            if (t1 > t2)
            {
                n2 = n2 - t1 * pow2 - t2 * p3 + t1 * p3 + t2 * pow2;
                break;
            }
            pow2 = p3;
        }

        return n2 <= INT_MAX && n2 > n ? (int) n2 : -1;
    }


};

int main()
{

//    int n = 12;
//    int n = 21;
//    int n = 230241;
//    int n = 12443322;       // 13222344


    LT0556 lt;

    cout<<lt.lt0556d(n)<<endl;

    return 0;
}
