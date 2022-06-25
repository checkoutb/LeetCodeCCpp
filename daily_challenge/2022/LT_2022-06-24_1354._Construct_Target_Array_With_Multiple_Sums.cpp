
#include "../../header/myheader.h"

class LT
{
public:


    // D

    //while (true) {
    //    a = pq.top(); pq.pop();
    //    total -= a;
    //    if (a == 1 || total == 1)
    //        return true;
    //    if (a < total || total == 0 || a % total == 0)
    //        return false;
    //    a %= total;
    //    total += a;
    //    pq.push(a);
    //}


    // %= �� ���� �������

    // ���ǲ�֪����Ϊʲô ����߱����϶��Ǵ�ġ� ��������Ӧ���ǣ� ��֪�� Ϊʲô ����߱��� ��� �� ��߱� ��һ���� (���ԾͲ���Ҫ�������߱�)��

    // ����߱�����Ϊ2�֣� init ��Ȼ�����ֵ�� init �������ֵ��
    //      ��Ȼ���ʱ�����Ǽ������������Ҫ��ȥ ��ͬ��sum other ���� �������� init �϶��������ֵ����
    // �������ֵ�� �ǾͿ϶����� ��߱� ȥ���� ������߱� ����ζ�ߣ� init = (Z+) + sum_other�� �������ֵ��
    // ��ϧ������



    // ����discuss��������󡣡�  discuss��ֱ�������� �����ı������� 
//Runtime: 162 ms, faster than 5.59 % of C++ online submissions for Construct Target Array With Multiple Sums.
//Memory Usage : 44.6 MB, less than 14.69 % of C++ online submissions for Construct Target Array With Multiple Sums.
    // tle������
    bool ltb(vector<int>& target)
    {
        if (target.size() == 1)
            return target[0] == 1;

        multiset<long long> mset(begin(target), end(target));

        long long sum2 = accumulate(begin(target), end(target), 0LL);

        return dfsb1(mset, sum2);
    }

    bool dfsb1(multiset<long long>& mset, int sum2)
    {
        if (*rbegin(mset) == 1LL)
            return true;

        long long mx = *rbegin(mset);
        mset.erase(prev(end(mset)));

        long long sumOther = sum2 - mx;

#ifdef __test
        cout << mx << "...." << sumOther << ", " << sum2 << endl;
#endif
        if (sumOther == 0LL)
            return false;

        int mul = mx / sumOther;

        while (mul > 0)
        {
            long long init = mx - sumOther * mul;
            if (init > 0LL)
            {
                mset.insert(init);
                long long diff = mx - init;
                sum2 -= diff;

                if (dfsb1(mset, sum2))
                    return true;
                else
                    return false;                               // add, after discuss ��������

                mset.erase(init);
                sum2 += diff;
            }
            mul--;
        }
        return false;
    }


    // ȫ1 ��� target
    // �϶�Ҫ�� ���� ��Сֵ����Ȼ����Сֵ���޷��� �����ˣ���Ϊ sum()
    // �Ǿ�ֻ��һ��·�� bububu, sum �滻˭�� ��������ζ���Ҫ�ȹ���С�ġ�
    // ���� ���� 10^9 ���������� * 2 �ܿ�ġ�
    //
    // hint�������Ƴ����ġ��� ȷʵ�� �������� == sum(��һ��״̬������) �� ��һ��״̬�������ڵ�״̬��ֻ�������������λ�÷����ı仯�� ���Լ������ֵ��
    // mx = sum(arr_last) = sum(arr_now) - diff(mx,lst) = sum(arr_now) - (mx - lst) = sum(arr_n) - mx + lst, lst = 2*mx - sum(arr_now)
    // [1, 10 0000 0000] tle������ �Ȳ����С��� 2 3 4 5 .... 1000000000  ���� init + mul*?
    // sum(other) + init. sum(other)*2 + init. sum(other)*? + init == mx ...������ͬ��init��ֵҲ��ͬ���⡣��ȡ��߱���������߱�����
    // sum(o) + init
    bool lta(vector<int>& target)
    {
        priority_queue<long long> priq(begin(target), end(target));

        long long sum2 = std::accumulate(begin(target), end(target), 0LL);

        while (!priq.empty())
        {
            long long mx = priq.top();
            if (mx == 1LL)
                break;
            priq.pop();
            long long t2 = 2LL * mx - sum2;
            if (t2 < 1LL)
                return false;

#ifdef __test
            cout << mx << " - " << t2 << endl;
#endif

            priq.push(t2);
            sum2 -= (mx - t2);
        }
        return true;
    }

};

int main()
{

    LT lt;

    //myvi vi = { 9,3,5 };

    //myvi vi = { 1,1,1,2 };

    //myvi vi = { 8,5 };

    //myvi vi = { 1,10'0000'0000 };

    //myvi vi = { 1,1,2 };

    myvi vi = { 2, 900000002 };

    cout << lt.ltb(vi) << endl;

    return 0;
}
