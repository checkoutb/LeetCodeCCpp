
#include "../header/myheader.h"

class LT0032
{
public:

// D D

// stack or dp

//            for(int i=1; i < s.length(); i++){
//                if(s[i] == ')'){
//                    if(s[i-1] == '('){
//                        longest[i] = (i-2) >= 0 ? (longest[i-2] + 2) : 2;
//                        curMax = max(longest[i],curMax);
//                    }
//                    else{ // if s[i-1] == ')', combine the previous length.
//                        if(i-longest[i-1]-1 >= 0 && s[i-longest[i-1]-1] == '('){
//                            longest[i] = longest[i-1] + 2 + ((i-longest[i-1]-2 >= 0)?longest[i-longest[i-1]-2]:0);
//                            curMax = max(longest[i],curMax);
//                        }
//                    }
//                }
//                //else if s[i] == '(', skip it, because longest[i] must be 0
//            }

//        memset(dp, 0, sizeof(dp));
//        for(int i = 1; i < s.length(); ++i){
//            if(s[i] == '(') {
//                dp[i] = 0;
//            } else if(s[i] == ')') {
//
//                if(s[i - 1] == '(') {
//                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
//                } else if(s[i - 1] == ')') {
//                    int toCheck = i - dp[i - 1] - 1;
//                    if(toCheck >= 0) {
//                        if(s[toCheck] == '(') {
//                            dp[i] = dp[i - 1] + 2 + (toCheck - 1 >= 0 ? dp[toCheck - 1] : 0);
//                        } else {
//                            dp[i] = 0;
//                        }
//                    }
//                }
//            }
//
//            mxlength = max(dp[i], mxlength);
//        }

//        for (int i = 0; i < n; i++) {
//            if (s[i] == '(') st.push(i);
//            else {
//                if (!st.empty()) {
//                    if (s[st.top()] == '(') st.pop();
//                    else st.push(i);
//                }
//                else st.push(i);
//            }
//        }
//        if (st.empty()) longest = n;
//        else {
//            int a = n, b = 0;
//            while (!st.empty()) {
//                b = st.top(); st.pop();
//                longest = max(longest, a-b-1);
//                a = b;
//            }
//            longest = max(longest, a);
//        }


// ++ ,burongyi ... 往事不堪回首月明中。
//12/15/2020 12:27	Accepted	20 ms	7.2 MB	cpp
//12/15/2020 11:34	Wrong Answer	N/A	N/A	cpp
//02/06/2018 16:22	Time Limit Exceeded	N/A	N/A	java
//02/06/2018 16:21	Wrong Answer	N/A	N/A	java
//02/06/2018 16:18	Time Limit Exceeded	N/A	N/A	java
//02/06/2018 16:17	Time Limit Exceeded	N/A	N/A	java
//02/06/2018 16:17	Time Limit Exceeded	N/A	N/A	java
//02/06/2018 16:17	Wrong Answer	N/A	N/A	java
//02/06/2018 16:16	Time Limit Exceeded	N/A	N/A	java
//02/06/2018 16:13	Time Limit Exceeded	N/A	N/A	java
//02/06/2018 16:13	Time Limit Exceeded	N/A	N/A	java
//02/06/2018 16:10	Wrong Answer	N/A	N/A	java
//02/06/2018 16:08	Wrong Answer	N/A	N/A	java
//02/06/2018 16:07	Runtime Error	N/A	N/A	java
//02/06/2018 16:05	Runtime Error	N/A	N/A	java
//02/06/2018 16:00	Time Limit Exceeded	N/A	N/A	java
//02/06/2018 15:59	Time Limit Exceeded	N/A	N/A	java
//02/06/2018 15:58	Time Limit Exceeded	N/A	N/A	java
//02/06/2018 15:57	Time Limit Exceeded	N/A	N/A	java
//02/06/2018 15:55	Time Limit Exceeded	N/A	N/A	java
//02/06/2018 15:54	Wrong Answer	N/A	N/A	java
//02/06/2018 15:51	Wrong Answer	N/A	N/A	java
//02/06/2018 15:09	Time Limit Exceeded	N/A	N/A	java
//02/06/2018 14:53	Wrong Answer	N/A	N/A	java
//02/06/2018 14:42	Wrong Answer	N/A	N/A	java
//02/06/2018 14:41	Wrong Answer	N/A	N/A	java
//02/06/2018 14:41	Compile Error	N/A	N/A	java
//02/06/2018 14:06	Wrong Answer	N/A	N/A	java

//Runtime: 20 ms, faster than 8.64% of C++ online submissions for Longest Valid Parentheses.
//Memory Usage: 7.2 MB, less than 83.39% of C++ online submissions for Longest Valid Parentheses.
    int lt0032b(string s)
    {
        int sz1 = s.size();
        vector<bool> vb(sz1, false);
        for (int i = 0; i < sz1; ++i)
        {
            if (s[i] == ')')
            {
                for (int j = i - 1; j >= 0; --j)
                {
                    if (vb[j])
                        continue;
                    else
                    {
                        if (s[j] == '(')
                        {
                            vb[j] = true;
                            vb[i] = true;
                        }
                        else
                        {

                        }
                        break;
                    }
                }
            }
        }
        int ans = 0;
        int cnt = 0;
        for (bool b : vb)
        {
            if (b)
            {
                cnt++;
            }
            else
            {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }

    // error
    int lt0032a(string s)
    {
        int ans = 0;
        int t2 = 0;
        int cnt = 0;
        int cnt2 = 0;
        for (char ch : s)
        {
            if (ch == '(')
            {
                t2++;
                cnt++;
                cnt2 = 0;
            }
            else
            {
                cnt++;
                t2--;
                cnt2++;
                if (t2 < 0)
                {
                    t2 = 0;
                    cnt = 0;
                    cnt2 = 0;
                }
                else
                {
                    if (t2 == 0)
                        ans = max(ans, cnt - t2);
                    else
                    {
//                    cout<<cnt<<","<<t2<<endl;       // 5,1
//                        ans = max(ans, cnt - t2);
                        ans = max(ans, cnt2 * 2);
                    }
                }
//                t2--;
//                cnt--;
//                if (t2 == 0)
//                {
//                    ans = max(ans, cnt);
//                }
//                t2 = max(0, t2);
//                cnt = max(0, cnt);
            }
        }
        return ans;
    }

};

int main()
{
    vector<string> vs = {
    "(()", ")()())", "",
    "()(()", "(()(())"};

    LT0032 lt;

    for (string& s : vs)
        cout<<lt.lt0032b(s)<<endl;

    return 0;
}
