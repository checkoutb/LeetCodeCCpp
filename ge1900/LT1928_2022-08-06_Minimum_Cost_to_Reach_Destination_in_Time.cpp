
#include "../header/myheader.h"

class LT1928
{
public:

    // D D


    //auto comp = [&](auto& a, auto& b)
    //{
    //    return a[2] > b[2];
    //};
    //priority_queue<node, vector<node>, decltype(comp)> pq(comp);





//Runtime: 305 ms, faster than 65.79 % of C++ online submissions for Minimum Cost to Reach Destination in Time.
//Memory Usage : 30.7 MB, less than 64.47 % of C++ online submissions for Minimum Cost to Reach Destination in Time.
    // ��������ȥ�� �ɻ���Ҳ���ܻ�ȥ��
    // tle��
    // Dijkstra . ��һ�ξ�����С�� ������ ��������
    int lt1928a(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees)
    {
        int sz1 = passingFees.size();
        //vector<int> 
        //priority_queue<pair<int, int>>

        // money, time, city
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> priq;

        unordered_map<int, unordered_map<int, int>> map2;

        //unordered_map<int, map<int, int>> map3;     // node, time, money
        vector<int> mntm(sz1, INT_MAX);                 // for tle.  min time
        mntm[0] = 0;

        for (vector<int>& vi : edges)
        {
            if (map2.find(vi[0]) == map2.end() || map2[vi[0]].find(vi[1]) == map2[vi[0]].end())
            {
                map2[vi[0]][vi[1]] = vi[2];
                map2[vi[1]][vi[0]] = vi[2];
            }
            else
            {
                if (vi[2] < map2[vi[0]][vi[1]])
                {
                    map2[vi[0]][vi[1]] = vi[2];
                    map2[vi[1]][vi[0]] = vi[2];
                }
            }
        }

        priq.push({passingFees[0], 0, 0});
        int mny, tm, cty;
        while (!priq.empty())
        {
            std::tie(mny, tm, cty) = priq.top();
            priq.pop();

            if (cty == sz1 - 1)
                return mny;

            for (auto& p : map2[cty])           // ���߻�ȥ�ġ�����tle?
            {
                if (tm + p.second <= maxTime)
                {
                    if (tm + p.second < mntm[p.first])          // priq������Ǯ��Ȼ���ĵĶ࣬��� ʱ�仹�࣬��ô�����塣
                    {
                        priq.push(std::make_tuple(mny + passingFees[p.first], tm + p.second, p.first));
                        mntm[p.first] = tm + p.second;
                    }
                }

            }

        }
        return -1;
    }

};

int main()
{

    LT1928 lt;

    int mxt = 26;
    myvvi vv = { {0,1,10},{1,2,10},{2,5,10},{0,3,1},{3,4,10},{4,5,15} };
    myvi fee = { 5,1,2,20,20,3 };

    cout << lt.lt1928a(mxt, vv, fee) << endl;

    return 0;
}
