
#include "../header/myheader.h"

class LT3160
{
public:

    // D D

    





// Runtime
// 452ms
// Beats41.62%of users with C++
// Memory
// 157.75MB
// Beats60.62%of users with C++
    // x y
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        std::map<int, int> map2, map3; // <ball, color>, <color, count>
        int szq = queries.size();
        std::vector<int> vi(szq);
        int ball, color, oldc;
        for (int i = 0; i < szq; ++i) {
            ball = queries[i][0];
            color = queries[i][1];
            if (map2.contains(ball)) {
                oldc = map2[ball];
                if (oldc != color) {
                    if (map3[oldc] == 1) {
                        map3.erase(oldc);
                    } else {
                        --map3[oldc];
                    }
                    map2[ball] = color;
                    ++map3[color];
                }
            } else {
                map2[ball] = color;
                ++map3[color];
            }
            vi[i] = map3.size();
        }
        return vi;
    }


};

int main()
{

    LT3160 lt;


    return 0;
}
