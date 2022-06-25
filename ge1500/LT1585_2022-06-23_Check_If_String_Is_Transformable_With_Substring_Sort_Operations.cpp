
#include "../header/myheader.h"

class LT1585
{
public:

    // D

    // 前面不能有比自己小的。

    //vector<vector<int>> idx(10);
    //vector<int> pos(10);
    //for (int i = 0; i < s.size(); ++i)
    //    idx[s[i] - '0'].push_back(i);
    //for (auto ch : t) {
    //    int d = ch - '0';
    //    if (pos[d] >= idx[d].size())
    //        return false;
    //    for (auto i = 0; i < d; ++i)
    //        if (pos[i] < idx[i].size() && idx[i][pos[i]] < idx[d][pos[d]])
    //            return false;
    //    ++pos[d];
    //}
    // 。。。。6


    // tle  134/138


    // 不需要区间。。。直接找，找到 就想办法移动过来。。。找区间的话， 区间的最后一个 不是 t[i]，只需要移动 [idx]之前的。
    bool lt1585d(string s, string t)
    {
        int sz1 = s.size();
        for (int i = 0; i < sz1; ++i)
        {
#ifdef __test
            cout << s << ", " << t << " -=-- " << i << endl;
#endif
            if (s[i] != t[i])
            {
                if (s[i] < t[i])
                    return false;
                for (int j = i + 1; j < sz1; ++j)
                {
                    if (s[j] == t[i])
                    {
                        for (int k = j; k > i; --k)
                        {
                            s[k] = s[k - 1];
                        }
                        s[i] = t[i];
                        goto AAA;
                    }
                    else if (s[j] < t[i])
                    {
                        return false;
                    }
                }
                return false;
                AAA:
                continue;
            }
        }
        return true;
    }


    // 136/138   "99...999888...88777...77...5..44..33...22...1.." "111...22...333...44...5...66...7...88...9.."   excepted: true
    // 看了hint，就是我这种啊。。我再试试。。。
    bool lt1585c(string s, string t)
    {
        int sz1 = s.size();

        for (int i = 0; i < sz1; ++i)
        {
#ifdef __test
            cout << i << endl;
            cout << " -   " << s << " - " << t << endl;
#endif
            if (s[i] != t[i])
            {
                int arr[10] = { 0 };
                int diff = 0;
                int idx = -1;
                for (int j = i; j < sz1; ++j)
                {
                    int sj = s[j] - '0';
                    int tj = t[j] - '0';
                    arr[sj]++;
                    arr[tj]--;

                    if (sj < (t[i] - '0') && (idx == -1))            // ... 由于直接sort，所以 有小于的 也无所谓。... 不是。。  区间 内可以有 比 t[i] 小的，但是 在这个 小于t[i] 的 前面，必须有一个 t[i]
                        return false;

                    if (s[j] == t[i] && idx == -1)
                        idx = j;

                    for (int a = 0; a < 10; ++a)
                    {
                        if (arr[a] != 0)
                        {
                            goto AAA;
                        }
                    }
                    s[idx] = s[j];
                    for (int k = j; k > i; k--)
                    {
                        s[k] = s[k - 1];
                    }
                    s[i] = t[i];
                    goto BBB;

                    AAA:
                    continue;
                }
                return false;
                BBB:
                continue;
            }
        }

        return true;
    }


    // gg

    // error

    // 应该是 找到一个前缀，里面 各类char数量 相等。  然后尝试 将所需的 char  一步一步向前移。 毕竟 一步一步的话，还有机会，一旦sort，就定型了。
    // 就是碰到 不匹配，从这个char开始，向后找，直到 一个 区间， s，t 在这个区间中的 各类char 的数量相等， 且包含 所需的char，
    //          且 区间内不能有 比 所需的char 小的，  然后 把 所需的char 放到第一位，其它各后移一位。

    // 不过 感觉 肯定 tle 。。。 试试，tle 赢一半
    // 有没有 一个区间不行，但是 更大的区间可以的？
    bool lt1585b(string s, string t)
    {
        int sz1 = s.size();

        for (int i = 0; i < sz1; ++i)
        {
#ifdef __test
            cout << i << endl;
            cout << " -   " << s << " - " << t << endl;
#endif
            if (s[i] != t[i])
            {
                int arr[10] = { 0 };
                int diff = 0;
                int idx = 0;
                for (int j = i; j < sz1; ++j)
                {
                    int sj = s[j] - '0';
                    int tj = t[j] - '0';
                    arr[sj]++;
                    arr[tj]--;

                    if (sj < (t[i] - '0'))
                        return false;

                    if (s[j] == t[i])
                        idx = j;

                    for (int a = 0; a < 10; ++a)
                    {
                        if (arr[a] != 0)
                        {
                            goto AAA;
                        }
                    }
                    s[idx] = s[j];
                    for (int k = j; k > i; k--)
                    {
                        s[k] = s[k - 1];
                    }
                    s[i] = t[i];
                    goto BBB;

                    AAA:
                    continue;
                }
                return false;
                BBB:
                continue;
            }
        }

        return true;
    }



    // ...error ...  从头开始 不行的。
    // 不匹配时，从当前位置，到 匹配的char 的位置， 这段 substring 中，匹配的char 是不是 最小的。
    // 有点费时间啊。tle？ 不不不， sliding window ? 对的，因为是 sort，所以 窗口 不需要变小的。
    bool lt1585a(string s, string t)
    {
        priority_queue<char, vector<char>, std::greater<char>> priq;
        int idx = 0;
        for (int i = 0; i < s.size(); ++i)
        {
#ifdef __test
            cout << i << endl;
#endif
            if (priq.empty())
            {
                if (s[i] != t[i])
                {
                    int tar = t[i];
                    idx = i;
                    while (idx < s.size())
                    {
                        priq.push(s[idx]);
                        if (s[idx++] == t[i])
                        {
                            break;
                        }
                    }
                    if (priq.top() != t[i])
                        return false;
                    priq.pop();
                }
            }
            else
            {
                int t2 = priq.top();
                
                if (t2 != t[i])
                {
                    while (idx < s.size())
                    {
                        priq.push(s[idx]);
                        if (s[idx++] == t[i])
                        {
                            break;
                        }
                    }
                    if (priq.top() != t[i])
                        return false;
                    priq.pop();
                }
                else
                {
                    priq.pop();
                }
            }

            //if (s[i] != t[i])
            //{
            //    
            //}
        }
        return true;
    }

};

int main()
{

    LT1585 lt;

    //string s = "84532", t = "34852";

//    string s = "34521", t = "23415";

    //string s = "12345", t = "12435";


    string s = "999888777666555444333222111000";
    string t = "111222333444555666000777888999";


    // error C2026: 字符串太大，已截断尾部字符
    //cout << s.size() << endl;

    cout << lt.lt1585d(s, t) << endl;

    return 0;
}
