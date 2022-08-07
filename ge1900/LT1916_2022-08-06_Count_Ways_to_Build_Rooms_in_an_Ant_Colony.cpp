
#include "../header/myheader.h"

class LT1916
{
public:

    // D


    // ������
    // nCr ���ټ���



    // g


    // tle
    int lt1916b(vector<int>& prevRoom)
    {
        int sz1 = prevRoom.size();
        vector<pair<int, int>> vp(sz1);
        unordered_map<int, vector<int>> map2;
        unordered_map<int, unordered_map<int, int>> map3;
        for (int i = 1; i < sz1; ++i)
            map2[prevRoom[i]].push_back(i);

        pair<int, int> ans = dfsb1(vp, 0, map2, map3);

#ifdef __test
        for (pair<int, int>& p : vp)
            cout << p.first << " - " << p.second << endl;
#endif

        return ans.second;
    }

    // node count : order
    pair<int, int> dfsb1(vector<pair<int, int>>& vp, int idx, unordered_map<int, vector<int>>& map2, unordered_map<int, unordered_map<int, int>>& map3)
    {
        if (vp[idx].first != 0)
            return vp[idx];

        int cnt = 1;
        long long ans = 1LL;
        const long long MOD = 1e9 + 7;

        if (map2.find(idx) != map2.end())
        {
            for (int nxt : map2[idx])
            {
                pair<int, int> p = dfsb1(vp, nxt, map2, map3);
                cnt += p.first;
                //ans = (ans * cb(cnt - 1, p.first)) % MOD;           // root �����һ����
                ans = (ans * cb2(cnt - 1, p.first, map3)) % MOD;
                ans = (ans * p.second) % MOD;
            }
        }

        return vp[idx] = std::make_pair(cnt, (int) ans);
    }


    int cb2(int n, int a, unordered_map<int, unordered_map<int, int>>& map3)
    {
        a = min(a, n - a);

        if (a == 1)
            return n;
        if (a == 0)
            return 1;

        if (map3.find(n) != map3.end() && map3[n].find(a) != map3[n].end())
            return map3[n][a];

        const int MOD = 1e9 + 7;

        int ans = (cb2(n - 1, a - 1, map3) + cb2(n - 1, a, map3)) % MOD;
        map3[n][a] = ans;
        return ans;
    }

    // C(n, m) = C(n - 1, m) + C(n - 1, m - 1)
    // ������ɡ�����
    int cb__(int n, int a)
    {
        int b = n - a;

        int a2 = 2;
        int b2 = 2;
        long long ans = 1LL;

        for (int i = n; i >= 2; --i)
        {
            ans = ans * i;                      // 2455248700467763200 * 37

            while (a2 <= a && (ans % a2) == 0)      // 1565173992043432680 * 12
            {
                ans /= a2;
                a2++;
            }
            while (b2 <= b && (ans % b2) == 0)
            {
                ans /= b2;
                b2++;
            }

            //while (a > 1 && ((ans % a) == 0))
            //{
            //    ans /= a;
            //    a--;
            //}
            //while (b > 1 && ((ans % b) == 0))
            //{
            //    ans /= b;
            //    b--;
            //}
        }

        return ans % 1000000007;
    }


    // error
    // ��һ����ֻ�� �� 0������ �ſ���
    // �ڶ����� �� 0���� �� �� ��һ��������
    // 3�� 0 or ��һ�� or �ڶ�����
    // prevRoom�� ֻ��һ�� �Ⱦ�����
    // ��һ��ȡ1���ڶ���ȡ2��    �� ��һ��ȡ2���ڶ���ȡ1��     ���ڵ�������˵ ��һ���� ���Կ��� top-down
    // ���ǳ���10^5..  ������key��
    //
    // hint�� Let dp[i] be the number of ways to solve the problem for the subtree of node i.
    int lt1916a(vector<int>& prevRoom)
    {
        int sz1 = prevRoom.size();
        vector<int> vi(sz1, -1);
        unordered_map<int, vector<int>> map2;       // node : children
        for (int i = 1; i < sz1; ++i)
        {
            map2[prevRoom[i]].push_back(i);
        }

        int ans = dfsa1(vi, 0, map2);
        return ans;
    }

    int dfsa1(vector<int>& vi, int idx, unordered_map<int, vector<int>>& map2)
    {
        if (vi[idx] != -1)
            return vi[idx];

        long long ans = 1LL;
        const long long MOD = 1e9 + 7;

        if (map2.find(idx) != map2.end())
        {
            for (int nxt : map2[idx])
            {
                //ans = (ans * dfsa1(vi, nxt, map2)) % MOD;
                // ֻҪ�����ڲ�˳�� �����ҾͿ��ԣ�  2������ ���� ����ġ�
                // x C y

            }
        }

        return vi[idx] = (int) ans;
    }

};

int main()
{

    LT1916 lt;

    //myvi v = { -1,0,1 };
    //myvi v = { -1,0,0,1,2 };
    myvi v = {-1, 0, 1, 2, 1};


    cout << lt.lt1916b(v) << endl;

    return 0;
}
