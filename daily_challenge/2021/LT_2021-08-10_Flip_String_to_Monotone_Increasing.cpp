
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        int count0 = 0, count1 = 0;
//        for(int i = 0; i < s.size(); i++){
//            count0 += (s[i]=='1');
//            count1 = min(count0, count1+(s[i]=='0'));
//        }
//        return count1;


//        for(int i = 1; i < s.size(); i++) {
//            prefixOnes[i] = prefixOnes[i - 1] + (s[i] - '0');
//            dp[i] = min(prefixOnes[i - 1], dp[i - 1]) + ((s[i] - '0') == 1 ? 0 : 1);
//        }


//        for (auto ch : S) {
//            if (ch == '1') {
//                ++counter_one;
//            } else {
//                ++counter_flip;
//            }
//            counter_flip = std::min(counter_one, counter_flip);
//        }
//        return counter_flip;
//




// AC
    int lta(string s)
    {
        int sz1 = s.size();
        vector<int> vi(sz1);
        int cnt1 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            cnt1 += (s[i] == '1' ? 1 : 0);
            vi[i] = cnt1;
        }
        int ans = sz1;
        int cnt0 = 0;
        for (int i = sz1 - 1; i >= 0; --i)
        {
            cnt0 += (s[i] == '0' ? 1 : 0);          // bool -> int...
            ans = min(ans, vi[i] + cnt0);
        }
        return ans - 1;
    }

};

int main()
{
//    string s = "00110";
//    string s = "010110";
    string s = "00011000";

    LT lt;

    cout<<lt.lta(s)<<endl;

    return 0;
}
