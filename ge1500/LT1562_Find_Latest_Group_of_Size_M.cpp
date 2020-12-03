
#include "../header/myheader.h"

class LT1562
{
public:

// D D

//dp[curr-left] = dp[curr+right] = cval;
// 只需要 边界 设置 正确的长度就可以了


//        if (m == len) return m;
//            int len_l = sum[tmp-1];
//            int len_r = sum[tmp+1];
//            int cnt = len_l + len_r + 1;
//            sum[tmp-len_l] = sum[tmp+len_r] = cnt;
//            if (len_l == m || len_r == m)
//                res = i;
//

//        int res = -1, n = A.size();
//        vector<int> length(n + 2), count(n + 1);
//        for (int i = 0; i < n; ++i) {
//            int a = A[i], left = length[a - 1], right = length[a + 1];
//            length[a] = length[a - left] = length[a + right] = left + right + 1;
//            count[left]--;
//            count[right]--;
//            count[length[a]]++;
//            if (count[m])
//                res = i + 1;
//        }



//        int res = -1, n = A.size();
//        if (n == m) return n;
//        vector<int> length(n + 2);
//        for (int i = 0; i < n; ++i) {
//            int a = A[i], left = length[a - 1], right = length[a + 1];
//            length[a - left] = length[a + right] = left + right + 1;
//            if (left == m || right == m)
//                res = i;
//        }


//		int n = arr.length;
//        if(m == n)
//            return n;
//
//        TreeSet<Integer> walls = new TreeSet<Integer>();
//        walls.add(0);
//        walls.add(n+1);
//
//        for(int i=n-1;i>=0;i--){
//            int left = walls.floor(arr[i]);
//            int right = walls.ceiling(arr[i]);
//            if(arr[i]-left-1 == m || right-arr[i]-1 == m)
//                return i;
//            walls.add(arr[i]);
//        }
//
//        return -1;


//        int res = -1, n = arr.length;
//        Map<Integer, Integer> cl = new HashMap<>(), fl = new HashMap<>();  // length of ceiling and floor to glue
//        int[] ls = new int[n + 1];
//        for (int i = 0; i < n; i++) {
//            int pos = arr[i], ceil = cl.getOrDefault(pos + 1, 0), floor = fl.getOrDefault(pos - 1, 0), newLen = ceil + floor + 1;
//            if (ceil > 0) ls[ceil]--;
//            if (floor > 0) ls[floor]--;
//            cl.put(pos - floor, newLen);  // new range;
//            fl.put(pos + ceil, newLen);
//            ls[newLen]++;  // new range length;
//            if (ls[m] > 0) res = i + 1;  // last
//        }





//        queue<pair<int, int>> que;
//        que.push({1, n}); // initial state


//        set<pair<int, int>> st;
//        st.insert({1, n});





// 把第一行的 +2， 改成 +1，  会出错，  把 cout<<"." 放开， +1 不会出错， 估计是 cout 导致内存中 uf 移动了？
// 越界这种，c++ 无所谓的，一般只是一个 错误的值， 不可能中断程序的， 现在 会中断，那就说明  真的超出内存限制了。
// 如果cout 不会导致 uf 在内存中移动， 那么不应该 之前中断，现在不中断啊。。 但是移动 一个 vector？ 没那么傻吧。
// 这个不清楚为什么。  难道 越界 还有一种 界限 是 c++管理的内存范围？，，不， 指针可以访问任何物理内存地址，所以c++也可以啊。
// 不清楚。   还是说， 当你越界到 一个 被使用 的 内存地址，就会抛错？

//Runtime: 276 ms, faster than 57.69% of C++ online submissions for Find Latest Group of Size M.
//Memory Usage: 79.8 MB, less than 80.34% of C++ online submissions for Find Latest Group of Size M.
    int lt1562b(vector<int>& arr, int m)
    {
        vector<int> uf(arr.size() + 2, 0);          // +2.
        int ans = -1;
        int cntm = 0;
        m = -m;
        for (int i = 0; i < arr.size(); ++i)
        {
            int val = arr[i];
            pair<int, int> left = ufa1(uf, val - 1);
            pair<int, int> right = ufa1(uf, val + 1);
            int len = left.second + right.second - 1;
            if (len == m)
                cntm++;
            if (left.second == m)
                cntm--;
            if (right.second == m)
                cntm--;
            if (cntm > 0)
                ans = i + 1;
            if (len == -1)
            {
                uf[val] = len;
            }
            else
            {
                if (left.second < 0)
                {
                    uf[val] = left.first;
                    if (right.second < 0)
                    {
                        uf[right.first] = left.first;
                    }
                    uf[left.first] = len;
                }
                else
                {
                    uf[val] = right.first;
                    uf[right.first] = len;
                }
            }
//            cout<<".";
        }
        return ans;
    }

    // index, value
    pair<int, int> ufa1(vector<int>& uf, int t)
    {
        if (uf[t] <= 0)
            return {t, uf[t]};
        pair<int, int> p = ufa1(uf, uf[t]);
        uf[t] = p.first;
        return p;
    }

// error
// tle tuotuodi
// 归并。
    int lt1562a(vector<int>& arr, int m)
    {
        unordered_map<int, int> map2;       // idx : size.index
        vector<int> vi;         // size
        int ans = -1;
        int cntm = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            int len = 1;
            int idxl = -1;
            int idxr = -1;
            if (map2.find(arr[i] - 1) != map2.end())
            {
                idxl = map2[arr[i] - 1];
                len += vi[idxl];
                if (vi[idxl] == m)
                    cntm--;
            }
            if (map2.find(arr[i] + 1) != map2.end())
            {
                idxr = map2[arr[i] + 1];
                len += vi[idxr];
                if (vi[idxr] == m)
                    cntm--;
            }
            if (len == m)
                cntm++;

            if (len == 1)
            {
                map2[arr[i]] = vi.size();
                vi.push_back(1);
            }
            else
            {
                map2[arr[i]] = (idxl == -1 ? idxr : idxl);

//                cout<<" . . .ma : "<<arr[i]<<" , "<<map2[arr[i]];
            }

            if (idxl != -1 && idxr != -1)       // !!!!!!!!   no , 还是缺了一部分。 还是得并查集。 。。 不如直接并查集。
            {
//                map2[arr[i] - 1] = map2[arr[i] + 1];
                map2[arr[i] + 1] = map2[arr[i] - 1];
            }

            #ifdef __test
            cout<<i<<", "<<arr[i]<<", "<<len<<"     "<<(idxl == -1 ? -3 : vi[idxl])<<", "<<(idxr == -1 ? -7 : vi[idxr])
            <<", - -  "<<idxl<<", , "<<idxr<<endl;
            #endif // __test
//            cout<<"            "<<vi[idxl]<<", "<<vi[idxr]<<endl;
            if (idxl != -1)
            {
//                        cout<<" . . . ll "<<vi[idxl]<<endl;

                vi[idxl] = len;
            }
            if (idxr != -1)
            {
//                    cout<<" / . . rr "<<vi[idxr]<<endl;
                vi[idxr] = len;

//                cout<<"   after rrr  "<<vi[idxr]<<endl;
//                cout<<" . . . "<<vi[map2[arr[i]]]<<endl;
            }

            if (cntm > 0)
                ans = i + 1;
        }
        return ans;
    }

};

int main()
{
    myvi asdf = {1,2,3};
    cout<<asdf[5]<<endl;

//    myvi v = {3,5,1,2,4};
//    int m{1};

//    myvi v = {3,1,5,4,2};
//    int m{2};

//    myvi v = {1};
//    int m{1};

//    myvi v = {2,1};
//    int m{2};

// 1 0 1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
    myvi v = {7,6,11,10,3,8,1,14,9,13,16,15,5,12,17  ,4,2};           // 15
    int m{13};
// 1  3   56789a0a1 a2 a3a4a5a6 a7



    LT1562 lt;

    cout<<lt.lt1562b(v, m);

    return 0;
}
