
#include "../header/myheader.h"

class LT1725
{
public:

// D D





//Runtime: 40 ms, faster than 85.44% of C++ online submissions for Number Of Rectangles That Can Form The Largest Square.
//Memory Usage: 18.3 MB, less than 76.75% of C++ online submissions for Number Of Rectangles That Can Form The Largest Square.
    int lt1725a(vector<vector<int>>& rectangles)
    {
        int mxlen = 0;
        int mxcnt = 0;
        for (vector<int>& vi : rectangles)
        {
            int len = min(vi[0], vi[1]);
            if (len > mxlen)
            {
                mxlen = len;
                mxcnt = 1;
            }
            else if (len == mxlen)
                mxcnt++;
        }
        return mxcnt;

//        map<int, int> map2;
//        for (vector<int>& vi : rectangles)
//        {
//            map2[]
//        }
    }

};

int main()
{

    LT1725 lt;


    return 0;
}
