
#include "../header/myheader.h"


class LT1611
{
public:



// hint  The fastest way to convert n to zero is to remove all set bits starting from the leftmost one.
// 找最左的符合规则的 来进行转换。。。


// 没用，969134 本地就要 2-3秒。。
// try bfs
    int lt1611b(int n)
    {
        if (n == 0)
            return 0;
        string s;
        while (n > 0)
        {
            s.push_back((char)('0' + (n % 2)));
            n /= 2;
        }
        unordered_set<string> set2;
        set2.insert(s);
        queue<string> que1;
        que1.push(s);
        int ans = 0;
        string tar(s.size(), '0');
        while (!que1.empty())
        {
            string s2 = que1.front();
            que1.pop();
            if (s2 == tar)
                return ans;
            int idx = s2.find("1");                 //。。。之前的 find_last_of。。不必要的， rfind 就可以。。
            string s3 = s2;
            s3[0] = (s3[0] == '1' ? '0' : '1');
            if (set2.find(s3) == set2.end())
            {
                set2.insert(s3);
                que1.push(s3);
            }

            if (idx != (s2.size() - 1))
            {
                s2[idx + 1] = (s2[idx + 1] == '1' ? '0' : '1');
                if (set2.find(s2) == set2.end())
                {
                    set2.insert(s2);
                    que1.push(s2);
                }
            }

            ans++;
        }
        return -123;
    }


// tle。。。
// 0位 在最右
// 最右的bit反转
// 如果 i-1 位 为1，i-2到0 为0，则 i 反转  。。。 。。如果 没有 -1 -2 就不需要判断。 可以直接成立。  没有 -1 的时候 就是 上面的。
// 所以说， 最右的bit 可以直接反转， 非最右的 要求 它的右面是 1000000 的 格式， 0的个数可以是 [0, MAX)
// 所以每次都是找 10..00 的格式，然后 反转前面的，如果前面不是1，那么就 反转 最后一个。 或者 都操作下，记录下。
// 每次从右往左找1，找不到 就结束了。
    int lt1611a(int n)
    {
        string s;
        while (n > 0)
        {
            s.push_back((char)('0' + (n % 2)));
            n /= 2;
        }
        std::reverse(begin(s), end(s));
        unordered_map<string, int> map2;
        dfsa1(s, map2, 0);
        string s2(s.size(), '0');
        int ans = map2[s2];

        #ifdef __test
        cout<<s<<", "<<s2<<endl;
//        for (auto&[k, v] : map2)
//        {
//            cout<<k<<", "<<v<<endl;
//        }
        #endif // __test

        return ans;
    }

    void dfsa1(string s, unordered_map<string, int>& map2, int cnt)
    {
        if (map2.find(s) != map2.end() && map2[s] <= cnt)
            return;

        map2[s] = cnt;
        int idx = s.find_last_of('1');
        if (idx == std::string::npos)
        {
            return;     // bfs 更合适。。
        }
        if (idx != 0)           // 这个提上来，多过了4个案例，不过还是tle。没有什么用。
        {
            string s3 = s;
            s3[idx - 1] = (s3[idx - 1] == '1' ? '0' : '1');
//            cout<<s<<" -2> "<<s3<<endl;
            dfsa1(s3, map2, cnt + 1);
        }
        string s2 = s;
        s2[s2.size() - 1] = (s2[s2.size() - 1] == '1' ? '0' : '1');
//        cout<<s<<" -1> "<<s2<<endl;
        dfsa1(s2, map2, cnt + 1);
    }

};

int main()
{

    LT1611 lt;

//    int n{3};
//    int n{6};
    int n(969134);

    time_t t = time(nullptr);           // 。。。 这个是多少秒。。
    clock_t ct = clock();
    cout<<t<<endl<<ct<<endl;
//    cout<<GetTickCount()<<endl;   // 。。忘记了。不是window。。

//    cout<<lt.lt1611a(n)<<endl;

    cout<<"time : "<<(time(nullptr) - t)<<endl;

    t = time(nullptr);

    cout<<lt.lt1611b(n)<<endl;

    cout<<"time2 : "<<(time(nullptr) - t)<<endl;


    return 0;
}
