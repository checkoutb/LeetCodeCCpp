
#include "../header/myheader.h"

class LT0371
{
public:

// deprecated.  写这个发现可以 & 1....
    int lt0371b(int a, int b)
    {
        int result = 0;
        int t2 = 1;
        int i = 1;
        int t1 = 0;
        stack<int> stk1;
        while (i <= 32)
        {
            int ta = a & t2;
            int tb = b & t2;

            #ifdef __test
            cout<<ta<<", "<<tb<<", "<<t1<<endl;
            #endif // __test

            if (ta ^ tb ^ t1)
            {
                stk1.push(1);
            }
            else
            {
                stk1.push(0);
            }
            t1 = ((ta > 0 && tb > 0) || (ta > 0 && t1 > 0) || (tb > 0 && t1 > 0)) ? 1 : 0;
            if (t1 != 0 && (a == 0 && b == 0))
                stk1.push(1);

            t2 <<= 1;
            i++;
        }
        while (!stk1.empty())
        {
            t1 = stk1.top();

            #ifdef __test
            cout<<t1<<".. ";
            #endif // __test

            stk1.pop();
            result = result << 1;
            result = result ^ t1;
        }
        return result;
    }



//
//    int getSum(int a, int b) {
//        if (b == 0) return a;
//        return getSum(a^b, uint(a&b)<<1);
//    }


//      int c;
//      while(b !=0 ) {
//        c = (a&b);
//        a = a ^ b;
//        b = (c)<<1;
//      }
//      return a;

// a ^ b 是不计算进位 后的结果。
// a & b 是 哪些位会生成进位。然后<<1，就是进位。


//Runtime: 4 ms, faster than 95.29% of C++ online submissions for Sum of Two Integers.
//Memory Usage: 8.4 MB, less than 5.05% of C++ online submissions for Sum of Two Integers.

    int lt0371a(int a, int b)
    {
        int result = 0;
        int t1 = 0;
        int f1 = 1;
        stack<int> stk1;
        while (a != 0 || b != 0)
        {
//            int ta = a ^ ((a >> 1) << 1);   // runtime error: left shift of negative value -1...这怎么玩。。
//            int tb = b ^ ((b >> 1) << 1);
            int ta = a & 1;
            int tb = b & 1;

            #ifdef __test
            cout<<ta<<", "<<tb<<", "<<t1<<endl;
            #endif // __test

            if (ta ^ tb ^ t1)
            {
                stk1.push(1);
            }
            else
            {
                stk1.push(0);
            }
            a >>= 1;
            b >>= 1;
            t1 = ((ta > 0 && tb > 0) || (ta > 0 && t1 > 0) || (tb > 0 && t1 > 0)) ? 1 : 0;
            if (t1 != 0 && (a == 0 && b == 0))
                stk1.push(1);

            if (f1 <= 0)
                break;
            f1 = f1 << 1;
        }
        while (!stk1.empty())
        {
            t1 = stk1.top();

            #ifdef __test
            cout<<t1<<".. ";
            #endif // __test

            stk1.pop();
            result = result << 1;
            result = result ^ t1;
        }
        return result;
    }
};

int main()
{
    LT0371 lt;
    cout<<endl<<lt.lt0371a(4,1)<<endl;

//    cout<<endl<<(-1 >> 1)<<endl;
    return 0;
}
