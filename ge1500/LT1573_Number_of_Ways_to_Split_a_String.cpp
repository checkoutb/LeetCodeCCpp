
#include "../header/myheader.h"

class LT1573
{
public:

// D D

//        if (cntOnes % 3 != 0) return 0;
//        if (cntOnes == 0) return (int) ((n - 1) * (n - 2) / 2 % mod); // combinations, select 2 slots from n - 1 slots;
//        long firstZeros = 0, secondZeros = 0, avg = cntOnes / 3, prefixOnes = 0;
//        for (int i = 0; i < n; i++) {
//            char c = s.charAt(i);
//            if (c == '1') prefixOnes++;
//            else {
//                if (prefixOnes == avg) firstZeros++; // btwn s1 and s2;
//                else if (prefixOnes == avg * 2) secondZeros++; // btwn s3 and s2;
//            }
//        }
//        return (int) (++firstZeros * ++secondZeros % mod);  // two 0s form 3 slots



// 最后4行...
//Runtime: 44 ms, faster than 65.85% of C++ online submissions for Number of Ways to Split a String.
//Memory Usage: 14.1 MB, less than 97.12% of C++ online submissions for Number of Ways to Split a String.
    int lt1573a(string s)
    {
        int cnt1 = 0;
        for (char& ch : s)
            if (ch == '1')
                cnt1++;
        if (cnt1 % 3 != 0)
            return 0;

        cnt1 /= 3;
        int i = 0;
        int cnt = 0;
        for (; i < s.size(); ++i)
        {
            if (s[i] == '1')
            {
                cnt++;
            }
            if (cnt == cnt1)
                break;
        }
        int t1 = i;         // last 1 of s1
        for (++i; i < s.size(); ++i)
        {
            if (s[i] == '1')
                break;
        }
        int t2 = i;         // first 1 of s2
        cnt = 0;
        for (; i < s.size(); ++i)
        {
            if (s[i] == '1')
            {
                cnt++;
                if (cnt == cnt1)
                    break;
            }
        }
        int t3 = i;         // last 1 of s2;
        for (++i; i < s.size(); ++i)
        {
            if (s[i] == '1')
                break;
        }
        int t4 = i;         // first 1 of s3
//        int mod = 1E9 + 7;
//        cout<<"        "<<t1<<", "<<t2<<" ; "<<t3<<", "<<t4<<endl;
        long ans = (long) (t2 - t1) * (t4 - t3) % (int)(1E9 + 7);
        if (cnt1 == 0)
            ans = (long) (1 + (int) (s.size()) - 2) * ((int) (s.size()) - 2) / 2 % (int) (1E9 + 7);
        return ans;
    }

};

int main()
{

    vector<string> vs = {"10101", "1001", "00000", "100100010100110"};

    LT1573 lt;

    for (string& s : vs)
        cout<<lt.lt1573a(s)<<endl;

    return 0;
}
