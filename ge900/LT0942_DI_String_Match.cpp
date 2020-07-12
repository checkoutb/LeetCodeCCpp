
#include "../header/myheader.h"

class LT0942
{
public:

// D D
//        int i = 0, s = S.size();
//        for (auto c : S) {
//            if (c == 'I') {
//                res.push_back(i++);
//            } else {
//                res.push_back(s--);
//            }
//        }
//        res.push_back(i);

//    vector<int> res;
//    for (int l = 0, h = S.size(), i = 0; i <= S.size(); ++i)
//        res.push_back(i == S.size() || S[i] == 'I' ? l++ : h--);
//    return res;

//        int left = count(S.begin(), S.end(), 'D'), right = left;
//        vector<int> res = {left};
//        for (char &c : S)
//            res.push_back(c == 'I' ? ++right : --left);
//        return res;

// 。。。

//Runtime: 12 ms, faster than 48.62% of C++ online submissions for DI String Match.
//Memory Usage: 8.4 MB, less than 99.28% of C++ online submissions for DI String Match.
    vector<int> lt0942b(string S)
    {
        int mx = 1;
        int mn = -1;
        int sz1 = S.size();
        vector<int> ans(sz1 + 1);
        for (int i = 1; i <= sz1; i++)
        {
            if (S[i - 1] == 'I')
            {
                ans[i] = mx++;
            }
            else
            {
                ans[i] = mn--;
            }
        }
        mn = -mn - 1;
        for (int i = 0; i <= sz1; i++)
        {
            ans[i] += mn;
        }
        return ans;
    }


// error
// S 是动作，返回符合这个动作的 状态
// 后面连续几个相同动作。
    vector<int> lt0942a(string S)
    {
        vector<int> ans(S.size() + 1, 1);
        vector<bool> notUsed(S.size() + 1, true);
        int sz1 = S.size();

        for (int i = S.size() - 2; i >= 0; i--)
        {
            if (S[i] == S[i + 1])
            {
                ans[i] = ans[i + 1] + 1;
            }
        }
        for (int i = 0; i < S.size(); i++)
        {
            char ch = S[i];
            if (ch == 'I')
            {
                int t3 = sz1 - ans[i];
                if (notUsed[t3])
                {
                    ans[i] = t3;
                    notUsed[t3] = false;
                }
                else
                {
                    for (int j = i - 1; j >= 0; j--)
                    {
                        if (notUsed[j])
                        {
                            ans[i] = j;
                            notUsed[j] = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                // 。。。 如果是本次是D，之前是I，那么需要比前面那个大。。。gg
                int t3 = ans[i];
                if (notUsed[t3])
                {
                    ans[i] = t3;
                    notUsed[t3] = false;
                }
                else
                {
                    for (int j = i + 1; j <= sz1; j++)
                    {
                        if (notUsed[j])
                        {
                            ans[i] = j;
                            notUsed[j] = false;
                            break;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < notUsed.size(); i++)
        {
            if (notUsed[i])
            {
                ans[sz1] = i;
                break;
            }
        }
        return ans;
    }

};

int main()
{

    string s = "IDID";
//    string s = "III";
//    string s = "DDI";

    LT0942 lt;

    vector<int> v = lt.lt0942b(s);

    for_each(begin(v), end(v), fun_cout);
    cout<<endl;

    return 0;
}
