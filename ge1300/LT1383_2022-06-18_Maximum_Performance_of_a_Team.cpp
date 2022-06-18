
#include "../header/myheader.h"

#include <array>

class LT1383
{
public:

    // D D

    //vector<pair<int, int>> eff_sp;
    //priority_queue <int, vector<int>, greater<int> > pq_speeds;


    //We keep the queue with maximum size of k.
    //Each time when we introduce a new engineer,
    //we need only O(logK) to find the smallest speed in the team now.
    // 
    //vector<pair<int, int>> ess(n);
    //for (int i = 0; i < n; ++i)
    //    ess[i] = { efficiency[i], speed[i] };
    //sort(rbegin(ess), rend(ess));             // .. 反序 rbegin。。。
    //long sumS = 0, res = 0;
    //priority_queue <int, vector<int>, greater<int>> pq; //min heap
    //for (auto& [e, s] : ess) {
    //    pq.emplace(s);
    //    sumS += s;
    //    if (pq.size() > k) {
    //        sumS -= pq.top();
    //        pq.pop();
    //    }
    //    res = max(res, sumS * e);
    //}

    // 效率从高到低，这样，遍历的时候，可以保证 que中的 是全部 高效的。。 然后删除 速度最低的。


    // 。。。。。。。 提交的 是没有 cout 的。
//Runtime: 258 ms, faster than 11.26 % of C++ online submissions for Maximum Performance of a Team.
//Memory Usage : 48.5 MB, less than 5.12 % of C++ online submissions for Maximum Performance of a Team.
    //  at most k at most k at most k at most k at most k at most k at most k at most k at most k
    int lt1383b(int n, vector<int>& speed, vector<int>& efficiency, int k)
    {
        vector<array<int, 3>> va(n);
        vector<array<int, 3>> va2(n);
        for (int i = 0; i < n; ++i)
        {
            //std::array<int, 3> a = { speed[i], efficiency[i], i };           // error C2079: “a”使用未定义的 class“std::array<int,3>”
            //va[i] = a;
            va[i] = { speed[i], efficiency[i], i };
            va2[i] = array<int, 3>{ efficiency[i], speed[i], i };
        }
        sort(begin(va), end(va));
        sort(begin(va2), end(va2));

        //priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minq;
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> minq;

        unordered_set<int> set2;        // minq.[2]

        // cout << "asd" << endl;

        long sum2 = 0L;
        long ans = 0L;
        int idxva = va.size() - 1;

        for (int i = 0; i < n; ++i)
        {
            int eff = va2[i][0];
            int spd = va2[i][1];
            int idx = va2[i][2];

            while (!minq.empty() && (minq.top().operator[](0) < eff || (minq.top()[0] == eff && minq.top()[1] < spd)))      // <= spd ?
            {
                cout << sum2 << ", - " << minq.top()[1] << endl;


                sum2 -= minq.top()[1];

                set2.erase(minq.top()[2]);
                cout << "..                                   del " << minq.top()[2] << endl;

                minq.pop();

                // cout << " ??" << endl;

            }

            cout << "  .. " << minq.size() << endl;
            if (!minq.empty())
                cout << "          .. " << minq.top()[1] << " spd ? eff: " << minq.top()[0] << endl;

            if (minq.size() < k && idxva >= 0 && (spd <= va[idxva][0])
                && set2.find(idx) == set2.end()
                )
            {

#ifdef __test
                cout << " ------ " << i;            // .... i .... idx ....
                cout << " - -set: ";
                for (int asd : set2)
                    cout << asd << ", ";
                cout << endl;
#endif



                minq.push({ eff, spd, idx });
                set2.insert(idx);
                cout << "..                           11    insert " << i << endl;

                cout << sum2 << " +1 " << spd << " .. " << eff << ", " << idxva << ", " << i << ",,. " << va[idxva][2] << endl;

                sum2 += spd;
            }

            // cout << "asd" << i << endl;

            while (minq.size() < k && idxva >= 0)
            {
                // cout << "?222" << endl;
                if (va[idxva][1] > eff || (va[idxva][1] == eff && va[idxva][0] >= spd))
                {
                    if (idx == va[idxva][2])
                    {
                        idxva--;        // ..
                        continue;
                    }

                    cout << sum2 << " +2 " << va[idxva][0] << endl;

                    sum2 += va[idxva][0];
                    minq.push({ va[idxva][1], va[idxva][0], va[idxva][2] });
                    set2.insert(va[idxva][2]);
                    cout << "..                          22   isert " << va[idxva][2] << endl;
                }
                idxva--;
            }
            //if (minq.size() == k)
            //{
#ifdef __test
                cout << "                  " << eff << ", " << spd << ", " << sum2 << ", " << ans << endl;
#endif
                ans = max(ans, sum2 * eff);
            //}
            //else
            //{
            //    break;
            //}

        }

        // cout << ans << endl;

        return ans % int (1e9 + 7);
    }


    // error  无法区分。
    // sum(speed) * min(efficiency)
    // sort by efficiency..  remove all ones that efficiency < efficiency
    int lt1383a(int n, vector<int>& speed, vector<int>& efficiency, int k)
    {
        // speed, eff
        vector<pair<int, int>> vp(n);
        // eff, speed
        vector<pair<int, int>> vp2(n);
        for (int i = 0; i < n; ++i)
        {
            vp[i] = make_pair(speed[i], efficiency[i]);
            vp2[i] = make_pair(efficiency[i], speed[i]);
            //vp.emplace_back(make_pair( speed[i], efficiency[i] ));
            //// vp2.emplace_back({ efficiency[i], speed[i] });           // 没有这种重载函数。
            //vp2.emplace_back(make_pair( efficiency[i], speed[i] ));
        }
        sort(begin(vp), end(vp));
        //sort(begin(efficiency), end(efficiency));
        sort(begin(vp2), end(vp2));

#ifdef __test
        for (pair<int, int>& p : vp2)
        {
            cout << p.first << ", " << p.second << endl;
        }
#endif


        // eff, speed
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minq;

        long sum2 = 0L;
        int mneff = 0;
        const int MOD = 1e9 + 7;
        int idxvp = vp.size() - 1;
        // int ans = INT_MAX;
        long ans = 0L;

        for (int i = 0; i < n; ++i)
        {
            int eff = vp2[i].first;
            // cout << " ?? " << eff << "?.." << n << endl;
            int spd = vp2[i].second;

            while (!minq.empty() && (minq.top().first < eff || (minq.top().first == eff && minq.top().second < spd)))
            {
                sum2 -= minq.top().second;
                minq.pop();
            }
            minq.push({ eff, spd });                // 这里push 和 下面的 push 可能是同一个工程师。无法区分。。
            sum2 += spd;
            while (minq.size() < k && idxvp >= 0)
            {
                if (vp[idxvp].second > eff || (vp[idxvp].second == eff && vp[idxvp].first >= spd))
                {
                    sum2 += vp[idxvp].first;
                    minq.push({ vp[idxvp].second, vp[idxvp].first });
                }
                idxvp--;
            }
            if (minq.size() == k)
            {
#ifdef __test
                cout << ans << ", " << sum2 << ", " << eff << endl;
#endif

                ans = max(ans, sum2 * eff);
            }
            else
            {
                break;
            }
        }
        return ans % MOD;

        //for (int i = 0; i < efficiency.size(); ++i)
        //{
        //    while (!minq.empty() && minq.top().first <= efficiency[i])      // == 怎么处理?
        //    {
        //        minq.pop();
        //    }
        //    
        //    while (minq.size() < k && idxvp >= 0)
        //    {
        //        if (vp[idxvp].second >= efficiency[i])      // ==
        //        {
        //            minq.push({ vp[idxvp].second, vp[idxvp].first });
        //            idxvp--;
        //        }
        //    }
        //    if (minq.)
        //}

    }

};

int main()
{

    LT1383 lt;

    //myvi v1 = { 2,10,3,1,5,8 };
    //myvi v2 = { 5,4,3,9,7,2 };
    //int k = 2;
    //k = 3;
    //k = 4;


    //myvi v1 = { 2, 8, 2 };
    //myvi v2 = { 2, 7, 1 };          // 56
    //int k = 2;


    //myvi v1 = { 8, 9, 5, 9 };        // 84   （5+9）* min(6,9)
    //myvi v2 = { 1, 2, 6, 9 };
    //int k = 2;

    
    myvi v1 = { 6, 7, 4 };          // 130          // 54 / 55 test cases passed.
    myvi v2 = { 10, 10, 2 };
    int k = 2;

    cout << lt.lt1383b((int)v1.size(), v1, v2, k) << endl;


    return 0;
}
