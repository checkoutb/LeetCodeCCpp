
#include "../../header/myheader.h"

class LT
{
public:

// D D

// unordered_map<string,multiset<string>>adj;
// ..这个挤在一起的写法好难看。


//vector<string> findItinerary(vector<pair<string, string>> tickets) {
//    for (auto ticket : tickets)
//        targets[ticket.first].insert(ticket.second);
//    visit("JFK");
//    return vector<string>(route.rbegin(), route.rend());
//}
//
//map<string, multiset<string>> targets;
//vector<string> route;
//
//void visit(string airport) {
//    while (targets[airport].size()) {
//        string next = *targets[airport].begin();
//        targets[airport].erase(targets[airport].begin());
//        visit(next);
//    }
//    route.push_back(airport);
//}

// 欧拉路。
// 这段代码 没有放回。




//Runtime18 ms
//Beats
//76.95%
//Memory14.7 MB
//Beats
//55.27%
    // 看了历史提交，没有tle，那就直接暴力
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        map<string, vector<string>> map2;
        for (vector<string>& vs : tickets)
        {
            map2[vs[0]].push_back(vs[1]);
        }
        for (auto& [_, vi] : map2)
        {
            sort(begin(vi), end(vi));
        }
        vector<string> ans;

        dfsa1(map2, "JFK", tickets.size(), ans);
        ans.push_back("JFK");
        reverse(begin(ans), end(ans));
        return ans;
    }

    bool dfsa1(map<string, vector<string>>& map2, string now, int remain, vector<string>& ans)
    {
        if (remain == 0)
            return true;
        --remain;

        vector<string>& vs = map2[now];
        string str = "";
        for (int i = 0; i < vs.size(); ++i)
        {
            if (vs[i].empty())
                continue;

            str = vs[i];
            vs[i] = "";

            if (dfsa1(map2, str, remain, ans))
            {
                ans.push_back(str);
                return true;
            }

            vs[i] = str;
        }
        return false;
    }

};

int main()
{

    LT lt;

//    vector<vector<string>> vvs = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};

    vector<vector<string>> vvs = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};

    vector<string> vs = lt.findItinerary(vvs);

    for (string& s : vs)
        cout<<s<<"->";

    cout<<endl;

    return 0;
}
