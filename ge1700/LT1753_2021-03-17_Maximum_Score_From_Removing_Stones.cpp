
#include "../header/myheader.h"

class LT1753
{
public:

// D D

//  // preprocess the input to make sure that a > b > c
//  int maximumScore(int a, int b, int c) {
//    if (a < b)
//      return maximumScore(b, a, c);
//    // b <= a
//    if (b < c)
//      return maximumScore(a, c, b);
//    // at this step, a >= b >= c
//    return b == 0 ? 0 : 1 + maximumScore(a - 1, b - 1, c);
//  }

//        int max_p = max(a,max(b,c));
//        int min_p = min(a, min(b,c));
//        int mid_p = (a+b+c)  - max_p - min_p;          // ..

//       while (heap.size()>1) {
//         auto u = heap.top(); heap.pop();
//         auto v = heap.top(); heap.pop();
//         if (--u>0)
//             heap.push(u);
//         if (--v>0)
//             heap.push(v);
//         cnt++;
//       }

//        x, y, z = sorted((a,b,c))
//
//        while x>0 and y>0 and x+y>z:
//            x -= 1
//            y -= 1
//            ans += 1
//        ans += x+y


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Score From Removing Stones.
//Memory Usage: 5.9 MB, less than 42.59% of C++ online submissions for Maximum Score From Removing Stones.
    int lt1753a(int a, int b, int c)
    {
        vector<int> vi = {a,b,c};
        std::sort(std::begin(vi), end(vi));
        a = vi[0];
        b = vi[1];
        c = vi[2];
        if (c >= (a + b))
            return (a + b);
        return (a + b + c) / 2;
    }

};

int main()
{

    LT1753 lt;


    return 0;
}
