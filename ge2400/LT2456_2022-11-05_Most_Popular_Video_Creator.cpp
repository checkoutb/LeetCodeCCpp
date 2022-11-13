
#include "../header/myheader.h"

class LT2456
{
public:






//Runtime302 ms
//Beats
//99.71 %
//Memory114.8 MB
//Beats
//97.67 %
    // 
    vector<vector<string>> lt2456a(vector<string>& creators, vector<string>& ids, vector<int>& views)
    {
        unordered_map<string, int> map2;
        unordered_map<string, int> map3;

        int sz1 = ids.size();

        for (int i = 0; i < sz1; ++i)
        {
            map2[creators[i]] += views[i];
            if (map3.find(creators[i]) == map3.end())
            {
                map3[creators[i]] = i;
            }
            else
            {
                if (views[map3[creators[i]]] < views[i] || (views[map3[creators[i]]] == views[i] && ids[map3[creators[i]]] > ids[i]))
                {
                    map3[creators[i]] = i;
                }
            }
        }

        int mx = -1;
        for (auto& p : map2)
        {
            mx = max(p.second, mx);
        }
        vector<vector<string>> vvs;
        for (auto& p : map2)
        {
            if (p.second == mx)
            {
                vvs.push_back({ p.first, ids[map3[p.first]] });
            }
        }
        return vvs;
    }

};

int main()
{

    LT2456 lt;

    vector<string> vs = { "alice","bob","alice","chris" };
    vector<string> id = { "one","two","three","four" };
    vector<int> vw = { 5,10,5,4 };

    vector<vector<string>> vvs = lt.lt2456a(vs, id, vw);

    for (vector<string>& vs : vvs)
    {
        cout << vs[0] << " - " << vs[1] << endl;
    }

    return 0;
}
