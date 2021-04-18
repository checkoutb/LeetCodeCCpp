
#include "../../header/myheader.h"

class LT5736
{
public:



//class Task{
//    int etime;
//    int ptime;
//    int id;
//}


    vector<int> lt5736c(vector<vector<int>>& tasks)
    {

    }


    // mmap2 + erase ?
// tle....
    vector<int> lt5736b(vector<vector<int>>& tasks)
    {
        priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> priq;
        long tm = INT_MAX;
        int sz1 = tasks.size();
        int mn = INT_MAX;
        int idx = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (tasks[i][0] < mn)
            {
                mn = tasks[i][0];
                idx = i;
            }
        }
        tm = tasks[idx][0];
        for (int i = 0; i < sz1; ++i)
        {
            if (tasks[i][0] == mn)
            {
                priq.push(make_pair(tasks[i][1], i));
                tasks[i][0] = INT_MAX;
            }
        }
        vector<int> ans;
//        priq.push(std::make_pair(tasks[idx][1], idx));
//        tasks[idx][0] = INT_MAX;
        while (!priq.empty())
        {
            pair<int, int> p2 = priq.top();
            priq.pop();
            tm += p2.first;
            ans.push_back(p2.second);
            for (int i = 0; i < sz1; ++i)
            {
                if (tasks[i][0] <= tm)
                {
                    priq.push(make_pair(tasks[i][1], i));
                    tasks[i][0] = INT_MAX;
                }
            }
            if (priq.empty())
            {
                mn = INT_MAX;
                idx = -1;
                for (int i = 0; i < sz1; ++i)
                {
                    if (tasks[i][0] < mn)
                    {
                        idx = i;
                        mn = tasks[i][0];
                    }
                }
                if (idx != -1)
                {
                    for (int i = 0; i < sz1; ++i)
                    {
                        if (tasks[i][0] == mn)
                        {
                            priq.push(std::make_pair(tasks[i][1], i));
                            tasks[i][0] = INT_MAX;
                        }
                    }
                }
            }
        }
        return ans;
    }



// error,   出现相同的就肯定不行了， 虽然现在还没有到那一步。
    vector<int> lt5736a(vector<vector<int>>& tasks)
    {
        vector<int> ans;
        unordered_map<int, unordered_map<int, int>> mmap2;
        for (int i = 0; i < tasks.size(); ++i)
        {
            mmap2[tasks[i][0]][tasks[i][1]] = i;
        }

        std::sort(begin(tasks), end(tasks));

        // process time, index,
//        priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<pair<int, int>>> priq;

        auto f1 = [&mmap2, &tasks](const pair<int, int>& p1, const pair<int, int>& p2)
        {
            if (p1.first != p2.first)
            {
                return p1.first < p2.first;
            }
            int t1 = p1.second;
            int t2 = p2.second;
            int i1 = mmap2[tasks[t1][0]][tasks[t1][1]];
            int i2 = mmap2[tasks[t2][0]][tasks[t2][1]];
            return i1 < i2;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f1)> priq(f1);

        int tm = tasks[0][0];
        int idx = 0;
        while (idx < tasks.size() && tasks[idx][0] == tasks[0][0])
        {
            priq.push(std::make_pair(tasks[idx][1], idx));
            idx++;
        }
        idx--;
        while (!priq.empty())
        {
            pair<int, int> p2 = priq.top();
            priq.pop();
            ans.push_back(mmap2[tasks[p2.second][0]][p2.first]);
            tm += p2.first;

//            cout<<"d,d,d,"<<tm<<endl;

            for (idx++; idx < tasks.size(); ++idx)
            {
//                cout<<" -------    "<<idx<<"m,  "<<tm<<endl;
                if (tasks[idx][0] <= tm)
                {
//                cout<<"got"<<endl;
                    priq.push(std::make_pair(tasks[idx][1], idx));
                }
                else
                {
                    idx--;
                    break;
                }
            }
//            cout<<"  - - -  "<<idx<<endl;
            if (priq.empty() && idx < tasks.size())
            {
                idx++;
                priq.push(std::make_pair(tasks[idx][1], idx));
                tm = tasks[idx][0];
            }
            #ifdef __test
//            cout<<priq.size()<<endl;
//            showVectorInt(ans);
            #endif // __test
        }
        return ans;
    }

};

int main()
{
    priority_queue<pair<int, int>> pq;
    pq.push({1,2});
    pq.push({11,22});
    pair<int, int> pqq = pq.top();
    cout<<pqq.first<<endl;

//    myvvi vv = {{1,2},{2,4},{3,2},{4,1}};

    myvvi vv = {{7,10},{7,12},{7,5},{7,4},{7,2}};

    // [6,1,2,9,4,10,0,11,5,13,3,8,12,7]
//    myvvi vv = {{19,13},{16,9},{21,10},{32,25},{37,4},{  49,24  },{   2   ,15},{38,41},{37,34},{33,6},{45,4},{18,18},{46,39},{  12,24  }};

    LT5736 lt;

    myvi v = lt.lt5736b(vv);

    showVectorInt(v);

    return 0;
}
