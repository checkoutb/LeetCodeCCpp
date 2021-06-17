
#include "../../header/myheader.h"


struct MyHash
{
	size_t operator()(const pair<long, int> &k) const noexcept
	{
		return std::hash<int>{}(k.second);
	}
};

struct MyComp
{
	bool operator()(const pair<long, int> &k1, const pair<long, int> &k2) const noexcept
	{
		return k1.first == k2.first && (k1.second == k2.second);
	}
};

class LT
{
public:

// D D


//bitset<15>track;
//track[i] = true;

// ? 搞不懂了， 10^9 不是10亿吗，  15个10亿 不是超过int上限了吗。。 为什么 int是可以的。。


// sort 只是加速， 不sort 也是可以执行的。





//06/16/2021 09:39	Accepted	0 ms	9.7 MB	cpp
//12/06/2019 17:01	Accepted	56 ms	8.4 MB	cpp
//12/06/2019 17:00	Runtime Error	N/A	N/A	cpp
// 之前的代码。。4个数字。。dfs。。  确实，每个火柴，肯定在 4条边上。
//    bool dfsa1(int a1, int a2, int a3, int a4, int tar, vector<int>& nums, int i)
//    {
//        if (a1 > tar || a2 > tar || a3 > tar || a4 > tar)
//        {
//            return false;
//        }
//        if (a1 == tar && a2 == tar && a3 == tar && a4 == tar)
//        {
//            return true;
//        }
//        if (dfsa1(a1 + nums[i], a2, a3, a4, tar, nums, i - 1))
//            return true;
//        if (dfsa1(a1, a2 + nums[i], a3, a4, tar, nums, i - 1))
//            return true;
//        if (dfsa1(a1, a2, a3 + nums[i], a4, tar, nums, i - 1))
//            return true;
//        if (dfsa1(a1, a2, a3, a4 + nums[i], tar, nums, i - 1))
//            return true;
//        return false;
//    }


// AC
    bool ltb(vector<int>& matchsticks)
    {
        int sz1 = matchsticks.size();
        long sum2 = std::accumulate(begin(matchsticks), end(matchsticks), 0L);
        if (sum2 % 4 != 0)
            return false;
        long sum4 = sum2 / 4;
        std::sort(begin(matchsticks), end(matchsticks), std::greater<int>());
        #ifdef __test
        showVectorInt(matchsticks);
        #endif // __test
        for (int i = 0; i < 3; ++i)
        {
            if (!dfsb2(matchsticks, sum4, 0L, 0))
            {
                #ifdef __test
                cout<<i<<", "<<sum4<<endl;
                #endif // __test
                return false;
            }
        }
        return true;
    }
    bool dfsb2(vector<int>& vi, long tar, long sum2, int idx)
    {
        if (sum2 == tar)
            return true;
        if (idx == vi.size())
            return false;
        if (sum2 > tar)
            return false;
        for (int i = idx; i < vi.size(); ++i)
        {
            if (vi[i] == -1)
                continue;
            if (dfsb2(vi, tar, sum2 + vi[i], i + 1))
            {
                vi[i] = -1;
                return true;
            }
        }
        return false;
    }


// ...................... use   >>>>> all <<<<<       the matchsticks to make one square
//    1 <= matchsticks.length <= 15
//    0 <= matchsticks[i] <= 10^9
// 15根，暴力。
// 能否找到一个 数字， 4种方式组成这个数字。  怎么去重？  15bit -> int.
//
    bool lta(vector<int>& matchsticks)
    {
//        vector<unordered_set<int>> vs1();     // 本来想dp，但是10^9。。。就想dfs，但是 似乎dp也可以的。

        int sz1 = matchsticks.size();
        long sum2 = 0L;
        for (int i : matchsticks)
            sum2 += i;
        long sum4 = sum2 / 4;
//        vector<unordered_set<int>> vs1(sz1);
//        unordered_map<int, int> map2;
//        vs1[0].insert(0);
//        vs1[0].insert(1);       // 2^15 > 30000.  减去 > 1/4 sum 的 ... 这种就是 bfs。。  数据结构了。

////        vector<unordered_set<pair<int, int>>> vs2(sz1);     // <sum, count>
//        vector<unordered_map<int, int>> vmap(sz1);       // <sum, count>
////        vmap[0].insert({0, 1});
//        vmap[0].insert({matchsticks[0], 1});

//        auto myhash = [](const pair<long, int>& key)  const noexcept {
//            return std::hash<int>{}(key.second);
//        };
//
//        auto mycomp = [](const pair<long, int>& p1, const pair<long, int>& p2)  const noexcept {
//            return p1.first == p2.first && p1.second == p2.second;
//        };

        // const Hash& hash = Hash(),
        // const key_equal& equal = key_equal(),
//        unordered_set<pair<long, int>, std::decltype(myhash), decltype(mycomp)> settest(10, myhash, mycomp);

        unordered_set<pair<long, int>, MyHash, MyComp> settest2;

        vector<unordered_set<pair<long, int>, MyHash, MyComp>> vs2(sz1);        // sum, flag
        vs2[0].insert({matchsticks[0], 1});
        for (int i = 1; i < sz1; ++i)
        {
            int t2 = matchsticks[i];
            int flg = 1 << i;
            vs2[i].insert({t2, flg});
            for (pair<long, int> p : vs2[i - 1])
            {
                if (p.first + t2 <= sum4)
                    vs2[i].insert({p.first + t2, p.second | flg});
            }
        }
        unordered_map<int, vector<int>> map2;

        for (unordered_set<pair<long, int>, MyHash, MyComp> sp : vs2)
            for (pair<long, int> p : sp)
            {
                map2[p.first].push_back(p.second);
            }
        for (unordered_map<int, vector<int>>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            #ifdef __test
//            cout<<it->first<<", "<<it->second.size()<<endl;
            #endif // __test
            if (it->second.size() < 4)
                continue;
            #ifdef __test
//            showVectorInt(it->second);
            #endif // __test
            if (dfsa1(it->second, 0, 0, 0))
                return true;
        }
        return false;
    }

    bool dfsa1(vector<int>& vi, int cnt, int idx, int flg)
    {
//        cout<<" . . "<<idx<<", "<<cnt<<endl;
        if (cnt == 4)
            return true;
        if (idx == vi.size())
            return false;
        for (int i = idx; i < vi.size(); ++i)
        {
            if ((vi[i] & flg) == 0)         // operator& < operator==
            {
                if (dfsa1(vi, cnt + 1, i + 1, flg | vi[i]))
                {
                    return true;
                }
            }
        }
        return false;
    }

};


int main()
{

//    myvi v = {1,1,2,2,2};
    myvi v = {3,3,3,3,4};

    LT lt;

    cout<<lt.ltb(v)<<endl;

    return 0;
}
