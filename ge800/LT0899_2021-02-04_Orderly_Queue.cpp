
#include "../header/myheader.h"

class LT0899
{
public:

// D D

//            for(int i=0;i<S.length()-1;i++){
//                S=S.substr(1)+S[0];
//                mn=min(mn,S);
//            }

//Remind what bubble sort eventually is: swap pairs
// For any String you can move any char to anywhere if you can swap adjacent characters
// .. 知道了，      abc    可以变成 bca - cab    也可以  acb - cba ，   cab 和 cba  后面的 2个char 互换位置了。


//Runtime: 8 ms, faster than 40.34% of C++ online submissions for Orderly Queue.
//Memory Usage: 6.8 MB, less than 82.35% of C++ online submissions for Orderly Queue.
// aaaabcaa  aaabcaaa  aabcaaaa  aacaaaab  aaaaaabc
// aabbbbcca
// aaccbcbba  ccbcbbaaa  cccbbaaab ccbbaaabc ccaaabbcb aaabbcbcc    bbcbccaaa  aaabbbccc
// ccbcbbaaa  cbcbbaaac  ccbbaaacb cbbaaacbc cbaaacbcb caaacbcbb  aaacbcbbc
//      cbcbbcaaa ccbbcaaab cbbcaaabc ccaaabcbb aaabcbbcc  bcbbccaaa cccaaabbb
    string lt0899a(string S, int K)
    {
        if (K > 1)
        {
            std::sort(begin(S), end(S));
            return S;
        }
        string mns = S;
        char mnch = S[0];
        for (int i = 0; i < S.size(); ++i)
            mnch = min(mnch, S[i]);
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == mnch)
            {
                string ss = S.substr(i) + S.substr(0, i);
                mns = min(mns, ss);
            }
        }
        return mns;

//        priority_queue<char> priq;
//        char mn = S[0];
//        for (int i = 0; i < S.size(); ++i)
//            mn = min(mn, S[i]);
//        int st = 0;
//        for (; st < K; ++st)
//            priq.push(S[st]);

    }

};

int main()
{
//    string s = {"cba"};
//    int k = 1;

    string s = {"baaca"};
    int k = 3;

    LT0899 lt;

    cout<<lt.lt0899a(s, k);

    return 0;
}
