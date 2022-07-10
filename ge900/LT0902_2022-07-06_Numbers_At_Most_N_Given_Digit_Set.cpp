
#include "../header/myheader.h"

class LT0902
{
public:

    // D D

    //string NS = to_string(N);
    //int digit = NS.size(), dsize = D.size(), rtn = 0;

    //for (int i = 1; i < digit; ++i)
    //    rtn += pow(dsize, i);

    //for (int i = 0; i < digit; ++i) {
    //    bool hasSameNum = false;
    //    for (string& d : D) {
    //        if (d[0] < NS[i])
    //            rtn += pow(dsize, digit - i - 1);
    //        else if (d[0] == NS[i])
    //            hasSameNum = true;
    //    }
    //    if (!hasSameNum) return rtn;
    //}
    //return rtn + 1;









    // 最后一轮循环中, x 必须在 {digit} 中.
//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Numbers At Most N Given Digit Set.
//Memory Usage : 8.3 MB, less than 26.91 % of C++ online submissions for Numbers At Most N Given Digit Set.
    // 
    int lt0902a(vector<string>& digits, int n)
    {
        int sz1 = digits.size();
        vector<vector<int>> vvi(11, vector<int>(11));
        long long t2 = 0LL;
        long long pw = 1LL;
        vector<int> vi;
        int ans = 0;
        
        for (string& s : digits)
            vi.push_back(s[0] - '0');

        for (int i : vi)
            vvi[1][i] = 1;

        int t4 = n;
        bool all = true;
        unordered_set<int> set2(begin(vi), end(vi));
        while (t4 > 0 && all)
        {
            if (set2.find(t4 % 10) == set2.end())
            {
                all = false;
                break;
            }
            t4 /= 10;
        }
        if (all)
            ans = 1;

        t4 = n;
        while ((t4 / 10) > 0)
            t4 /= 10;


        int cnt = vi.size();
        int idx = 2;
        pw *= 10;
        while (pw <= n)
        {
            for (int i : vi)
                vvi[idx][i] = cnt;
            cnt *= vi.size();
            pw *= 10;
            idx++;
        }

        //while (pw > n)
        //    pw /= 10;


#ifdef __test
        for (myvi& v : vvi)
        {
            for (int i : v)
                cout << i << ", ";
            cout << endl;
        }
        cout << " iiddxx  " << idx << ", " << pw << ", " << endl;
#endif

        for (int i = 1; i <= idx - 2 - (t4 >= vi[0] ? 0 : 0); ++i)
        {
            for (int j = 1; j < 10; ++j)
            {
                ans += vvi[i][j];
            }
        }

        bool bigger = false;
        bool isfirst = true;

        while (n > 0)
        {
            int x = n / pw;
            n = n % pw;
            pw /= 10;

#ifdef __test
            cout << x << " --- " <<" ,, " << ans <<" - - "<<n << endl;
#endif

            if (x == 0)
            {
                if (isfirst)
                {
                    idx--;
                    continue;
                }
                else
                {
                    break;
                }
            }


            if (isfirst)
            {
                for (int i = 1; i < x; ++i)
                {
                    ans += vvi[idx][i];
                }
                isfirst = false;
            }
            else
            {
                if (bigger)
                {

                    for (int i = 1; i < x; ++i)
                    {
                        ans += vvi[idx][i];
                    }
                    if (x > vi[vi.size() - 1])
                        break;
                    if (x < vi[0])
                        break;
                }
            }
            if (x >= vi[0])
                bigger = true;

            if (x > vi[vi.size() - 1])
                break;

            if (x < vi[0])
                break;

            if (set2.find(x) == set2.end())
            {
                if (x >= vi[0])
                {
                    break;
                }
            }

            idx--;
        }

        //for (int i = 1; i <= 10; ++i)
        //{
        //    for (int j = 1; j <= 10; ++j)
        //    {
        //        ans += vvi[i][j];
        //    }
        //}

        return ans;

        //for (int i = 1; i <= 10; ++i)
        //{
        //    for (int n : vi)
        //    {

        //    }
        //}

    }

};

int main()
{

    LT0902 lt;

    //vector<string> vs = { "1","3","5","7" };
    //int n = 100;

    //vector<string> vs = { "1","4","9" };
    //int n = 1000000000;

    //vector<string> vs = { "7" };
    //int n = 8;

    //vector<string> vs = { "3","4","8" };
    //int n = 4;

    //vector<string> vs = { "5","6" };
    //int n = 19;

    //vector<string> vs = { "9" };
    //int n = 55;

    //vector<string> vs = { "1" };
    //int n = 834;

    //vector<string> vs = { "1","7" };        // 10.   1 7 11 17 71 77   111 117 171 177
    //int n = 231;

    vector<string> vs = { "3", "4", "6", "7", "9" };            // 280
    int n = 4170;

    //vector<string> vs = { "1", "5", "7", "8" };         // 81/84 .. 340
    //int n = 10212;



    cout << lt.lt0902a(vs, n) << endl;

    return 0;
}
