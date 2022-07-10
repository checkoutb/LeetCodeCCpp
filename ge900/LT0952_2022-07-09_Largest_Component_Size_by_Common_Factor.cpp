
#include "../header/myheader.h"

class LT0952
{
public:

    // D

    //for (int i = 0; i < N; i++) {
    //    int a = A[i];
    //    for (int j = 2; j * j <= a; j++) {
    // 
    // ������ÿ��������ʽ�ֽ⡣


    //for (int& a : A) {
    //    for (int k = 2; k <= sqrt(a); k++) {
    //        if (a % k == 0) {
    //            ufs.Union(a, k);
    //            ufs.Union(a, a / k);
    //        }
    //    }
    //}

    // ���Լ�������uf��


    // g

    // ����˵����ѡ�� nums �е�������Ȼ����㣿   ֵ��unique�ġ�
    // ���߶�ÿ�����ֽ�����ʽ�ֽ⡣������
    // ���߶�ÿ������ * {2..316} ���Ƿ���� ������������316��Ӧ�û���һ�롣��


    // tle������
    // 10�������� ���1�����������������sqrt(10��) = 316.xxx�� ��ʽ�ֽ⣬�ֽ⵽ ������
    // ... ����sqrt������2��13��26 ������ 13.���� ������ һ�롣����
    int lt0952b(vector<int>& nums)
    {
        int sz1 = nums.size();
        bitset<50005> bs;         // [0,0,0..0]

        vector<int> uf(sz1, -1);

        int mx = *max_element(begin(nums), end(nums));

        //int sqt = sqrt(mx);
        int sqt = mx / 2 + 1;

        for (int i = 2; i <= sqt; ++i)
        {

            if (!bs[i])
            {
                for (int j = (i << 1); j <= sqt; j += j)
                {
                    bs.set(j);      // set 1
                }

#ifdef __test
                cout << "factor : " << i << endl;
#endif

                int tp = -1;
                for (int j = 0; j < sz1; ++j)
                {
                    if ((nums[j] % i) == 0)
                    {
                        if (tp == -1)
                        {
                            tp = ufa(uf, j);
                        }
                        else
                        {
                            int t2 = ufa(uf, j);
                            if (t2 != tp)
                                uf[t2] = tp;
                        }
                    }
                }
            }
        }

        unordered_map<int, int> map2;

        for (int i = 0; i < sz1; ++i)
        {
            map2[ufa(uf, i)]++;
        }
        int ans = 0;
        for (auto& p : map2)
            ans = max(ans, p.second);

        return ans;
    }


    // tle *2 .. ����sort�� ����һ��㡣����
    int lt0952a(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<int> uf(sz1, -1);

        sort(begin(nums), end(nums));

        for (int i = 0; i < sz1; ++i)
        {
            for (int j = i + 1; j < sz1; ++j)
            {
                int u1 = ufa(uf, i);
                int u2 = ufa(uf, j);

                if (u1 == u2)
                    continue;

                int t2 = gcda(max(nums[i], nums[j]), min(nums[i], nums[j]));
                if (t2 != 1)
                {
                    uf[u1] = u2;
                }
            }
        }
        unordered_map<int, int> map2;
        for (int i = 0; i < sz1; ++i)
        {
            map2[ufa(uf, i)]++;
        }
        int ans = 0;
        for (auto& p : map2)
        {
            ans = max(ans, p.second);
        }
        return ans;
    }

    int gcda(int a, int b)
    {
        return (b == 0) ? a : gcda(b, a % b);
    }

    int ufa(vector<int>& uf, int i)
    {
        return (uf[i] == -1) ? i : (uf[i] = ufa(uf, uf[i]));
    }

};

int main()
{

    LT0952 lt;

    //myvi v = { 4,6,15,35 };

    //myvi v = { 20,50,9,63 };

    myvi v = { 2,3,6,7,4,12,21,39 };

    cout << lt.lt0952b(v) << endl;

    return 0;
}
