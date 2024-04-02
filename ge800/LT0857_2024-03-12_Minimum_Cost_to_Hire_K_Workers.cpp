
#include "../header/myheader.h"

class LT0857
{
public:


    // D

    // 按 wage/quality 升序。 加人 的时候，剔除 quality 最大的。

    // 但是为什么按 w/q 升序 ？ 我想不出来。

    // 已选中的人 的 最大 w/q  就是 整个团队的  w/q,  团队的q 就是 sum2。
    // 团队q 是比较难排序的，和团队的每个人有关， 但是 w/q 容易排序，只和 最高的w/q 的那个人有关。
    // 所以 w/q 排序，缓慢上升， T人的时候 T quality最大的。

    // g

    // k 个人
    // 工资按比例， 并且至少要 wage。
    // 按 wage / quality 排序？ 然后 subarr ？ no
    // 实发最高的人 肯定是 quality最大的。 T他。
    // 总工资 = sum(quality) * max(wage/quality)
    // priq + multiset
    // ... 不能T quality 最大的。。
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k)
    {
        int sum2 = 0;
        int sz1 = wage.size();
        std::priority_queue<pair<int, int>> priq;
        // std::multiset<double> mset;
        std::priority_queue<pair<double, int>> pp2;
        double ans = INT_MAX;
        vector<bool> vb(sz1, false);    // in priq?
        for (int i = 0; i < sz1; ++i)
        {
            int tq = quality[i];
            int tw = wage[i];
            // if (priq.size() < k - 1)
            // {
                sum2 += tq;
                priq.push(std::make_pair(tq, i));
                // mset.insert()            // double 没办法删除，不够精确。  可能吗？感觉可能 . 不会。
                        // 不够精确 != 不能复现。  本次 1/3 是 0.3333, 下次还是 0.3333 不够精确，但不会变。
                pp2.push(std::make_pair(1.0 * tw / tq, i));
                vb[i] = true;
            // }
            // else
            // {

            if (priq.size() == k)
            {
                while (vb[pp2.top().second] == false)
                    pp2.pop();

                ans = min(ans, sum2 * pp2.top().first);
                sum2 -= priq.top().first;
                vb[priq.top().second] = false;

#ifdef __test
                cout<<"pop: "<<priq.top().second<<"\n";
#endif

                priq.pop();
            }
                // sum2 -=
            // }
        }

        return ans;
    }

};

int main()
{

    LT0857 lt;

    myvi v = {3,1,10,10,1};
    myvi v2 = {4,8,2,2,7};
    int k = 3;

    cout<<lt.mincostToHireWorkers(v, v2, k);

    return 0;
}
