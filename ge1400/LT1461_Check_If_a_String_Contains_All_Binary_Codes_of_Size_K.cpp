
#include "../header/myheader.h"

class LT1461
{
public:


// D
// 还是暴力，不过 是对 s 暴力求解 长度为k的substr ， 有多少个 int。


//https://leetcode.com/submissions/detail/423933477/


//class Solution {
//public:
//    using Queue = deque<char>;
//    using Set = unordered_set<string>;
//    bool hasAllCodes(string S, int K, Queue q = {}, Set all = {}) {
//        for (auto c: S) {
//            q.push_back(c);
//            if (q.size() == K) all.insert({ q.begin(), q.end() }), q.pop_front();
//        }
//        return all.size() == 1 << K;
//    }
//};
// using ...


// tle.
//        int N = 1 << K;
//        for (auto i{ 0 }; i < N; ++i) {
//            auto t = bitset<32>(i).to_string();
//            t = t.substr(t.size() - K);
//            if (S.find(t) == string::npos)
//                return false;
//        }
//        return true;


// 记得之前也有类似的。。好像很简单。。。但。。。。 k=20，暴力肯定tle。
// 有10，必然就有1了，  所以 只需要校验 某几个。。但是 哪几个。。
// 110， 包含了 1， 10， 11， 不，如果 1011，也是包含全部的。
// 110100
    bool lt1461a(string s, int k)
    {

    }

};

int main()
{

    LT1461 lt;


    return 0;
}
