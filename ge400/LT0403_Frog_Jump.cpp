
#include "../header/myheader.h"

class LT0403
{
public:


// discuss
//bool canCross(vector<int>& stones, int pos = 0, int k = 0) {
//    for (int i = pos + 1; i < stones.size(); i++) {
//        int gap = stones[i] - stones[pos];
//        if (gap < k - 1) continue;
//        if (gap > k + 1) return false;
//        if (canCross(stones, i, gap)) return true;
//    }
//    return pos == stones.size() - 1;
//}
// 后面写了，新的case加入后，无法accept。
//
//    unordered_map<int, bool> dp;
//
//    bool canCross(vector<int>& stones, int pos = 0, int k = 0) {
//        int key = pos | k << 11;
//
//        if (dp.count(key) > 0)
//            return dp[key];
//
//        for (int i = pos + 1; i < stones.size(); i++) {
//            int gap = stones[i] - stones[pos];
//            if (gap < k - 1)
//                continue;
//            if (gap > k + 1)
//                return dp[key] = false;
//            if (canCross(stones, i, gap))
//                return dp[key] = true;
//        }
//
//        return dp[key] = (pos == stones.size() - 1);
//    }



//  HashMap<Integer, HashSet<Integer>> map = new HashMap<Integer, HashSet<Integer>>(stones.length);
//
//        for (int i = 0; i < stones.length - 1; i++) {
//        	int stone = stones[i];
//        	for (int step : map.get(stone)) {
//        		int reach = step + stone;
//        		if (reach == stones[stones.length - 1]) {
//        			return true;
//        		}
//        		HashSet<Integer> set = map.get(reach);
//        		if (set != null) {
//        		    set.add(step);                               // 0
//        		    if (step - 1 > 0) set.add(step - 1);        // -1
//        		    set.add(step + 1);                          // +1
//        		}
//        	}
//        }



// after discuss....
    bool lt0403c(vector<int>& stones)
    {
        if (stones.size() == 1)
            return true;
        if (stones[1] != 1)
            return false;

        int sz1 = stones.size();
//        vector<int> v2;
//        for (int i = 0; i < sz1; i++) {
//            if (i > 3 && stones[i] > stones[i - 1] * 2) {return false;}
//            v2.push_back(stones[i]);
//        }
//        return dfsc1(v2, 1, 1);

        set<int> set1;
        for (int i = 0; i < sz1; i++)
        {
            if (i > 3 && stones[i] > stones[i - 1] * 2)
                return false;
            set1.insert(stones[i]);
        }
        return dfsc2(set1, stones[sz1 - 1], 1, 1);
    }

//  Runtime: 16 ms, faster than 96.37% of C++ online submissions for Frog Jump.
//  Memory Usage: 11.8 MB, less than 91.82% of C++ online submissions for Frog Jump.

// 或许是因为dfs，从k-1开始的原因。而这里从k+1开始。以及stone > stone * 2.

    bool dfsc2(set<int>& set1, int last, int pos, int k)
    {
        if (pos + k + 1 >= last && pos + k - 1 <= last)
        {
            return true;
        }
        if (set1.find(pos + k + 1) != set1.end())
            if (dfsc2(set1, last, pos + k + 1, k + 1))
                return true;
        if (set1.find(pos + k) != set1.end() && dfsc2(set1, last, pos + k, k))
            return true;
        if (k > 1 && set1.find(pos + k - 1) != set1.end() && dfsc2(set1, last, pos + k - 1, k - 1))
            return true;

        return false;
    }

// tle
    bool dfsc1(vector<int>& stones, int index, int k)
    {
        int sz1 = stones.size();
        if (index == sz1 - 1)
            return true;

        int a1 = stones[index];
        int t1 = k - 1 + a1;
        int t2 = k + a1;
        int t3 = k + 1 + a1;
        for(int i = index + 1; i < sz1; i++)
        {
            int t5 = stones[i];

            if (t5 > t3)
                break;
            if (t5 == t1 && dfsc1(stones, i, k - 1))
            {
                #ifdef __test
                cout<<t1<<", "<<k-1<<endl;
                #endif // __test
                return true;
            }
            if (t5 == t2 && dfsc1(stones, i, k))
            {
                #ifdef __test
                cout<<t2<<", "<<k<<endl;
                #endif // __test
                return true;
            }
            if (t5 == t3 && dfsc1(stones, i, k + 1))
            {
                #ifdef __test
                cout<<t3<<", "<<k+1<<endl;
                #endif // __test
                return true;
            }
        }
        return false;
    }


// 15/39 tle  [0,999].
    bool lt0403b(vector<int>& stones)
    {
        int sz1 = stones.size();
        if (sz1 == 1)
            return true;
        if (sz1 == 2)
            return stones[1] == 1;
        vector<int> arr[sz1];
        arr[1].push_back(1);

        for (int i = 1; i < sz1; i++)
        {
            long t1 = stones[i];
            int j = i + 1;
            for (int unit : arr[i])
            {
                long t2 = t1 + unit - 1;
                long t3 = t1 + unit;
                long t4 = t1 + unit + 1;
//                for (j = max(0, j - 2); j < sz1; j++)           // ....heap use after free...是由于外层是forEach，是iterator，这里可能导致arr[i]增加一个数值。
                for (j = max(i + 1, j - 2); j < sz1; j++)
                {
                    int t5 = stones[j];
                    if (t5 > t4)
                        break;
                    if (t5 == t2)
                        arr[j].push_back(unit - 1);
                    if (t5 == t3)
                        arr[j].push_back(unit);
                    if (t5 == t4)
                        arr[j].push_back(unit + 1);
                }
            }
        }

        return !arr[sz1 - 1].empty();
    }


    // 16/39 tle  [0,998]+9999999
    bool lt0403a(vector<int>& stones)
    {
        if (stones.size() == 1)
            return true;
        if (stones[1] != 1)
            return false;
        return dfsa1(stones, 1, 1);
    }

    bool dfsa1(vector<int>& stones, int index, int k)
    {
        int sz1 = stones.size();
        if (index == sz1 - 1)
            return true;

        int a1 = stones[index];
        int t1 = k - 1 + a1;
        int t2 = k + a1;
        int t3 = k + 1 + a1;
        for(int i = index + 1; i < sz1; i++)
        {
            int t5 = stones[i];

            if (t5 > t3)
                break;
            if (t5 == t1 && dfsa1(stones, i, k - 1))
            {
                #ifdef __test
                cout<<t1<<", "<<k-1<<endl;
                #endif // __test
                return true;
            }
            if (t5 == t2 && dfsa1(stones, i, k))
            {
                #ifdef __test
                cout<<t2<<", "<<k<<endl;
                #endif // __test
                return true;
            }
            if (t5 == t3 && dfsa1(stones, i, k + 1))
            {
                #ifdef __test
                cout<<t3<<", "<<k+1<<endl;
                #endif // __test
                return true;
            }
        }
        return false;
    }
};

int main()
{
//    vector<int> vs = {0,1,3,5,6,8,12,17,100};
//    vector<int> vs = {0,1,3,4,5,7,9,10,12};
//    vector<int> vs = {0, 2};


    LT0403 lt;
    cout<<lt.lt0403c(vs)<<endl;

    return 0;
}
