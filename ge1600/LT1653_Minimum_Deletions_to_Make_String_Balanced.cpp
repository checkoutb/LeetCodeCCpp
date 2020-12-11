
#include "../header/myheader.h"

class LT1653
{
public:

// D D


//        for(int i = 0; i < n; i++){
//            if (s[i] == 'a' and b){
//                b-- ;
//                ans++ ;
//            }
//            else if (s[i] == 'b')  b++ ;
//        }
// 抵消，   ans++ ， 可能是删除 a 也可能是删除 b


//        for(int i=0;i<s.length();i++){
//            if(s[i]=='a'){
//                ans = min(ans+1, b);
//            }else{
//                b++;
//            }
//        }


//        for (int i = 0; i < l; i++) {
//            if (s.charAt(i) == 'a') {
//                //case 1: keep current a. ==> prev chars must be a...a
//                //so need to remove all 'b' chars before i, which is bcount
//
//                //case 2: remove current a ==> prev chars must be a...ab...b
//                //so need to remove current a and whatever makes substring before current i valid which is dp[i];
//                dp[i + 1] = Math.min(dp[i] + 1, bcount);
//            } else {
//                //since it is always valid to append 'b' if substring before current i is valid, so just copy whatever makes substring before i valid which is dp[i];
//                dp[i + 1] = dp[i];
//                bcount++;
//            }
//        }


//        for(int i = n-1; i >=0; i--){
//            char c = s[i];
//            if(!st.empty() && st.top() < c){
//                res++;
//                st.pop();
//            }else{
//                st.push(c);
//            }
//        }


//    for (auto ch : s) {
//        b += ch == 'b';
//        a -= ch == 'a';
//        res = min(res, b + a);
//    }




//Runtime: 176 ms, faster than 35.20% of C++ online submissions for Minimum Deletions to Make String Balanced.
//Memory Usage: 66.7 MB, less than 5.51% of C++ online submissions for Minimum Deletions to Make String Balanced.
// 以某个b 为 第一个b，然后看 代价。
// aaa bbb
    int lt1653a(string s)
    {
        int sz1 = s.size();
        vector<vector<int>> vv(2, vector<int>(sz1));
        // 0: 前面多少个b,   1: 后面多少个a
        int cnt = 0;
        for (int i = 0; i < sz1; ++i)
            if (s[i] == 'b')
                vv[0][i] = cnt++;
        int ans = cnt;                      // b全delete
        for (int i = sz1 - 1, cnt = 0; i >= 0; --i)
            if (s[i] == 'a')
                cnt++;
            else
                vv[1][i] = cnt;
        ans = min(ans, cnt);
//        int ans = INT_MAX;
        for (int i = 0; i < sz1; ++i)
            if (s[i] == 'b')
                ans = min(vv[0][i] + vv[1][i], ans);
        return ans;
//        return ans == INT_MAX ? 0 : ans;

//        vector<int> v(s.size());
//        int cnt = 0;
//        for (int i = 0; i < s.size(); ++i)
//        {
//            if (s[i] == 'a')        // 前面有多少个b
//                v[i] = cnt;
//            else
//                cnt++;
//        }
//        cnt = 0;
//        for (int i = s.size() - 1; i >= 0; --i)
//        {
//            if (s[i] == 'b')        // 后面有多少个a
//                v[i] = cnt;
//            else
//                cnt++;
//        }

    }

};

int main()
{

//    string s = "aababbab";
    string s = "bbaaaaabb";

    LT1653 lt;

    cout<<lt.lt1653a(s);

    return 0;
}
