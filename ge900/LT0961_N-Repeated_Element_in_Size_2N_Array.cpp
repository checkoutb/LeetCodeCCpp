
#include "../header/myheader.h"

class LT0961
{
public:

// D niubi


//Runtime: 68 ms, faster than 87.74% of C++ online submissions for N-Repeated Element in Size 2N Array.
//Memory Usage: 25 MB, less than 40.59% of C++ online submissions for N-Repeated Element in Size 2N Array.
// size [4, 10000]
    int lt0961a(vector<int>& A)
    {
        unordered_set<int> set2;
        for (int i : A)
        {
            if (set2.find(i) != set2.end())
                return i;
            set2.insert(i);
        }
        return -1;
    }

};

int main()
{

    LT0961 lt;


    return 0;
}
