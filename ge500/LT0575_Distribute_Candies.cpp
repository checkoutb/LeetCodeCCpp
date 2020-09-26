
#include "../header/myheader.h"

class LT0575
{
public:


// D D

//return min(unordered_set<int>(begin(c), end(c)).size(), c.size() / 2);

//        sort(candies.begin(), candies.end());
//        for (int i = 0; i < candies.size(); i++) {
//            kinds += candies[i] != candies[i - 1];
//        }



//Runtime: 456 ms, faster than 95.64% of C++ online submissions for Distribute Candies.
//Memory Usage: 116.4 MB, less than 38.42% of C++ online submissions for Distribute Candies.
    int lt0575a(vector<int>& candies)
    {
        unordered_set<int> set1;
        for (int type : candies)
        {
            set1.insert(type);
        }
        return set1.size() > candies.size() / 2 ? candies.size() / 2 : set1.size();
    }

};

int main()
{

    LT0575 lt;


    return 0;
}
