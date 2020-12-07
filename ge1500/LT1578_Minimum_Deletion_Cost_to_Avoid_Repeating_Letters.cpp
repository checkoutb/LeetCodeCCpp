
#include "../header/myheader.h"

class LT1578
{
public:

// D D

//        for (int x = 1; x < s.size(); x++) {
//            if (s[x] == s[x-1]) {
//                ret += std::min(cost[x], cost[x-1]);
//                cost[x] = std::max(cost[x], cost[x-1]);
//            }
//        }


//        for (int i = 0; i < n; ++i) {
//            if (i > 0 && s[i] != s[i - 1])
//                max_cost = 0;
//            res += min(max_cost, cost[i]);
//            max_cost = max(max_cost, cost[i]);
//        }




// 260 - 300 ms
//Runtime: 512 ms, faster than 7.84% of C++ online submissions for Minimum Deletion Cost to Avoid Repeating Letters.
//Memory Usage: 95.7 MB, less than 72.68% of C++ online submissions for Minimum Deletion Cost to Avoid Repeating Letters.
    int lt1578a(string s, vector<int>& cost)
    {
        int sz1 = s.size();
        int ans = 0;
        char lst = 'A';
        int lstCost = -1;
        for (int i = 0; i < sz1; ++i)
        {
            if (s[i] == lst)
            {
                ans += min(lstCost, cost[i]);
                lstCost = max(lstCost, cost[i]);
            }
            else
            {
                lst = s[i];
                lstCost = cost[i];
            }
        }
        return ans;
    }

};

int main()
{
//    string s{"abaac"};
//    myvi v = {1,2,3,4,5};

//    string s("abc");
//    myvi v = {1,2,3};

    string s = "aabaa";
    myvi v = {1,2,3,4,1};

    LT1578 lt;

    cout<<lt.lt1578a(s, v)<<endl;

    return 0;
}
