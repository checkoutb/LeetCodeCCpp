
#include "../header/myheader.h"

class LT1311
{
public:

// D D

//  while (level-- > 0) {
//    vector<int> q2;
//    for (auto i : q1) {
//      for (auto j : friends[i])
//        if (visited.insert(j).second)
//          q2.push_back(j);
//    }
//    swap(q1, q2);
//  }
// ...
//  set<pair<int, string>> s;
//  for (auto& p : freq)
//    s.insert({ p.second, p.first });
//  for (auto& p : s)
//    res.push_back(p.second);


//        while (not q.empty()) {
//            if (curLevel == level)
//                break;




//Runtime: 132 ms, faster than 68.20% of C++ online submissions for Get Watched Videos by Your Friends.
//Memory Usage: 35 MB, less than 82.95% of C++ online submissions for Get Watched Videos by Your Friends.
    vector<string> lt1311a(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level)
    {
        vector<string> ans;
        unordered_set<int> set2;
        queue<int> que2;
        que2.push(id);
        set2.insert(id);
        while (level-- > 0)
        {
            int sz1 = que2.size();
            while (sz1-- > 0)
            {
                int fnt = que2.front();
                que2.pop();
                for (int i : friends[fnt])
                {
                    if (set2.find(i) == set2.end())
                    {
                        que2.push(i);
                        set2.insert(i);
                    }
                }
            }
        }
        unordered_map<string, int> map2;
        while (!que2.empty())
        {
            int fnt = que2.front();
            que2.pop();
            for (string& s : watchedVideos[fnt])
                map2[s]++;
        }
        for (auto& p : map2)
        {
            #ifdef __test
            cout<<p.first<<" : "<<p.second<<endl;
            #endif // __test
            ans.push_back(p.first);
        }
        std::sort(begin(ans), end(ans), [&map2](const string& s1, const string& s2) { return map2[s1] != map2[s2] ? (map2[s1] < map2[s2]) : (s1 < s2); });
        return ans;
    }

};

int main()
{
    cout<<("asd"<"cccc")<<endl;

    vector<vector<string>> vvs = {{"a","b"},{"c"},{"b","c"},{"d"}};
    myvvi vvi = {{1,2},{0,3},{0,3},{1,2}};
    int id{0}, lv{1};

    LT1311 lt;

    vector<string> vs = lt.lt1311a(vvs, vvi, id, lv);
    cout<<" = = "<<endl;
    for (string& s : vs)
        cout<<s.size()<<" : "<<s<<endl;

    return 0;
}
