
#include "../header/myheader.h"

class LT1912
{
public:



};

// D D


//typedef long long ll;
//ll big = 300001;
//
//// {movie, {price * big + shop}}. For each movie, keeps the prices and shop that has this movie available for rent.
//unordered_map<ll, set<ll>> mp;
//
//// {price * big * big + shop * big + movie}. To keep track of the rented movies. 
//set<ll> rented;
//
//// {shop * big + movie, price}. This is just used to lookup prices given movie and shop.
//unordered_map<ll, ll> prices;





//vector<set<pair<int, int>>> available = vector<set<pair<int, int>>>(10010);            //List of movies not rented
//vector<set<pair<int, int>>> getPrice = vector<set<pair<int, int>>>(10010);
//set<pair<int, pair<int, int>>> rented;
//
//auto it = getPrice[movie].lower_bound({ shop, INT_MIN });






//Runtime: 1973 ms, faster than 32.46 % of C++ online submissions for Design Movie Rental System.
//Memory Usage : 400.8 MB, less than 76.32 % of C++ online submissions for Design Movie Rental System.
// search : movie最便宜的 5家店。
// report：最便宜的 租出去 的 5个movie。           priq
// map<movie, map<shop, rented?>>     还需要一个
// map<movie, map<price, shop>>
// order by price,shop,movie
class MovieRentingSystem {

    unordered_map<int, unordered_map<int, int>> map2;       // ... -rent,  +exist...
    unordered_map<int, vector<vector<int>>> map3;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> priq;

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (vector<int>& vi : entries)
        {
            map2[vi[1]][vi[0]] = vi[2];          // exist
            map3[vi[1]].push_back({vi[2], vi[0]});
        }

        for (auto& p : map3)
        {
            sort(begin(p.second), end(p.second));
        }

    }

    vector<int> search(int movie) {
        vector<int> vi;
        if (map3.find(movie) == map3.end())
            return vi;

        for (int i = 0, mxi = map3[movie].size(); i < mxi && vi.size() < 5; ++i)
        {
            int shp = map3[movie][i][1];
            //int prc = map3[movie][i][0];
            if (map2[movie][shp] > 0)
                vi.push_back(shp);
        }

        return vi;
    }

    // price,shop,movie
    void rent(int shop, int movie) {
        priq.push({ map2[movie][shop], shop, movie });
        map2[movie][shop] = -map2[movie][shop];
    }

    void drop(int shop, int movie) {
        map2[movie][shop] = -map2[movie][shop];
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;

        while ((!priq.empty()) && ans.size() < 5)
        {
            vector<int> vi = priq.top();
            priq.pop();
            if (map2[vi[2]][vi[1]] < 0)
            {
                if (ans.size() > 0 && (vi[1] == ans[ans.size() - 1][1]) && vi[2] == ans[ans.size() - 1][2])         // ... 借出，归还，借出， priq中就有2条 相同的数据了。
                {
                    continue;
                }
                ans.push_back(vi);
            }
        }
        vector<vector<int>> ans2;
        for (vector<int>& vi : ans)
        {
            ans2.push_back({ vi[1], vi[2] });
            priq.push(vi);
        }

        return ans2;
    }
};



int main()
{

    LT1912 lt;

    myvvi vv2 = { {0, 1, 5},{0, 2, 6},{0, 3, 7},{1, 1, 4},{1, 2, 7},{2, 1, 5} };

    MovieRentingSystem movieRentingSystem(3, vv2);
    vector<int> vi = movieRentingSystem.search(1);  // return [1, 0, 2], Movies of ID 1 are unrented at shops 1, 0, and 2. Shop 1 is cheapest; shop 0 and 2 are the same price, so order by shop number.
    showVectorInt(vi);
    movieRentingSystem.rent(0, 1); // Rent movie 1 from shop 0. Unrented movies at shop 0 are now [2,3].
    movieRentingSystem.rent(1, 2); // Rent movie 2 from shop 1. Unrented movies at shop 1 are now [1].
    myvvi vv = movieRentingSystem.report();   // return [[0, 1], [1, 2]]. Movie 1 from shop 0 is cheapest, followed by movie 2 from shop 1.
    cout << " ========== st " << endl;
    for (myvi& v : vv)
    {
        for (int i : v)
        {
            cout << i << ", ";
        }
        cout << endl;
    }
    cout << " ========== en " << endl;
    movieRentingSystem.drop(1, 2); // Drop off movie 2 at shop 1. Unrented movies at shop 1 are now [1,2].
    vi = movieRentingSystem.search(2);  // return [0, 1]. Movies of ID 2 are unrented at shops 0 and 1. Shop 0 is cheapest, followed by shop 1.
    showVectorInt(vi);

    return 0;
}
