
#include "../header/myheader.h"

class LT2211
{
public:

// D D


//        while(!s.empty() && s.back()=='R') {
//            s.pop_back();
//        }
//        reverse(s.begin(), s.end());
//        while(!s.empty() && s.back()=='L') {
//            s.pop_back();
//        }
//        int ans=(int)s.size();
//        for(auto &i : s) {
//            ans-=i=='S';
//        }



//Runtime: 67 ms, faster than 75.00% of C++ online submissions for Count Collisions on a Road.
//Memory Usage: 18.6 MB, less than 62.50% of C++ online submissions for Count Collisions on a Road.
// tle :  RRRR...RRRRLLL...LLL
// 只要 前面有 非自己的 自己肯定会撞的。
    int lt2211(string directions)
    {
        bool chg = true;
        int ans = 0;
        int sz1 = directions.size();

        int cntl = 0;
        int cntr = 0;
        for (int i = 0; i < sz1; i++)
        {
            if (directions[i] == 'L')
                cntl++;
            else
                break;
        }
        for (int i = sz1 - 1; i >= 0; --i)
        {
            if (directions[i] == 'R')
                cntr++;
            else
                break;
        }
        directions = directions.substr(cntl, sz1 - cntl - cntr);

        int cnts = count_if(begin(directions), end(directions), [](char ch){ return ch == 'S'; });

        return directions.size() - cnts;



////        cout<<directions<<", "<<sz1<<", "<<cntl<<", "<<cntr<<endl;;
//
//        while (chg)
//        {
//            chg = false;
//            for (int i = 0; i < directions.size(); ++i)
//            {
//                if (directions[i] == 'S')
//                    continue;
//                if (directions[i] == 'L')       // <<<
//                {
//                    if (i > 0 && directions[i - 1] != 'L')
//                    {
//                        directions[i] = 'S';
//                        ans++;
//                        chg = true;
//                        while ((i + 1) < sz1 && directions[i + 1] == 'L')
//                        {
//                            i++;
//                            directions[i] = 'S';
//                            ans++;
//                        }
//                    }
//                }
//                else
//                {
//                    if ((i + 1) < sz1 && directions[i + 1] != 'R')
//                    {
//                        directions[i] = 'S';
//                        ans++;
//                        chg = true;
////                        while ((i + 1) < sz1 && )
//                    }
//                }
//            }
//        }
//        return ans;
    }

};

int main()
{

    LT2211 lt;

//    string s = "RLRSLL";
//    string s = "LLRR";
    string s = "RSLL";

    cout<<lt.lt2211(s)<<endl;

    return 0;
}
