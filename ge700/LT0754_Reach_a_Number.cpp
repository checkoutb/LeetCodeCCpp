
#include "../header/myheader.h"

class LT0754
{
public:



// discuss
//        target = Math.abs(target);
//        int step = 0;
//        int sum = 0;
//        while (sum < target) {
//            step++;
//            sum += step;
//        }
//        while ((sum - target) % 2 != 0) {
//            step++;
//            sum += step;
//        }
//        return step;




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reach a Number.
//Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Reach a Number.


// 1 2 3 4 -5 == 5....

// diff % 2 == 0?
    int lt0754b(int target)
    {
        target = abs(target);
        float f1 = sqrt(1.0 / 4 + 2 * target) - 0.5;            // 10^9.....  8.0 * target ...
        #ifdef __test
        cout<<f1<<endl;
        #endif // __test
        int cnt = ceil(f1);
        int sum = (1 + cnt) * cnt / 2;
//        cout<<sum<<", "<<target<<", "<<f1<<endl;
//        if ((sum - target) > f1)
//            cnt++;
        return (sum - target) % 2 ? (sum - target) % 2 == (cnt + 1) % 2 ? cnt + 1 : cnt + 2 : cnt;
    }


// ....  1+2-3+4+5 == 9...... 就是max1超过target，然后+1。。。。毕竟max1,target的差距肯定是在[1, max1]中啊。。
// -1+2 == 1,   -3+4 == 1,   感觉是 先-1-2-3...负数 然后+10+11+12...正数。 逼近target，剩下的就只能靠 +n-(n-1) 或 -n+(n+1) 一步步逼近了。
// target < 0 ... 10^9 * 2 < INT_MAX..(n+1)*n/2=tar  n^2 + n - tar*2 = 0;    (-1 +- sqrt(1 - 4*(-tar*2))) / 2
// tar<0 : tar = -tar;    -0.5 +- sqrt(1+8*tar)/2
//
    int lt0754a(int target)
    {
        target = std::abs(target);
        float f1 = std::sqrt(1 + 8 * target) / 2.0 - 0.5;
        int cnt = std::ceil(f1);
        int max2 = (1 + cnt) * cnt / 2;
        int max1 = max2;
        int diff = max2 - target;
        int diff1 = diff;
        int ans = std::floor(f1);
        int m1 = (1 + ans) * ans / 2;
        ans += (target - m1) * 2;

        #ifdef __test
        cout<<"a : "<<floor(f1)<<", "<<ans<<", "<<m1<<endl;
        cout<<f1<<", "<<cnt<<", "<<max1<<endl;
        #endif // __test

        int i = 1;
        while (diff >= 0)
        {
            max1 = max2;
            diff1 = diff;
            max2 -= (2 * i);
            diff = max2 - target;
            i++;
        }
        cnt += std::min(max1 - target + diff1, target - max2 - diff);           // abs(diff) * 2

        #ifdef __test
        cout<<max1<<", "<<target<<", "<<diff1<<", ||| "<<target<<","<<max2<<","<<diff<<endl;
        cout<<"                  ans: ";
        #endif // __test

        ans = std::min(ans, cnt);
        return ans;
    }

};

int main()
{

    int targets[] = {3, 2, 5, 9, 4};

    LT0754 lt;

    for (int tar : targets)
    {
        cout<<"                 input: "<<tar<<endl;
        cout<<lt.lt0754b(tar)<<endl;
    }

    return 0;
}
