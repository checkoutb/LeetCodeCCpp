
#include "../header/myheader.h"

class LT1461
{
public:

    // D D

    //bool data[target];
    //memset(data, 0, sizeof(data));

    //return len({ s[i:i + k] for i in xrange(len(s) - k + 1) }) == 2 * *k

    //return len(findall(r"0+1|1+0", s)) >= k


    //Set<String> seen = new HashSet<>();
    //for (int i = k; i <= s.length() && seen.size() < 1 << k; ++i) {
    //    seen.add(s.substring(i - k, i));
    //}
    //return seen.size() == 1 << k;


    //It can be packed optimally with a de Bruijn sequence(which can be generated with an Euler Tour).
    //we can write if ((1 << k) > s.size()) return false;


//Runtime: 68 ms, faster than 91.51 % of C++ online submissions for Check If a String Contains All Binary Codes of Size K.
//Memory Usage : 18.8 MB, less than 92.77 % of C++ online submissions for Check If a String Contains All Binary Codes of Size K.
    // daily challenge
    // 2^20 ~= 1000000 .. bit
// If the size of the bitset is not known at compile time, std::vector<bool> or boost::dynamic_bitset<> may be used. 
    bool lt1461a(string s, int k)
    {
        if (s.size() < k * 2)
            return false;
        vector<bool> vb(1 << k);
        int num = 0;
        int t2 = 1 << k;
        for (int i = 0; i < k - 1; ++i)
        {
            num <<= 1;
            num += (s[i] - '0');
        }
        for (int i = k - 1; i < s.size(); ++i)
        {
            num <<= 1;
            num += (s[i] - '0');
            num %= t2;
            vb[num] = true;
        }
        for (bool b : vb)
        {
            if (!b)
                return false;
        }
        return true;

        //int t2 = 1 << k;
        //bitset<> bs(t2);
        //int num = 0;
        //for (int i = 0; i < k - 1; ++i)
        //{
        //    num <<= 1;
        //    num += (s[i] - '0');
        //}
        //for (int i = k - 1; i < s.size(); ++i)
        //{
        //    num <<= 1;
        //    num += (s[i] - '0');
        //    bs.set(1 << num);
        //}
        //return bs.all();
    }

};

int main()
{

    LT1461 lt;

    string s = "0011";
    int k = 2;

    cout << lt.lt1461a(s, k) << endl;

    return 0;
}
