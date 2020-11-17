
#include "../header/myheader.h"

class LT1333
{
public:

// D D

//        return Arrays.stream(restaurants)
//            .filter(s -> s[2] >= veganFriendly && s[3] <= maxPrice&& s[4] <= maxDistance)
//            .sorted((a,b) -> {
//                if(a[1] == b[1])
//                    return b[0] - a[0];
//                else
//                    return b[1] - a[1];
//                })
//            .map(i -> i[0])
//            .collect(Collectors.toList());






//Runtime: 148 ms, faster than 94.58% of C++ online submissions for Filter Restaurants by Vegan-Friendly, Price and Distance.
//Memory Usage: 29.2 MB, less than 39.02% of C++ online submissions for Filter Restaurants by Vegan-Friendly, Price and Distance.
// [id=1, rating=4, veganFriendly=1, price=40, distance=10]
    vector<int> lt1333a(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance)
    {
        vector<int> ans;
        map<int, vector<int>> map2;     // rating : ids
        for (vector<int>& vi : restaurants)
        {
            if (veganFriendly == 1 && vi[2] != 1)
                continue;
            if (vi[3] > maxPrice)
                continue;
            if (vi[4] > maxDistance)
                continue;
            map2[vi[1]].push_back(vi[0]);
        }

        for (map<int, vector<int>>::reverse_iterator it = map2.rbegin(); it != map2.rend(); it++)
        {
            sort(begin(it->second), end(it->second), std::greater<int>());
            for (int id : it->second)
                ans.push_back(id);
        }
        return ans;
    }

};

int main()
{

//    vector<vector<int>> vvi = {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
//    int a{1}, b{50}, c{10};

    vector<vector<int>> vvi = {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};
    int a{0}, b{50}, c{10};

    LT1333 lt;

    vector<int> v = lt.lt1333a(vvi, a, b, c);

    showVectorInt(v);

    return 0;
}
