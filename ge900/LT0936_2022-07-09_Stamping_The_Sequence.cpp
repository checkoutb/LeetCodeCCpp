
#include "../header/myheader.h"

class LT0936
{
public:



    // g


    //vector<int> lt0936b(string stamp, string target)
    //{
    //    int sz1 = target.size();
    //    vector<int> ans;
    //    bool can = true;
    //    while (can)
    //    {
    //        can = false;

    //    }
    //    if (count(begin(target), end(target), 'A') != target.size())
    //        return {};
    //    reverse(begin(ans), end(ans));
    //    return ans;
    //}




    // 缺了 AbA 。。。
    // .. 不行。。
    // 应该ok的， 原先少了 while(can) 这层。导致只能 从长到短 进行 find。
    //
    // error...
    // 暴力？每次 搜索 stamp，有就 替换为 A， 没有就尝试 stamp[0:-2] + "A", "A" + stamp[1:-1]。
    // target[0] == stamp[0]， 一路向后，如果不相等，那么尝试 用 stamp[x] 来和 当前的 target[y] 来进行匹配。
    // 感觉KMP了，但。。
    // 10 * target.length 有什么用？ 这个 每次turn 至少有一个 char 会成为 最终的 char的吧？ 那就是最多 target.length 次。
    // .. 最左的。
    // 难在最左。。
    // 不，把 stamp 替换成A后， 它左侧的就是上次的。
    // 好像就是 找 stamp，然后向左找，然后向右找， 然后再找stamp。
    // ...好像是要求 stamp的最左侧的char 所在的下标。。不是 最左侧的操作。。。 yes
    vector<int> lt0936a(string stamp, string target)
    {
        int sz1 = target.size();
        vector<int> ans;

        bool can = true;
        //string s2 = stamp;
        //int st1 = 0;
        //int en2 = stamp.size() - 1;
        int t2 = -1;
        int t3 = -1;
        string oris = stamp;
        int sz2 = stamp.size();
        while (can)
        {
            can = false;
            string s2 = oris;
            stamp = oris;
            int st1 = 0;
            int en2 = stamp.size() - 1;
#ifdef __test
            cout << ".." << endl;
#endif
            while (st1 < stamp.size())
            {
                //t2 = target.find(stamp);
                //t3 = target.find(s2);

                //t2 = (t2 == std::string::npos) ? INT_MAX : t2;
                //t3 = (t3 == std::string::npos) ? INT_MAX : t3;

                //if (min(t2, t3) == INT_MAX)
                //{
                //    stamp[st1++] = 'A';
                //    s2[en2--] = 'A';
                //    continue;
                //}

                //if (t2 < t3)
                //{
                //    target.replace(t2, sz2, sz2, 'A');

                //}
                //else
                //{
                //    target.replace(t3, sz2, sz2, 'A');
                //}

                can = false;
                while ((t2 = target.find(stamp)) != std::string::npos)
                {
                    //target.replace(t2, stamp.size(), "A");
                    target.replace(t2, stamp.size(), stamp.size(), 'A');
                    can = true;
                    ans.push_back(t2);
                }
                while ((t2 = target.find(s2)) != std::string::npos)
                {
                    //target.replace(t2, stamp.size(), "A");
                    target.replace(t2, stamp.size(), stamp.size(), 'A');
                    can = true;
                    ans.push_back(t2);
                }

#ifdef __test
                cout << stamp << " - " << s2 << ", " << target << endl;
#endif

                ////...
                //can = true;

                stamp[st1++] = 'A';
                s2[en2--] = 'A';
            }
        }
#ifdef __test
        cout << "target: " << target << endl;
        showVectorInt(ans);
#endif

        // 前缀，后缀 都被剔除了，所以 剩下的 就是 中间的，中间的，说明是第一个放的。
        // ... 中间，就需要两侧的距离够。。
        for (int i = 0; i < sz1; ++i)
        {
            if (target[i] != 'A')
            {
                string s = "";
                for (int j = i; j < sz1 && target[j] != 'A'; ++j)
                {
                    s.push_back(target[j]);
                    target[j] = 'A';
                }
                t2 = oris.rfind(s, i);
                if (t2 == std::string::npos)
                    return {};
                if (oris.size() - t2 > target.size() - i)
                    return {};
                ans.push_back(i - t2);
            }
        }



        if (count(begin(target), end(target), 'A') != target.size())
            return {};

        std::reverse(begin(ans), end(ans));
        return ans;
    }

};

int main()
{

    LT0936 lt;

    //string s = "abc", t = "ababc";

    //string s = "abca", t = "aabcaca";

    //string s = "uskh", t = "uskhkhhskh";

    //string s = "zbs", t = "zbzbsbszbssbzbszbsss";       // zbzbs bs zbs s b zbs  zbsss

    //string s = "oufnpynyipqceggekcdw", t = "ooufnpynyipqceggekcdwwdwc";

    string s = "zomkijviod", t = "zzomkizomkzozomkijviodijviodzomkijvizomkijviododdd";      // 可行的。


    myvi v = lt.lt0936a(s, t);


    string ss = "abcdefghijkl";
    string s2 = ss.replace(2, 4, 2, 'A');

    cout << ss << ", " << s2 << endl;
    
    showVectorInt(v);

    return 0;
}
