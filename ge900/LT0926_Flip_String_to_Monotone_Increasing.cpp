
#include "../header/myheader.h"

class LT0926
{
public:


// D D
//        int cnt=0;
//        int ans=0;
//        for(int i=0;i<s.length();i++){
//            if(s[i]=='1') cnt++;
//            if(s[i]=='0' and cnt>0){
//                ans=min(cnt,ans+1);
//            }
//        }
//        return ans;

//    int minFlipsMonoIncr(const std::string& S, int counter_one  = 0, int counter_flip = 0) {
//        for (auto ch : S) {
//            if (ch == '1') {
//                ++counter_one;
//            } else {
//                ++counter_flip;
//            }
//            counter_flip = std::min(counter_one, counter_flip);
//        }
//        return counter_flip;
//    }

//int minFlipsMonoIncr(string S, int f0 = 0, int f1 = 0) {
//    for (auto c : S) {
//        f0 += c - '0';
//        f1 = min(f0, f1 + 1 - (c - '0'));
//    }
//    return f1;
//}

//Runtime: 20 ms, faster than 30.18% of C++ online submissions for Flip String to Monotone Increasing.
//Memory Usage: 8 MB, less than 39.07% of C++ online submissions for Flip String to Monotone Increasing.
    int lt0926a(string S)
    {
        vector<int> vs(S.size(), 0);
//        vector<int> vs2(S.size(), 0);
        int changeCnt = 0;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == '1')
            {
                changeCnt++;
            }
            vs[i] = changeCnt;
        }
        changeCnt = 0;
        int ans = INT_MAX;
        for (int i = S.size() - 1; i >= 0; i--)
        {
            if (S[i] == '0')
            {
                changeCnt++;
            }
            vs[i] += changeCnt;
            if (vs[i] < ans)
            {
                ans = vs[i];
            }
        }
        return ans - 1;
    }

};

int main()
{

    string s = "010110";

    LT0926 lt;

    cout<<lt.lt0926a(s)<<endl;

    return 0;
}
