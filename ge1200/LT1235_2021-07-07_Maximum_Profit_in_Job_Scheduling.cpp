
#include "../header/myheader.h"

class LT1235
{
public:

// D D

// 得全复制下来。。。

// top-down, bottom-up

// sort by endTime



//    vector<int> idx(startTime.size());
//    iota(begin(idx), end(idx), 0);
//    sort(begin(idx), end(idx), [&](int i, int j) { return startTime[i] > startTime[j]; });
//    map<int, int> memo;
//    int max_profit = 0;
//    for (auto i = 0; i < idx.size(); ++i) {
//        auto it = memo.lower_bound(endTime[idx[i]]);
//        max_profit = max(max_profit, (it == end(memo) ? 0 : it->second) + profit[idx[i]]);
//        memo[startTime[idx[i]]] = max_profit;
//    }
//    return max_profit;
// 我感觉是第一次看到，这种。iota。   会把  0,以及 0的自增， 0的自增的自增 。。。。 赋予 idx。。。


//        for (int i = 0; i < n; ++i) {
//            jobs.push_back({endTime[i], startTime[i], profit[i]});
//        }
//        sort(jobs.begin(), jobs.end());
//        map<int, int> dp = {{0, 0}};
//        for (auto& job : jobs) {
//            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
//            if (cur > dp.rbegin()->second)
//                dp[job[0]] = cur;
//        }



//Runtime: 152 ms, faster than 57.34% of C++ online submissions for Maximum Profit in Job Scheduling.
//Memory Usage: 59.1 MB, less than 47.24% of C++ online submissions for Maximum Profit in Job Scheduling.
// hint:  dp, sort, binary-search.
// 我感觉我全符合啊。   map2是memo，  dfs+memo == top-down dp,  也用到了lower_bound, 也 sort了。
// 唯一可能的问题，就是 memo，不够速度。 但是有 复制前值，不会太慢啊。
// define the dp[i] as the maximum profit taking elements from the suffix starting at i.
// 从后往前。
// Use binarySearch (lower_bound/upper_bound on C++) to get the next index for the DP transition.
// 从前往后，是没有子问题的。
// 从后往前，每个job，根据这个job的end，去搜索 start， 然后加一下， 还要和  后面的那个对比一下，来防止遍历。
    int lt1235b(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        int sz1 = startTime.size();
        vector<vector<int>> vvi;
        for (int i = 0; i < sz1; ++i)
        {
            vvi.push_back((vector<int>){startTime[i], endTime[i], profit[i]});
        }
        std::sort(begin(vvi), end(vvi));
        for (int i = 0; i < sz1; ++i)
        {
            startTime[i] = vvi[i][0];
            endTime[i] = vvi[i][1];
            profit[i] = vvi[i][2];
        }
        vector<int> vi(sz1);
        for (int i = sz1 - 1; i >= 0; --i)
        {
            int en = endTime[i];
            vector<int>::iterator it = std::lower_bound(begin(startTime), end(startTime), en);
            if (it == end(startTime))
            {
                vi[i] = max(vi[i], profit[i]);
                if (i + 1 < sz1)
                    vi[i] = max(vi[i + 1], vi[i]);          // 把后面的比现在大的复制过来，这样就不需要遍历。
                continue;
            }
            int dis = distance(begin(startTime), it);
//            vi[i] = max(vi[i], profit[i] + )            // 不需要 vi[i]。
            int t2 = (i + 1 < sz1) ? vi[i + 1] : -1;
            vi[i] = max(t2, profit[i] + vi[dis]);
        }
        return vi[0];
    }



// 15/27 tle...
// 0-1beibao?
// dfs可以，不知道会不会tle。
    int lt1235a(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
//        unordered_map<int, int> map2;       // 当第key的job完成/跳过时， 最大的 profit。
//        map<int, int> map2;
        int sz1 = startTime.size();
        vector<int> map2(sz1, -1);
//        std::sort(begin(startTime), end(startTime), [&endTime](int i){})      // compare by value, ... no index...
//        vector<pair<int, int>> vp(sz1);
//        for (int i = 0; i < sz1; ++i)
//        {
//            vp[i] = std::make_pair(endTime[i], startTime[i]);
//        }
//        std::sort(begin(vp), end(vp));
//        for (int i = 0; i < sz1; ++i)
//        {
//            startTime[i] = vp[i].second;
//            endTime[i] = vp[i].first;
//        }
//////        vector<vector<int>> vvi(sz1);
//////        for (int i = 0; i < sz1; ++i)
//////            vvi.push_back({endTime[i], startTime[i], profit[i]});
//////        std::sort(begin(vvi), end(vvi));
//////        for (int i = 0; i < sz1; ++i)
//////        {
//////            startTime[i] = vvi[i][1];
//////            endTime[i] = vvi[i][0];
//////            profit[i] = vvi[i][2];
//////        }             // ...............................
        vector<vector<int>> vvi;
        for (int i = 0; i < sz1; ++i)
        {
            // buhui...
//            vvi.push_back(vector<int>(){startTime[i], endTime[i], profit[i]});
//            vvi.emplace_back(startTime[i], endTime[i], profit[i]);
//            vector<int> vi = {startTime[i], endTime[i], profit[i]};
//            vvi.push_back(vi);
            vvi.emplace_back((vector<int>){startTime[i], endTime[i], profit[i]});       // ...
        }
        sort(begin(vvi), end(vvi));
        for (int i = 0; i < sz1; ++i)
        {
            startTime[i] = vvi[i][0];
            endTime[i] = vvi[i][1];
            profit[i] = vvi[i][2];
        }
        dfsa1(startTime, endTime, profit, startTime[0], map2, 0);
        return ans;
    }
    int ans = 0;
    void dfsa1(vector<int>& st, vector<int>& en, vector<int>& pf, int jobend,
//               unordered_map<int, int>& map2
                vector<int>& map2
               , int got
               )
    {
//        if (idx >= st.size())
//        {
//            if (got > ans)
//                ans = got;
//            return;
//        }
        vector<int>::iterator it = std::lower_bound(begin(st), end(st), jobend);
        if (it == end(st))
        {
            if (got > ans)
                ans = got;
            return;
        }
        int dis = std::distance(begin(st), it);
        for (int i = dis - 1; i >= 0; --i)
        {
            if (map2[i] >= got)
            {
                map2[dis] = map2[i];        // 把前面的值刷过来，就像uf的 find，来缩短搜索路径。
                return;
            }
        }
        for (int i = dis; i < st.size(); ++i)
        {
            dfsa1(st, en, pf, en[i], map2, got + pf[i]);
        }
    }


};

int main()
{
//    myvi st = {1,2,3,3};
//    myvi en = {3,4,5,6};
//    myvi pf = {50,10,40,70};

//    myvi st = {1,2,3,4,6};
//    myvi en = {3,5,10,6,9};
//    myvi pf = {20,20,100,70,60};

//    myvi st = {1,1,1};
//    myvi en = {2,3,4};
//    myvi pf = {5,6,4};

    myvi st = {4,2,4,8,2};          // un sorting..........
    myvi en = {5,5,5,10,8};
    myvi pf = {1,2,8,10,4};         // 18

//// 998?
//    myvi st = {341,22,175,424,574,687,952,439,51,562,962,890,250,47,945,914,835,937,419,343,125,809,807,959,403,861,296,39,802,562,811,991,209,375,78,685,592,409,369,478,417,162,938,298,618,745,888,463,213,351,406,840,779,299,90,846,58,235,725,676,239,256,996,362,819,622,449,880,951,314,425,127,299,326,576,743,740,604,151,391,925,605,770,253,670,507,306,294,519,184,848,586,593,909,163,129,685,481,258,764};
//    myvi en = {462,101,820,999,900,692,991,512,655,578,996,979,425,893,975,960,930,991,987,524,208,901,841,961,878,882,412,795,937,807,957,994,963,716,608,774,681,637,635,660,750,632,948,771,943,801,985,476,532,535,929,943,837,565,375,854,174,698,820,710,566,464,997,551,884,844,830,916,970,965,585,631,785,632,892,954,803,764,283,477,970,616,794,911,771,797,776,686,895,721,917,920,975,984,996,471,770,656,977,922};
//    myvi pf = {85,95,14,72,17,3,86,65,50,50,42,75,40,87,35,78,47,74,92,10,100,29,55,57,51,34,10,96,14,71,63,99,8,37,16,71,10,71,83,88,68,79,27,87,3,58,56,43,89,31,16,9,49,84,62,30,35,7,27,34,24,33,100,25,90,79,58,21,31,30,61,46,36,45,85,62,91,54,28,63,50,69,48,36,77,39,19,97,20,39,48,72,37,67,72,46,54,37,53,30};


    LT1235 lt;

    cout<<lt.lt1235b(st, en, pf);

    return 0;
}
