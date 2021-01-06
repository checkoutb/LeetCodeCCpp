
#include "../header/myheader.h"

class LT1237
{
public:

// D D

//                int fRes = customfunction.f(x, y);
//                if (fRes == z) {
//                    result.push_back({x, y});
//                } else if (fRes > z) {
//                    break;
//                }



//        for (int x = 1; x <= 1000; ++x) {
//            while (y > 1 && customfunction.f(x,y) > z) y--;
//            if (customfunction.f(x,y) == z)
//                res.push_back({x, y});
//        }


//        for (int x = 1; x <= 1000; ++x) { // upper limit is 1000
//            int low = 1, high = 1001;
//            while (low < high) {
//                int mid = (low + high) / 2;
//                if (customfunction.f(x, mid) < z) {
//                    low = mid + 1;
//                } else {
//                    high = mid;
//                }
//            }
//            if (customfunction.f(x, low) == z)
//                result.add(Arrays.asList(x, low));
//        }


//The function is constantly increasing, i.e.:
//    f(x, y) < f(x + 1, y)
//    f(x, y) < f(x, y + 1)


//Runtime: 140 ms, faster than 16.73% of C++ online submissions for Find Positive Integer Solution for a Given Equation.
//Memory Usage: 6.6 MB, less than 61.90% of C++ online submissions for Find Positive Integer Solution for a Given Equation.
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z)
    {
        vector<vector<int>> ans;
        for (int i = 1; i <= 1000; ++i)
        {
            for (int j = 1; j <= 1000; ++j)
            {
                if (customfunction.f(i, j) == z)
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT1237 lt;


    return 0;
}
