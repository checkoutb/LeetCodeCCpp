
#include "../../header/myheader.h"

class LT6155
{
public:




    //1115 / 24127	Ouha 	12	0:44:01	0:09:28 	0:20:44 2	0:34:01 	


    // D

    // 6.7% ͨ���ʡ�����

    //if (i + 1 < n) {
    //    // untrim previous and trim by next
    //    pq.add(new long[] {cursum + abs[(int)i] - abs[(int)i + 1], i + 1});
    //    // trim by next
    //    pq.add(new long[] {cursum - abs[(int)i + 1], i + 1});
    //}



    // g

    // �о�Ӧ���� ���� + ĳ���жϣ� ����ȷ�� ���ξ��� ans��
    // �����±� �� wrong answer..
    // ���ִ��ˣ� Ӧ���� ���� �±�ģ� ���� ֵ��  ��ϧ�ˡ�����
    // ���ֺ���̫�ԡ� l ���ˣ�Ӧ���� ��С��sum������ �����ͣ������� ���� �϶�tle �ġ�
    // �Ǿ�ֻ�������ˣ� �ѵ� prefix sum��  ���� ���� ������ ��С������
    // tle... ����
    // tle.  +  t2 > k
    // tle��
    // ������
    long long kSum(vector<int>& nums, int k)
    {
        long long sum2 = 0LL;
        int sz1 = nums.size();
        long long mns = 0LL;
        for (int i = 0; i < sz1; ++i)
        {
            if (nums[i] > 0)
                sum2 += nums[i];
            else
            {
                nums[i] = -nums[i];
            }
            mns += nums[i];
        }

        sort(begin(nums), end(nums));

        long long l = 0, r = sz1;
        long long ans = -123;
        while (l <= r)
        {
            long long md2 = l + (r - l) / 2;
            long long md = nums[md2];

            unordered_map<long long, int> map2;
            map2[0] = 1;
            int cnt = 1;
            for (int i = 0; i < sz1; ++i)
            {
                int t2 = nums[i];
                unordered_map<long long, int> map3;
                for (auto& p : map2)
                    if (p.first + t2 <= md)
                        map3[p.first + t2] += p.second;

                for (auto& p : map3)
                {
                    cnt += p.second;
                    map2[p.first] += p.second;
                }
                if (cnt > k)
                    break;
            }

#ifdef __test
            cout << l << " - " << md << " - " << r << " --- " << cnt << endl;
#endif

            if (cnt == k)
            {
                ans = sum2 - md;
                r = md2 - 1;
            }
            else if (cnt > k)
            {
                ans = sum2 - md;
                r = md2 - 1;
            }
            else
            {
                l = md2 + 1;
            }

        }
        return ans;




        //priority_queue<int, vector<int>, std::greater<int>> priq;
        //multiset

        //map<long long, int> map2;
        //map2[0] = 1;
        //for (int i = 0; i < sz1; ++i)
        //{
        //    map<long long, int> map3;
        //    int t2 = 0;
        //    for (auto& p : map2)
        //    {
        //        map3[p.first + nums[i]] += p.second;
        //        if (p.first <= nums[i])
        //            t2 += p.second;
        //    }
        //    for (auto& p : map3)
        //        map2[p.first] += p.second;
        //    if (t2 > k)
        //        break;
        //}

        //for (auto& p : map2)
        //{
        //    if (k > p.second)
        //    {
        //        k -= p.second;
        //    }
        //    else
        //    {
        //        return sum2 -= p.first;
        //    }
        //}
        //return -123;
    }

};

int main()
{

    LT6155 lt;

    //myvi v = { 2,4,-2 };
    //int k = 5;

    //myvi v = { 1,-2,3,4,-10,12 };
    //int k = 16;

    myvi v = { -731575093, -236261761, -759616099, -167023428, -350754181, 385948503, -770162071, -60277982, -680948276, 696763878, -959139513, 562428318, 
        1951742, 463221991, 15174891, 693641656, -171514964, -676270856, 862700558, -194013414 };
    int k = 504;

    cout << lt.kSum(v, k) << endl;

    return 0;
}
