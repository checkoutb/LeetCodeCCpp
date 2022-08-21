
#include "../header/myheader.h"

class LT1363
{
public:

    // D D


    //int m1[] = { 1, 4, 7, 2, 5, 8 }, m2[] = { 2, 5, 8, 1, 4, 7 };
    //int sum = 0, ds[10] = {};
    //for (auto d : digits) {
    //    ++ds[d];
    //    sum += d;
    //}
    //while (sum % 3 != 0) {
    //    for (auto i : sum % 3 == 1 ? m1 : m2) {
    //        if (ds[i]) {
    //            --ds[i];
    //            sum -= i;
    //            break;
    //        }
    //    }
    //}
    //for (int i = 9; i >= 0; --i)
    //    res += string(ds[i], '0' + i);
    //return res.size() && res[0] == '0' ? "0" : res;
    // 
    // .. ¼õ·¨¡£¡£


    //dp = [-1, -1, -1]
    //    for a in sorted(digits)[:: - 1]:
    //for x in dp[:] + [0] :
    //    y = x * 10 + a
    //    dp[y % 3] = max(dp[y % 3], y)
    //    return str(dp[0]) if dp[0] >= 0 else ""




//Runtime: 30 ms, faster than 83.09 % of C++ online submissions for Largest Multiple of Three.
//Memory Usage : 19.4 MB, less than 89.34 % of C++ online submissions for Largest Multiple of Three.

    // 1+2
    // 2+2+2
    // 1+1+1
    //
    //              3+3 -> min+min
    // 3+2 -> 2+2   min+min
    // 3+1 -> 3+0       // ...
    // 3+0 -> 3+0       // ...
    // 2+2 -> min(2,2) + min(2,2)
    // 2+1 -> 1+1 == min(2,1) + min(2,1)
    // 2+0  min+min
    // 1+1
    // 1+0
    // 0+0
    // 
    // 2+4 -> 1+1 + 3+0
    // 2+5 -> 2+2  3+0
    // 2+6 
    // 1+4
    // 5+0
    //
    // 3+4 ..min+min   1+1 -> 2+3 -> 2+2
    //
    // 3+5 ... 3+0 + 2+2 ....
    string lt1363a(vector<int>& digits)
    {
        map<int, int> map2;
        //vector<int> v1;
        //vector<int> v2;

        priority_queue<int> pq1;
        priority_queue<int> pq2;

        for (int i = 0; i < digits.size(); ++i)
        {
            switch (digits[i] % 3)
            {
            case 0:
                map2[digits[i]]++;
                break;
            case 1:
                //v1.push_back(digits[i]);
                pq1.push(digits[i]);
                if (pq1.size() >= 6)
                {
                    for (int a = 3; a > 0; --a)
                    {
                        map2[pq1.top()]++;
                        pq1.pop();
                    }
                }
                break;
            default:
                //v2.push_back(digits[i]);
                pq2.push(digits[i]);
                if (pq2.size() >= 6)
                {
                    for (int a = 3; a > 0; --a)
                    {
                        map2[pq2.top()]++;
                        pq2.pop();
                    }
                }
                break;
            }
        }
        if (pq1.size() > pq2.size())
        {
            swap(pq1, pq2);
        }

        // pq1.size() <= pq2.size();

#ifdef __test
        cout << pq1.size() << " - " << pq2.size() << endl;
#endif

        //if (pq2.size() > 3 && pq1.size() <= 3)
            while (pq2.size() > 3 && !pq1.empty())              // ...
            {
                map2[pq2.top()]++;
                map2[pq1.top()]++;
                pq2.pop();
                pq1.pop();
            }

        if (pq2.size() >= 3 && pq1.size() < 2)
        {
            while (!pq2.empty())
            {
                map2[pq2.top()]++;
                pq2.pop();
            }
        }
        else
        {
            for (int a = pq1.size(); a > 0; --a)
            {
                map2[pq1.top()]++;
                map2[pq2.top()]++;
                pq1.pop();
                pq2.pop();
            }
        }

#ifdef __test
        cout << pq1.size() << " + " << pq2.size() << endl;
#endif

        // 
        if (map2.size() == 1 && map2.begin()->first == 0)
            return "0";

        int sz1 = 0;
        for (auto& p : map2)
        {
            sz1 += p.second;
        }

        string ans(sz1, ' ');

        int idx = 0;

        for (map<int, int>::reverse_iterator it = map2.rbegin(); it != map2.rend(); ++it)
        {
            char ch = char('0' + it->first);
            for (int i = 0; i < it->second; ++i)
            {
                ans[idx++] = ch;
            }
        }

        return ans;
    }

};

int main()
{

    LT1363 lt;

    //myvi v = { 1,8,9 };
    //myvi v = { 1,6,7,8,0 };
    //myvi v = { 1 };
    //myvi v = { 0,0,0 };

    //myvi v = { 7, 1, 2, 4, 0, 0, 4, 0, 3, 8 };              // "874431000"

    myvi v = { 4,8,7,0,0,7,4,4,1,4,0,0,4,8,2,4,4,5,4,2,2,7,1,4,1,1,1,0,7,5,7,1,7,0,8,2,2,2,8,0,7,5,8,0,8,7,5,4,8,4,8,1,7,7,0,7,1,7,4,5,7,5,7,4,0,0,1 };

    cout << lt.lt1363a(v) << endl;

    return 0;
}
