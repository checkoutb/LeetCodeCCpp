
#include "../header/myheader.h"

class LT1234
{
public:


// D D

//Specilly this time we don't care the count of elements inside the window,
//we want to know the count outside the window.
// 似乎所有的 代码 都是 while (cnt['Q'] < sz/4)

//    unordered_map<char, int> cnt;
//    int sz = s.size(), n = s.size() / 4, res = INT_MAX;
//    for (auto ch : s)
//        ++cnt[ch];
//    for (int i = 0, j = 0; i < s.size(); ++i) {
//        --cnt[s[i]];
//        while (j < s.size() && all_of(begin(cnt), end(cnt),
//            [&](const pair<char, int> &p) { return p.second <= n; })) {
//            res = min(res, i - j + 1);
//            ++cnt[s[j++]];
//        }
//    }


//        for (int j = 0; j < n; ++j) {
//            count[s[j]]++;
//        }
//        for (int j = 0; j < n; ++j) {
//            count[s[j]]--;
//            while (i < n && count['Q'] <= k && count['W'] <= k && count['E'] <= k && count['R'] <= k) {
//                res = min(res, j - i + 1);
//                count[s[i++]] += 1;
//            }
//        }
// 外层--， 内层++
// 切去j， 所以外面的 cnt[sj]--
// 当剩余部分满足 <= k时， i是substring的开始， 所以 少切 i， 外面就需要++。
// 切一个尾巴，满足时，少切一个头， 直到不满足。  然后再切一个尾巴， 循环。。


// 我这个是， 外层是substr的开始， en是结束。
// 外部subseq 不满足时，就切掉，直到满足，记录 长度。
// 然后 不切i， 再开始下一个循环。


//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Replace the Substring for Balanced String.
//Memory Usage: 8 MB, less than 5.75% of C++ online submissions for Replace the Substring for Balanced String.
    int lt1234c(string s)
    {
//        s = s + s;
        int sz2 = s.size();
//        int mx2 = sz2 / 8;
        int mx2 = sz2 / 4;
        int arr[90] = {0};
        int en = 0;
        int mn = INT_MAX;
        for (char ch : s)
            arr[ch]++;
        if (arr['Q'] == arr['W'] && arr['W'] == arr['E'] && arr['E'] == arr['R'])
            return 0;
//cout<<arr['Q']<<", "<<arr['W']<<", "<<arr['E']<<", "<<arr['R']<<", "<<mx2<<endl;
        for (int i = 0; i < sz2; ++i)
        {
//            bool can = false;
            while (en < sz2 && (arr['Q'] > mx2 || arr['W'] > mx2 || arr['E'] > mx2 || arr['R'] > mx2))
            {
                arr[s[en]]--;
                en++;
            }
//cout<<arr['Q']<<", "<<arr['W']<<", "<<arr['E']<<", "<<arr['R']<<endl;
            if (arr['Q'] <= mx2 && arr['W'] <= mx2 && arr['E'] <= mx2 && arr['R'] <= mx2)
            {
//                #ifdef __test
//                cout<<i<<", "<<en<<endl;
//                cout<<arr['Q']<<", "<<arr['W']<<", "<<arr['E']<<", "<<arr['R']<<endl;
//                #endif // __test
                mn = min(mn, en - i);
            }

//            for (; en < sz2; )
//            {
//                if (arr[s[en]] > mx2)
//                {
//                    arr[s[en]]--;
//                    en++;
//                    if (arr['Q'] <= mx2 && arr['W'] <= mx2 && arr['E'] <= mx2 && arr['R'] <= mx2)
//                    {
////                        cout<<en<<", "<<i<<endl;
//                        mn = min(mn, en - i + 1);
//                        break;
//                    }
//                }
//                else
//                {
////                    ar
//                    break;
//                }
//            }
            arr[s[i]]++;
        }
        return mn;
    }



// substring, 所以不能分割， 所以，窗口和这个相反。。。窗口里是 使得 外部能满足/4的 substring。
// sliding window
    int lt1234b(string s)
    {
        s = s + s;
        int sz2 = s.size();
        int mx2 = sz2 / 8;
        int arr[90] = {0};
        int mx = 0;
        int mxt = 0;
        int ans = 0;
        int st = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (arr[s[i]] >= mx2)
            {
                while (st < i && s[st] != s[i])
                {
                    mxt--;
                    arr[s[st]]--;
                    st++;
//                    cout<<" . .. .. "<<endl;
                }
                mxt--;
                arr[s[i]]--;
                st++;
            }
            mxt++;
            arr[s[i]]++;
            if (mx < mxt)
                cout<<mx<<", "<<mxt<<", "<<i<<", "<<st<<", "<<s.substr(st, i - st + 1)<<endl;
            mx = max(mx, mxt);
        }
        if (mx == sz2)
            return 0;
        return sz2 / 2 - mx;
    }


// error
// 哪段substr 包含的 QWER 最多，且不每个char都不超过n/4.
// 2bei.
// kadane 。 。 。md，不能用的。。。too naive.
    int lt1234a(string s)
    {
        s = s + s;
        int sz2 = s.size();
        int mx2 = sz2 / 8;
        int arr[90] = {0};
        int mx = 0;
        int mxt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (arr[s[i]] >= mx2)
            {
//                cout<<"    "<<mx<<", "<<mxt<<endl;
                mx = max(mx, mxt);
                mxt = 1;
                arr['Q'] = 0;
                arr['W'] = 0;
                arr['E'] = 0;
                arr['R'] = 0;
            }
            else
            {
                mxt++;
            }
            arr[s[i]]++;
        }
//        cout<<mx<<", "<<mxt<<endl;
        mx = max(mx, mxt);
        if (mx == sz2)
            return 0;
        return sz2 / 2 - mx;
    }

};

int main()
{

    vector<string> vs = {
    "QWER","QQWE","QQQW","QQQQ",
    "WWQQRRRRQRQQ","WEWEQQRWRRWREQWEEWEQERQWWWRERRWEWWQWQQWQEREQRQRRREQWWERRERQWWRRWRWRQRWWQWRWWWWREWWWW",       // 14
    "RRWREWREWQREQWEQEQQRERREWRQRWWERRWRWWERQQERWQREEWERWRQQRRWQQWWQE"     // 7
    };
//    vector<string> vs = {"WWQQRRRRQRQQ"};       // 换RQRQ.  WWQQRRR RQRQ Q
//    vector<string> vs = {"WEWEQQRWRRWREQWEEWEQERQWWWRERRWEWWQWQQWQEREQRQRRREQWWERRERQWWRRWRWRQRWWQWRWWWWREWWWW"};       // 14

//    15,21,14,21      84/4=21    6,0,7,0,0
//    W  EWEQQRWRRWREQWEEWEQERQWWWRERRWEWWQWQQWQEREQRQRRREQWWERRERQWWRRWRWRQRWWQ  WRWWWWREWWWW

    LT1234 lt;

    for (string& s : vs)
    {
        cout<<s<<endl;
        cout<<lt.lt1234c(s)<<endl;
    }
    return 0;
}
