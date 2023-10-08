
#include "../header/myheader.h"

class LT2813
{
public:

// D D

//        vector<int> dup;
//        unordered_set<int> seen;
//        for (int i = 0; i < A.size(); ++i) {
//            if (i < k) {
//                if (seen.count(A[i][1])) {
//                    dup.push_back(A[i][0]);
//                }
//                cur += A[i][0];
//            } else if (seen.find(A[i][1]) == seen.end()) {
//                if (dup.empty()) break;
//                cur += A[i][0] - dup.back();
//                dup.pop_back();
//            }
//            seen.insert(A[i][1]);
//            res = fmax(res, cur + 1L * seen.size() * seen.size());
//        }

// fmax




//Runtime580 ms
//Beats
//16.41%
//Memory189.2 MB
//Beats
//29.41%
    // 1 category:
    // 2 cate :
    // 3 ..
    // k category :
    // zhishao qian k ge profit.
    // after k, must +++ new category.
    long long findMaximumElegance(vector<vector<int>>& items, int k)
    {
        long long ans = 0LL;
        sort(rbegin(items), rend(items));

        #ifdef __test
        for (myvi & vi : items)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test

        map<int, int> map2;     // <category, profit>
        for (int i = k; i < items.size(); ++i)
        {
            if (map2.find(items[i][1]) == map2.end())
            {
                map2[items[i][1]] = items[i][0];
            }
        }

        long long pft = 0LL;
//        set<category> set2;
        map<int, int> map3;     // <category, item count>

        for (int i = 0; i < k; ++i)
        {
            pft += items[i][0];
            ++map3[items[i][1]];

//            cout<<items[i][0]<<" ? "<<items[i][1]<<" , "<<i<<" . "<<k<<endl;

        }

//        cout<<map2.size()<<"   "<<map3.size()<<endl;

        for (auto& [k, _] : map3)
        {
            map2.erase(k);
        }


        ans = pft + 1LL * map3.size() * map3.size();

//        map<int, int> map4;     // <profix, category>
        vector<pair<int, int>> vp;
        vp.reserve(map2.size());
        for (auto& [k, v] : map2)
        {
            vp.push_back(std::make_pair(v, k));
        }

        int idx = 0;
        sort(rbegin(vp), rend(vp));

        #ifdef __test
        cout<<vp.size()<<"    --"<<endl;
        for (auto& [k, v] : vp)
        {
            cout<<k<<"  pft , cate: "<<v<<endl;
        }
        #endif // __test

        int t2, t3;
        for (int i = k - 1; i >= 0 && idx < vp.size(); --i)
        {
            t2 = items[i][0];   // profix
            t3 = items[i][1];   // category

            #ifdef __test
            cout<<"     "<<t3<<" . "<<map3[t3]<<endl;
            #endif // __test

            if (map3[t3] == 1)
            {
                continue;
            }

            --map3[t3];
            map3[vp[idx].second] = 1;
            pft -= t2;
            pft += vp[idx].first;
            ++idx;

            long long t4 = pft + 1LL * map3.size() * map3.size();

            #ifdef __test
            cout<<" ,, "<<i<<", "<<pft<<", "<<map3.size()<<", "<<t4<<" -- "<<ans<<endl;
            #endif // __test

            ans = max(ans, t4);
        }
        return ans;
    }

};

int main()
{

    LT2813 lt;

//    myvvi vv = {{3,2},{5,1},{10,1}};
//    int k = 2;

    myvvi vv = {{2,2},{8,6},{10,6},{2,4},{9,5},{4,5}};  // 39
    int k = 4;

    cout<<lt.findMaximumElegance(vv, k)<<endl;

    return 0;
}
