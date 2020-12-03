
#include "../header/myheader.h"

class LT1529
{
public:

// D D

//        for(char x : target){
//            if(num_flip % 2 ^ (x - '0')) num_flip++;
//        }


//        for (char c : target.toCharArray()) {
//            if (c != prev) {
//                prev = c;
//                res++;
//            }
//        }



//Runtime: 16 ms, faster than 86.66% of C++ online submissions for Bulb Switcher IV.
//Memory Usage: 9.8 MB, less than 42.54% of C++ online submissions for Bulb Switcher IV.
// 几个 01 或 10 。。。 + s[0] == '1'
    int lt1529a(string target)
    {
        bool is0 = true;
        int ans = 0;
        for (int i = 0; i < target.size(); ++i)
        {
            if (target[i] == '0')
            {
                if (!is0)
                {
                    is0 = !is0;
                    ans++;
                }
            }
            else
            {
                if (is0)
                {
                    is0 = !is0;
                    ans++;
                }
            }
        }
        return ans;
    }

};

int main()
{

    vector<string> vs = {"10111","101","00000","001011101"};

    LT1529 lt;

    for (string& s : vs)
        cout<<lt.lt1529a(s)<<endl;

    return 0;
}
