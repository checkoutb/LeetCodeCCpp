
#include "../header/myheader.h"

class LT2225
{
public:

// D D

//        vector<int>los(100001), win(100001);
//        for(auto &i:matches) ++los[i[1]], ++win[i[0]];
//        vector<int>A, B;
//        for(int i=1; i<100001; ++i) {
//            if(los[i]==0 && win[i]) A.push_back(i);
//            else if(los[i]==1) B.push_back(i);
//        }
//        return {A, B};

// 。。 vector<short>  。。 no 十万 > 65535  vector<unsigned short>


//        Map<Integer, Integer> losses = new TreeMap<>();
//        for(int[] m : matches){
//            losses.put(m[0], losses.getOrDefault(m[0], 0));
//            losses.put(m[1], losses.getOrDefault(m[1], 0) + 1);
//        }
//        List<List<Integer>> r = Arrays.asList(new ArrayList<>(), new ArrayList<>());
//        for(Integer player : losses.keySet())
//            if(losses.get(player) <= 1)
//                r.get(losses.get(player)).add(player);



//        vector<vector<int>> answer(2);
//        for(int player: players) {
//            if(!losers.count(player)) {  // if the plays hasn't lost any game
//                answer[0].push_back(player);
//            } else if(losers.count(player) && losers[player] == 1) { // if the player lost only one game
//                answer[1].push_back(player);
//            }
//        }



//    set<int> all, l, l2;
//    vector<int> a0, a1;
//    for (auto &m : matches) {
//        all.insert({m[0], m[1]});
//        if (!l.insert(m[1]).second)
//            l2.insert(m[1]);
//    }
//    set_difference(begin(all), end(all), begin(l), end(l), back_inserter(a0));
//    set_difference(begin(l), end(l), begin(l2), end(l2), back_inserter(a1));
//    return {a0, a1};



//Runtime: 677 ms, faster than 89.27% of C++ online submissions for Find Players With Zero or One Losses.
//Memory Usage: 181.9 MB, less than 50.61% of C++ online submissions for Find Players With Zero or One Losses.
// lost 0 , lost 1
    vector<vector<int>> lt2225a(vector<vector<int>>& matches)
    {
        unordered_map<int, int> map2;       // lost - count
        unordered_set<int> set2;        // all
        for (vector<int>& vi : matches)
        {
            set2.insert(vi[0]);
            set2.insert(vi[1]);
            map2[vi[1]]++;
        }
        vector<vector<int>> ans(2, vector<int>());
        for (int i : set2)
        {
            if (map2.find(i) == map2.end())
            {
                ans[0].push_back(i);
            }
        }
        for (auto& p : map2)
        {
            if (p.second == 1)
            {
                ans[1].push_back(p.first);
            }
        }
        std::sort(begin(ans[0]), end(ans[0]));
        std::sort(begin(ans[1]), end(ans[1]));
        return ans;
    }

};

int main()
{

    LT2225 lt;


    return 0;
}
