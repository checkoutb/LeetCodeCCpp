
#include "../header/myheader.h"

class LT2564
{
public:


    // hint: ... ‘§¥¶¿Ìs°£

    // g


    // tle.
    myvvi lt2564a(string s, vector<vector<int>>& queries)
    {
        map<int, vector<int>> map2;
        int szq = queries.size();
        int tar = 0;
        vector<vector<int>> vvi;
        for (int i = 0; i < szq; ++i)
        {
            tar = queries[i][0] ^ queries[i][1];
            if (map2.find(tar) != map2.end())
            {
                vvi.emplace_back(map2[tar]);
                continue;
            }
            vector<int> vi(2, -1);
            string s2;
            int t2 = tar;

            if (t2 == 0)
                s2.push_back('0');

            while (t2 > 0)
            {
                s2.push_back(char(t2 % 2 + '0'));
                t2 >>= 1;
            }

            reverse(begin(s2), end(s2));

            int idx = s.find(s2);
            
            if (idx != std::string::npos)
            {
                vi[0] = idx;
                vi[1] = idx + s2.size() - 1;
            }
            vvi.emplace_back(vi);
            map2[tar] = vi;
        }
        return vvi;
    }

};

int main()
{

    LT2564 lt;

    string s = "101101";
    myvvi vv = { {0,5},{1,2},{23,8} };

    myvvi vv2 = lt.lt2564a(s, vv);

    for (myvi& vi : vv2)
    {
        cout << vi[0] << " - " << vi[1];
        cout << endl;
    }


    return 0;
}
