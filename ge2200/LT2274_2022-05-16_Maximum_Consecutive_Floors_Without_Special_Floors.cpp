
#include "../header/myheader.h"

class LT2274
{
public:

// D D

//special.insert(end(special), {bottom - 1, top + 1});


//res = max(A[0] - bottom, top - A[n - 1]);


//return max({res, special[0]-bottom, top-special[n-1]});




//Runtime: 284 ms, faster than 25.00% of C++ online submissions for Maximum Consecutive Floors Without Special Floors.
//Memory Usage: 57.9 MB, less than 100.00% of C++ online submissions for Maximum Consecutive Floors Without Special Floors.
    int lt2274a(int bottom, int top, vector<int>& special)
    {
        special.push_back(bottom - 1);
        special.push_back(top + 1);
        std::sort(begin(special), end(special));
        int ans = 0;
        for (int i = 1; i < special.size(); ++i)
        {
            ans = max(ans, special[i] - special[i - 1] - 1);
        }
        return ans;
    }

};

int main()
{

    LT2274 lt;


    return 0;
}
