
#include "../header/myheader.h"

class LT2549
{
public:

    // D D

    //if (n > 2)
    //    return n - 1;
    //return 1;

    //return max(n-1, 1);


    //Runtime16 ms
    //    Beats
    //    10.75 %
    //    Memory6.5 MB
    //    Beats
    //    17.3 %
    // 6 % 5 == 1
    // 15 % 14  % 7
    // x-1 /1 /2 /3 /4
    // 13 12 6 4 3 2
    int lt2549a(int n)
    {
        if (n <= 2)
        {
            return 1;
        }
        set<int> set2;
        bool chg = true;
        set2.insert(n);
        while (chg)
        {
            vector<int> vi;

            for (int x : set2)
            {
                if (x == 1)
                {
                    ;       // never happen
                }
                else if (x == 2)
                {
                    ;       // cannot find i that 2%i == 1
                }
                else
                {
                    --x;
                    for (int a = 1, mxa = std::sqrt(x); a <= mxa; ++a)
                    {
                        if ((x % a == 0) && set2.find(x / a) == set2.end())
                        {
                            vi.push_back(x / a);
                        }
                    }
                }
            }

            chg = !vi.empty();
            set2.insert(begin(vi), end(vi));
        }
        
        return set2.size();


        //return n == 2 ? 0 : n - 1;        // 但是没有办法获得 1。。。


        //set<int> set2;
        //bool chg = true;
        //set.insert(n);
        //while (chg)
        //{
        //    vector<int> vi;

        //    for (int x : set2)
        //    {
        //        if (x == 1)         // .  1 % any == 1 . and N%(N-1) = 1  so N-1. N-2..
        //        {
        //            if (set2.find(x) == set2.end())
        //                vi.push_back(x);
        //            continue;
        //        }
        //        if (x == 2)
        //            continue;

        //    }

        //    chg = !vi.empty();
        //    set2.insert(begin(vi), end(vi));
        //}

    }

};

int main()
{

    LT2549 lt;

    //int n = 5;
    int n = 3;


    cout << lt.lt2549a(n) << endl;

    return 0;
}
