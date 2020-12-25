
#include "../header/myheader.h"

class LT0373
{
public:


// D D

//        auto comp = [&nums1, &nums2](pair<int, int> & a, pair<int, int> & b) {
//            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
//        };
//
//        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);


//#define ppi pair<int, pair<int, int>>
//        int n = nums1.size(), m=nums2.size();
//        priority_queue<ppi, vector<ppi>, greater<ppi>> p;
//        if(n==0 || m==0) return {};
//        // fill 'pq' with the match result between the first element of 'nums1' and all elements in 'nums2'.
//        // these will surely be the minimum values possible.
//        for(int i=0;i<m;i++){
//            p.push({nums1[0]+nums2[i] ,  {0, i} });
//        }
//        int count = 0;
//        vector<vector<int>> ans;
//        while(!p.empty()){
//            auto tmp = p.top();
//            p.pop();
//            int i = tmp.second.first;
//            int j = tmp.second.second;
//            ans.push_back({nums1[i] , nums2[j]});
//            if(++count == k) return ans;
//            i++;
//            if(i < n){
//                p.push({nums1[i]+nums2[j], {i, j}});
//            }
//        }
// 初始化{0, i}， 以后每次都 第一个下标 ++ 。


//return sorted(itertools.product(nums1, nums2), key=sum)[:k]
//return map(list, sorted(itertools.product(nums1, nums2), key=sum)[:k])
//return map(list, heapq.nsmallest(k, itertools.product(nums1, nums2), key=sum))
//return heapq.nsmallest(k, ([u, v] for u in nums1 for v in nums2), key=sum)

//    streams = map(lambda u: ([u+v, u, v] for v in nums2), nums1)
//    stream = heapq.merge(*streams)
//    return [suv[1:] for suv in itertools.islice(stream, k)]

//https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84577/O(k)-solution
// 几十行。py。


// hai you shui !...
//Runtime: 8 ms, faster than 99.06% of C++ online submissions for Find K Pairs with Smallest Sums.
//Memory Usage: 9.6 MB, less than 76.48% of C++ online submissions for Find K Pairs with Smallest Sums.
//[]
//[3,5,7,9]
//1             wo tmd
    vector<vector<int>> lt0373c(vector<int>& nums1, vector<int>& nums2, int k)
    {
        vector<vector<int>> ans;
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        if (sz1 == 0 || sz2 == 0)
            return ans;
        k = min(k, sz1 * sz2);
        auto fun = [](const pair<int, pair<int,int>>& p1, const pair<int, pair<int, int>>& p2){ return p1.first > p2.first; };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(fun)> que1(fun);
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(fun)> que2(fun);
        for (int i = 0; i < sz1; ++i)
        {
            que1.push({nums1[i] + nums2[0], {i, 0}});       // >=
        }
        for (int j = 1; j < sz2; ++j)
        {
            que2.push({nums1[0] + nums2[j], {0, j}});       // <
        }
        while (k-- > 0)
        {
            int mn1 = que1.empty() ? INT_MAX : que1.top().first;
            int mn2 = que2.empty() ? INT_MAX : que2.top().first;
            if (mn1 < mn2)
            {
                pair<int, pair<int, int>> p = que1.top();
                que1.pop();
                int i1 = p.second.first;
                int i2 = p.second.second;
                ans.push_back({nums1[i1], nums2[i2]});
//                cout<<i1<<" = "<<i2<<endl;
                if (i2 + 1 <= i1 && i2 + 1 < sz2)
                    que1.push({nums1[i1] + nums2[i2 + 1], {i1, i2 + 1}});
//                cout<<" , ,1 , "<<nums1[i1] + nums2[i2 + 1]<<endl;
            }
            else
            {
                pair<int, pair<int, int>> p = que2.top();
                que2.pop();
                int i1 = p.second.first;
                int i2 = p.second.second;
                ans.push_back({nums1[i1], nums2[i2]});
//                cout<<i1<<" - "<<i2<<endl;
                if (i1 + 1 < i2 && i1 + 1 < sz1)
                    que2.push({nums1[i1 + 1] + nums2[i2], {i1 + 1, i2}});
//                cout<<" . . 2 ,"<<nums1[i2 + 1] + nums2[i2]<<endl;
            }
        }
        return ans;
    }

// error
    vector<vector<int>> lt0373b(vector<int>& nums1, vector<int>& nums2, int k)
    {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        k = min(k, sz1 * sz2);
        vector<int> vi(sz1, 0);     // index
        vector<vector<int>> ans;
//        unordered_set<pair<int, int>> set2(5);
        unordered_map<int, unordered_set<int>> map2;
        auto fun = [](const pair<int, pair<int,int>>& p1, const pair<int, pair<int, int>>& p2){ return p1.first > p2.first; };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(fun)> que1(fun);
        que1.push({nums1[0] + nums2[0], {0, 0}});
        while (!que1.empty() && k-- > 0)
        {
            pair<int, pair<int, int>> p = que1.top();
            que1.pop();
            int idx1 = p.second.first;
            int idx2 = p.second.second;
            if (map2[idx1].find(idx2) != map2[idx1].end())
                ;
//                continue;
//            pair<int, int> pair2 = {idx1, idx2};
//            if (set2.find(pair2) != set2.end())
//                continue;
//            cout<<p.first<<endl;
            else
                ans.push_back({nums1[idx1], nums2[idx2]});
            map2[idx1].insert(idx2);
            if (idx1 + 1 != sz1)
                que1.push({nums1[idx1 + 1] + nums2[idx2], {idx1 + 1, idx2}});
            if (idx2 + 1 != sz2)
                que1.push({nums1[idx1] + nums2[idx2 + 1], {idx1, idx2 + 1}});
            if (idx1 + 1 != sz1 && idx2 + 1 != sz2)
                que1.push({nums1[idx1 + 1] + nums2[idx2 + 1], {idx1 + 1, idx2 + 1}});
        }

        return ans;
//        for (int i = 0; i < sz1; ++i)
//        {
//            int mn = INT_MAX;
//            int t1 = -1;
//            int t2 = -1;
//            for (int j = 0; j < sz1; ++j)
//            {
//
//            }
//        }
    }


// error... 估计之前runtime error 也是这样的。。
    vector<vector<int>> lt0373a(vector<int>& nums1, vector<int>& nums2, int k)
    {
        vector<vector<int>> ans;
        int idx1 = 0;
        int idx2 = 0;
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        k = min(k, sz1 * sz2);
        while (k-- > 0)
        {
            ans.push_back({nums1[idx1], nums2[idx2]});
            if (idx1 == nums1.size() - 1)
            {
                idx2++;
                continue;
            }
            if (idx2 == nums2.size() - 1)
            {
                idx1++;
                continue;
            }
            if (nums1[idx1 + 1] + nums2[idx2] < nums1[idx1] + nums2[idx2 + 1])
                idx1++;
            else
                idx2++;
        }
        return ans;
    }

};

int main()
{
//    myvi v1 = {1,7,11};
//    myvi v2 = {2,4,6};
//    int k{3};

//    myvi v1 = {1,2};
//    myvi v2 = {3};
//    int k{3};

//    myvi v1 = {1,1,2};
//    myvi v2 = {1,2,3};
//    int k{10};

    myvi v1 = {1,2,4,5,6};
    myvi v2 = {3,5,7,9};
    int k{20};

    LT0373 lt;

    myvvi vv = lt.lt0373c(v1, v2, k);

    for (myvi& vi : vv)
        cout<<vi[0]<<", "<<vi[1]<<endl;

    return 0;
}
