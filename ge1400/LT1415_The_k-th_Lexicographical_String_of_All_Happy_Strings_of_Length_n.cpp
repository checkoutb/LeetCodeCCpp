
#include "../header/myheader.h"

class LT1415
{
public:


// D D

//For the string of size n, we can build 3 * pow(2, n - 1) strings.
//So, if k <= pow(2, n - 1), then the first letter is a,
//k <= 2 * pow(2, n - 1) - then b, otherwise c.
//We can also return empty string right away if k > 3 * pow(2, n - 1).
//    auto prem = 1 << (n - 1);
//    if (k > 3 * prem)
//        return "";
//    string s = string(1, 'a' + (k - 1) / prem);
//    while (prem > 1) {
//        k = (k - 1) % prem + 1;
//        prem >>= 1;
//        s += (k - 1) / prem == 0 ? 'a' + (s.back() == 'a') : 'b' + (s.back() != 'c');
//    }
//    return s;


//DFS builds all possible strings in a lexicographical order. Each time a string is built,
//we decrease the global counter k.
//When k reaches zero, we short-circut DFS and build the resulting string right-to-left.
//string getHappyString(int n, int &k, int p = 0, char last_ch = 0) {
//    if (p == n)
//        --k;
//    else
//        for (char ch = 'a'; ch <= 'c'; ++ch) {
//            if (ch != last_ch) {
//                auto res = getHappyString(n, k, p + 1, ch);
//                if (k == 0)
//                    return string(1, ch) + res;
//            }
//        }
//    return "";
//}
// 构造的时候 只需要 != 前面， 并且 dfs，所以最先构造出来的是ababab， 构造顺序符合 字典顺序。


//    def getHappyString(self, n: int, k: int) -> str:
//        nextLetter = {'a': 'bc', 'b': 'ac', 'c': 'ab'}
//        q = collections.deque(['a', 'b', 'c'])
//        while len(q[0]) != n:
//            u = q.popleft()
//            for v in nextLetter[u[-1]]:
//                q.append(u + v)
//        return q[k - 1] if len(q) >= k else ''
// bfs 构造全部。。。


//Runtime: 4 ms, faster than 75.56% of C++ online submissions for The k-th Lexicographical String of All Happy Strings of Length n.
//Memory Usage: 6.3 MB, less than 65.30% of C++ online submissions for The k-th Lexicographical String of All Happy Strings of Length n.
// 121
//      122
// 123
// 131
// 132
//      133
//      211
// 212
// 213
//      221
//      222
//      223
// 231
// 12 13  21 23   31 32
// 找到需要调整的 最高位，然后后续 121212
    string lt1415a(int n, int k)
    {
        vector<int> v(n, 0);
        for (int i = 0; i < n; ++i)
            v[i] = (i % 2 + 1);             // 1212121  abababa
        while (k-- > 1)
        {
            int i = n - 1;
            for (; i >= 0; --i)
            {
                int pre = (i == 0) ? -1 : v[i - 1];
                int t2 = v[i];
                while (t2 <= 3)
                {
                    t2++;
                    if (t2 != pre)
                        break;
                }
                if (t2 <= 3)
                {
                    v[i] = t2;
                    break;
                }
                if (i == 0)
                    return "";
            }
            int t4 = 1;
            for (++i; i < n; ++i)
            {
                v[i] = t4;
                t4 = (3 - t4);
            }
        }
        string ans;
        for (int i : v)
            ans += char ('a' + i - 1);
        return ans;
    }

};

int main()
{

//    int n{1}, k{3};
//    int n{3}, k{9};
//    int n{2}, k{7};
    int n{10}, k{100};

    LT1415 lt;

    cout<<lt.lt1415a(n, k);

    return 0;
}
