
#include "../../header/myheader.h"

class LT6135
{
public:



// 2428 / 26877	Ouha 	18	1:25:46	0:02:21 	0:17:20 1	0:46:52 3	1:00:46 1

// AC
// tle
    int longestCycle(vector<int>& edges)
    {
        int sz1 = edges.size();
        vector<bool> vst(sz1, false);
        int ans = -1;



        for (int i = 0; i < sz1; ++i)
        {
            if (vst[i])
                continue;

            int cnt = 0;
            int nd = i;
            vst[nd] = true;
            unordered_map<int, int> map2;
            map2[nd] = cnt;

            while (edges[nd] != -1)
            {
                nd = edges[nd];
                cnt++;
                if (map2.find(nd) != map2.end())
                {
                    int t2 = cnt - map2[nd];
                    if (t2 > ans)
                    {
                        ans = t2;
                    }
                    break;
                }
                else
                {
                    map2[nd] = cnt;
                }

                if (vst[nd])                    // for TLE
                    break;

                vst[nd] = true;
            }
        }
        return ans;
    }


    int longestCycle__a(vector<int>& edges)
    {
        int sz1 = edges.size();
        vector<bool> vst(sz1, false);
        int ans = -1;


        for (int i = 0; i < sz1; ++i)
        {
            if (vst[i])
                continue;

//
//            unordered_set<int> set2;
//            set2.insert(i);
//

            int cnt = 0;
            int nd = i;
            vst[nd] = true;

            unordered_set<int> set2;
            set2.insert(nd);

            while (edges[nd] != -1)
            {
                nd = edges[nd];

                #ifdef __test
                cout<<nd<<endl;
                #endif // __test

                vst[nd] = true;
                cnt++;
                if (nd == i)
                {
                    if (cnt > ans)
                        ans = cnt;
                    break;
                }
                if (set2.find(nd) != set2.end())
                    break;
                else
                    set2.insert(nd);
            }


        }
        return ans;

    }

};

int main()
{

    LT6135 lt;

    myvi v = {3,3,4,2,3};
    //myvi v = {2,-1,3,1};


    cout<<lt.longestCycle(v)<<endl;

    return 0;
}
