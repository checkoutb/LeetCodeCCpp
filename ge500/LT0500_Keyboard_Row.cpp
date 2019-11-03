
#include "../header/myheader.h"

class LT0500
{
//    set<char> line1 = {};
    set<char> line2 = {'q','w','e','r','t','y','u','i','o','p'};
    set<char> line3 = {'a','s','d','f','g','h','j','k','l'};
    set<char> line4 = {'z','x','c','v','b','n','m'};
public:
    // Qq算什么，毕竟要shift啊。。
    // buzhidao, 估计是一行的，毕竟通过了。

//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Keyboard Row.
//Memory Usage: 8.5 MB, less than 57.14% of C++ online submissions for Keyboard Row.

// 才发现这里只有小写
// 看了discuss的正则，alphabet没有数字。。。。

// 用第一个字符为这个string定性，然后lineX.contains()。。不存在就下一个string。

// discuss是：
// map保存char - 行数。首个char获得行数，然后后续的char只要行数不相等，就break。
// details只能看到一个，也是这样的。


    vector<string> lt0500a(vector<string>& words)
    {
        vector<string> ans;
        set<int> set2;
        for (string w : words)
        {
            set2.clear();
            for (char c : w)
            {
                if (c >= '0' && c <= '9')
                {
                    set2.insert(1);
                }
                if (line2.find(c) != line2.end())
                {
                    set2.insert(2);
                }
                if (line3.find(c) != line3.end())
                {
                    set2.insert(4);
                }
                if (line4.find(c) != line4.end())
                {
                    set2.insert(8);
                }
                if (set2.size() > 1)
                {
                    break;
                }
            }
            if (set2.size() == 1)
            {
                ans.push_back(w);
            }
        }
        return ans;
    }
};

int main()
{
    vector<string> v = {"Hello", "Alaska", "Dad", "Peace"};

    LT0500 lt;
    vector<string> v2 = lt.lt0500a(v);

    cout<<endl<<endl;
    for_each(v2.begin(), v2.end(), fun_cout_s);
    cout<<endl;
    return 0;
}
