
#include "../header/myheader.h"

class LT1561
{
public:

// D D

//        for (unsigned int i = 0; i < piles.size() / 3; ++i)
//            ret += piles[i * 2 + 1];


//return sum(sorted(A)[len(A) / 3::2])




//Runtime: 324 ms, faster than 56.34% of C++ online submissions for Maximum Number of Coins You Can Get.
//Memory Usage: 53.7 MB, less than 64.59% of C++ online submissions for Maximum Number of Coins You Can Get.
    // ..
    int lt1561a(vector<int>& piles)
    {

        int ans = 0;
        sort(begin(piles), end(piles));
        for (int i = piles.size() / 3; i < piles.size(); i += 2)
        {
            ans += piles[i];
        }
        return ans;


        // naive ...
//        int ans = 0;
//        sort(begin(piles), end(piles));
//        for (int i = 1; i < piles.size(); i += 3)
//        {
//            ans += piles[i];
//        }
//        return ans;
    }

};

int main()
{

    LT1561 lt;


    return 0;
}
