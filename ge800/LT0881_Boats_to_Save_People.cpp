
#include "../header/myheader.h"

class LT0881
{
public:

// D D
//        while (i <= j) {
//            nB++;
//            if (people[i] + people[j] <= limit)
//                i++;
//            j--;
//        }

//        int i, j;
//        sort(people.rbegin(), people.rend());
//        for (i = 0, j = people.size() - 1; i <= j; ++i)
//            if (people[i] + people[j] <= limit) j--;
//        return i;
// j--, 限制了 i.


//Runtime: 296 ms, faster than 45.42% of C++ online submissions for Boats to Save People.
//Memory Usage: 42.1 MB, less than 22.97% of C++ online submissions for Boats to Save People.
// greedy?
    int lt0881a(vector<int>& people, int limit)
    {
        std::sort(begin(people), end(people));
        int ans = 0;
        int l = 0;
        int r = people.size() - 1;

        while (l <= r)
        {
            int p1 = people[l];
            l++;
            while (r >= l)
            {
                if (p1 + people[r] <= limit)
                {
                    r--;
//                    ans++;
                    break;
                }
                else
                {
                    r--;
                    ans++;
                }
            }
            ans++;
        }

        return ans;
    }

};

int main()
{

    vector<int> p = {3,5,3,4};
    int lmt = 5;

//    vector<int> p = {3,2,2,1};
//    int lmt = 3;

//    vector<int> p = {1,2};
//    int lmt = 3;

    LT0881 lt;

    cout<<lt.lt0881a(p, lmt)<<endl;

    return 0;
}
