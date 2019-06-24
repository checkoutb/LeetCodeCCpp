
#include "../header/myheader.h"

class LT0389
{
public:


// discuss
//    int elem(int n,bool isleft)
//    {
//        if(n==1) return 1;
//        if(isleft==false && n%2==0)
//        {
//            return elem(n/2,!isleft)*2-1;
//        }
//        else
//            return elem(n/2,!isleft)*2;
//    }
//    int lastRemaining(int n) {
//        bool isleft=true;
//        return elem(n,isleft);
//    }

//        int rest = n, head = 1, step = 1;
//        bool left = true;
//        while(rest > 1){
//            if(left || rest % 2 == 1) head = head + step;
//            step *= 2;
//            rest /= 2;
//            left = !left;
//        }
//        return head;
// 简化版，毕竟返回s，所以只需要判断s的位置就可以了。

//        int time=1,rem,left=1,right=n;
//        bool dir=true;
//        while(left<right){
//            time*=2;
//            if(dir){
//                rem=left%time;
//                left+=time/2;
//                if(right%time==rem){
//                    right-=time/2;
//                }
//            }
//            else{
//                rem=right%time;
//                right-=time/2;
//                if(left%time==rem){
//                    left+=time/2;
//                }
//            }
//            dir=!dir;
//        }
//        return left;
// 这个和我一样，但是20ms里的。。



// discuss

//    int lastRemaining(int n) {
//        return recursion(n, true);
//    }
//    // return the left number of 1 - n starting from eliminting left to right
//    int recursion(int n, bool isLeft) {
//        if(n == 1) return n;
//        if(!isLeft && (n % 2) == 0) {
//            // eliminate all the even numbers
//            // [1, 2, 3, 4, 5, 6] -> [1, 3, 5]
//            // It is equivalent to consider the number left in [1, 2, 3] * 2 - 1
//            return recursion(n / 2, !isLeft) * 2 - 1;
//        } else {
//            // eliminate all the odd numbers
//            // [1, 2, 3, 4, 5, 6] -> [2, 4, 6]
//            // It is equivalent to consider the number left in [1, 2, 3] * 2
//            return recursion(n / 2, !isLeft) * 2;
//        }
//    }


//int lastRemaining(int n) {
//    return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
//}

//    int lastRemaining(int n) {
//        if (n == 1) return 1;
//        if (n <= 4) return 2;
//        if (n % 2 != 0) n -= 1;
//        if (n % 4 != 0) return 4 * lastRemaining(n/4);
//        return 4 * lastRemaining(n/4) - 2;
//    }
// if n is an odd number, then f(1..n) = f(1..n-1), because after the first round elimination, the last odd number will be removed.
// f(1..12) = f(2,6,10) = 2* f(1,3,5) = 2* [f(2,4,6) - 1] = 2 * [2f(1,2,3) - 1] = 4f(1..3) - 2;
// 10. first=> 2,4,6,8,10, second => 4, 8 => f(10) = 4*f(1..2) => f(n) = 4f(n/4)





//Runtime: 4 ms, faster than 94.92% of C++ online submissions for Elimination Game.
//Memory Usage: 8.2 MB, less than 60.77% of C++ online submissions for Elimination Game.

// 文章本天成。
    // 头尾2个指针。配合t1，怎么结束。
    int lt0389b(int n)
    {
        int s = 1;
        int e = n;
        int t1 = 2;
        bool flag1 = true;
        while(s < e)
        {
            #ifdef __test
            cout<<s<<" , "<<e<<", "<<t1<<endl;
            system("pause");
            #endif // __test

            if (flag1)
            {
                if ((e - s) % t1 == 0)
                {
                    e -= (t1 / 2);
                }
                s += (t1 / 2);
            }
            else
            {
                if ((e - s) % t1 == 0)
                {
                    s += (t1 / 2);
                }
                e -= (t1 / 2);
            }
            flag1 = !flag1;
            t1 *= 2;
        }
        #ifdef __test
        cout<<s<<", "<<e<<endl;
        #endif // __test
        return s;
    }


    // 似乎是每次都是一个隔一个的remove，从左至右，从右至左。
    // 间隔应该是2，4，8，16，32

    // 3375 / 3377      100000000   stack-overflow
    int lt0389a(int n)
    {
        int r = 0;
        int i = 0;
        int t1 = 2;
        bool flag1 = true;
        bool arr2[n + 1] = {false};
        while (i < n - 1)           // n - 1..
        {

            #ifdef __test
//            cout<<i<<endl;
//            system("pause");
//            for(bool b : arr2)
//            {
//                cout<<b<<", ";
//            }
//            cout<<endl;
            #endif // __test

            // left -> right
            if (flag1)
            {
                int j = 1;
                for (; j <= n; j++)         // 可以记录上一次的起始，然后本次继续用。
                {
                    if (!arr2[j])
                    {
                        break;
                    }
                }

                while (i < n - 1 && j <= n)
                {
                    i++;
                    arr2[j] = true;
                    j += t1;
                }
            }
            else        // right -> left
            {
                int j = n;
                while (j >= 1)
                {
                    if (!arr2[j])
                        break;
                    j--;
                }
                while (j >= 1 && i < n - 1)
                {
                    i++;
                    arr2[j] = true;
                    j -= t1;
                }
            }
            flag1 = !flag1;
            t1 *= 2;
        }
        #ifdef __test
//        cout<<"...  "<<i<<endl;
        #endif // __test

        for (int j = 1; j <= n; j++)
        {
            #ifdef __test
//            cout<<arr2[j]<<endl;
            #endif // __test

            if (!arr2[j])
            {
                r = j;
                break;
            }
        }
        return r;
    }
};

int main()
{
    int n = 9;

    LT0389 lt;
    cout<<lt.lt0389b(n)<<endl;

    return 0;
}
