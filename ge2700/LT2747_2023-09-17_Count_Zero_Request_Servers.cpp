
#include "../header/myheader.h"

class LT2747
{
public:

// D D

//    int i=0;
//    int j=0;
//    int servers=0;
//    for(auto& [query,index]:queries_indexes){
//      for(;j<logs.size() && logs[j][1]<=query;j++){
//        if(++count[logs[j][0]]==1){
//          servers++;
//        }
//      }
//      for(;i<logs.size() && logs[i][1]<query-x;i++){
//        if(--count[logs[i][0]]==0){
//          servers--;
//        }
//      }
//      ans[index]=n-servers;
//    }
//
// 双指针。


//        int l = 0, r = 0;
//        for (auto& q: qs) {
//            int start = max(0, q.first - x), end = q.first;
//
//            // add new logs
//            while (r < k && logs[r][1] <= end) ++serverCnt[logs[r++][0]];
//            // remove outdated logs
//            while (l <= r && l < k && logs[l][1] < start) {
//                --serverCnt[logs[l][0]];
//                if (serverCnt[logs[l][0]] == 0) serverCnt.erase(logs[l][0]);
//                ++l;
//            };
//
//            ans[q.second] = n - serverCnt.size();
//        }


//    int i = 0, j = 0, used = 0;
//    for (int id : ids) {
//        for (; i < logs.size() && logs[i][1] <= qs[id]; ++i)
//            used += (++cnt[logs[i][0]] == 1);
//        for (; j < logs.size() && logs[j][1] < qs[id] - x; ++j)
//            used -= (--cnt[logs[j][0]] == 0);
//        res[id] = n - used;
//    }


//Runtime567 ms
//Beats
//45.5%
//Memory228.8 MB
//Beats
//25.56%
    vector<int> countServers(
        int n, vector<vector<int>>& logs, int x, vector<int>& queries)
    {
        vector<pair<int, int>> vpq(queries.size());
        for (int i = 0; i < queries.size(); ++i)
        {
            vpq[i].first = queries[i];
            vpq[i].second = i;
        }
        sort(begin(vpq), end(vpq));

        sort(begin(logs), end(logs), [](const vector<int>& v1, const vector<int>& v2){
            if (v1[1] == v2[1])
            {
                return v1[0] < v2[0];
            }
            return v1[1] < v2[1];
        });

        map<int, int> map2;     // <server, last log time>
        map<int, int> map3;     // <log time, server count>
        int cnt = 0;
        vector<int> ans(vpq.size());
        int st, en;
        int idx = 0;        // next
        for (int i = 0; i < vpq.size(); ++i)
        {
            en = vpq[i].first;
            st = en - x;

            while (idx < logs.size() && logs[idx][1] <= en)
            {
                int server = logs[idx][0];
                if (map2.find(server) != map2.end() && map3.find(map2[server]) != map3.end())
                {
                    --map3[map2[server]];
                    --cnt;
                }
                else
                {
                    ;
                }
                map2[server] = logs[idx][1];
                ++map3[logs[idx][1]];
                ++cnt;
                ++idx;
            }

            while (!map3.empty() && map3.begin()->first < st)
            {
//                cout<<".... "<<map3.begin()->first<<endl;
                cnt -= map3.begin()->second;
                map3.erase(map3.begin());
            }

            #ifdef __test
            cout<<map3.size()<<" - "<<map2.size()<<" - "<<st<<", "<<en<<endl;
            cout<<"    "<<idx<<endl;
            #endif // __test

            ans[vpq[i].second] = n - cnt;
        }
        return ans;
    }

};

int main()
{

    LT2747 lt;

    int n = 3;
    myvvi vv = {{1,3},{2,6},{1,5}};
    int x = 5;
    myvi v = {10,11};

    myvi v2 = lt.countServers(n,vv,x,v);

    showVectorInt(v2);

    return 0;
}
