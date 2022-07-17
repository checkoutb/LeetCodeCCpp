
#include "../header/myheader.h"

class LT1744
{
public:

    // D D

    //On the A[type] / cap day, you must already have ths type of candy.
    //On the A[t + 1] - 1 day, you must already have finished ths type of candy.
    //So if you want to eat your favorite candy on your favorite day,
    //this A[t] // c <= d < A[t + 1] must be True.


    //vector<long long> prefix(n + 1, 0);
    //for (int i = 1; i < n + 1; ++i) prefix[i] = prefix[i - 1] + candies[i - 1];

    //vector<bool> ans;
    //for (auto& query : queries) {
    //    long long type = query[0], day = query[1], capacity = query[2];
    //    long long maxDay = prefix[type + 1] - 1;
    //    long long minDay = prefix[type] / capacity;

    //    if (day <= maxDay && day >= minDay) ans.push_back(true);
    //    else ans.push_back(false);
    //}




    // 。。 t2 >= dy 好像也不对。 应该是 t2 >= dy + 1

//Runtime: 699 ms, faster than 18.90 % of C++ online submissions for Can You Eat Your Favorite Candy on Your Favorite Day ? .
//Memory Usage : 121 MB, less than 82.68 % of C++ online submissions for Can You Eat Your Favorite Candy on Your Favorite Day ? .
//Runtime: 410 ms, faster than 85.04 % of C++ online submissions for Can You Eat Your Favorite Candy on Your Favorite Day ? .
//Memory Usage : 121.1 MB, less than 54.33 % of C++ online submissions for Can You Eat Your Favorite Candy on Your Favorite Day ? .
    vector<bool> lt1744a(vector<int>& candiesCount, vector<vector<int>>& queries)
    {
        int sz1 = candiesCount.size();
        int sz2 = queries.size();
        vector<bool> ans(sz2);
        //int sum2 = std::accumulate(begin(candiesCount), end(candiesCount), 0);

        vector<long long> v2(sz1);
        v2[0] = candiesCount[0];
        for (int i = 1; i < sz1; ++i)
        {
            v2[i] = v2[i - 1] + candiesCount[i];
        }

        for (int i = 0; i < sz2; ++i)
        {
            int tp = queries[i][0];
            int dy = queries[i][1];
            int cp = queries[i][2];

            long long t2 = v2[tp];
            long long t3 = (tp == 0 ? 0 : v2[tp - 1]);

            //if (t2 >= dy && t3 < (1LL * (cp) * (dy + 1) - 1))           // 这个和下面的 都可以通过。但是这个应该是错的。
            if (t2 >= dy && t3 < (1LL * (cp) * (dy + 1)))
                ans[i] = true;

        }

        return ans;
    }

};

int main()
{

    LT1744 lt;


    return 0;
}
