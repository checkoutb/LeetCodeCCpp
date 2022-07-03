
#include "../../header/myheader.h"

class LT
{
public:

    // D D




//Runtime: 74 ms, faster than 96.68 % of C++ online submissions for Maximum Area of a Piece of Cake After Horizontaland Vertical Cuts.
//Memory Usage : 32.3 MB, less than 76.96 % of C++ online submissions for Maximum Area of a Piece of Cake After Horizontaland Vertical Cuts.
    // ? 感觉就是 水平最大gap * 垂直最大gap 啊。
    int lta(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
    {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(begin(horizontalCuts), end(horizontalCuts));
        sort(begin(verticalCuts), end(verticalCuts));

        int mxh = 0;
        int mxw = 0;

        for (int i = 1; i < horizontalCuts.size(); ++i)
        {
            mxh = max(mxh, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < verticalCuts.size(); ++i)
            mxw = max(mxw, verticalCuts[i] - verticalCuts[i - 1]);

#ifdef __test
        cout << mxh << ", " << mxw << endl;
#endif

        return (1LL * mxh * mxw) % 1000000007;

    }

};

int main()
{

    LT lt;

    //int h = 5;
    //int w = 4;
    //myvi v = { 1,2,4 };
    //myvi v2 = { 1,3 };

    int h = 1000000000;         // 81
    int w = 1000000000;
    myvi v = { 2 };
    myvi v2 = { 2 };

    cout << 1000000009 << endl << (int)(1e9 + 7) << endl;

    cout << lt.lta(h, w, v, v2) << endl;

    return 0;
}
