
#include "../header/myheader.h"

class LT0474
{
public:







//
//        int[] count = count(s);
//        for (int i=m;i>=count[0];i--)
//            for (int j=n;j>=count[1];j--)
//                dp[i][j] = Math.max(1 + dp[i-count[0]][j-count[1]], dp[i][j]);

// for for 的是  m,n减去s的0，1个数后，还剩下的0，1的个数 所组成的范围。如果其他string，在这个范围内，那么说明2个string可以用m,n个0，1组成。





// gg...







// lt0474c... 16/63 tle...
    static int countX(string str, char c)
    {
        int ans = 0;
        for (char ch : str)
        {
            if (ch == c)
                ans++;
        }
        return ans;
    }

    int count1(string str)
    {
        int ans = 0;
        for (char ch : str)
        {
            if (ch == '1')
                ans++;
        }
        return ans;
    }

    static bool comparec1(const string& a, const string& b)
    {
        return countX(a, '1') > countX(b, '1');
    }

    static bool comparec2(const string& a, const string& b)
    {
        return countX(a, '0') > countX(b, '0');
    }

    int lt0474c(vector<string>& strs, int m, int n)
    {
        std::sort(strs.begin(), strs.end(), LT0474::comparec1);
        vector<string> v1(strs);
        std::sort(strs.begin(), strs.end(), LT0474::comparec2);
        vector<string> v0(strs);

        #ifdef __test
        for_each(v1.begin(), v1.end(), fun_cout_s);
        cout<<endl;
        for_each(v0.begin(), v0.end(), fun_cout_s);
        cout<<endl;
        #endif // __test

        int ans = recursionc1(v0, v1, m, n, -1);

        return std::max(ans, 0);
    }

    int recursionc1(vector<string>& v0, vector<string>& v1, int m, int n, int cnts)
    {
        if (m >= 0 && n >= 0)
            cnts++;
        if (m <= 0 && n <= 0)
            return cnts;

        int t1 = cnts;
        if (v0.size() > 0)
        {
            string s0 = v0[v0.size() - 1];
            v0.pop_back();
            vector<string>::iterator it1 = std::find(v1.begin(), v1.end(), s0);
            v1.erase(it1);
            int n1 = count1(s0);
            int n0 = s0.size() - n1;

            t1 = std::max(t1, recursionc1(v0, v1, m - n0, n - n1, cnts));
            v0.push_back(s0);
            v1.insert(it1, s0);
        }
        if (v1.size() > 0)
        {
            string s1 = v1[v1.size() - 1];
            v1.pop_back();
            vector<string>::iterator it0 = std::find(v0.begin(), v0.end(), s1);
            v0.erase(it0);
            int n1 = count1(s1);
            int n0 = s1.size() - n1;

            t1 = std::max(t1, recursionc1(v0, v1, m - n0, n - n1, cnts));
            v1.push_back(s1);
            v0.insert(it0, s1);
        }

        return t1;
    }

// error
//["111","1000","1000","1000"]
//9
//3
// ans:3, output:1....
    int lt0474b(vector<string>& strs, int m, int n)
    {
        std::sort(strs.begin(), strs.end(), [](string& a, string& b){ return a.size() < b.size();});

        #ifdef __test
        for_each(strs.begin(), strs.end(), fun_cout_s);
        cout<<endl;
        #endif // __test

        int ans = 0;
        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            int n1s = count1(s);
            int n0s = s.size() - n1s;
            if (m >= n0s && n >= n1s)
            {
                ans++;
                m -= n0s;
                n -= n1s;
            }
        }
        return ans;
    }


    // 16 / 63 tle...
    int lt0474a(vector<string>& strs, int m, int n)
    {
        if (m < 0 || n < 0)
            return 0;
        int ans = recursiona1(strs, m, n, 0, -1);
        return ans;
    }

    int recursiona1(vector<string>& strs, int m, int n, int start, int cnts)
    {
        if (m >= 0 && n >= 0)
            cnts++;
        else
            return cnts;
        int ans = cnts;
        for (int i = start; i < strs.size(); i++)
        {
            string s = strs[i];
            int num1s = count1(s);
            int num0s = s.size() - num1s;
            int t2 = recursiona1(strs, m - num0s, n - num1s, i + 1, cnts);
            ans = std::max(t2, ans);
        }
        return ans;
    }

};

int main()
{

// 4
//    vector<string> v = {"10", "0001", "111001", "1", "0"};
//    int m = 5;
//    int n = 3;

// 2
//    vector<string> v = {"10", "0", "1"};
//    int m = 1;
//    int n = 1;

//["111","1000","1000","1000"]
//9
//3
//    -- 3
    vector<string> v = {"111","1000","1000","1000"};
    int m = 9;
    int n = 3;

    LT0474 lt;

    cout<<lt.lt0474c(v, m, n)<<endl;

    return 0;

}
