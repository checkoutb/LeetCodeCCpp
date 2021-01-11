
#include "../header/myheader.h"

class LT0991
{
public:

// D D

//        while(x<y){
//             if( y&1){
//                 y+=1;
//             }
//            else{
//                y/=2;
//            }
//            ans++;
//        }
//        return ans+(x-y);


//        int res = 0;
//        while (Y > X) {
//            Y = Y % 2 > 0 ? Y + 1 : Y / 2;
//            res++;
//        }
//        return res + X - Y;


//return X >= Y ? X - Y : 1 + Y % 2 + brokenCalc(X, (Y + 1) / 2);


//        int multiple = 1, res = 0;
//        while (X * multiple < Y)
//            multiple <<= 1, res++;
//        int diff = X * multiple - Y;
//        while (diff > 0) {
//            res += diff / multiple;
//            diff -= diff / multiple * multiple;
//            multiple >>= 1;
//        }
//        return res;



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Broken Calculator.
//Memory Usage: 6.1 MB, less than 99.67% of C++ online submissions for Broken Calculator.
    int lt0991b(int X, int Y)
    {
        if (Y < X)
            return X - Y;
        int cnt = 0;
        int y2 = Y;
        while (Y > X)
        {
            y2 = Y;
            if (Y % 2 == 0)
            {
                Y /= 2;
            }
            else
            {
                Y++;
            }
            cnt++;
        }
        int t1 = cnt;
        if (Y != X)
        {
            t1 = cnt + (X - Y);
//            int t2 = cnt + ();
        }
        return t1;
    }

// 难道是 优先/2. 不能就++ ，然后继续 尝试/2 。。 好像是的。
// 1 14      1-2-4-8-16-15-14       1-2-4-8-7-14     。。。
// 感觉是优先 *2, 然后看 大于Y的最小值  和 小于Y的最大值
// 1 10000000 tle
    int lt0991a(int X, int Y)
    {
        if (Y < X)
            return X - Y;
        queue<int> que1;
        unordered_set<int> set2;
        que1.push(X);
        set2.insert(X);
        int ans = 0;
        while (true)
        {
            int sz1 = que1.size();
            while (sz1-- > 0)
            {
                int t2 = que1.front();
                que1.pop();
                if (t2 == Y)
                    goto AAA;
                int t4 = t2 - 1;
                int t5 = t2 * 2;
                if (set2.find(t4) == set2.end())
                {
                    set2.insert(t4);
                    que1.push(t4);
                }
                if (set2.insert(t5).second == true)
                {
                    que1.push(t5);
                }
            }
            ans++;
        }
        AAA:
        return ans;
    }

};

int main()
{
//    int x{2}, y{3};
//    int x{5}, y{8};
//    int x{3}, y{10};
//    int x{1024}, y{1};
//    int x{1}, y{1024};
    int x{1}, y{14};

    LT0991 lt;

    cout<<lt.lt0991b(x,y);

    return 0;
}
