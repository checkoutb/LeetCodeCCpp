
#include "../header/myheader.h"

class LT2244
{
public:

// D D

//        for(auto& [_, cnt] : mp) {


//        for (auto& it: count) {
//            if (it.second == 1) return -1;
//            res += (it.second + 2) / 3;
//        }


//    sort(begin(t), end(t));
//    for (int i = 0; i <= t.size(); ++i) {
//        if (i < t.size() && (i == 0 || t[i - 1] == t[i]))
//            ++cnt;
//        else {
//            if (cnt == 1)
//                return -1;
//            res += cnt / 3 + (cnt % 3 ? 1 : 0);
//            cnt = 1;
//        }
//    }


//Runtime: 229 ms, faster than 100.00% of C++ online submissions for Minimum Rounds to Complete All Tasks.
//Memory Usage: 103.7 MB, less than 100.00% of C++ online submissions for Minimum Rounds to Complete All Tasks.
    int lt2244a(vector<int>& tasks)
    {
        unordered_map<int, int> map2;
        for (int i : tasks)
        {
            map2[i]++;
        }
        int ans = 0;

        for (auto& p : map2)
        {
            int t2 = p.second;
            if (t2 < 2)
                return -1;
            ans += (t2 / 3) + (t2 % 3 != 0);
        }

        return ans;
    }

};

int main()
{

    LT2244 lt;


    return 0;
}
