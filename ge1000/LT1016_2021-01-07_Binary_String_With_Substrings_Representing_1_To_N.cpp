
#include "../header/myheader.h"

class LT1016
{
public:

// D D

//    string binary(int x){
//        string ans;
//        while(x){
//            ans += to_string(x&1);
//            x >>= 1;
//        }
//        reverse(ans.begin(), ans.end());
//        return ans;
//    }
//
//    bool queryString(string S, int N) {
//        for(int i=N/2; i<=N; i++){
//            if (S.find(binary(i))==string::npos) return false;
//        }
//        return true;
//    }
//int i=N/2; i<=N; i++
// N/2,,


//        for (int i = N; i > N / 2;  --i) {
//            string b = bitset<32>(i).to_string();
//            if (S.find(b.substr(b.find("1"))) == string::npos)
//                return false;
//        }
//        return true;


//  while (N > 0) {
//    auto s = bitset<32>(N--).to_string();
//    if (S.find(s.substr(s.find("1"))) == string::npos) return false;
//  }
//  return true;



// 1
// 10 11
// 100 101 110 111
// 1000 1001 1010 1011 1100 1101 1110 1111
// 竟然没有tle。。感觉还是 暴力枚举的样子。。
//Runtime: 4 ms, faster than 53.67% of C++ online submissions for Binary String With Substrings Representing 1 To N.
//Memory Usage: 6.6 MB, less than 64.68% of C++ online submissions for Binary String With Substrings Representing 1 To N.
// 包含 110011  的时候 必然 包含 1100，
// 怎么找到 110011
// 1 11 111 1111 11111
// 1 10 101 1011 10111          // 有111
// 1 10 100 1000 10000
// dfs 加0 或加1， 是否小于N， 是否存在。  还是枚举啊。
    bool lt1016a(string S, int N)
    {
        return dfsa1(S, N, "1", 1);
    }
    bool dfsa1(string& S, int N, string str, int val)
    {
        bool ans = true;
        if ((val * 2) > N && (val * 2 + 1) > N)
            return S.find(str) != string::npos;

        if (val * 2 <= N)
            if (!dfsa1(S, N, str + "0", val * 2))
                return false;

        if ((val * 2 + 1) <= N)
            if (!dfsa1(S, N, str + "1", val * 2 + 1))
                return false;
        return true;
//        if (val > N)
//            return true;
//        bool b0 = dfsa1(S, N, str + "0", val * 2);
//        bool b1 = dfsa1(S, N, str + "1", val * 2 + 1);
//        if (b0 && b1)
//            return false;

    }

};

int main()
{
    string s = "0110";
    int n{4};

    LT1016 lt;

    cout<<lt.lt1016a(s, n);

    return 0;
}
