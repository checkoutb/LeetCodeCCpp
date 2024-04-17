
#include "../header/myheader.h"

class LT1996
{
public:


    // D D



// Runtime
// 394ms
// Beats32.37%of users with C++
// Memory
// 128.63MB
// Beats60.26%of users with C++

    // both >
    int numberOfWeakCharacters(vector<vector<int>>& properties)
    {
        std::sort(std::begin(properties), std::end(properties), [](const vector<int>& v1, const vector<int>& v2){
            if (v1[0] == v2[0])
                return v1[1] > v2[1];
            return v1[0] < v2[0];
        });

        int ans = 0;
        int mxDef = -1;
        for (int i = properties.size() - 1; i >= 0; --i)
        {
            if (properties[i][1] < mxDef)
                ++ans;
            else
                mxDef = properties[i][1];
        }
        return ans;
    }

};

int main()
{

    LT1996 lt;


    return 0;
}
