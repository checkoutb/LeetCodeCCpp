
#include "../header/myheader.h"

class LT1742
{
public:

// D D

// int [] 也可以 begin(xx),end(xx)


//            while (digits % 10 == 0) { // for ball numbers with trailing 0's, decrease 9 for each 0.
//                id -= 9;
//                digits /= 10;
//            }






//Runtime: 4 ms, faster than 99.62% of C++ online submissions for Maximum Number of Balls in a Box.
//Memory Usage: 5.9 MB, less than 79.75% of C++ online submissions for Maximum Number of Balls in a Box.
// 1  2  3  4  5  6  7  8  9
// 10 11 12 13             18 19
//    20 21 22 23          27 28 29
//       30
//                         90 91 92
// 100 101
//    110
// 10个一轮。
// 10^5  99999 = 45
    int lt1742a(int lowLimit, int highLimit)
    {
//        unordered_map<int, int> map2;
        int arr[50] = {0};
        int t2 = 0;
        int t3 = lowLimit;
        while (t3 > 0)
        {
            t2 += t3 % 10;
            t3 /= 10;
        }
//        while (lowLimit < highLimit / 10 * 10)
        while (lowLimit % 10 != 0)
        {
            arr[t2]++;
//            map2[]++;
            lowLimit++;
            t2++;
        }
//        t3 =
//        while (t3)
        while (lowLimit <= highLimit)
        {
            if (lowLimit % 10 == 0)
                for (t2 = 0, t3 = lowLimit; t3 > 0; t3 /= 10)
                {
                    t2 += t3 % 10;
                }
            lowLimit++;
            arr[t2++]++;
        }
        int ans = 0;
        for (int i = 0; i < 50; ++i)
        {
            if (arr[i] > ans)
                ans = arr[i];
        }
        return ans;
//        return *ma
//        for (int i = 0; i )
//        #ifdef __test
//        for ()
//        #endif // __test
//        int mx = 1;
//        int cnt = 0;
//        for (int i = 0; i < 50; ++i)
//        {
//            #ifdef __test
//            cout<<i<<", "<<arr[i]<<", "<<mx<<endl;
//            #endif // __test
//            if (arr[i] > mx)
//            {
//                mx = arr[i];
//                cnt = 1;
//            }
//            else if (arr[i] == mx)
//                cnt++;
//        }
//        return cnt;
    }

};

int main()
{

//    myvi v = {1,10};
//    myvi v = {5,15};
//    myvi v = {19,28};
    myvi v = {11,104};

    LT1742 lt;

    cout<<lt.lt1742a(v[0], v[1]);

    return 0;
}
