
#include "../header/myheader.h"

class LT1125
{
public:



// tle
    vector<int> lt1125a(vector<string>& req_skills, vector<vector<string>>& people)
    {
        unordered_map<string, vector<int>> map2;
        for (int i = 0; i < people.size(); ++i)
        {
            for (string& s : people[i])
            {
                map2[s].push_back(i);
            }
        }
        dfsa1(unordered_set<string>(begin(req_skills), end(req_skills)), people, map2, {}, 0);
        return ans;
    }
    vector<int> ans;
    int anssz = INT_MAX;
    void dfsa1(unordered_set<string> req, vector<vector<string>>& peo, unordered_map<string, vector<int>>& map2, vector<int> vi, int idx)
    {
        if (req.empty())
        {
            if (vi.size() < anssz)
            {
                ans = vi;
                anssz = vi.size();
            }
        }
        if (idx >= peo.size())
            return;
        dfsa1(req, peo, map2, vi, idx + 1);
        bool chg = false;
        for (int i = 0; i < peo[idx].size(); ++i)
        {
            if (req.find(peo[idx][i]) != req.end())
            {
                chg = true;
                req.erase(peo[idx][i]);
            }
        }
        if (chg)
        {
            vi.push_back(idx);
            dfsa1(req, peo, map2, vi, idx + 1);
        }
    }

};

int main()
{
    vector<string> r = {"java","js1","js2"};
    vector<vector<string>> v = {{"java"},{"js1"},{"js1","js2"}};

    LT1125 lt;

    myvi vi = lt.lt1125a(r, v);

    showVectorInt(vi);

    return 0;
}
