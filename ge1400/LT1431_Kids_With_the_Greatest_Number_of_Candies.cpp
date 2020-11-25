
#include "../header/myheader.h"

class LT1431
{
public:

// D D



//Runtime: 4 ms, faster than 80.01% of C++ online submissions for Kids With the Greatest Number of Candies.
//Memory Usage: 9.2 MB, less than 62.30% of C++ online submissions for Kids With the Greatest Number of Candies.
    vector<bool> lt1431a(vector<int>& candies, int extraCandies)
    {
        int mx = *std::max_element(begin(candies), end(candies));
        vector<bool> ans(candies.size());
        for (int i = 0; i < ans.size(); ++i)
        {
            ans[i] = (candies[i] + extraCandies >= mx);
        }
        return ans;
    }

};

int main()
{
//    vector<int> v = {2,3,5,1,3};
//    int e{3};

//    vector<int> v = {4,2,1,1,2};
//    int e{1};

    vector<int> v = {12,1,12};
    int e{10};

    LT1431 lt;

    vector<bool> ans = lt.lt1431a(v, e);
    for (bool b : ans)
        cout<<b<<", ";

    return 0;
}
