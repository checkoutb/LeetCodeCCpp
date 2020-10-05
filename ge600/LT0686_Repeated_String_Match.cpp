
#include "../header/myheader.h"

class LT0686
{
public:


// D D

//    for (auto i = 0, j = 0; i < A.size(); ++i) {
//        for (j = 0; j < B.size() && A[(i + j) % A.size()] == B[j]; ++j);
//        if (j == B.size())
//            return (i + j - 1) / A.size() + 1;
//    }
// 每次 a移动一个位置，来 和b的开头 匹配。


//    vector<int> prefTable(b.size() + 1); // 1-based to avoid extra checks.
//    for (auto sp = 1, pp = 0; sp < b.size(); )
//      if (b[pp] == b[sp])
//          prefTable[++sp] = ++pp;
//      else if
//          (pp == 0) prefTable[++sp] = pp;
//      else
//          pp = prefTable[pp];
//    for (auto i = 0, j = 0; i < a.size(); i += max(1, j - prefTable[j]), j = prefTable[j]) {
//        while (j < b.size() && a[(i + j) % a.size()] == b[j]) ++j;
//        if (j == b.size())
//            return (i + j - 1) / a.size() + 1;
//    }
// kmp。。。。。。。




//Runtime: 8 ms, faster than 89.15% of C++ online submissions for Repeated String Match.
//Memory Usage: 7.1 MB, less than 30.68% of C++ online submissions for Repeated String Match.
    int lt0686a(string a, string b)
    {
//        if (b.find(a) == std::string::npos)           // aa , a
//            return -1;
        string s;
        int ans = 0;
        while (s.size() < b.size())
        {
            s += a;
            ans++;
        }
        if (s.find(b) == std::string::npos)
        {
            s += a;
            ans++;
        }
        else
        {
            return ans;
        }
        if (s.find(b) == std::string::npos)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }

};

int main()
{

//    string a{"a"}, b{"aa"};
    string a{"aa"}, b{"a"};

    LT0686 lt;

    cout<<lt.lt0686a(a,b)<<endl;

    return 0;
}
