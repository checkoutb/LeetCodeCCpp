
#include "../header/myheader.h"

class LT2332
{
public:


    // D D


    //for (int i = 0; i < buses.size(); i++) {
    //    int count = 0;
    //    while (count < capacity && j < m && passengers[j] <= buses[i]) {
    //        count++;
    //        if (j == 0 || (j && passengers[j] > passengers[j - 1] + 1))
    //            ans = passengers[j] - 1;
    //        j++;
    //    }
    //
    //    if (count < capacity && (j == 0 || passengers[j - 1] != buses[i])) {
    //        ans = buses[i];
    //    }
    //}

    // for 循环中 直接计算 ans。

    

        //07 / 10 / 2022 18 : 37	Accepted	319 ms	66.3 MB	cpp
        //07 / 10 / 2022 18 : 36	Runtime Error	N / A	N / A	cpp
        //07 / 10 / 2022 18 : 34	Wrong Answer	N / A	N / A	cpp
        //07 / 10 / 2022 18 : 32	Runtime Error	N / A	N / A	cpp
//Runtime: 319 ms, faster than 50.00 % of C++ online submissions for The Latest Time to Catch a Bus.
//Memory Usage : 66.3 MB, less than 50.00 % of C++ online submissions for The Latest Time to Catch a Bus.
    // bus 离开的时间， 乘客来的时间
    // 乘客到达时间 <= bus离开时间 且 bus 不满， 就可以上车
    // 乘客会排队。
    // 返回 最晚的时间， 这个时间点，你到车站，就能上车。
    // 那就是找 最后一个 上车的人， 点击替换他(比他快1秒)， 我就可以上车了。  当然，车没满的话，随便。
    // 有限制，不能同时到达，那么就得往前搜索一个空位。
    int lt2332a(vector<int>& buses, vector<int>& passengers, int capacity)
    {
        sort(begin(buses), end(buses));
        sort(begin(passengers), end(passengers));

        int sz1 = buses.size();
        int sz2 = passengers.size();

        int ibus = 0;
        int ipas = 0;
        int cnt = 0;

        for (; ibus < sz1; ++ibus)
        {
            int leave = buses[ibus];
            cnt = 0;
            for (int i = 0; i < capacity && ipas < sz2 && passengers[ipas] <= leave; ++i)
            {
                ++ipas;
                cnt++;
            }

        }
        --ipas;         // last passenger

#ifdef __test
        cout << ipas << endl;
#endif

        if (ipas == -1)                         // ...
        {
            return buses[ibus - 1];
        }

        if (cnt < capacity)
        {
            //return buses[ibus - 1];
            if (buses[ibus - 1] > passengers[ipas])             // .
                return buses[ibus - 1];
        }


        int ans = passengers[0] - 1;

        for (int i = ipas; i >= 1; --i)
        {
            if (passengers[i - 1] != passengers[i] - 1)
            {
                ans = passengers[i] - 1;
                break;
            }
        }
        
        return ans;
    }

};

int main()
{

    LT2332 lt;

    //myvi v = { 10,20 };               // 16
    //myvi v2 = { 2,17,18,19 };
    //int cap = 2;
    
    //myvi v = { 20,30,10 };              // 20
    //myvi v2 = { 19,13,26,4,25,11,21 };
    //int cap = 2;

    //myvi v = { 2 };             // 1
    //myvi v2 = { 2 };
    //int cap = 2;

    myvi v = { 3 };
    myvi v2 = { 4 };
    int cap = 1;

    cout << lt.lt2332a(v, v2, cap) << endl;

    return 0;
}
