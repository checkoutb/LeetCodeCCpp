
#include "../header/myheader.h"

class LT2442
{
public:





//Runtime: 716 ms, faster than 67.84 % of C++ online submissions for Count Number of Distinct Integers After Reverse Operations.
//Memory Usage : 106.5 MB, less than 88.27 % of C++ online submissions for Count Number of Distinct Integers After Reverse Operations.
    int lt2442a(vector<int>& nums)
    {
        unordered_set<int> set2;

        for (int i : nums)
        {
            //if (set2.find(i) != set2.end())           // will wrong
            //{
            //    continue;
            //}
            set2.insert(i);
            int t2 = 0;
            while (i > 0)
            {
                t2 *= 10;
                t2 += (i % 10);
                i /= 10;
            }
            set2.insert(t2);
        }
        return set2.size();
    }

};

int main()
{

    LT2442 lt;

//    myvi v = { 22,22,22 };

    myvi v = { 1,13,10,12,31 };

    cout << lt.lt2442a(v) << endl;

    return 0;
}
