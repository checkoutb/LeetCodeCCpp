
#include "../../header/myheader.h"

class LT
{
public:

// D D


//int num(char a,char b) {
//    return (a-'0')*10+(b-'0');
//}
//int numDecodings(string s) {
//    int len = s.length();
//    vector<int> dp(len+1,0);
//    dp[0]=1;
//    for (int i = 1;i<=len;i++) {
//        if (s[i-1]!='0')
//          dp[i] = dp[i-1];
//        if (i!=1&&s[i-2]!='0'&&num(s[i-2],s[i-1])<=26)
//            dp[i]+=dp[i-2];
//    }
//    return dp[len];


//        vector<int> dp(n+1);
//        dp[n] = 1;
//        for(int i=n-1;i>=0;i--) {
//            if(s[i]=='0') dp[i]=0;
//            else {
//                dp[i] = dp[i+1];
//                if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) dp[i]+=dp[i+2];
//            }
//        }
//        return s.empty()? 0 : dp[0];


//    int numDecodings(string s) {
//        return s.empty() ? 0: numDecodings(0,s);
//    }
//    int numDecodings(int p, string& s) {
//        int n = s.size();
//        if(p == n) return 1;
//        if(s[p] == '0') return 0; // sub string starting with 0 is not a valid encoding
//        int res = numDecodings(p+1,s);
//        if( p < n-1 && (s[p]=='1'|| (s[p]=='2'&& s[p+1]<'7'))) res += numDecodings(p+2,s);
//        return res;
//    }



// AC
    int lta(string s)
    {
        int sz1 = s.size();
        vector<int> vi(sz1);
//        unordered_set<string> set2;
//        for (int i = 1; i <= 26; ++i)
//        {
//            set2.insert(std::to_string(i));
//        }
//        unordered_set<int> set2;
//        for (int i = 1; i <= 9; ++i)
//        {
//            set2.insert()
//        }
        int t2 = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            t2 = s[i] - '0';
            if (t2 == 0)
            {
                if (i == 0 || s[i - 1] == '0' || s[i - 1] >= '3')
                    return 0;
                vi[i] = i <= 1 ? 1 : vi[i - 2];         // . 和上一个char合并，所以拿上上个char的。。因为上一个char的结果是 单独上一个，或者 上一个+上上一个 的和。
                                // 没有是1. bu  20是1, 30是0
            }
            else
            {
                vi[i] = vi[i] + (i == 0 ? 1 : vi[i - 1]);
                if (i > 0 && s[i - 1] != '0')
                {
                    t2 += (s[i - 1] - '0') * 10;
                    if (t2 <= 26)
                    {
                        vi[i] = vi[i] + (i == 1 ? 1 : vi[i - 2]);
                    }
                }
            }
        }
        #ifdef __test
        showVectorInt(vi);
        #endif // __test

//        // 10好特殊。。 110是对的。   20     30.
//        if (s[sz1 - 1] == '0' && sz1 == 2)
//            return s[0] == '1' || s[0] == '2' ? 1 : 0;

        return vi[sz1 - 1];
    }

};

int main()
{
//    string s = "12";
//    string s = "226";
//    string s = "0";
//    string s = "06";
//    string s = "11106";
//    string s = "111";           // 1 1 1    1 11    11 1
                // 1110    1 1 10   11 10    反而减少了。

//    string s = "012123123";

//    string s = "10";
    string s = "30";
//    string s = "33";
//    string s = "22";
//    string s = "10011";
//    string s = "207";

    LT lt;

    cout<<lt.lta(s)<<endl;

    return 0;
}
