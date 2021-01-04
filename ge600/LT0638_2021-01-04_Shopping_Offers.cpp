
#include "../header/myheader.h"

class LT0638
{
public:

// D D

//        for (int i = 0; i < price.size(); i++) {
//            result += price[i] * needs[i];
//        }
//
//        for (int i = 0; i < special.size(); i++) {
//            bool isValid = true;
//            for (int j = 0; j < needs.size(); j++) {
//                needs[j] -= special[i][j];
//                if (needs[j] < 0) {
//                    isValid = false;
//                }
//            }
//
//            if (isValid) {
//                result = min(result, special[i].back() + shoppingOffers(price, special, needs));
//            }
//
//            for (int j = 0; j < needs.size(); j++) {
//                needs[j] += special[i][j];
//            }
//        }



//void operator+=(vector<int> &a, const vector<int> &b) {
//    for (int i = 0; i < a.size(); i++)
//        a[i] += b[i];
//}
//
//void operator-=(vector<int> &a, const vector<int> &b) {
//    for (int i = 0; i < a.size(); i++)
//        a[i] -= b[i];
//}
//
//bool operator<(const vector<int> &a, const int &n) {
//    for (int i : a)
//        if (i < n)
//            return true;
//    return false;
//}
//
//int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cost = 0) {
//    if (needs < 0)
//        return INT_MAX;
//
//    int m = inner_product(needs.begin(), needs.end(), price.begin(), cost);
//
//    for (auto &offer : special) {
//        if (cost + offer.back() >= m) // pruning
//            continue;
//        needs -= offer;
//        m = min(m, shoppingOffers(price, special, needs, cost + offer.back()));
//        needs += offer;
//    }
//
//    return m;
//}



//Runtime: 28 ms, faster than 63.10% of C++ online submissions for Shopping Offers.
//Memory Usage: 13.9 MB, less than 56.19% of C++ online submissions for Shopping Offers.
    int lt0638a(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
    {
        dfsa1(price, special, needs, 0, 0);
        return ans;
    }
    int ans = INT_MAX;
    void dfsa1(vector<int>& price, vector<vector<int>>& special, vector<int> needs, int idx, int amount)
    {
        if (idx == special.size())
        {
            for (int i = 0; i < needs.size(); ++i)
            {
                amount += needs[i] * price[i];
            }
            ans = min(ans, amount);
            return;
        }
        int cnt = 0;
        vector<int> vi = special[idx];
        while (true)
        {
            dfsa1(price, special, needs, idx + 1, amount);
//            bool neg = false;
            for (int i = 0; i < vi.size() - 1; i++)
            {
                needs[i] -= vi[i];
                if (needs[i] < 0)
                    return;
            }
            amount += vi[vi.size() - 1];
        }
    }

};

int main()
{
//    myvi v1 = {2,5};
//    myvvi vv1 = {{3,0,5},{1,2,10}};
//    myvi v2 = {3,2};

    myvi v1 = {2,3,4};
    myvvi vv1 = {{1,1,0,4},{2,2,1,9}};
    myvi v2 = {1,2,1};

    LT0638 lt;

    cout<<lt.lt0638a(v1,vv1,v2);

    return 0;
}
