
#include "../header/myheader.h"

class LT0967
{
public:


// D D
//        List<Integer> cur = Arrays.asList(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
//        for (int i = 2; i <= N; ++i) {
//            List<Integer> cur2 = new ArrayList<>();
//            for (int x : cur) {
//                int y = x % 10;
//                if (x > 0 && y + K < 10)
//                    cur2.add(x * 10 + y + K);
//                if (x > 0 && K > 0 && y - K >= 0)
//                    cur2.add(x * 10 + y - K);
//            }
//            cur = cur2;
//        }
//        return cur.stream().mapToInt(j->j).toArray();
// ...last step..




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Numbers With Same Consecutive Differences.
//Memory Usage: 7.9 MB, less than 69.08% of C++ online submissions for Numbers With Same Consecutive Differences.
    vector<int> lt0967c(int N, int K)
    {
        vector<int> ans;
        if (N == 1)
            ans.push_back(0);

        for (int i = 1; i < 10; i++)
        {
            dfsa1(i, 1, N, K, ans);
        }
        return ans;
    }

    void dfsa1(int t, int cnt, int& N, int& K, vector<int>& ans)
    {
        if (cnt == N)
        {
            ans.push_back(t);
            return;
        }
        int t2 = t % 10;
        int t3 = t2 - K;
        int t4 = t2 + K;
        if (t3 >= 0 && t3 < 10)
        {
            dfsa1(t * 10 + t3, cnt + 1, N, K, ans);
        }
        if (t3 != t4 && t4 >= 0 && t4 < 10)
        {
            dfsa1(t * 10 + t4, cnt + 1, N, K, ans);
        }
    }




// error
// cao, 123
    vector<int> lt0967b(int N, int K)
    {
        vector<int> ans;
        if (N == 1)
        {
            for (int i = 0; i < 10; i++)
            {
                ans.push_back(i);
            }
            return ans;
        }
        unordered_set<int> set2;
        if (N == 1)
            set2.insert(0);

        for (int i = 1; i < 10 - K; i++)
        {
            int t1 = i;
            int cnt = 1;
            int t2 = i + K;
            while (cnt < N)
            {
                t1 *= 10;
                t1 += t2;
                t2 = (t2 > K) ? t2 - K : t2 + K;
                cnt++;
            }
//            ans.push_back(t1);
            set2.insert(t1);
        }

        if (K != 0)
        {
            for (int i = K; i < 10; i++)
            {
                int t1 = i;
                int cnt = 1;
                int t2 = i - K;
                while (cnt++ < N)
                {
                    t1 *= 10;
                    t1 += t2;
                    t2 = (t2 >= K) ? t2 - K : t2 + K;
                }
//                ans.push_back(t1);
                set2.insert(t1);
            }
        }
        ans = vector<int>(begin(set2), end(set2));
        return ans;
    }



// error
    vector<int> lt0967a(int N, int K)
    {

        vector<int> ans;
        if (N == 1)
        {
            for (int i = 0; i < 10; i++)
            {
                ans.push_back(i);
            }
            return ans;
        }

        unordered_set<int> set2;

        for (int i = 1; i < 10 - K; i++)
        {
            int t1 = i;
            int cnt = 1;
            int t2 = i + K;
            while (cnt < N)
            {
                t1 *= 10;
                t1 += t2;
                t2 = (t2 > K) ? t2 - K : t2 + K;
                cnt++;
            }
            set2.insert(t1);
        }

        for (int i = K; i < 10; i++)
        {
            int t1 = i;
            int cnt = 1;
            int t2 = t1 - K;
            while (cnt++ < N)
            {
                t1 *= 10;
                t1 += t2;
                t2 = (t2 >= K) ? t2 - K : t2 + K;
            }
            set2.insert(t1);
        }
        ans = vector<int>(begin(set2), end(set2));

        return ans;
    }

};

int main()
{

//    int n = 3, k = 7;

//    int n = 1, k = 0;

//    int n = 1, k = 1;

    int n = 3, k = 1;

    LT0967 lt;

    vector<int> ans = lt.lt0967c(n, k);

    for_each(begin(ans), end(ans), fun_cout);
    cout<<endl;

    return 0;
}
