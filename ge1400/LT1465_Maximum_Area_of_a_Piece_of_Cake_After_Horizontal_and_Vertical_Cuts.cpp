
#include "../header/myheader.h"

class LT1465
{
public:

// D D





//Runtime: 168 ms, faster than 71.12% of C++ online submissions for Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts.
//Memory Usage: 32.7 MB, less than 17.33% of C++ online submissions for Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts.
    int lt1465a(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
    {
        sort(begin(horizontalCuts), end(horizontalCuts));
        sort(begin(verticalCuts), end(verticalCuts));
        int mxh = max(horizontalCuts[0], h - horizontalCuts[horizontalCuts.size() - 1]);
        int mxv = max(verticalCuts[0], w - verticalCuts[verticalCuts.size() - 1]);
        for (int i = 1; i < horizontalCuts.size(); ++i)
        {
            mxh = max(mxh, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < verticalCuts.size(); ++i)
            mxv = max(mxv, verticalCuts[i] - verticalCuts[i - 1]);
        int ans = (int) (((long) mxh * mxv) % 1000000007);
        return ans;
    }

};

int main()
{

    LT1465 lt;


    return 0;
}
