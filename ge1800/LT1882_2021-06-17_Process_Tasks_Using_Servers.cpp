
#include "../header/myheader.h"

class LT1882
{
public:

// D D







// D

// 哈哈
//https://leetcode.com/problems/process-tasks-using-servers/discuss/1239822/Wrong-test-results

// 但是  还是无法理解。
// 我知道可以 pick 多个任务， 但是又有什么用？  多个任务，不还是 按照下标走的。。。。。。。。。。。。。。。。。。。。
// 知道了，   开始时间的问题。。。。。   时间24s的时候，有3个任务(是之前22,23,24这3s 应该开始的，但是由于没有服务器所以就卡住)， 如果来3台服务器，那么 这3个任务都是 24s开始的。
//                                       但是，我这段代码，一次只处理一个任务，会导致 3个任务分别是 24,25,26 开始。



// .... 把 sttm++ 删掉就可以了。。。。。。。。。。。。。。。。。。。。。。。。。。。
//Runtime: 472 ms, faster than 72.46% of C++ online submissions for Process Tasks Using Servers.
//Memory Usage: 125.8 MB, less than 56.82% of C++ online submissions for Process Tasks Using Servers.

    vector<int> lt1882_after_D(vector<int>& servers, vector<int>& tasks)
    {

    }




// gg 无法理解。

//如果有多项任务等待分配，则按照 下标递增 的顺序完成分配。  leetcode-cn

// 。。 for中第一个while的问题。  <=i 不正确的。  应该是 等于top的 全都要pop出来。   或者说是 else的问题

// 好像也不是。。 priq2 用pair 没有问题的。
//
//If there are no free servers and the queue is not empty,
//we wait until a server becomes free and immediately assign the next task.
//If multiple servers become free at the same time,
//then multiple tasks from the queue will be assigned in order of insertion following the weight and index priorities above.
//
// in order of insertion following the weight and index priorities above.   priq2.
    vector<int> lt1882b(vector<int>& servers, vector<int>& tasks)
    {
//        priority_queue<pair<int, int>> priq1;   // available            weight, index
//        priority_queue<pair<int, int>> priq2;       // time, index

        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2){
                if (p1.first == p2.first)
                    return p1.second > p2.second;               // 这里是最小堆， 所以 T 会导致p1 排后面。那为什么priority<int> 会是最大的排前面。pri<int> 是不是默认 less导致的？ 但是 less 也应该是 越小越优先吧。。
                else
                    return p1.first > p2.first;
            };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> priq1{comp};
//        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> priq2{comp};

        auto comp2 = [](const tuple<int, int, int>& t1, const tuple<int, int, int>& t2){
                if (std::get<0>(t1) != std::get<0>(t2))
                    return get<0>(t1) > get<0>(t2);
                if (std::get<1>(t2) != std::get<1>(t1))
                    return get<1>(t1) > get<1>(t2);
                return false;
            };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(comp2)> priq2{comp2};

        for (int i = 0; i < servers.size(); ++i)
        {
            priq1.push(std::make_pair(servers[i], i));
        }
        int cnt = 0;
        vector<int> ans;
        int sttm = -1;
        for (int i = 0; i < tasks.size(); ++i)
        {
//            sttm++;       // 。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
            sttm = max(sttm, i);
            int t2 = tasks[i];

            #ifdef __test
            if (i == 147 || i == 148)
            {
                cout<<" - ----------------"<<endl;

                cout<<priq2.size()<<", "<<priq1.size()<<", "<<endl;

                cout<<" - --=============-"<<endl;
            }
            #endif // __test


//            while (!priq2.empty() && priq2.top().first <= i)     // <   ! <=.   no
            while (!priq2.empty() && std::get<0>(priq2.top()) <= i)
            {
//                int idx = priq2.top().second;
//                priq2.pop();
//                priq1.push({servers[idx], idx});
                int idx = std::get<2>(priq2.top());
                priq2.pop();
                priq1.push(std::make_pair(servers[idx], idx));
//                priq1.push(std::make_tuple())
            }

                        #ifdef __test
            if (i == 147 || i == 148)
            {
                cout<<" - ----------------"<<endl;

                cout<<priq2.size()<<", "<<priq1.size()<<", "<<endl;

                cout<<" - --=============-"<<endl;
            }
            #endif // __test

            if (!priq1.empty())
            {
                int idx = priq1.top().second;
                priq1.pop();
//                priq2.push({i + t2, idx});
                priq2.push(std::make_tuple(sttm + t2, cnt++, idx));
                ans.push_back(idx);
            }
            else
            {
                int tm2 = std::get<0>(priq2.top());
                while (!priq2.empty() && std::get<0>(priq2.top()) == tm2)
                {
                    int idx = std::get<2>(priq2.top());             // start time 也有问题了。
                    priq2.pop();
                    priq1.push({servers[idx], idx});

                                #ifdef __test
            if (i == 147 || i == 148)
            {
                cout<<" - ---while------"<<endl;

                cout<<priq2.size()<<", "<<priq1.size()<<", "<<endl;
                cout<<". "<<idx<<", "<<servers[idx]<<endl;
                cout<<" - --===while=====-"<<endl;
            }
            #endif // __test

                }

                            #ifdef __test
            if (i == 147 || i == 148)
            {
                cout<<" - ---else----"<<endl;

                cout<<priq2.size()<<", "<<priq1.size()<<", "<<endl;

                cout<<" - --==else========-"<<endl;
            }
            #endif // __test

                sttm = tm2;
                int idx = priq1.top().second;
                priq1.pop();
                priq2.push(make_tuple(sttm + t2, cnt++, idx));
                ans.push_back(idx);
//////////////                int idx = std::get<2>(priq2.top());
//////////////                int tm2 = std::get<0>(priq2.top());
////////////////                int idx = priq2.top().second;
////////////////                int tm2 = priq2.top().first;
//////////////                priq2.pop();
//////////////                priq2.push(std::make_tuple(tm2 + t2, cnt++, idx));
////////////////                priq2.push({tm2 + t2, idx});
//////////////                ans.push_back(idx);
            }
        }
        return ans;
    }



//    std::array<int, 5> iArray;
// ...。。。编译不了。。 lower_bound， operator[] 都错了。。
//// error ... task没有重量。
//// 所以hint2也就知道了。因为前面的任务只会用 最小的可用的。。  而不是 >task重量的最小可用。
//
//// 1秒的开始。  t+task[j] free
//// 能用的最小负载，相同最小负载，就前面的。
//// priq_  时间，负载，  不。优先不了。
//// 负载， 时间， 下标。
//// You can maintain a Heap of available Servers and a Heap of unavailable servers
//// 似乎应该是  每个负载 对应2个堆， 一个可用，一个不可用。 那就2个priq   可用的按下标排， 不可用的按结束时间排。
//// hint2 没看懂。
//// 是不是说，前面的任务执行范围覆盖了自己，那么就少一个server，但是不知道 前面的任务会用哪个 啊。
//// 先来一个tle
//    vector<int> lt1882a(vector<int>& servers, vector<int>& tasks)
//    {
//        vector<int[]> va;
//        for (int i = 0; i < servers.size(); ++i)
//        {
//            va.push_back({servers[i], i, 0});       // 负载，下标，时间
//        }
//        std::sort(begin(va), end(va));
//        vector<int> ans;
//        for (int i = 0; i < tasks.size(); ++i)
//        {
//            int t2 = tasks[i];
//            vector<int[]>::iterator it = std::lower_bound(begin(va), end(va), t2, [](const int[]& arr, int tar){ return arr[0] < tar; });
////            int idx = std::distance(begin(va), it);
////            for (int )
//            for (; it != end(va); it++)
//            {
//                if (it->operator[](2) <= i)
//                {
//                    it->operator[](2) = i + t2;
//                }
//            }
//        }
//        return ans;
//    }

};

int main()
{

//    priority_queue<int> pri{std::greater<int>()};         // no match function....
    priority_queue<int> pri{std::less<int>()};      // less 但是 还是37是top。。。
    pri.push(3);
    pri.push(32);
    pri.push(37);
    cout<<pri.size()<<endl;
    cout<<pri.top()<<endl;

    myvi v4 = {4,5,6,32,3,4,1};
    priority_queue<int> ppp{std::less<int>(), v4};      // greater   no match function ...
    cout<<ppp.top()<<endl;

    // 第三个是无效的。。。。 真的难。
//    priority_queue<int, vector<int>, std::decltype(std::greater<int>())> pp2{std::greater<int>()};


//    myvi ser = {3,3,2};
//    myvi tsk = {1,2,3,2,1,2};

//    myvi ser = {5,1,4,3,2};
//    myvi tsk = {2,1,2,4,5,2,1};


// except: xxxxx 41,25,52,40,58,9,52,40]
    myvi ser = {338,890,301,532,284,930,426,616,919,267,571,140,716,859,980,469,628,490,195,664,925,652,503,301,917,563,82,947,910,451,366,190,253,516,503,721,889,964,506,914,986,718,520,328,341,765,922,139,911,578,86,435,824,321,942,215,147,985,619,865};
    myvi tsk = {773,537,46,317,233,34,712,625,336,221,145,227,194,693,981,861,317,308,400,2,391,12,626,265,710,792,620,416,267,611,875,361,494,128,133,157,638,632,2,158,428,284,847,431,94,782,888,44,117,489,222,932,494,948,405,44,185,587,738,164,356,783,276,547,605,609,930,847,39,579,768,59,976,790,612,196,865,149,975,28,653,417,539,131,220,325,252,160,761,226,629,317,185,42,713,142,130,695,944,40,700,122,992,33,30,136,773,124,203,384,910,214,536,767,859,478,96,172,398,146,713,80,235,176,876,983,363,646,166,928,232,699,504,612,918,406,42,931,647,795,139,933,746,51,63,359,303,752,799,836,50,854,161,87,346,507,468,651,32,717,279,139,851,178,934,233,876,797,701,505,878,731,468,884,87,921,782,788,803,994,67,905,309,2,85,200,368,672,995,128,734,157,157,814,327,31,556,394,47,53,755,721,159,843};

    cout<<ser[56]<<" . . "<<ser[36]<<endl;

//         [26,50,47,11,56,31,18,55,32,9,4,2,23,53,43,0,44,30,6,51,29,51,15,17,22,34,38,33,42,3,25,10,49,51,7,58,16,21,19,31,19,12,41,35,45,52,13,59,47,36,1,28,48,39,24,8,46,20,5,54,27,37,14,57,40,59,8,45,4,51,47,7,58,4,31,23,54,7,9,56,2,46,56,1,17,42,11,30,12,44,14,32,7,10,23,1,29,27,6,10,33,24,19,10,35,30,35,10,17,49,50,36,29,1,48,44,7,11,24,57,42,30,10,55,3,20,38,15,7,46,32,21,40,16,59,30,53,17,18,22,51,11,53,36,57,26,5,         56,36  ,55,31,34,57,7,52,37,31,10,0,51,41,2,32,25,0,7,49,47,13,14,24,57,28,4,45,43,39,38,8,2,44,45,29,25,25,12,54,5,44,30,27,23,26,7,33,58,41,25,52,40,58,9,52,40]
// except: [26,50,47,11,56,31,18,55,32,9,4,2,23,53,43,0,44,30,6,51,29,51,15,17,22,34,38,33,42,3,25,10,49,51,7,58,16,21,19,31,19,12,41,35,45,52,13,59,47,36,1,28,48,39,24,8,46,20,5,54,27,37,14,57,40,59,8,45,4,51,47,7,58,4,31,23,54,7,9,56,2,46,56,1,17,42,11,30,12,44,14,32,7,10,23,1,29,27,6,10,33,24,19,10,35,30,35,10,17,49,50,36,29,1,48,44,7,11,24,57,42,30,10,55,3,20,38,15,7,46,32,21,40,16,59,30,53,17,18,22,51,11,53,36,57,26,5,         36,56  ,55,31,34,57,7,52,37,31,10,0,51,41,2,32,25,0,7,49,47,13,14,24,57,28,4,45,43,39,38,8,2,44,45,29,25,25,12,54,5,44,30,27,23,26,7,33,58,41,25,52,40,58,9,52,40]


    string s1 = "[26,50,47,11,56,31,18,55,32,9,4,2,23,53,43,0,44,30,6,51,29,51,15,17,22,34,38,33,42,3,25,10,49,51,7,58,16,21,19,31,19,12,41,35,45,52,13,59,47,36,1,28,48,39,24,8,46,20,5,54,27,37,14,57,40,59,8,45,4,51,47,7,58,4,31,23,54,7,9,56,2,46,56,1,17,42,11,30,12,44,14,32,7,10,23,1,29,27,6,10,33,24,19,10,35,30,35,10,17,49,50,36,29,1,48,44,7,11,24,57,42,30,10,55,3,20,38,15,7,46,32,21,40,16,59,30,53,17,18,22,51,11,53,36,57,26,5,           ,55,31,34,57,7,52,37,31,10,0,51,41,2,32,25,0,7,49,47,13,14,24,57,28,4,45,43,39,38,8,2,44,45,29,25,25,12,54,5,44,30,27,23,26,7,33,58,41,25,52,40,58,9,52,40]";
    string s2 = "[26,50,47,11,56,31,18,55,32,9,4,2,23,53,43,0,44,30,6,51,29,51,15,17,22,34,38,33,42,3,25,10,49,51,7,58,16,21,19,31,19,12,41,35,45,52,13,59,47,36,1,28,48,39,24,8,46,20,5,54,27,37,14,57,40,59,8,45,4,51,47,7,58,4,31,23,54,7,9,56,2,46,56,1,17,42,11,30,12,44,14,32,7,10,23,1,29,27,6,10,33,24,19,10,35,30,35,10,17,49,50,36,29,1,48,44,7,11,24,57,42,30,10,55,3,20,38,15,7,46,32,21,40,16,59,30,53,17,18,22,51,11,53,36,57,26,5,           ,55,31,34,57,7,52,37,31,10,0,51,41,2,32,25,0,7,49,47,13,14,24,57,28,4,45,43,39,38,8,2,44,45,29,25,25,12,54,5,44,30,27,23,26,7,33,58,41,25,52,40,58,9,52,40]";

    cout<<" ? "<<(s1==s2)<<endl;

    myvi tar = {26,50,47,11,56,31,18,55,32,9,4,2,23,53,43,0,44,30,6,51,29,51,15,17,22,34,38,33,42,3,25,10,49,51,7,58,16,21,19,31,19,12,41,35,45,52,13,59,47,36,1,28,48,39,24,8,46,20,5,54,27,37,14,57,40,59,8,45,4,51,47,7,58,4,31,23,54,7,9,56,2,46,56,1,17,42,11,30,12,44,14,32,7,10,23,1,29,27,6,10,33,24,19,10,35,30,35,10,17,49,50,36,29,1,48,44,7,11,24,57,42,30,10,55,3,20,38,15,7,46,32,21,40,16,59,30,53,17,18,22,51,11,53,36,57,26,5,         36,56  ,55,31,34,57,7,52,37,31,10,0,51,41,2,32,25,0,7,49,47,13,14,24,57,28,4,45,43,39,38,8,2,44,45,29,25,25,12,54,5,44,30,27,23,26,7,33,58,41,25,52,40,58,9,52,40};

    LT1882 lt;

    myvi vi = lt.lt1882b(ser, tsk);

    showVectorInt(vi);

    for (int i = 0; i < tar.size(); ++i)
    {
        if (tar[i] != vi[i])
        {
            cout<<i<<", "<<tar[i]<<", "<<vi[i]<<endl;
        }
    }

    return 0;
}
