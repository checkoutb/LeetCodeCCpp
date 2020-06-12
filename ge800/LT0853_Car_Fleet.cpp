
#include "../header/myheader.h"

class LT0853
{
public:

// D D
//for (int i = 0; i < pos.size(); i++) m[-pos[i]] = (double)(target - pos[i]) / speed[i];
// 取负，保存耗时。


//  vector<pair<int, int>> v;
//  sort(begin(v), end(v), greater<pair<int,int>>());


//Runtime: 88 ms, faster than 49.89% of C++ online submissions for Car Fleet.
//Memory Usage: 23.5 MB, less than 13.56% of C++ online submissions for Car Fleet.
// 计算各自需要多少小时到达目的地，如果前面有耗时比他多的，就合并
    int lt0853a(int target, vector<int>& position, vector<int>& speed)
    {
        map<int, int> map2;
        int sz1 = speed.size();
        for (int i = 0; i < sz1; i++)
        {
            map2[target - position[i]] = speed[i];
        }
        double times = -1;
        int ans = 0;
        for (auto& p : map2)
        {
            double tms = 1.0 * p.first / p.second;
            if (tms > times)
            {
                ans++;
                times = tms;
            }
        }
        return ans;
    }

};

int main()
{

    int target = 12;
    vector<int> p = {10,8,0,5,3};
    vector<int> s = {2,4,1,1,3};

    LT0853 lt;

    cout<<lt.lt0853a(target, p, s)<<endl;

    return 0;
}
