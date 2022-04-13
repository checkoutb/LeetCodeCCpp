
#include "../header/myheader.h"

class LT2224
{
public:

// D D


//        s1 = current.substr(0,2);
//        s2 = current.substr(3,2);
//        int curr = stoi(s1)*60 + stoi(s2);
//
//        int diff = corr-curr;
//        total += (diff / 60);
//        diff %= 60;

//        vector<int>me={60,15,5,1};
//        for(auto x:me){
//            m+=time/x;
//            time=c%x;
//        }
//        return m;

// 乘法计算出个数，而不是加法。。


//    auto toMin = [](string &s) {
//        return s[0] * 600 + s[1] * 60 + s[3] * 10 + s[4] ;
//    };
//    int d = toMin(correct) - toMin(current);
//    return d / 60 + d % 60 / 15 + d % 15 / 5 + d % 5;

// 。。 current <= correct


//Runtime: 4 ms, faster than 24.25% of C++ online submissions for Minimum Number of Operations to Convert Time.
//Memory Usage: 5.9 MB, less than 58.46% of C++ online submissions for Minimum Number of Operations to Convert Time.
    int lt2224a(string current, string correct)
    {
        int h1 = (current[0] - '0') * 10 + (current[1] - '0');
        int h2 = (correct[0] - '0') * 10 + (correct[1] - '0');
        int m1 = (current[3] - '0') * 10 + (current[4] - '0');
        int m2 = (correct[3] - '0') * 10 + (correct[4] - '0');
        int ans = (h2 - h1 + 24) % 24;
        if (m1 > m2)
        {
            m2 += 60;
            ans--;
        }
        while (m1 + 15 <= m2)
        {
            m1 += 15;
            ans++;
        }
        while (m1 + 5 <= m2)
        {
            m1 += 5;
            ans++;
        }
        while (m1 + 1 <= m2)
        {
            m1++;
            ans++;
        }
        return ans;
    }

};

int main()
{

    LT2224 lt;


    return 0;
}
