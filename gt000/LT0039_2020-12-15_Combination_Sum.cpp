
#include "../header/myheader.h"

class LT0039
{
public:

// D D

//        Arrays.sort(cands); // sort candidates to try them in asc order
//        List<List<List<Integer>>> dp = new ArrayList<>();
//        for (int i = 1; i <= t; i++) { // run through all targets from 1 to t
//            List<List<Integer>> newList = new ArrayList(); // combs for curr i
//            // run through all candidates <= i
//            for (int j = 0; j < cands.length && cands[j] <= i; j++) {
//                // special case when curr target is equal to curr candidate
//                if (i == cands[j]) newList.add(Arrays.asList(cands[j]));
//                // if current candidate is less than the target use prev results
//                else for (List<Integer> l : dp.get(i-cands[j]-1)) {
//                    if (cands[j] <= l.get(0)) {
//                        List cl = new ArrayList<>();
//                        cl.add(cands[j]); cl.addAll(l);
//                        newList.add(cl);
//                    }
//                }
//            }
//            dp.add(newList);
//        }
//        return dp.get(t-1);





//Runtime: 12 ms, faster than 61.67% of C++ online submissions for Combination Sum.
//Memory Usage: 11.4 MB, less than 65.32% of C++ online submissions for Combination Sum.
    vector<vector<int>> lt0039a(vector<int>& candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> path;
        dfsa1(candidates, target, 0, 0, ans, path);
        return ans;
    }

    void dfsa1(vector<int>& candi, int target, int st, int sum2, vector<vector<int>>& ans, vector<int>& path)
    {
        if (sum2 == target)
            ans.push_back(path);
//            ans.push_back(vector<int>(path));     // 结果一样的， 看来 push_back 自动调用 复制构造函数的。
        if (sum2 >= target)
            return;

        for (int i = st; i < candi.size(); ++i)
        {
            path.push_back(candi[i]);
            dfsa1(candi, target, i, sum2 + candi[i], ans, path);
            path.pop_back();
        }
    }

};

int main()
{
//    myvi v = {2,3,6,7};
//    int t = 7;

//    myvi v = {2,3,5};
//    int t = 8;

//    myvi v = {2};
//    int t = 1;

    myvi v = {1};
    int t = 2;

    LT0039 lt;

    myvvi vv = lt.lt0039a(v, t);

    for (myvi& vi : vv)
    {
        for (int i : vi)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
