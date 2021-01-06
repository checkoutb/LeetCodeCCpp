
#include "../header/myheader.h"

class LT1033
{
public:

// D D

//int mx = max({ a, b, c }), mn = min({ a, b, c }), mid = a + b + c - mx - mn;


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Moving Stones Until Consecutive.
//Memory Usage: 6.6 MB, less than 66.87% of C++ online submissions for Moving Stones Until Consecutive.
// 最少，最多2步。 最多就是 内部空格数。
    vector<int> lt1033a(int a, int b, int c)
    {
        vector<int> vi = {a,b,c};
        sort(begin(vi), end(vi));
        return {(max(vi[1] - vi[0], vi[2] - vi[1]) == 1) ? 0 : (vi[1] - vi[0] <= 2 || vi[2] - vi[1] <= 2) ? 1 : 2, vi[2] - vi[0] - 2};
    }

};

int main()
{
//    int a{1},b{2},c{5};
    int a{2},b{3},c{4};
//    int a{3},b{5},c{1};

    cout<<" : "<<max({1,11,4,2,5,2})<<endl;

    LT1033 lt;

    vector<int> vi = lt.lt1033a(a,b,c);
    cout<<vi[0]<<" : "<<vi[1];

    return 0;
}
