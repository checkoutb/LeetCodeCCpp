
#include "../header/myheader.h"

class LT1143
{
public:


// D D

// detail 里 全是 二维数组。

//        for(int i=1; i <= n; i++){
//            for(int j=1; j <= m; j++){
//                if(text1[i-1] == text2[j-1])
//                    lookup[i][j] = 1 + lookup[i-1][j-1];
//                else
//                    lookup[i][j] = max(lookup[i-1][j], lookup[i][j-1]);
//            }
//        }
// 如果 相等，则=+1， 感觉是把结果放到 i+1, j+1 中了。  是因为 在数组边界时， 取上个长度 会越界。而且 i==j，说明i和j都是本次使用的，上次的最大就只能是i-1, j-1 了。


//char[] X, char[] Y, int m, int n
//		for (int i = 1; i <= m; i++) {
//			int prev = 0;
//			for (int j = 1; j <= n; j++) {
//				int temp = memo[j];
//				if (X[i - 1] == Y[j - 1]) {
//					memo[j] = prev + 1;
//				} else {
//					memo[j] = Math.max(memo[j], memo[j - 1]);
//				}
//				prev = temp;
//			}
//		}
// 一维数组， temp, prev 似乎就是 防止 自己成为自己的前一个char？
// memo 保存了 如果当前只有[0,i],  Y所能组成的最大长度。
// 然后 加一个 i 进去， 松弛？， 如果相等，则 当前Y[0, j] 所能组成的最大长度 + 1。



// 4 wrong, 1 compile error, 2 tle...
//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Longest Common Subsequence.
//Memory Usage: 6.5 MB, less than 6.87% of C++ online submissions for Longest Common Subsequence.
    int lt1143b(string text1, string text2)
    {
        int arr1[1001] = {0};
        for (int i = 0; i < 1001; i++)
            arr1[i] = 10000;
        arr1[0] = -1;
        int sz1 = text1.size();
        int sz2 = text2.size();
        int mnsz = min(sz1, sz2);
        int ans = 0;

        for (int i = 0; i < sz2; i++)
        {
            char ch2 = text2[i];
            for (int k = ans; k >= 0; k--)
            {
                for (int m = arr1[k] + 1; m < sz1 && m < arr1[k + 1]; m++)
                {
                    if (ch2 == text1[m])
                    {
                        arr1[k + 1] = m;
                        ans = max(ans, k + 1);
                        break;
                    }
                }
            }

//            for (int k = 0; k <= mnsz; k++)     // len > 1
//            {
//                if (arr1[k] == 10000)
//                    break;
//                for (int m = arr1[k] + 1; m < sz1 && m < arr1[k + 1]; m++)
//                {
//                    if (ch2 == text1[m])
//                    {
//                        arr1[k + 1] = m;
//                        break;
//                    }
//                }
//            }
//            for (int j = 0; j < sz1; j++)       // len 1            // 这个for 先的话，可能把自己当作前一个char了。。。。keyi hebing,,,dei fanxu...
//            {
//                if (ch2 == text1[j])
//                {
//                    arr1[1] = min(arr1[1], j);
////                    arr1[0] = 0;
//                    break;
//                }
//            }
        }
//        int ans = 0;
//        while (ans + 1 < 1001 && arr1[ans + 1] != 10000)
//        {
//            ans++;
//        }
        #ifdef __test
        for (int i = 0; i < mnsz + 1; i++)
        {
            cout<<arr1[i]<<", ";
        }
        cout<<endl;
        #endif // __test

        return ans;
    }


// 不过，看输出的时候，感觉 可以只用 一维数组的。 保存 当前 能达到下标长度 的 最小 text1.index.
// md, 42/43 tle.
// xuan or buxuan...bu, zheshi dfs,,,, xianzai zhezhong  dei huisu, huisu dao tou...
    int lt1143a(string text1, string text2)
    {
//        int arr1[1002][26] = {{0}};
//        int arr2[1002][26] = {{0}};
//        int arr1[1002][2] = {{0}};          // [len, char in text1];
//        int arr1[1001][1001] = {{0}};       // i:text2.index, j:text1.index, val:mxlen
        int arr1[1001][1001] = {{0}};       // row:text2.index, col:ans.length, val:text1.index.
        for (int i = 0; i < 1001; i++)
        {
            for (int j = 0; j < 1001; j++)
            {
                arr1[i][j] = -1;
            }
        }
        int sz1 = text1.size();
        int sz2{static_cast<int>(text2.size())};            // leetcode want static_cast<int>
        int mnsz{min(sz1, sz2)};
        int ans = 0;
        int i1{0}, i2{0};
        char ch1, ch2;
        while (i2 < sz2)
        {
//        cout<<i2<<endl;
            ch2 = text2[i2];
//            int mxlen = 0;
            for (int i = 0; i < sz1; i++)           // sz2 ...
            {
                if (text1[i] == ch2)
                {
//                    arr1[i2][0] = 1;
//                    arr1[i2][1] = i;
//                    arr1[i2][i] = 1;
                    arr1[i2][1] = i;
                    ans = max(ans, 1);
                    break;
                }
            }
            for (int i = 1; i < mnsz && i <= i2; i++)      // len
            {
//            cout<<"  "<<i2<<" + "<<i<<endl;
                int mxk = 1001;
                for (int j = 0; j < i2; j++)               // text2.index
                {
                    if (arr1[j][i] != -1)
                    {
                        for (int k = arr1[j][i] + 1; k < sz1 && k < mxk; k++)      // find text1.index
                        {
                            if (ch2 == text1[k])            // text2[k] ....
                            {
                                if (arr1[i2][i + 1] == -1)
                                    arr1[i2][i + 1] = k;
                                else
                                    arr1[i2][i + 1] = min(k, arr1[i2][i + 1]);          // zhiqian meiyou  min, zhijie =k...
                                mxk = min(mxk, k);

//                                arr1[i2][i + 1] = k;                // i(len) + 1
//                                cout<<" ? "<<i<<endl;
//                                cout<<i2<<", "<<ch2<<", "<<j<<", "<<i<<", "<<k<<endl;
                                ans = max(ans, i + 1);
                                break;      // meiyouzhege...
                            }
                        }
                    }
                }
            }
//            for (int i = 0; i < i2; i++)
//            {
////                char lst = text2[i];
////                int lstst = text2[]
//
//            }

            i2++;
        }

        #ifdef __test
        for (int i = 0; i <= sz2; i++)
        {
            cout<<"  "<<text2[i]<<": ";
            for (int j = 0; j <= mnsz; j++)
            {
                cout<<arr1[i][j]<<",";
            }
            cout<<endl;
        }

        #endif // __test

        return ans;
    }

};

int main()
{

//    string arr1[] = {"abcde", "abc", "abc"};
//    string arr2[] = {"ace", "abc", "def"};
//
    LT1143 lt;
//
//    cout<<sizeof(arr1)<<", "<<sizeof(string)<<endl;           // sizeofstring 32
//
//    for (int i = 0; i < sizeof(arr1) / sizeof(string); i++)
//    {
//        cout<<"start: "<<arr1[i]<<" : "<<arr2[i]<<endl;
//        cout<<lt.lt1143a(arr1[i], arr2[i])<<endl;
//    }

//    string s1 = "ezupkr";           // 2   ur           // md luozhi cuowu.
//    string s2 = "ubmrapg";

//    string s1 = "xaxx";         // you yige luozhi cuowu
//    string s2 = "a";

//    string s1 = "abcba";        // 5
//    string s2 = "abcbcba";

    string s1 = "fcvqfcnglshwpgxujwrylqzejmdubkxs";         // 11
    string s2 = "bctsfwdelkdqzshupmrufyxklsjurevip";



    cout<<s1<<", "<<s2<<endl;
    cout<<lt.lt1143b(s1, s2);


    return 0;
}
