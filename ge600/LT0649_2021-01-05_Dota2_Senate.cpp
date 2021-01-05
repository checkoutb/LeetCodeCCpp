
#include "../header/myheader.h"

class LT0649
{
public:

// D D


//        queue<int> r, d;
//        for (int i = 0; i < senate.size(); i++)
//            (senate[i] == 'R') ? r.push(i) : d.push(i);
//        while (!r.empty() && !d.empty()) {
//            int x = r.front(); r.pop();
//            int y = d.front(); d.pop();
//            (x < y) ? r.push(x + n) : d.push(y + n);              // + n, 就是 下一轮
//        }
//        return r.size() > d.size() ? "Radiant" : "Dire";



//        while ( true )
//        {
//            char sen = senate[it];
//            //std::cout << remainD << remainR << bannedD << bannedR << std::endl;
//            if (!remainD )
//                return "Radiant";
//            if (!remainR)
//                return "Dire";
//            if ( sen == 'R' )
//                if ( bannedR == 0 )
//                {
//                    bannedD++;
//                    remainD--;
//                    senate += 'R';                // . R 活到了 下一轮。
//                }
//                else
//                    bannedR--;
//            if ( sen == 'D' )
//                if ( bannedD == 0 )
//                {
//                    bannedR++;
//                    remainR--;
//                    senate += 'D';
//                }
//                else
//                    bannedD--;
//            it++;
//        }



//Runtime: 216 ms, faster than 12.33% of C++ online submissions for Dota2 Senate.
//Memory Usage: 6.8 MB, less than 100.00% of C++ online submissions for Dota2 Senate.
    string lt0649a(string senate)
    {
        int sz1 = senate.size();
        bool isR = false;
        char emp = '-';
        while (true)
        {
            for (int i = 0; i < sz1; ++i)
            {
                if (senate[i] == 'R')
                {
                    for (int j = 1; j < sz1; ++j)
                    {
                        if (senate[(i + j) % sz1] == 'D')
                        {
                            senate[(i + j) % sz1] = emp;
                            goto BBB;
                        }
                    }
                    isR = true;
                    goto AAA;

                    BBB:
                    continue;
                }
                else if (senate[i] == 'D')
                {
                    for (int j = 1; j < sz1; ++j)
                    {
                        if (senate[(i + j) % sz1] == 'R')
                        {
                            senate[(i + j) % sz1] = emp;
                            goto CCC;
                        }
                    }
                    isR = false;
                    goto AAA;

                    CCC:
                    continue;
                }
            }
        }
        AAA:
        return isR ? "Radiant" : "Dire";
    }

};

int main()
{
    string s = "RDD";

    LT0649 lt;

    cout<<lt.lt0649a(s);

    return 0;
}
