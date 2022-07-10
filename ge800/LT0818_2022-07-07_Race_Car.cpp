
#include "../header/myheader.h"

class LT0818
{
public:


    // D D

    // 2�ֲ���
    // 1. ����target��Ȼ��ת��
    // 2. ����target��ǰһ����ת��*2


// if (!visited.contains(nextSpeed + "," + nextPosition) && Math.abs(target - nextPosition) < target) {


    // 600�� �� 3�� ���� Testcase 3452 ������ġ���һֱ���ӣ�ֱ�� ���� true�������ʼ��ʱ���� 6ǧ �� 200 ������
//Runtime: 2838 ms, faster than 5.02 % of C++ online submissions for Race Car.
//Memory Usage : 183.2 MB, less than 5.02 % of C++ online submissions for Race Car.
    int lt0818a(int target)
    {
        unordered_map<int, unordered_map<int, int>> map2;       // <pos, <spd, step>>
        queue<pair<int, int>> que1;
        que1.push({ 0, 1 });
        map2[0][1] = 0;

        while (!que1.empty())
        {
            pair<int, int> p = que1.front();
            que1.pop();
            int pos = p.first;
            int spd = p.second;
            int stp = map2[pos][spd];

#ifdef __test
            cout << pos << ", " << spd << ", " << stp << endl;
#endif

            if (pos == target)
                return stp;

            p = funAa1(pos, spd);
            int np = p.first;
            int ns = p.second;

            if (abs(np) < 60770012)
            {
                if (abs(ns) < 30710)
                {
                    if (map2.find(np) == map2.end() || map2[np].find(ns) == map2[np].end())
                    {
                        map2[np][ns] = stp + 1;
                        que1.push({ np, ns });
                    }
                }
            }

            p = funRa1(pos, spd);
            np = p.first;
            ns = p.second;

            if (abs(np) < 60770012)
            {
                if (abs(ns) < 30710)
                {
                    if (map2.find(np) == map2.end() || map2[np].find(ns) == map2[np].end())
                    {
                        map2[np][ns] = stp + 1;
                        que1.push({ np, ns });
                    }
                }
            }

        }
        return -1;
    }

    pair<int, int> funAa1(int pos, int spd)
    {
        return { pos + spd, spd * 2 };
    }

    pair<int, int> funRa1(int pos, int spd)
    {
        return { pos, spd > 0 ? -1 : 1 };
    }

};

int main()
{

    LT0818 lt;

    int t = 6;


    cout << lt.lt0818a(t) << endl;

    return 0;
}
