
#include "../header/myheader.h"

class LT2910
{
public:




//     Runtime171 ms
// Beats
// 90.75%
// Memory113.4 MB
// Beats
// 99.51%
    //
    // no prime... just   for (int i = vi0; i > 0; --i)


    // g
    // 629/630


    // all index in group 's value are same
    // any 2 group,  count diff <= 1 ..
    // min group count
    //
    // each index is a group ..
    // so binary search ?. no  min gcd ?  no, if diff=0, gcd .. but diff<=1 ..
    // bs: ..
    // {2,5,8,4,5,} /2 => {2, 2,2,1, 2,2,2,2, 2,2, 2,2,1}
    //              /3 => {2, 2,3, 3,3,2, 2,2, 2,3}
    //       min, min+1
    //   min/2 (min/2,min/2+1)
    // /2 /3 is min+1 ...
    // try: (min,min+1), (min-1, min),   min/2 , if min is odd, (min/2, min/2+1), else (min/2,min/2+1), (min/2-1,min/2) ... /2 is fast.
    // if there is a odd, it is always odd.
    // min: 10 , try (10,11) (9,10)
    //    then 5, try (5,6), (4,5)
    //    then 2 (5 is odd), just try (2,3)
    //    then 1   (1,2)
    // 30   (30,31),(29,30)
    // 15   (15,16),(14,15)
    // 7+8  (7,8)
    // 5 5 5 ...............
    // 10 10 10...........
    //
    // if (7,8) ok,   (15,16) or (14,15)  must will ok.   7777778 == (14,15)     788888888 == (15,16)
    // prime.........
    //
    // if all value are same, so a group, is it ok?
    // (1,2) is always ok
    int minGroupsForValidAssignment(vector<int>& nums)
    {
        std::sort(std::begin(nums), std::end(nums));
        std::vector<int> vi;
        int cnt = 1;
        for (size_t i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                ++cnt;
            }
            else
            {
                vi.push_back(cnt);
                cnt = 1;
            }
        }
        vi.push_back(cnt);

        std::sort(std::begin(vi), std::end(vi));

#ifdef __test
        showVectorInt(vi);
#endif

        int ans = groupCount(vi, vi[0]);
        if (ans != -1)
            return ans;
        ans = groupCount(vi, vi[0] - 1);
        if (ans != -1)
            return ans;

        // error... min(not -1, not -1)
        // int ans = std::max(groupCount(vi, vi[0]), groupCount(vi, vi[0] - 1));
        // if (ans != -1)
        //     return ans;

//         std::vector<bool> vb(static_cast<size_t>(vi[0]) + 1, false);
//         int vi0 = vi[0];
//         for (size_t i = 2; i < vb.size(); ++i)  // split into i groups
//         {
//             if (vb[i])
//                 continue;
//             for (size_t j = i << 1; j < vb.size(); j += i)
//                 vb[j] = true;
//
//             ans = groupCount(vi, vi0 / i);
//             if (ans != -1)
//                 return ans;
//
//             // if ((vi0 % i == 0) && (ans = groupCount(vi, vi0 / i - 1)) != -1)
//             if ((ans = groupCount(vi, vi0 / i - 1)) != -1)
//                 return ans;
//
//         }

        int vi0 = vi[0];
        for (int i = vi0; i > 0; --i)                   // use this is ok, use prime is error.....
        {
            if ((ans = groupCount(vi, i)) != -1)
                return ans;
        }

        // return ans;  // un-reachable
        return -1;
    }

    // -1 is no way
    // mn, mn+1
    // ....1................1 2 3
    int groupCount(const std::vector<int>& vi, int mn)
    {
        if (mn <= 0)
            return -1;

        int cnt = 0;

        if (mn == 1)
        {
            for (int num : vi)
                cnt += num / 2 + num % 2;
            return cnt;
        }

        for (int num : vi)
        {
            // .....
            int t2 = num / (mn + 1);
            int t3 = num % (mn + 1);

            if (t3 != 0 && (mn - t3 > t2))
                return -1;
            cnt += t2 + (t3 != 0);

//             if ((num % mn) > (num / mn))
//                 return -1;
//
//             int t2 = num / mn;
//             int t3 = num % mn;


            // // try mn+1 fist, then try mn
            // if ((num % (mn + 1)) == 0 || (num % (mn + 1)) == mn)
            // {
            //     cnt += num / (mn + 1);
            // }
            // else
            // {
            //     if ((num % mn) > (num / mn))
            //         return -1;
            //     cnt += num / mn;
            // }


            // if ((num % mn) > (num / mn))
            //     return -1;
            // cnt += num / mn;
        }
#ifdef __test
        cout<<mn<<",... "<<cnt<<endl;
#endif

        return cnt;
    }

};

int main()
{

    LT2910 lt;

    // myvi vi{3,2,3,2,3};
    // myvi vi{1,1,3,10,10,10};
    // myvi vi{1,1,2,1,1,1,3,1,2,3};   // 6 2 2  -> 4       3 3 2 2
    myvi vi{1,1,1,3,3,3,1,2,1,1,1,2,1}; // 2 3 8     -> 5   2 3 332

    std::cout<<lt.minGroupsForValidAssignment(vi)<<endl;

    return 0;
}
