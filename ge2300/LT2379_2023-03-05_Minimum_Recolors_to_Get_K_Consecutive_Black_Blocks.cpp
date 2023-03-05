
#include "../header/myheader.h"

class LT2379
{
public:







    //Runtime4 ms
    //    Beats
    //    42.71 %
    //    Memory6.1 MB
    //    Beats
    //    67.91 %
    int lt2379a(string blocks, int k)
    {
        int sz1 = blocks.size();
        int cntw = 0;
        
        for (int i = 0; i < k; ++i)
            cntw += blocks[i] == 'W';

        //int ans = min(cntw, k - cntw);
        int ans = cntw;

        for (int i = k; i < sz1; ++i)
        {
            cntw += (blocks[i] == 'W') - (blocks[i - k] == 'W');
            //ans = min(ans, min(cntw, k - cntw));
            ans = min(ans, cntw);
        }
        return ans;
    }

};

int main()
{

    LT2379 lt;

    string s = "WBWBBBW";
    int k = 2;

    cout << lt.lt2379a(s, k) << endl;

    return 0;
}
