
#include "../header/myheader.h"

class LT1250
{
public:

// D D

//    std::__gcd()

//        int g=nums[0];
//        for(auto x:nums)
//        {
//            g=__gcd(x,g);
//        }

//        int g=0;
//        for(auto i:a){
//            g=__gcd(g,i);
//        }


//return accumulate(nums.begin(), nums.end(), nums[0], gcd<int, int>) == 1;



//Runtime: 52 ms, faster than 55.33% of C++ online submissions for Check If It Is a Good Array.
//Memory Usage: 29.3 MB, less than 71.76% of C++ online submissions for Check If It Is a Good Array.

// 是不是有个奇数就肯定行？ ... 3/6 ...   只要最大公约数是1 ？
// 6 10 15
// 10 15
// ????? hint1：  Eq. ax+by=1 has solution x, y if gcd(a,b) = 1.
// 那么6 10 15 为什么是 true 呢。
// a,b互质的充分必要条件是存在整数x,y使ax+by=1.        互质是公约数只有1的两个整数，叫做互质整数。
// ？？？ gcd==1 <=> 互质 <=> 存在整数xy使得ax+by=1   那么 6 10 15 是什么？ 为什么expected true
// 。。。。。不是 选2个树。。 是 选n个数。。 所以存在gcd=1 就必然true，   但是不存在gcd=1 那么就取3个，4个数。

//n个整数间的裴蜀定理
//设a1,a2,a3......an为n个整数，d是它们的最大公约数，那么存在整数x1......xn使得x1*a1+x2*a2+...xn*an=d。
//特别来说，如果a1...an互质（不是两两互质），那么存在整数x1......xn使得x1*a1+x2*a2+...xn*an=1。证法类似两个数的情况。

// 是整个数组的元素 互质。   就是不停gcd， 用gcd的结果 和下一个元素 继续gcd？

    bool lt1250a(vector<int>& nums)
    {
        if (nums.size() <= 1)
            return nums[0] == 1;
        int g = gcd(nums[0], nums[1]);
        for (int i = 2; i < nums.size() && g != 1; ++i)
        {
            g = gcd(nums[i], g);
        }
        return g == 1;

//        for (int i = 0; i < nums.size(); ++i)
//        {
//            for (int j = i + 1; j < nums.size(); ++j)
//            {
//                if (gcd(nums[i], nums[j]) == 1)
//                    return true;
//            }
//        }
//        return false;

//        for (int i : nums)
//            if (i % 2)
//                return true;
//        return false;
    }
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        if (a < b)
        {
            a += b;
            b = a - b;
            a = a - b;
        }
        int c = a % b;
        return gcd(b, c);
    }

};

int main()
{

    LT1250 lt;

    cout<<lt.gcd(5,12)<<endl;
    cout<<lt.gcd(6,12)<<endl;
    cout<<lt.gcd(3,6)<<endl;

    return 0;
}
