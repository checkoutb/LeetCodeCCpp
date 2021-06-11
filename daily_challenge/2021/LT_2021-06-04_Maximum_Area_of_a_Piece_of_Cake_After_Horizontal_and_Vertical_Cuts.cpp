
#include "../../header/myheader.h"

class LT
{
public:

// D D

//maxStripHeight = max([verticalStrips[i + 1] - verticalStrips[i] for i in range(len(verticalStrips) - 1)])



// AC .. 1E9 + 7 shi double...
// 一个横向最大间距，一个纵向最大间距， 0 & h/w
    int lta(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
    {
        std::sort(begin(horizontalCuts), end(horizontalCuts));
        sort(begin(verticalCuts), end(verticalCuts));
        int mxh = max(horizontalCuts[0], h - horizontalCuts[horizontalCuts.size() - 1]);
        int mxv = std::max(verticalCuts[0], w - verticalCuts[verticalCuts.size() - 1]);
        for (int i = 1; i < horizontalCuts.size(); ++i)
        {
            mxh = max(mxh, horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        for (int i = 1; i < verticalCuts.size(); ++i)
        {
            mxv = max(mxv, verticalCuts[i] - verticalCuts[i - 1]);
        }
        #ifdef __test
        cout<<mxh<<", "<<mxv<<endl;
        #endif // __test
        return 1L * mxh * mxv % ((int) 1E9 + 7);
    }

};

int main()
{
    int h = 5;
    int w = 4;
    myvi v1 = {1,2,4};
    myvi v2 = {1,3};


    LT lt;

    cout<<lt.lta(h, w, v1, v2)<<endl;

    return 0;
}
