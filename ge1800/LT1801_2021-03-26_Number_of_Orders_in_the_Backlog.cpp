
#include "../header/myheader.h"

class LT1801
{
public:

// D D

//map<int,long> buy, sell;
// long .

//        map<int, int> sell;
//        map<int, int, greater<int>> buy;


//    auto getAmount = []( priority_queue<array<int, 2>> &pq) {
//        long res = 0;
//        while (!pq.empty())
//            res += pq.top()[1], pq.pop();
//        return res;
//    };
//    priority_queue<array<int, 2>> buy, sell;
//    for (auto &o : orders) {
//        if (o[2])
//            sell.push({-o[0], o[1]});
//        else
//            buy.push({o[0], o[1]});
//        while (!sell.empty() && !buy.empty() && -sell.top()[0] <= buy.top()[0]) {
//            auto [sell_p, sell_a] = sell.top(); sell.pop();
//            auto [buy_p, buy_a] = buy.top(); buy.pop();
//            if (sell_a > min(sell_a, buy_a))
//                sell.push({sell_p, sell_a - min(sell_a, buy_a)});
//            if (buy_a > min(sell_a, buy_a))
//                buy.push({buy_p, buy_a - min(sell_a, buy_a)});
//        }
//    }
//    return (getAmount(sell) + getAmount(buy)) % 1000000007;




//Runtime: 192 ms, faster than 99.50% of C++ online submissions for Number of Orders in the Backlog.
//Memory Usage: 64.1 MB, less than 58.47% of C++ online submissions for Number of Orders in the Backlog.
    int lt1801c(vector<vector<int>>& orders)
    {
        map<int, int> buy;
        map<int, int> sell;
        for (vector<int>& vi : orders)
        {

            #ifdef __test
            cout<<"++++"<<endl;
            if (!buy.empty())
                for (auto& p : buy)         // pair<int, int> buxing...
                    cout<<p.first<<", "<<p.second<<endl;
            cout<<" ====== "<<endl;
            if (!sell.empty())
                for (auto& p : sell)
                    cout<<p.first<<", "<<p.second<<endl;
            cout<<" - -- "<<endl;
            #endif // __test

            if (vi[2] == 0)
            {
                while (!sell.empty() && vi[1] > 0 && vi[0] >= sell.begin()->first)
                {
                    if (vi[1] >= sell.begin()->second)
                    {
                        vi[1] -= sell.begin()->second;
                        sell.erase(sell.begin());
                    }
                    else
                    {
                        sell.begin()->second -= vi[1];
                        vi[1] = 0;
                    }
                }
                if (vi[1] > 0)
                {
                    buy[vi[0]] += vi[1];
                }
            }
            else
            {
                while (!buy.empty() && vi[1] > 0 && vi[0] <= std::prev(buy.end())->first)
                {
                    if (vi[1] >= buy.rbegin()->second)
                    {
                        vi[1] -= buy.rbegin()->second;
                        buy.erase(prev(buy.end()));
                    }
                    else
                    {
                        buy.rbegin()->second -= vi[1];
                        vi[1] = 0;
                    }
                }
                if (vi[1] > 0)
                {
                    sell[vi[0]] += vi[1];
                }
            }
        }
        int ans = 0;
        const int mod = 1E9 + 7;
        while (!buy.empty())
        {
            ans = (ans + buy.begin()->second) % mod;
            buy.erase(buy.begin());
        }
        for (; !sell.empty(); sell.erase(sell.begin()))
        {
            ans = (ans + sell.begin()->second) % mod;
        }
        return ans;
    }


// 不可变的话，不如map
// .. sell 后不需要 (std::greater)， 加的话，估计是 指针
// pair不可变。。 bu，还是说 priq里不可变？ ... priq里不可变。。。
    int lt1801b(vector<vector<int>>& orders)
    {
//        priority_queue<pair<int, int>> buy;
//        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(std::greater<pair<int, int>>())> sell;
        priority_queue<vector<int>> buy;
        priority_queue<vector<int>, vector<vector<int>>, decltype(std::greater<vector<int>>())> sell;
        cout<<sell.empty()<<endl;
        for (vector<int>& vi : orders)
        {
            if (vi[2] == 0)
            {
//                while (!sell.empty() && vi[1] > 0 && vi[0] >= sell.top().first)
                while (!sell.empty()
                    && vi[1] > 0
                    && vi[0] >= sell.top()[0])
                {
                    if (vi[1] >= sell.top()[1])
                    {
                        vi[1] -= sell.top()[1];
                        sell.pop();
                    }
                    else
                    {
//                        sell.top()[1] -= vi[1];
                        vi[1] = 0;
                    }
                }
                if (vi[1] > 0)
                {
                    buy.push({vi[0], vi[1]});
                }
            }
            else
            {
//                while (!buy.empty() && vi[1] > 0 && vi[0] <= buy.top().first)
                while (!buy.empty() && vi[1] > 0 && vi[0] <= buy.top()[0])
                {
                    if (vi[1] >= buy.top()[1])
                    {
                        vi[1] -= buy.top()[1];
                        sell.pop();
                    }
                    else
                    {
//                        buy.top()[1] -= vi[1];
                        vi[1] = 0;
                    }
                }
                if (vi[1] > 0)
                {
                    sell.push({vi[0], vi[1]});
                }
            }
        }
        int ans = 0;
        const int mod = 1E9 + 7;
        while (!buy.empty())
        {
            ans = (ans + buy.top()[1]) % mod;
            buy.pop();
        }
        while (!sell.empty())
        {
            ans = (ans + sell.top()[1]) % mod;
            sell.pop();
        }
        return -1;
    }


// heap. priority_queue
    int lt1801a(vector<vector<int>>& orders)
    {
//        priority_queue<>
        map<int, int> buy;
        map<int, int> sell;
        for (vector<int>& vi : orders)
        {
            if (vi[2] == 0)     // buy
            {
                if (!sell.empty() && sell.begin()->first <= vi[0])
                {
                    if (vi[1] >= sell.begin()->second)
                    {
                        int t2 = vi[1] - sell.begin()->second;

                    }
                }
            }
            else
            {

            }
        }
        return -1;
    }

};

int main()
{
//    myvvi vv = {{10,5,0},{15,2,1},{25,1,1},{30,4,0}};
//    myvvi vv = {{7,1000000000,1},{15,3,0},{5,999999995,0},{5,1,1}};


    // 82
    myvvi vv = {{27,30,0},{10,10,1},{28,17,1},{19,28,0},{16,8,1},{14,22,0},{12,18,1},{3,15,0},{25,6,1}};

    LT1801 lt;

    cout<<lt.lt1801c(vv)<<endl;

//    pair<int, int> p = {1,3};
//    p.first = 3;
//    p.second = 5;
//    cout<<p.first<<", "<<p.second<<endl;
//
//    priority_queue<pair<int, int>> priq;
//    priq.push(p);
//    cout<<priq.top().first<<endl;
////    priq.top().first = 4;
//
//    priority_queue<vector<int>> pq;
//    pq.push({1,2});
//    cout<<pq.top()[1]<<endl;


    return 0;
}
