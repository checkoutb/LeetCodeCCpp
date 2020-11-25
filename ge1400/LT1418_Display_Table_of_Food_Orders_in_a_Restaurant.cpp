
#include "../header/myheader.h"

class LT1418
{
public:

// D D

//map<int,map<string,int>> mymap;
//            for(string s:dishes){
//                row.push_back(to_string(mp[s]));
//            }



//Runtime: 176 ms, faster than 91.22% of C++ online submissions for Display Table of Food Orders in a Restaurant.
//Memory Usage: 63.2 MB, less than 68.78% of C++ online submissions for Display Table of Food Orders in a Restaurant.
    vector<vector<string>> lt1418a(vector<vector<string>>& orders)
    {
        map<int, vector<int>> map2;         // table : {count of food1/2/3/4/5,  no table}
        unordered_map<string, int> map3;        // foodname : idx of map2.values;
        set<string> foodset;
        for (vector<string>& vs : orders)
            foodset.insert(vs[2]);
        int idx = 0;
        vector<vector<string>> ans;
        vector<string> row(1, "Table");
        for (string s : foodset)
        {
            map3[s] = idx++;
            row.push_back(s);
        }
        ans.push_back(row);

        for (vector<string>& vs : orders)
        {
            int table = std::stoi(vs[1]);
            if (map2.find(table) == map2.end())
                map2[table] = vector<int>(map3.size());
            map2[table][map3[vs[2]]]++;
        }

        for (map<int, vector<int>>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            int table = it->first;
            vector<int>& vi = it->second;
            row = vector<string>();
            row.push_back(to_string(table));
            for (int i : vi)
                row.push_back(to_string(i));
            ans.push_back(row);
        }

        return ans;
    }

};

int main()
{
//    vector<vector<string>> vs = {{"David","3","Ceviche"},{"Corina","10","Beef Burrito"},
//    {"David","3","Fried Chicken"},{"Carla","5","Water"},{"Carla","5","Ceviche"},{"Rous","3","Ceviche"}};

    vector<vector<string>> vs = {{"James","12","Fried Chicken"},{"Ratesh","12","Fried Chicken"},
    {"Amadeus","12","Fried Chicken"},{"Adam","1","Canadian Waffles"},{"Brianna","1","Canadian Waffles"}};

    LT1418 lt;

    vector<vector<string>> vvs = lt.lt1418a(vs);
    for (vector<string>& v : vvs)
    {
        for (string& s : v)
            cout<<s<<", ";
        cout<<endl;
    }

    return 0;
}
