
#include "../header/myheader.h"

class LT2251
{
public:

// D D


//        for (auto& t : flowers)
//            start.push_back(t[0]), end.push_back(t[1]);
//        sort(start.begin(), start.end());
//        sort(end.begin(), end.end());
//        vector<int> res;
//        for (int t : persons) {
//            int started = upper_bound(start.begin(), start.end(), t) - start.begin();
//            int ended = lower_bound(end.begin(), end.end(), t) - end.begin();
//            res.push_back(started - ended);
//        }
// 到这天 开花的 - 凋零的。。


//        vector<vector<int>> line;
//        for (auto& f : flowers) {
//            line.push_back({f[0], +1});
//            line.push_back({f[1]+1, -1});
//        }
//        sort(line.begin(), line.end());
//        int prefix = 0;
//        vector<int> time, vals;
//        for (auto& l : line) {
//            time.push_back(l[0]);
//            vals.push_back(prefix += l[1]);
//        }
//        vector<int> ans;
//        for (auto& p : persons) {
//            auto it = upper_bound(time.begin(), time.end(), p);
//            if (it == time.begin()) ans.push_back(0);
//            else ans.push_back(vals[it - time.begin() - 1]);
//        }
//        return ans;




//Runtime: 478 ms, faster than 20.00% of C++ online submissions for Number of Flowers in Full Bloom.
//Memory Usage: 107.7 MB, less than 20.00% of C++ online submissions for Number of Flowers in Full Bloom.
// bloom filter. 。。这道题目 是开花。。不是人名。
    vector<int> lt2251a(vector<vector<int>>& flowers, vector<int>& persons)
    {
        map<int, int> map2;
        for (vector<int>& vi : flowers)
        {
            map2[vi[0]]++;
            map2[vi[1] + 1]--;
        }

        map<int, vector<int>> map3;
        for (int i = 0; i < persons.size(); ++i)
        {
            map3[persons[i]].push_back(i);
        }

        vector<int> ans(persons.size());

        int cnt = 0;
        map<int, int>::iterator itf = begin(map2);
        for (map<int, vector<int>>::iterator itp = begin(map3); itp != end(map3); itp++)
        {
            int day = itp->first;
            while ((itf != end(map2)) && (itf->first <= day))
            {
                cnt += itf->second;
                itf++;
            }
            for (int i : itp->second)
            {
                ans[i] = cnt;
            }
        }

        return ans;
    }

};

int main()
{

    LT2251 lt;

//    myvvi vv = {{1,6},{3,7},{9,12},{4,13}};
//    myvi v2 = {2,3,7,11};

    myvvi vv = {{1,10},{3,3}};
    myvi v2 = {3,3,2};

    myvi v3 = lt.lt2251a(vv, v2);

    showVectorInt(v3);

    return 0;
}
