
#include "../header/myheader.h"

class LT1478
{
public:

    // D

    // Ԥ�ȼ����� [i][j] �� ֻ��һ�� ���� �� �ܾ���
    //
    // dp[k][i]  �� i ��ʼ �� ���ķ��ӣ��ܹ� k ������ �����ġ�
    //for (int j = i; j < n; j++)
    //    ans = min(ans, costs[i][j] + dp(houses, n, k - 1, j + 1));


    // g



    // tle������
    // 
    // ����Ӧ���� ĳЩhouse �ſڡ� �Ų��ſ� ��һ����ֻ���� �ſں��㡣
    // �� �޳����䣬���� �������䡣
    // ���Էֿ�ģ�dfs+memo 
    // ���ǣ�ȡ�ŵ�ʱ�򣬲����ܳ���  2���������� �������� �� ��� ���Ա���
    // ������� ���� ͬһ���ʱ����ֻ��һ�����䣬 ��ô������� �� ��λ�� ������ʡ�   (x+1)/2
    // [house st][house en][mailbox]
    int lt1478a(vector<int>& houses, int k)
    {
        int sz1 = houses.size();

        if (sz1 == k)
            return 0;

        sort(begin(houses), end(houses));

        vector<vector<vector<int>>> vvvi(sz1, vector<vector<int>>(sz1, vector<int>(k + 1, -1)));

        dfsa1(houses, k, 0, sz1 - 1, vvvi);

        return vvvi[0][sz1 - 1][k];
    }

    int dfsa1(vector<int>& hs, int k, int st, int en, vector<vector<vector<int>>>& vvvi)
    {
        if ((en - st + 1) <= k)
            return 0;

        if (vvvi[st][en][k] != -1)
            return vvvi[st][en][k];

        if (k == 1)
        {
            int t2 = (st + (en - st + 1) / 2);
            t2 = hs[t2];
            int ans = 0;

            for (int i = st; i <= en; ++i)
            {
                ans += abs(hs[i] - t2);
            }
            vvvi[st][en][k] = ans;
            return ans;
        }

        int ans = INT_MAX;

        for (int i = st; i < en; ++i)
        {
            for (int j = 1; j < k; ++j)
            {
                int t2 = dfsa1(hs, j, st, i, vvvi) + dfsa1(hs, k - j, i + 1, en, vvvi);
                ans = min(ans, t2);
            }
        }
        vvvi[st][en][k] = ans;
        return ans;
    }

};

int main()
{

    LT1478 lt;

    //myvi v = { 1,4,8,10,20 };
    //int k = 3;

    myvi v = { 2,3,5,12,18 };
    int k = 5;

    cout << lt.lt1478a(v, k) << endl;

    return 0;
}
