
#include "../header/myheader.h"

class LT1296
{
public:

// D D



//Runtime: 372 ms, faster than 65.82% of C++ online submissions for Divide Array in Sets of K Consecutive Numbers.
//Memory Usage: 50.2 MB, less than 23.05% of C++ online submissions for Divide Array in Sets of K Consecutive Numbers.
    bool lt1296a(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        if (sz1 % k != 0)
            return false;

        map<int, int> map2;
        for (int n : nums)
            map2[n]++;
        for (map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            int v = it->second;
            if (v == 0)
                continue;
            if (v < 0)
                return false;

            int ke = it->first;
            for (int i = 1; i < k; ++i)
            {
                if (map2.find(ke + i) == map2.end())
                    return false;

                map2[ke + i] -= v;
            }
        }
        return true;
    }

};

int main()
{

//    vector<int> v = {1,2,3,3,4,4,5,6};
//    int k = 4;

    vector<int> v = {3,2,1,2,3,4,3,4,5,9,10,11};
    int k = 3;

    LT1296 lt;

    cout<<lt.lt1296a(v, k);

    return 0;
}
