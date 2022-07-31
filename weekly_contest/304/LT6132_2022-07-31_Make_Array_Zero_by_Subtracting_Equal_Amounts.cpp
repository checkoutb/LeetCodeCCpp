
#include "../../header/myheader.h"

class LT6132
{
public:



    // AC
    int minimumOperations(vector<int>& nums)
    {
        unordered_set<int> set2;
        for (int i : nums)
        {
            if (i != 0)
                set2.insert(i);
        }
        return set2.size();
    }

};

int main()
{

    LT6132 lt;


    return 0;
}
