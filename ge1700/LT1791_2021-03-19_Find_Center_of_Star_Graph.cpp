
#include "../header/myheader.h"

class LT1791
{
public:

// D D

//return e[0][0] == e[1][0] || e[0][0] == e[1][1] ? e[0][0] : e[0][1];



//Runtime: 200 ms, faster than 100.00% of C++ online submissions for Find Center of Star Graph.
//Memory Usage: 67.3 MB, less than 100.00% of C++ online submissions for Find Center of Star Graph.
// ...
    int lt1791a(vector<vector<int>>& edges)
    {
        vector<int> vi{edges[0][0], edges[0][1], edges[1][0], edges[1][1]};
        std::sort(vi.begin(), vi.end());
        for (int i = 1; i < 4; ++i)
        {
            if (vi[i] == vi[i - 1])
                return vi[i];
        }
        return -1;
    }

};

int main()
{

    LT1791 lt;


    return 0;
}
