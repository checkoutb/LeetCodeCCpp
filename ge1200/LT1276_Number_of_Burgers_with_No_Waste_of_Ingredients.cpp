
#include "../header/myheader.h"

class LT1276
{
public:


// D D

//        int low = 0; int high = totalNumberBurgers;
//        while (low <= high) {
//            int mid = low + (high - low) / 2;
//
//            int currSlices = mid*4 + (totalNumberBurgers - mid)*2;
//            if (currSlices == tomatoSlices) {
//                return {mid, totalNumberBurgers-mid};
//            }
//
//            if (currSlices < tomatoSlices) {
//                low = mid+1;
//            } else {
//                high = mid-1;
//            }
//        }


//        for (int jumbo = 0; jumbo <= burgers; jumbo++) {
//            int small = burgers - jumbo;
//            if (tomatoSlices == 4*jumbo + 2*small)
//                return {jumbo, small};
//        }

//        if (t % 2 == 0 && c * 2 <= t && t <= c * 4)
//            return {t / 2 - c, c * 2 - t / 2};
//        return {};



//Runtime: 4 ms, faster than 83.04% of C++ online submissions for Number of Burgers with No Waste of Ingredients.
//Memory Usage: 7.8 MB, less than 5.06% of C++ online submissions for Number of Burgers with No Waste of Ingredients.
// 4+1, 2+1
    vector<int> lt1276a(int tomatoSlices, int cheeseSlices)
    {
        if ((tomatoSlices < cheeseSlices * 2) || (tomatoSlices > cheeseSlices * 4) || ((tomatoSlices - cheeseSlices * 2) % 2 != 0))
            return vector<int>();
        int t1 = (tomatoSlices - cheeseSlices * 2) / 2;
        return {t1, cheeseSlices - t1};
    }

};

int main()
{

//    int t{16}, c{7};
//    int t{17}, c{4};
//    int t{0}, c{0};
    int t{2}, c{1};

    LT1276 lt;

    vector<int> v = lt.lt1276a(t, c);

    cout<<" sz: "<<v.size()<<endl;;
    for (int i : v)
        cout<<i<<", ";

    return 0;
}
