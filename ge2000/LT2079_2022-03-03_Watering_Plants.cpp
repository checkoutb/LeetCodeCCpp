
#include "../header/myheader.h"

class LT2079
{
public:

// D D

//    for (int i = 0; i < p.size(); ++i) {
//        if (can < p[i]) {
//            res += i * 2;
//            can = capacity;
//        }
//        can -= p[i];
//    }
//    return res + p.size();


//Runtime: 4 ms, faster than 76.71% of C++ online submissions for Watering Plants.
//Memory Usage: 8.5 MB, less than 46.96% of C++ online submissions for Watering Plants.
// 硬算
    int lt2079a(vector<int>& plants, int capacity)
    {
        int ans = 0;
        int wat = capacity;
        for (int i = 0; i < plants.size(); ++i)
        {
            if (wat >= plants[i])
            {
                wat -= plants[i];
                ans++;
            }
            else
            {
                ans += i * 2;
                wat = capacity;
                --i;
            }
        }
        return ans;
    }

};

int main()
{

    LT2079 lt;

//    myvi v = {2,2,3,3};
//    int t = 5;

//    myvi v = {1,1,1,4,2,3};
//    int t = 4;

    myvi v = {7,7,7,7,7,7,7};
    int t = 11;

    cout<<lt.lt2079a(v, t)<<endl;

    return 0;
}
