
#include "../header/myheader.h"

class LT2092
{
public:

    // D

    // 使用 uf 连接 相同time 的 开会的人。
    // 判断 上一步中 开会的人，是否和 0 相连，不相连则 reset。





    // tle
    // 每个人，扩散，松弛， 会议开始的时间>=我知道秘密的时间，扩散出去。 并且 我知道秘密的时间可能前移
    // priq bububu
    // 按开会时间排序，但是怎么处理 同时开会的 情况。 主要是 瞬间的。。
    vector<int> lt2092a(int n, vector<vector<int>>& meetings, int firstPerson)
    {
        vector<int> vi(n, -1);          // -1: don't know,  N: time
        vi[firstPerson] = 0;
        vi[0] = 0;

        sort(begin(meetings), end(meetings), [](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];
        });

#ifdef __test
        for (myvi& v : meetings)
        {
            cout << v[0] << "+" << v[1] << " in " << v[2] << endl;
        }
#endif

        for (int i = 0; i < meetings.size(); )
        {
            unordered_map<int, vector<int>> map2;

            int tm = meetings[i][2];

            queue<int> que1;

            while (i < meetings.size() && meetings[i][2] == tm)
            {
                if (vi[meetings[i][0]] != -1)
                    que1.push(meetings[i][0]);
                if (vi[meetings[i][1]] != -1)
                    que1.push(meetings[i][1]);

                map2[meetings[i][0]].push_back(meetings[i][1]);
                map2[meetings[i][1]].push_back(meetings[i][0]);

                ++i;
            }

            while (!que1.empty())
            {
                int fnt = que1.front();
                que1.pop();
                for (int nxt : map2[fnt])
                {
                    if (vi[nxt] == -1)
                    {
                        vi[nxt] = tm;
                        que1.push(nxt);
                    }
                }
            }


            //while (meetings[i][2] == tm)
            //{
            //    //if (vi[meetings[i][0]] != -1)
            //    //    map2[-meetings[i][0]].push_back(meetings[i][1]);
            //    //else
            //    //    map2[mee]
            //    //if (v)
            //    
            //    map2[meetings[i][0] * ((vi[meetings[i][0]] == -1) * 2 - 1)].push_back(meetings[i][1]);
            //    map2[meetings[i][1] * ((vi[meetings[i][1]] == -1) * 2 - 1)].push_back(meetings[i][0]);

            //    ++i;
            //}

            //queue<int> que1;
            //for (auto& p : map2)
            //{
            //    if (p.first > 0)
            //        break;

            //    que1.push(-p.first);
            //}

            //while (!que1.empty())
            //{
            //    int ps = que1.front();
            //    que1.pop();

            //    for (int nxt : )

            //}

        }

        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            if (vi[i] != -1)
                ans.push_back(i);
        }
        return ans;
    }

};

int main()
{

    LT2092 lt;

    //int n = 6;
    //myvvi vv = { {1,2,5},{2,3,8},{1,5,10} };
    //int f = 1;

    //int n = 4;
    //myvvi vv = { {3,1,3},{1,2,2},{0,3,3} };
    //int f = 3;

    //int n = 5;
    //myvvi vv = { {3,4,2},{1,2,1},{2,3,1} };
    //int f = 1;


    int n = 11;
    myvvi vv = { {5, 1, 4}, { 0, 4, 18 } };         // 0145
    int f = 1;


    myvi v = lt.lt2092a(n, vv, f);

    showVectorInt(v);

    return 0;
}
