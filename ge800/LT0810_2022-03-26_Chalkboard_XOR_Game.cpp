
#include "../header/myheader.h"

class LT0810
{
public:

// D D


//        return accumulate(nums.cbegin(), nums.cend(), 0, std::bit_xor<int>()) == 0
//                || nums.size() % 2 == 0;

//        int ans = 0;
//        for(int i=0; i<nums.size(); i++) {
//            ans = ans^nums[i];
//        }
//        if(nums.size()%2 ==0 || ans==0)
//            return true;
//        return false;


//mem = {}
//def SG(A):                      # 求状态A的SG数
//   if A not in mem:
//       S = sub_states(A)       # sub_states(A)将A尽可能细致地拆分成子状态
//       if len(S) > 1:          # A可以拆分，用子状态的异或求其SG数
//           mem[A] = reduce(operator.xor, [SG(B) for B in S])
//       else:                   # A不可拆分，根据定义求其SG数
//           mem[A] = mex(set(SG(B) for B in next_states(A)))
//                               # next_states(A)返回A的所有次态
//                               # 注意这条语句蕴含了“终局态的SG数为0”
//   return mem[A]
//Sprague-Grundy theorem


//        int xo = 0;
//        for (int i: nums) xo ^= i;
//        return xo == 0 || nums.size() % 2 == 0;
//If xor == 0, Alice win directly.
//If xor != 0 and length of numbers is even, Alice will win.
//
//Beacause:
//All numbers won't be the same. Otherwise xor will be equal to 0
//If all numbers are not the same, It means there are at least 2 different numbers.
//Alice can always erase a number different from current xor.
//So Alice won't never lose this turn at this situation.



//Runtime: 119 ms, faster than 6.12% of C++ online submissions for Chalkboard XOR Game.
//Memory Usage: 14.8 MB, less than 44.90% of C++ online submissions for Chalkboard XOR Game.
// brainteaser ： 脑筋急转弯。。。
// 剩下的数字的个数都是偶数，就输了，但是，如果有2种类型，就不可能 个数变成偶数。  还有 1 5 4 这个 ^ 后就是0。
// 那就是 bit ？
// 1 5 4 能规避掉， 1 5 4 x 的组合，应该能找到选择一个数字，使得 ^ 不为0的。 对必然能。
// 1 1 5 4
// 1 2 5 4
// 开始时，只有一种数字，且个数是奇数，那么就输了。
// 奇数个数字a + 任意其他一个 就赢
// 3种及以上，这步不会输。
// 如果Alice 未移除前 是 奇数个数， 那么她肯定要尽量让 数字分散。 不能相同，一但相同，Alice就输了。
// 如果alice 未移除前 是偶数，那么她要让 数字变成相同值，来让bob输。
// 所以说 移除哪个并不关太关心，只要移除后 不会输，
// 移除前，奇数，移除 最多的 。如果移除最多的会导致0，那么就换一个？还是必输？
// 移除前，偶数，移除 非最多的
    bool lt0810a(vector<int>& nums)
    {
        unordered_map<int, int> map2;
        int xor2 = 0;
        for (int n : nums)
        {
            map2[n]++;
            xor2 ^= n;
        }
//        cout<<xor2<<endl;
        int sz1 = nums.size();
        while (sz1 > 0)
        {
            // alice
            if (xor2 == 0)
                return true;
            int mxcnt = -1;
            int mx = -1;
            for (auto& p : map2)
            {
                if (p.second > mxcnt)
                {
                    mxcnt = p.second;
                    mx = p.first;
                }
            }
            if (sz1 % 2 == 0)       // remove not maxcnt
            {
                for (auto& p : map2)
                {
                    if (p.first == mx)
                        continue;
                    if ((xor2 ^ p.first) != 0)
                    {
                        #ifdef __test
                        cout<<", rm "<<p.first<<endl;
                        #endif // __test
                        xor2 ^= p.first;
                        map2[p.first]--;
                        if (map2[p.first] == 0)
                        {
                            map2.erase(p.first);
                        }
                        goto AAA;
                    }
                }
                xor2 ^= mx;
                map2[mx]--;
                if (mxcnt == 1)
                    map2.erase(mx);
            }
            else
            {
                if ((xor2 ^ mx) != 0)
                {
                    xor2 ^= mx;
                    map2[mx]--;
                    if (mxcnt == 1)
                        map2.erase(mx);
                    goto AAA;
                }
                for (auto& p : map2)
                {
                    if ((xor2 ^ p.first) != 0)
                    {
                        xor2 ^= p.first;
                        map2[p.first]--;
                        if (map2[p.first] == 0)
                            map2.erase(p.first);
                        goto AAA;
                    }
                }
                return false;
            }
            AAA:
            sz1--;

            #ifdef __test
            cout<<"AAA : "<<xor2<<"m "<<mx<<", "<<mxcnt<<endl;
            #endif // __test

            // bob
            if (xor2 == 0)
                return false;

            mxcnt = -1;
            mx = -1;
            for (auto& p : map2)
            {
                if (p.second > mxcnt)
                {
                    mxcnt = p.second;
                    mx = p.first;
                }
            }
            if (sz1 % 2 == 0)       // remove not maxcnt
            {
                for (auto& p : map2)
                {
                    if (p.first == mx)
                        continue;
                    if ((xor2 ^ p.first) != 0)
                    {
                        xor2 ^= p.first;
                        map2[p.first]--;
                        if (map2[p.first] == 0)
                        {
                            map2.erase(p.first);
                        }
                        goto BBB;
                    }
                }
                xor2 ^= mx;
                map2[mx]--;
                if (mxcnt == 1)
                    map2.erase(mx);
            }
            else
            {
                if ((xor2 ^ mx) != 0)
                {
                    xor2 ^= mx;
                    map2[mx]--;
                    if (mxcnt == 1)
                        map2.erase(mx);
                    goto BBB;
                }
                for (auto& p : map2)
                {
                    if ((xor2 ^ p.first) != 0)
                    {
                        xor2 ^= p.first;
                        map2[p.first]--;
                        if (map2[p.first] == 0)
                            map2.erase(p.first);
                        goto BBB;
                    }
                }
                return true;
            }
            BBB:
            sz1--;
            #ifdef __test
            cout<<"BBB "<<xor2<<", "<<mx<<", "<<mxcnt<<endl;
            #endif // __test
        }
        return xor2 == 0;
    }

};

int main()
{

    LT0810 lt;

//    myvi v = {1,1,2};
//    myvi v = {2,0};
    myvi v = {1,2,3};

    cout<<lt.lt0810a(v)<<endl;

    return 0;
}
