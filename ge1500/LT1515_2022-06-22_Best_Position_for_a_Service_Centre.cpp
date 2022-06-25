
#include "../header/myheader.h"

class LT1515
{
public:

    // D

    // ��С����


    // error�� ��� ����վ��������Դ� С��


    // ѡ��һ�� x �ᣬ y�������£���õľ��� Ӧ���� �������ϵ������ߡ� ���Կ�����ǰ�˳��ġ�
    // ���е� x ���� ��С�� ���룬 Ӧ��Ҳ�� �������ϵ� �����ߡ�
    // ��֪����û�� һ��������� ��ʽ����
    double lt1515a(vector<vector<int>>& positions)
    {
        int mnx = 1111, mny = 1111, mxx = 0, mxy = 0;
        for (vector<int>& vi : positions)
        {
            mnx = min(vi[0], mnx);
            mny = min(vi[1], mny);
            mxx = max(vi[0], mxx);
            mxy = max(vi[1], mxy);
        }

        int x = (mnx + mxx) / 2;
        int x1 = x - 1;
        int x2 = x + 1;


        while (true)
        {


            tuple<int, int, double> tup = find_min(positions, x, mny, mxy);
            tuple<int, int, double> tup1 = find_min(positions, x, mny, mxy);
            tuple<int, int, double> tup2 = find_min(positions, x, mny, mxy);

            double db = std::get<2>(tup);
            double db1 = std::get<2>(tup1);
            double db2 = get<double>(tup2);

            if (db <= db1 && db <= db2)
            {
                return db;
            }
            if (db1 > db2)
            {
                x++, x1++, x2++;
            }
            else
            {
                x--, x1--, x2--;
            }
        }

        return -1;
    }

    // x, y, min_distance_sum
    // �о� ���Ӧ�ô�һ�㡣���� �����֣�
    tuple<int, int, double> find_min(vector<vector<int>>& positions, int x, int mny, int mxy)
    {
        int y = (mny + mxy) / 2;
        int y1 = y - 1;
        int y2 = y + 1;

        double sm = 0;
        double sm1 = 0;
        double sm2 = 0;

        bool cal = true;
        bool cal1 = true;
        bool cal2 = true;

        while (true)
        {
            if (cal)
                sm = 0;
            if (cal1)
                sm1 = 0;
            if (cal2)
                sm2 = 0;

            for (vector<int>& vi : positions)
            {
                int a = vi[0], b = vi[1];
                int t2 = (a - x) * (a - x);
                if (cal)
                    sm += std::sqrt(t2 + (b - y) * (b - y));
                if (cal1)
                    sm1 += std::sqrt(t2 + (b - y1) * (b - y1));
                if (cal2)
                    sm2 += std::sqrt(t2 + (b - y2) * (b - y2));
            }

            cal = cal1 = cal2 = false;

            if ((sm <= sm1 && sm <= sm2))
            {
#ifdef __test
                cout << x << ", " << y << ", " << sm << endl;
#endif
                return { x, y, sm };
            }
            if (sm1 > sm2)          // '\'
            {
                sm1 = sm;
                sm = sm2;
                cal2 = true;
                y++;
                y1++;
                y2++;
            }
            else
            {
                sm2 = sm;
                sm = sm1;
                cal1 = true;
                y--;
                y1--;
                y2--;
            }
        }
        return { 1,1,1 };
    }

};

int main()
{

    LT1515 lt;

    //myvvi vv = { {1,0},{1,2},{2,1},{0,1} };

    // myvvi vv = { {1,1},{3,3} };

    myvvi vv = { {1, 1},{0, 0},{2, 0} };            // 2.73205   1+sqrt(3)      .. �ѵ���� ���겻��������

    cout << lt.lt1515a(vv) << endl;

    //cout << sqrt(3) << endl;

    return 0;
}
