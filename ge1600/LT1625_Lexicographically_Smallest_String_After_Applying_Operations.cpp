
#include "../header/myheader.h"

class LT1625
{
public:



// gg ...
// s 必然偶数长度， 那就看b是不是奇数，奇数就意味着 所有位 都可以是 第一个。 然后看 每个 char + a * N 的 最小值是什么。
// 如果这个最小值 唯一， 那么 能达到这个 最小值的 char 就是 首位， 就结束。
// 不唯一， 首位 就是在 多个char 中，  就要看 它们的 后一个char的 可能值 的大小。. b是奇数，能看后一个char，并且这个char能改变，
// b是偶数， 也是看 后一个char， 但是这个char 不能变。
    string lt1625a(string s, int a, int b)
    {
        unordered_map<char, int> map2;
        unordered_map<char, int> unchg;
        vector<bool> vb(10);
        for (int i = 0; i < s.size(); ++i)
        {
            if (b % 2 == 0 && i % 2 == 1)       // b偶数的情况下， 奇数index 不可能为 首位。 所以跳过。
                continue;
            if (map2.find(s[i]) != map2.end())
                continue;
            int t2 = s[i] - '0';
            int mn = t2;
            if (b % 2 == 0 && i % 2 == 0)       // 移动偶数位， 由于 只是 奇数位 + a, 所以 偶数位 不会被修改。
            {
                unchg[s[i]] = mn;
                continue;
            }
            std::fill(begin(vb), end(vb), false);
            while (vb[t2] == false)
            {
                vb[t2] = true;
                mn = min(mn, t2);
                t2 = (t2 + a) % 10;
//                cout<<t2<<endl;
            }
            map2[s[i]] = mn;
        }
//        cout<<map2.size()<<" . . "<<endl;
        int mn2 = 10;
        for (auto& p : map2)
        {
            mn2 = min(mn2, p.second);
        }
        int mn3 = 10;
        for (auto& p : unchg)
        {
            mn3 = min(mn2, p.second);
        }
        vector<int> vidx;
        if (mn2 == min(mn2, mn3))
        {
            for (auto& p : map2)
            {
                if (p.second == mn2)        // p.first is char
                {
                    for (int i = 0; i < s.size(); ++i)
                    {
                        if (b % 2 == 0 && i % 2 == 0)
                            continue;
                        if (s[i] == p.first)
                            vidx.push_back(i);
                    }
                }
    //            cout<<"aa"<<endl;
            }

            #ifdef __test
            for (auto& p : map2)
                cout<<p.first<<", - "<<p.second<<endl;
            showVectorInt(vidx);
            cout<<endl;
            #endif // __test
//            vector<string> vs(vidx.size());
            for (int i = 0; i < vidx.size(); ++i)
            {
                int cnt = 0;
                int t2 = s[vidx[i]];
                while (t2 != mn2)
                {
                    t2 = (t2 + a) % 10;
                    cnt++;
    //                cout<<"a1 "<<mn2<<","<<t2<<endl;
                }
                int ad = cnt * a;
                string s2 = s.substr(vidx[i]) + s.substr(0, vidx[i]);
                cout<<"s.s.s "<<s2<<endl;
                for (int j = 0; j < s2.size(); j += 2)
                {
                    s2[j] = char ((s2[j] + ad) % 10 + '0');
                }
            }
        }
        if (b % 2 == 0)
        {
            std::nth_element(vs.begin(), vs.begin(), vs.end());
            return vs[0];
        }
        else
        {
            for (string& s3 : vs)
            {
                char c3 = s3[1];
                int t2 = c3;
                int ad = 0;
                int mn3 = map2[c3];
                while (t2 != mn3)
                {
                    t2 = (t2 + a) % 10;
                    ad += a;
                }
                for (int j = 1; j < s3.size(); j += 2)
                {
                    s3[j] = char ((s3[j] + ad) % 10 + '0');
                }
            }
            std::nth_element(begin(vs), begin(vs), end(vs));
            return vs[0];
        }
        return "Aa";
    }

};

int main()
{
    vector<string> vs = {"5525"
//    , "74", "0011", "43987654"
    };
    myvi v1 = {9
//    ,5,4,7
    };
    myvi v2 = {2
//    ,1,2,3
    };

    LT1625 lt;

    for (int i = 0; i < vs.size(); ++i)
    {
        string s = lt.lt1625a(vs[i], v1[i], v2[i]);
        cout<<" ans : ."<<s<<"."<<endl;
    }

    return 0;
}
