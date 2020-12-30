
#include "../header/myheader.h"

class LT0516
{
public:

// D

//dp[i][j] = dp[i+1][j-1] + 2 if s.charAt(i) == s.charAt(j)
//otherwise, dp[i][j] = Math.max(dp[i+1][j], dp[i][j-1])
//Initialization: dp[i][i] = 1


// gg
    int lt0516a(string s)
    {
        int sz1 = s.size();
        int ans = 1;
        int mxcnt1 = 0;
        vector<int> arr(sz1);
        int arr2[123] = {0};
        for (int i = 0; i < sz1; ++i)
        {
//            if (arr[i] != 0)
//                continue;
            char ch = s[i];
            int cnt1 = 1;
            int skip2 = arr2[ch];
            bool flag2 = false;
            for (int j = sz1 - 1; j > i; --j)
            {
                if (arr[j] != 0)
                    cnt1 = max(arr[j] + 1, cnt1);
//                    cnt1++;
                if (ch == s[j])
                {
                    if (skip2-- > 0)
                        continue;
                    if (arr[j] <= cnt1)
                    {
                        arr[j] = cnt1;
                        arr[i] = cnt1;
                        flag2 = true;
//                        arr2[ch]++;
                        if (cnt1 >= mxcnt1)
                        {
                            mxcnt1 = cnt1;
                            ans = max(ans, cnt1 * 2 + (i + 1 != j));
                        }
//                        break;
                    }
                    else
                    {

                    }
                }
            }
            if (flag2)
            {
                arr2[ch]++;
                for (int j = 'a'; j <= 'z'; ++j)
                {
                    if (ch != j)
                        arr2[j] = 0;
                }
            }
            #ifdef __test
            cout<<" . "<<i<<endl;
            for (int& i : arr)
                cout<<i<<", ";
            cout<<endl;
            #endif // __test
        }
        return ans;

//        int ans = *std::max_element(begin(arr), end(arr));

//        vector<int>::iterator mxele = std::max_element(begin(arr), end(arr));
//        int mx = *mxele;
//        vector<int>::iterator it2 = std::prev(mxele);
//        vector<int>::iterator it3 = std::next(mxele);
//        int ans = mx * 2 + (*it2 != mx && *it3 != mx);        // bbabab    122221

//        int mx = *std::max_element(begin(arr), end(arr));
//        int ans = mx;
//        for (int i = 0; i < sz1; ++i)
//        {
//            if (arr[i] == mx)
//            {
//
////                int pre = i == 0 ? mx : arr[i - 1];
////                int nxt = i == sz1 - 1 ? mx : arr[i + 1];
////                if (pre != mx || nxt != mx)
////                {
////                    ans++;
////                    break;
////                }
////                char p = i == 0 ? s[i] : s[i - 1];
////                char n = i == sz1 - 1 ? s[i] : s[i + 1];
////                if ()
//            }
//        }

//        return ans;
    }

};

int main()
{
//    string s = "bbabab";
//    string s = "cbbd";

//    string s = "abcabcabcabc";      // 7

//    string s = "aabaaba";       // 6

    string s = "abaabaa";

    LT0516 lt;

    cout<<lt.lt0516a(s)<<endl;

    return 0;
}
