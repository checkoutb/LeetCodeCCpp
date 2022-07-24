
#include "../../header/myheader.h"

class LT6126
{
public:



};






// AC      。。。。。。。。。。。。。。。。。。。。。。。。。
struct cmp
{
    bool operator()(pair<int, string>& p1, pair<int, string>& p2){
        if (p1.first == p2.first)
        {
            return p1.second > p2.second;
        }
        else
        {
            return p1.first < p2.first;
        }
    }
};

class FoodRatings {

    unordered_map<string, string> map2;     // food - cuisine
    //unordered_map<string, unordered_map<string, int>> map3;   // cuisine - <food, rating>

    priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pro;

    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, cmp>> map3;

    unordered_map<string, string> map4;     // cuisine - maxRateFood

    unordered_map<string, int> map5;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int sz1 = foods.size();
        for (int i = 0; i < sz1; ++i)
        {
            map2[foods[i]] = cuisines[i];
            map3[cuisines[i]].push(make_pair(ratings[i], foods[i]));
            map5[foods[i]] = ratings[i];
        }
    }

    void changeRating(string food, int newRating) {
        map3[map2[food]].push({newRating, food});
        map5[food] = newRating;
    }

    string highestRated(string cuisine) {
        string ans;

        while (true)
        {
            pair<int, string> tp = map3[cuisine].top();
            if (tp.first != map5[tp.second])
                map3[cuisine].pop();
            else
            {
                ans = tp.second;
                break;
            }
        }
        return ans;
    }
};



//
//// tle...
//// tle
//// 食物，类别，rate
//// 返回这个类别中 rate最高的 食物
//// 食物是distinct 的
//class FoodRatings2 {
//
//    unordered_map<string, string> map2;     // food - cuisine
//    unordered_map<string, unordered_map<string, int>> map3;   // cuisine - <food, rating>
//
//    unordered_map<string, string> map4;     // cuisine - maxRateFood
//
//public:
//    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
//        int sz1 = foods.size();
//
//        for (int i = 0; i < sz1; ++i)
//        {
//            this->map2[foods[i]] = cuisines[i];
//            this->map3[cuisines[i]][foods[i]] = ratings[i];
//        }
//    }
//
//    void changeRating(string food, int newRating) {
//        this->map3[this->map2[food]][food] = newRating;
//
//        if ((map4[map2[food]].empty()))
//            return;
//
//        if (food == map4[map2[food]])
//        {
//            if (newRating == map3[map2[food]][map4[map2[food]]])
//            {
//                map4[map2[food]] = "";
//            }
//        }
//        else
//        {
//            #ifdef __test
//            cout<<newRating<<", "<<map3[map2[food]][food]<<endl;
//            #endif // __test
//
//            if (newRating == map3[map2[food]][map4[map2[food]]])
//            {
//                map4[map2[food]] = min(food, map4[map2[food]]);
//            }
//            else if (newRating > map3[map2[food]][map4[map2[food]]])
//            {
//                #ifdef __test
//                cout<<"?"<<food<<endl;
//                #endif // __test
//
//                map4[map2[food]] = food;
//            }
//        }
//    }
//
//    string highestRated(string cuisine) {
//
//        if (!map4[cuisine].empty())
//        {
//            #ifdef __test
//            cout<<"11"<<endl;
//            #endif // __test
//            return map4[cuisine];
//        }
//
//        string ans = "";
//        int rate = -1;
//        for (auto& p : this->map3[cuisine])
//        {
//            if (p.second > rate)
//            {
//                ans = p.first;
//                rate = p.second;
//            }
//            else if (p.second == rate)
//            {
//                ans = min(ans, p.first);
//            }
//        }
//        map4[cuisine] = ans;
//        return ans;
//    }
//};



int main()
{

    LT6126 lt;

    vector<string> vs = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> vs2 = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> v = {9, 12, 8, 15, 14, 7};

    FoodRatings foodRatings(vs, vs2, v);
    cout<<"1"<<endl;
    cout<<endl<<foodRatings.highestRated("korean"); // return "kimchi"
                                        // "kimchi" is the highest rated korean food with a rating of 9.
    cout<<endl<<foodRatings.highestRated("japanese"); // return "ramen"
                                          // "ramen" is the highest rated japanese food with a rating of 14.
    foodRatings.changeRating("sushi", 16); // "sushi" now has a rating of 16.
    cout<<endl<<foodRatings.highestRated("japanese"); // return "sushi"
                                          // "sushi" is the highest rated japanese food with a rating of 16.
    foodRatings.changeRating("ramen", 16); // "ramen" now has a rating of 16.
    cout<<endl<<foodRatings.highestRated("japanese"); // return "ramen"
                                          // Both "sushi" and "ramen" have a rating of 16.
                                          // However, "ramen" is lexicographically smaller than "sushi".


    return 0;
}
