
#include "../header/myheader.h"

class LT2347
{
public:

    // D D




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Best Poker Hand.
//Memory Usage: 10 MB, less than 50.00% of C++ online submissions for Best Poker Hand.
    string lt2347a(vector<int>& ranks, vector<char>& suits)
    {
        if (suits[0] == suits[1] && suits[1] == suits[2] && suits[2] == suits[3] && suits[3] == suits[4])
            return "Flush";

        unordered_map<int, int> map2;

        for (int i : ranks)
            map2[i]++;

        int arr[10] = {0};

        for (pair<const int, int>& p : map2)
        {
            arr[p.second]++;
        }

        for (int i = 5; i >= 2; --i)
        {
            if (arr[i] > 0)
            {
                switch(i)
                {
                case 5:
                case 4:
                case 3:
                    return "Three of a Kind";
                case 2:
                    return "Pair";
                }
            }
        }
        return "High Card";
    }

};

int main()
{

    LT2347 lt;

    myvi v = {4,4,2,4,4};
    vector<char> vs = {'d','a','a','b','c'};

    cout<<lt.lt2347a(v, vs)<<endl;

    return 0;
}
