
#include "../header/myheader.h"

class LT0875
{
public:


// gg...
// 好像只是 ceil(sum/cnt) ？
// 不， she chooses some pile of bananas -> choose one pile of ...   也是 pile.. 不加s。。
//
    int lt0875a(vector<int>& piles, int H)
    {
        int ans = 0;
        std::sort(begin(piles), end(piles), std::greater<int>());

        ans = piles[0];
        H -= piles.size();

        while (H > 0)
        {

        }


        return ans;

    }

};

int main()
{

    vector<int> v = {3,6,7,11};
    int h = 8;

    LT0875 lt;

    cout<<lt.lt0875a(v, h)<<endl;

    return 0;
}
