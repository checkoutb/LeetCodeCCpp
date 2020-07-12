
#include "../header/myheader.h"

class LT0930
{
public:

// D D
//        unordered_map<int, int> c({{0, 1}});
//        int psum = 0, res = 0;
//        for (int i : A) {
//            psum += i;
//            res += c[psum - S];
//            c[psum]++;
//        }
//        return res;
// 。。。


//    int numSubarraysWithSum(vector<int>& A, int S) {
//        return atMost(A, S) - atMost(A, S - 1);
//    }
//    int atMost(vector<int>& A, int S) {
//        if (S < 0) return 0;
//        int res = 0, i = 0, n = A.size();
//        for (int j = 0; j < n; j++) {
//            S -= A[j];
//            while (S < 0)
//                S += A[i++];
//            res += j - i + 1;
//        }
//        return res;
//    }


//        if(A == null || A.length == 0) return 0;
//        int[] freq = new int[A.length + 1];
//        int ans = 0;
//        int sum = 0;
//        for(int i = 0;i<A.length;i++){
//            sum += A[i];
//            int index = sum - S;
//            if(index >= 0) ans += freq[index];
//            if(sum == S) ans++;
//            freq[sum]++;
//        }
//        return ans;

//        int left = 0, cnt = 0, n = A.size(), ans = 0;
//        for (int i = 0; i < n; i++) {
//            cnt += A[i];
//            while (left < i && cnt > S)cnt -= A[left++];
//            if (cnt < S)continue;
//            if (cnt == S)ans++;
//            int t = left;
//            while (t < i && A[t] == 0) {
//                t++, ans++;
//            }
//        }
//        return ans;



//Runtime: 100 ms, faster than 54.46% of C++ online submissions for Binary Subarrays With Sum.
//Memory Usage: 31.6 MB, less than 45.69% of C++ online submissions for Binary Subarrays With Sum.
    int lt0930c(vector<int>& A, int S)
    {
        unordered_map<int, int> map2;
        int s = 0;
        for (int i = 0; i < A.size(); i++)
        {
            s += A[i];
            map2[s]++;
        }
        int ans = 0;
        if (S != 0)
            map2[0]++;

        #ifdef __test
        for (auto p : map2)
        {
            cout<<p.first<<", "<<p.second<<endl;
        }
        #endif // __test

        for (unordered_map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            int k = it->first;
            int v = it->second;
            if (S == 0)
            {
                if (k > 0)
                    v--;
                while (v > 0)
                {
                    ans += v;
                    v--;
                }
            }
            else
            {
//                int v2 = map2[k + S];         // 这个会导致[k + S] 初始化为0， 使得map2 增加元素，导致iterator。。
                int v2 = 0;
                if (map2.find(k + S) != map2.end())
                    v2 = map2[k + S];
                ans += v2 * v;
            }
        }
        return ans;
    }


// error
    int lt0930b(vector<int>& A, int S)
    {
        map<int, int> map2;
        int s = 0;
        for (int i = 0; i < A.size(); i++)
        {
            s += A[i];
            map2[s]++;
        }
        int ans = 0;
        if (map2.begin()->first == S)
        {
            int v2 = map2.begin()->second;
            while (v2 > 0)
            {
                ans += v2;
                v2--;
            }
//            return ans;
        }
        map2[0]++;

        #ifdef __test
        for (auto p : map2)
        {
            cout<<p.first<<" : "<<p.second<<endl;
        }
        #endif // __test

        for (map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            int k = it->first;
            int v = it->second;
            for (map<int, int>::iterator it2 = map2.begin(); it2 != it; it2++)
            {
                int k2 = it2->first;
                int v2 = it2->second;

//                cout<<k2<<", "<<v2<<", "<<k<<", "<<v<<endl;

                if (k - k2 == S)
                {
                    ans += (v2 * v);
                }
            }
        }
        return ans;
    }

    // tle
    int lt0930a(vector<int>& A, int S)
    {
        int s = 0;
        for (int i = 0; i < A.size(); i++)
        {
            s += A[i];
            A[i] = s;
        }
        A.insert(A.begin(), 0);
        int ans = 0;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = i + 1; j < A.size(); j++)
            {
                if (A[j] - A[i] == S)
                {
                    ans++;
                }
            }
        }
        return ans;
    }

};

int main()
{

//    vector<int> a = {1,0,1,0,1};
//    int s = 2;

// 15
//    vector<int> a = {0,0,0,0,0};
//    int s = 0;

    // 27
    vector<int> a = {0,0,0,0,0,0,1,0,0,0};
    int s = 0;


    LT0930 lt;

    cout<<lt.lt0930c(a, s)<<endl;

    return 0;
}
