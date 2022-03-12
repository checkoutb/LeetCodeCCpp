
#include "../header/myheader.h"

class LT2195
{
public:


// D D

//    long long res = (long long)k * (k + 1) / 2;
//    for (int n : set<int>(begin(nums), end(nums)))
//        if (n <= k)
//            res += (++k) - n;
//    return res;

//    long long res = (long long)k * (k + 1) / 2, last = 0;
//    make_heap(begin(nums), end(nums), greater<int>());
//    while (!nums.empty() && nums.front() <= k) {
//        int n = nums.front();
//        pop_heap(begin(nums), end(nums), greater<int>()); nums.pop_back();
//        if (n != last)
//            res += (++k) - n;
//        last = n;
//    }
//    return res;


//Runtime: 435 ms, faster than 21.03% of C++ online submissions for Append K Integers With Minimal Sum.
//Memory Usage: 102.1 MB, less than 12.72% of C++ online submissions for Append K Integers With Minimal Sum.
// 最小 未出现的 k个。 .. 重复的
    long long lt2195a(vector<int>& nums, int k)
    {
        map<int, int> map2;
        for (int n : nums)
            map2[n]++;
        long long pre = 0LL;
        long long ans = 0LL;
        for (map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            #ifdef __test
            cout<<". ..  "<<(it->first)<<", "<<pre<<endl;
            #endif // __test
            if (it->first == pre + 1)
            {
//                ans += 1LL * (it->first) * it->second;
                pre = it->first;
                continue;
            }
            #ifdef __test
            cout<<"cmp "<<k<<", "<<(it->first)<<", "<<pre<<endl;
            #endif // __test
            if (k > (it->first - pre - 1))
            {
                long long st = pre + 1, en = it->first - 1;
                ans += (st + en) * (en - st + 1) / 2;
                k -= en - st + 1;
//                ans += 1LL * it->first * it->second;
                pre = it->first;
//                            cout<<".."<<ans<<endl;
                #ifdef __test
                cout<<", "<<ans<<", "<<st<<", "<<en<<endl;
                #endif // __test
            }
            else
            {
                long long st = pre + 1;
                long long en = st + k - 1;
                ans += (st + en) * (k) / 2;
                k = 0;
//            cout<<ans<<", "<<st<<", "<<en<<endl;
//                ans += 1LL * it->first * it->second;
                #ifdef __test
                cout<<"- "<<ans<<", "<<st<<", "<<en<<endl;
                #endif // __test
                break;
            }
        }
        #ifdef __test
        cout<<",k "<<k<<", "<<pre<<endl;
        #endif // __test
        if (k > 0)
        {
            long long st = pre + 1;
            long long en = st + k - 1;
            ans += (st + en) * (k) / 2;
            #ifdef __test
            cout<<st<<", "<<en<<", "<<pre<<endl;
            #endif // __test
        }
        return ans;

//        std::sort(begin(nums), end(nums));
//        int t2 = 0;
//        for (int i = 0; i < nums.size(); ++i)
//        {
//            if (nums[i] - i - 1 > k)
//            {
//                t2 = i;
//                break;
//            }
//        }
//        return ans;
    }

};

int main()
{

    LT2195 lt;

    myvi v = {1,4,25,10,25};
    int k = 2;

//    myvi v = {5,6};
//    int k = 6;

    cout<<lt.lt2195a(v, k)<<endl;

    return 0;
}
