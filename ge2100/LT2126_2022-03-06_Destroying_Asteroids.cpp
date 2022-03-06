
#include "../header/myheader.h"

class LT2126
{
public:


// D D


//    sort(begin(a), end(a));
//    return accumulate(begin(a), end(a), mass, [](int m, int a){
//        return m < a ? 0 : min(100000, m + a);
//    });


//Runtime: 325 ms, faster than 47.05% of C++ online submissions for Destroying Asteroids.
//Memory Usage: 102.7 MB, less than 47.90% of C++ online submissions for Destroying Asteroids.
    bool lt2126a(int mass, vector<int>& asteroids)
    {
        long mas2 = mass;
        std::sort(begin(asteroids), end(asteroids));
        for (int i = 0; i < asteroids.size(); ++i)
        {
            if (mas2 < asteroids[i])
            {
                return false;
            }
            else
            {
                mas2 += asteroids[i];
            }
        }
        return true;
    }

};

int main()
{

    LT2126 lt;


    return 0;
}
