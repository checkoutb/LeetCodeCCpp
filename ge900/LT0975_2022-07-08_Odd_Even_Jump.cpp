
#include "../header/myheader.h"

class LT0975
{
public:


    // D D


    //int n = A.size(), res = 1;
    //vector<int> higher(n), lower(n);
    //higher[n - 1] = lower[n - 1] = 1;
    //map<int, int> map;
    //map[A[n - 1]] = n - 1;
    //for (int i = n - 2; i >= 0; --i) {
    //    auto hi = map.lower_bound(A[i]), lo = map.upper_bound(A[i]);
    //    if (hi != map.end()) higher[i] = lower[hi->second];
    //    if (lo != map.begin()) lower[i] = higher[(--lo)->second];
    //    if (higher[i]) res++;
    //    map[A[i]] = i;
    //}
    //return res;



    //vector<pair<bool, bool>> dp(A.size());
    //map<int, int> m;
    //dp[A.size() - 1] = { true, true };
    //for (int i = A.size() - 1; i >= 0; --i) {
    //    auto it = m.lower_bound(A[i]);
    //    if (it != end(m)) {
    //        res += dp[i].first = dp[it->second].second;
    //        if (it->first == A[i]) ++it;
    //    }
    //    if (it != begin(m)) dp[i].second = dp[prev(it)->second].first;
    //    m[A[i]] = i;
    //}
    //return res;



//Runtime: 97 ms, faster than 91.08 % of C++ online submissions for Odd Even Jump.
//Memory Usage : 28.5 MB, less than 44.77 % of C++ online submissions for Odd Even Jump.
    // 。。 怎么快速找 比自己大的最小值，并且还要能再次使用的。
    // vector<pair<value, index>> ? . 这个可能快一点，但是估计。。 因为 可能index 小于自己，所以还是需要 for 往后搜索。
    // 或者 set 。 map。     map。
    int lt0975b(vector<int>& arr)
    {
        int sz1 = arr.size();

        vector<int> vio(sz1, -1);   // >= me & small
        vector<int> vie(sz1, -1);   // <= me & big

        //vio[sz1 - 1] = 1;
        //vie[sz1 - 1] = 1;

        map<int, int> map2;     // value : index
        map2[arr[sz1 - 1]] = sz1 - 1;

        for (int i = sz1 - 2; i >= 0; --i)
        {
            map<int, int>::iterator it = map2.lower_bound(arr[i]);
            if (it == map2.end())
            {
                // [i] is biggest . no eq
                //vio[i] = -1;
                vie[i] = std::prev(it)->second;
            }
            else if (it == map2.begin() && arr[i] != map2.begin()->first)
            {
                // [i] is smallest , no eq
                vio[i] = it->second;
                //vie[i] = -1;
            }
            else
            {
                int t2 = it->first;
                if (t2 == arr[i])
                {
                    vio[i] = vie[i] = it->second;
                }
                else
                {
                    // it->first > arr[i]
                    vio[i] = it->second;
                    it = std::prev(it);
                    vie[i] = it->second;
                }
            }
            map2[arr[i]] = i;
        }
        
#ifdef __test
        showVectorInt(vio);
        showVectorInt(vie);
#endif

        vector<int> vbodd(sz1, -1);
        vector<int> vbeven(sz1, -1);
        vbodd[sz1 - 1] = vbeven[sz1 - 1] = 1;

        int ans = 0;
        for (int i = sz1 - 2; i >= 0; --i)
        {
            dfsb1(arr, vbodd, vbeven, i, 1, vio, vie);
        }
        for (int i = 0; i < sz1; ++i)
        {
            ans += vbodd[i] == 1;
        }
        return ans;
    }

    int dfsb1(vector<int>& arr, vector<int>& vbodd, vector<int>& vbeven, int idx, int stp, vector<int>& nxtodd, vector<int>& nxteven)
    {

#ifdef __test
        cout << stp << " --- " << idx << endl;
#endif

        if (stp % 2)
        {
            if (vbodd[idx] != -1)
                return vbodd[idx];
        }
        else
        {
            if (vbeven[idx] != -1)
                return vbeven[idx];
        }
        if (stp % 2)
        {
            int nxt = nxtodd[idx];
            if (nxt == -1)
                vbodd[idx] = 0;
            else
                vbodd[idx] = dfsb1(arr, vbodd, vbeven, nxt, stp + 1, nxtodd, nxteven);

            return vbodd[idx];
        }
        else
        {
            int nxt = nxteven[idx];
            if (nxt == -1)
                vbeven[idx] = 0;
            else
                vbeven[idx] = dfsb1(arr, vbodd, vbeven, nxt, stp + 1, nxtodd, nxteven);

            return vbeven[idx];
        }
    }


    // tle。*2 ...  for(1..n){dfs} , for(n..1){dfs} 都是tle。。。
    int lt0975a(vector<int>& arr)
    {
        int sz1 = arr.size();
        
        vector<int> vbodd(sz1, -1);
        vector<int> vbeven(sz1, -1);
        vbodd[sz1 - 1] = 1;
        vbeven[sz1 - 1] = 1;

        for (int i = sz1 - 1; i >= 0; --i)
        {
            dfsa1(arr, vbodd, vbeven, i, 1);
        }
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
            ans += vbodd[i];
        return ans;
    }

    // 0:false, 1true
    int dfsa1(vector<int>& arr, vector<int>& vbodd, vector<int>& vbeven, int idx, int stp)
    {
        if (stp % 2)        // odd
        {
            if (vbodd[idx] != -1)
                return vbodd[idx];
        }
        else
        {
            if (vbeven[idx] != -1)
                return vbeven[idx];
        }

        if (stp % 2)        // odd .... just bool stp...
        {
            int chose = -1;
            for (int i = idx + 1; i < arr.size(); ++i)
            {
                if (arr[i] >= arr[idx])
                {
                    if (chose == -1)
                        chose = i;
                    else
                    {
                        if (arr[i] < arr[chose])
                            chose = i;
                    }
                }
            }

            if (chose == -1)
                vbodd[idx] = 0;
            else
                vbodd[idx] = dfsa1(arr, vbodd, vbeven, chose, stp + 1);

            return vbodd[idx];
        }
        else
        {
            int chose = -1;
            for (int i = idx + 1; i < arr.size(); ++i)
            {
                if (arr[i] <= arr[idx])
                {
                    if (chose == -1 || arr[i] > arr[chose])
                    {
                        chose = i;
                    }
                }
            }

            if (chose == -1)
                vbeven[idx] = 0;
            else 
                vbeven[idx] = dfsa1(arr, vbodd, vbeven, chose, stp + 1);

            return vbeven[idx];
        }
    }



    // 1,3,5:  后续中 比自己大的，且 最小的， 多个则取前面的
    // 2,4,6： 后续中 比自己小的，且最大的， 多个取前面的。
    //int lt0975a(vector<int>& arr) 
    //{
    //    int sz1 = arr.size();
    //    stack<int> mnstk;       // smaller than me
    //    stack<int> mxstk;       // bigger than me

    //    mnstk.push(sz1 - 1);
    //    mxstk.push(sz1 - 1);

    //    vector<int> vib(sz1, -1);
    //    vector<int> vis(sz1, -1);

    //    for (int i = sz1 - 2; i >= 0; --i)
    //    {
    //        while (!mxstk.empty() && arr[mxstk.top()] < arr[i])
    //        {
    //            mxstk.pop();
    //        }
    //        while (!mnstk.empty() && arr[mnstk.top()] > arr[i])
    //        {
    //            mnstk.pop();
    //        }

    //        if (!mxstk.empty())
    //            vib

    //    }

    //}

};

int main()
{

    LT0975 lt;

    myvi v = { 10,13,12,14,15 };          // 2
    //myvi v = { 2,3,1,1,4 };         // 3
    //myvi v = { 5,1,3,4,2 };           // 3

    cout << lt.lt0975b(v) << endl;

    return 0;
}
