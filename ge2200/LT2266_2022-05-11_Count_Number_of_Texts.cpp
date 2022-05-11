
#include "../header/myheader.h"

class LT2266
{
public:

// D D

//        for(int i=1;i<=inp.length();i++){
//            dp[i]=dp[i-1]%MOD;
//            if(i-2>=0 and inp[i-1]==inp[i-2]){
//                dp[i]=(dp[i]+dp[i-2])%MOD;
//                if(i-3>=0 and inp[i-1]==inp[i-3]){
//                    dp[i]=(dp[i]+dp[i-3])%MOD;
//                    if(i-4>=0 and (inp[i-1]=='7' or inp[i-1]=='9') and inp[i-1]==inp[i-4])
//                        dp[i]=(dp[i]+dp[i-4])%MOD;
//                }
//            }
//        }
// == 7 || == 9...




//For i + 1-th character, the number of messages is dp[i + 1] = dp[i], plus:            // 本次是新起一个，所以截至本次至少是 dp[i] 种
//    dp[i - 1] if key[i + 1] == key[i]                                         // 如果本次和上一个相同，那么选择 和上一个合并，那么就 + dp[i-1]
//    dp[i - 2] if key[i + 1] == key[i - 1]
//    dp[i - 3] if key[i + 1] == key[i - 2]
//    dp[i - 4] if key[i + 1] == key[i - 3] and key[i + 1] is either 7 or 9.
// 描述应该有点瑕疵，应该是 在上一个if成立的情况下，继续判断。
//
// 这个是以本char为结尾，可以有多少种可能。由于会判断是否和前1/2/3/4个char相等，所以需要保存以前1/2/3/4个char为结尾的 短信的可能个数
//               我的是 以本char为结尾，这个char是连续的 第1/2/3/4 个char的 可能个数，所以保存的是 本个char作为 连续的 1/2/3/4 个char的 短信的可能个数。
//
//    int dp[5] = {1, 1, 1, 1, 1}, n = k.size();
//    for (int i = n - 1; i >= 0; --i) {
//        dp[i % 5] = 0;
//        int max_j = min(n, i + (k[i] == '7' || k[i] == '9' ? 4 : 3));
//        for (int j = i; j < max_j && k[i] == k[j]; ++j)
//            dp[i % 5] = (dp[i % 5] + dp[(j + 1) % 5]) % 1000000007;
//    }
//    return dp[0];


//        int n(pressedKeys.size()), p(1e9+7), dp[n+1];
//        int cnt[10]={0,0,3,3,3,3,3,4,3,4};
//        memset(dp,0,sizeof(dp));
//        dp[0] = 1;
//        for (int i(0); i < n; ++i) {
//            for (int k(0), m(cnt[pressedKeys[i]-'0']); k < m && k<i+1 && pressedKeys[i]==pressedKeys[i-k]; ++k)
//                dp[i+1] = (dp[i+1]+dp[i-k])%p;
//        }
//        return dp[n];



//Runtime: 66 ms, faster than 67.23% of C++ online submissions for Count Number of Texts.
//Memory Usage: 10.9 MB, less than 97.88% of C++ online submissions for Count Number of Texts.
// 好像所有地方都可以插入"空格"。
// 不过不清楚 2点击4次 是不是一个 单独的 a。。还是说至多是 ca ？  。。 应该是 ca吧？
// 前面是结束或继续，已经连续x次，且 x+1 是有效的，那么本次可以连续上去
    int lt2266a(string pressedKeys)
    {
        const int MOD = 1e9 + 7;
//        int arrcnt[10] = {0,0,3,3,3,3,3,4,3,4};
//        char arrch[10][4] = {{},{},{'a','b','c'},{'d','e','f'},{'g','h',}}
        string arrch[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int ans = 0;

        int arr[5] = {0};
        arr[1] = {1};

        for (int i = 1; i < pressedKeys.size(); ++i)
        {
            int arr2[5] = {0};
            if (pressedKeys[i] != pressedKeys[i - 1])
            {
                for (int j = 1; j <= 4; j++)
                {
//                    arr2[1] += arr[j];
                    arr2[1] = (arr2[1] + arr[j]) % MOD;
                }
            }
            else
            {
                // ==, 继续上次，或者 重启一个新char
                for (int j = 1; j <= 4; j++)
                {
//                    arr2[1] += arr[j];          // 重启
                    arr2[1] = (arr2[1] + arr[j]) % MOD;
                }
                for (int j = 2; j <= arrch[pressedKeys[i] - '0'].size(); ++j)
                {
                    arr2[j] = arr[j - 1];
//                    arr2[j] = (arr2[j] + arr[j - 1]) % MOD;
//                    arr2[j] += arr[j - 1];          // "+="  ==  "="
                }
            }
            swap(arr, arr2);
        }
        for (int i = 1; i <= 4; ++i)
        {
            ans = (ans + arr[i]) % MOD;
        }
        return ans;
    }

};

int main()
{

    LT2266 lt;

//    string s = "22233";
    string s = "222222222222222222222222222222222222";

    cout<<lt.lt2266a(s)<<endl;

    return 0;
}
