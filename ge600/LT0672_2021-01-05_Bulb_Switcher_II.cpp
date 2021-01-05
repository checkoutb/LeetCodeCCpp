
#include "../header/myheader.h"

class LT0672
{
public:

// D D

//        n=min(n,3);
//        if(m==0)
//            return 1;
//        if(m==1)
//            return n==1?2:n==2?3:4;
//        if(m==2)
//            return n==1?2:n==2?4:7;
//        return n==1?2:n==2?4:8;
// ...


//string result(min(n, 6), '1');


//        if(m==0) return 1;
//        if(n==1) return 2;
//        if(n==2&&m==1) return 3;
//        if(n==2) return 4;
//        if(m==1) return 4;
//        if(m==2) return 7;
//        if(m>=3) return 8;
//        return 8;


//    n = min(n, 3);
//    return min(1<<n, 1+m*n);




//Runtime: 88 ms, faster than 6.35% of C++ online submissions for Bulb Switcher II.
//Memory Usage: 15.2 MB, less than 6.35% of C++ online submissions for Bulb Switcher II.
    int lt0672b(int n, int m)
    {
        n = (n - 1) % 12 + 1;
        unordered_set<string> set2;
        string s;
        for (int i = 0; i < n; ++i)
        {
            s += "1";
        }
        set2.insert(s);
        while (!set2.empty() && m-- > 0)
        {
            unordered_set<string> set3;

            for (unordered_set<string>::iterator it = set2.begin(); it != set2.end(); it++)
            {
                s = *it;
                string s1(s);
                string s2(s);
                string s3(s);
                string s4(s);
                for (int i = 0; i < n; ++i)
                {
                    s1[i] = s1[i] == '1' ? '0' : '1';
                    if (i % 2 == 1)
                        s2[i] = s2[i] == '1' ? '0' : '1';
                    if (i % 2 == 0)
                        s3[i] = s3[i] == '1' ? '0' : '1';
                    if (i % 3 == 0)                 // first is 0.
                        s4[i] = s4[i] == '1' ? '0' : '1';
                }
                set3.insert(s1);
                set3.insert(s2);
                set3.insert(s3);
                set3.insert(s4);
            }

            std::swap(set2, set3);
        }
        #ifdef __test
        for (unordered_set<string>::iterator it = set2.begin(); it != set2.end(); it++)
            cout<<*it<<", ";
        cout<<endl;
        #endif // __test
        return set2.size();
    }


// .... 写得太顺了， 在错误的道路上。。。
// all
// 奇数
// 偶数
// 1 4 7 10 13 16
// 可以操作的次数 应该 和 长度有关。  6n + 1？
// 1:on  0:off
    int lt0672a(int n, int m)
    {
        n = (n - 1) % 12 + 1;
        unordered_set<string> set2;
        queue<string> que1;
        string s;
        for (int i = 0; i < n; ++i)
            s += "1";
        set2.insert(s);
        que1.push(s);
        while (!que1.empty() && m-- > 0)
        {
            int sz1 = que1.size();
            while (sz1-- > 0)
            {
                s = que1.front();
                que1.pop();

                string s2(s);
                for (int i = 0; i < n; ++i)
                {
                    s2[i] = s2[i] == '1' ? '0' : '1';
                }
                if (set2.find(s2) == set2.end())
                {
                    set2.insert(s2);
                    que1.push(s2);
                }

                s2 = s;
                for (int i = 0; i < n; i += 2)
                {
                    s2[i] = s2[i] == '1' ? '0' : '1';
                }
                if (set2.find(s2) == set2.end())
                {
                    set2.insert(s2);
                    que1.push(s2);
                }

                s2 = s;
                for (int i = 1; i < n; i += 2)
                {
                    s2[i] = s2[i] == '1' ? '0' : '1';
                }
                if (set2.find(s2) == set2.end())
                {
                    set2.insert(s2);
                    que1.push(s2);
                }

                s2 = s;
                for (int i = 1; i < n; i += 3)
                {
                    s2[i] = s2[i] == '1' ? '0' : '1';
                }
                if (set2.find(s2) == set2.end())
                {
                    set2.insert(s2);
                    que1.push(s2);
                }
            }
        }
        #ifdef __test
        for (unordered_set<string>::iterator it = set2.begin(); it != set2.end(); it++)
            cout<<*it<<", ";
        cout<<endl;
        #endif // __test
        return set2.size();
    }

};

int main()
{
//    int n{1}, m{1};
    int n{2}, m{1};
//    int n{3}, m{1};

    LT0672 lt;

    cout<<lt.lt0672b(n,m);

    return 0;
}
