
#include "../header/myheader.h"

class LT1505
{
public:

    // D

    // Segment Tree�� Fenwick Tree




    // g


    // Ӧ��Ҫ ��ά��һ�� arr[10]�� ���� �ж��� ���� ��
    // Ӧ���� swap�� �޸� arr[10]����� arr[x] ��ֵ С�� ����ǰ���Ǹ�ֵ���±꣬�� ++ �� ������Ҫ����   ����� �����arr[10]�� ��Ҫ�� ���� �����ʱ�� ���ǵ���
    // ���� ��� һֱ���󣬵���  ֮ǰ����ǰ���±� �� ǰ���ˣ� ��ô ����Ҫ �±��ֵ -- ��  ��Ҫά�� �޸ĵ��±꼯�ϡ���


    //string lt1505b(string num, int k)
    //{
    //    int arr[10] = { 0 };                // next idx's index
    //    std::fill(begin(arr), end(arr), -1);

    //    string ans(num.size(), ' ');
    //    int ansi = 0;
    //    for (int i = 0; i < num.size(); ++i)
    //    {
    //        if (num[i] == 'a')
    //            continue;
    //        int n = num[i] - '0';
    //        int chose = -1;
    //        if (k > 0)
    //        {
    //            for (int a = 0; a < n; ++i)
    //            {
    //                while (arr[a] <)
    //            }
    //        }
    //    }
    //}


    // error
    // ... swap �� ����ͷ����˱仯������
    string lt1505a(string num, int k)
    {
        vector<pair<int, vector<int>>> vp(10);
        for (int i = 0; i < num.size(); ++i)
        {
            vp[num[i] - '0'].second.push_back(i);
        }
        string ans(num.size(), ' ');
        int ansi = 0;
        for (int i = 0; i < num.size(); ++i)
        {
            if (num[i] == 'a')
                continue;

            int n = num[i] - '0';
#ifdef __test
            //cout << n << "..." << endl;
#endif
            int chose = -1;
            if (k > 0)
                for (int a = 0; a < n; ++a)
                {
#ifdef __test
                    //cout << vp[a].first << ", " << vp[a].second.size() << ", " << k << endl;
#endif

                    while (vp[a].first < vp[a].second.size() && (vp[a].second[vp[a].first] < i))
                        vp[a].first++;

                    if (vp[a].first < vp[a].second.size() && (vp[a].second[vp[a].first] - i <= k))
                    {
                        k -= vp[a].second[vp[a].first] - i;
                        chose = vp[a].second[vp[a].first];
                        vp[a].first++;
                        break;
                    }
                }
#ifdef __test
            //cout << i << ", " << chose << ", " << ansi << endl;
#endif
            if (chose == -1)
            {
                ans[ansi++] = num[i];
            }
            else
            {
                ans[ansi++] = num[chose];
                num[chose] = 'a';
                i--;
            }
#ifdef __test
            cout << num << " - " << ans << ", " << k << endl;
#endif
        }
        return ans;
    }


    // �о���tle��  3���a��k��1�� �Ǿ� С�� 3��*1��  ���� findMinInRange ���� �ж� nowi+i<s.size()

    // ���ڲ���swap��
    // �������k����Χ�ڣ���С�ģ����Լ�������Ȼ�� k-����������
    // �� ��С�� �ŵ� ��ǰλ�ã� ������ �������һλ��
    //string lt1505a(string num, int k)
    //{
    //    while (k > 0)
    //    {

    //    }
    //}

    //int findMinInRange(string& s, int nowi, int k)
    //{
    //    char mnch = s[nowi];
    //    int mni = nowi;
    //    for (int i = 1; i <= k; ++i)
    //    {
    //        if (s[i + nowi] < mnch)
    //        {
    //            mnch = s[i + nowi];
    //            mni = nowi + i;
    //        }
    //    }
    //    return mni == nowi ? -1 : mni;
    //}

};

int main()
{

    LT1505 lt;

    //string s = "4321";
    //int k = 4;

    //string s = "100";
    //int k = 1;

    //string s = "36789";
    //int k = 1233;

    string s = "9438957234785635408";           // "0345989723478563548"
    int k = 23;


    cout << lt.lt1505a(s, k) << endl;

    return 0;
}
