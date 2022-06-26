
#include "../header/myheader.h"

class LT1728
{
public:






    // gg



    // 老鼠只能往食物那里走，反方向的话，迟早1000步出局。
    // 老鼠的步伐 是 猫的2倍(+1)， 。。 没用，还要看距离， 猫就在食物隔壁的话， 只要老鼠无法一步到达，都是输。
    // 猫是 走向老鼠，还是 食物？ 如果有关口。。不， 老鼠可以跳过猫。
    // 跳，所以不能转向。
    // Example 3 不动，等1000； 或者 猫走一步，老鼠也只能走一步， 所以猫先到食物。
    // 就是 老鼠走向食物，但不能进入 猫的范围。 猫也走向食物。
    // 猫抓老鼠，只有当 猫的步伐能大于老鼠时，才有机会的。 而且 老鼠需要达到食物才算赢，那么猫也直接去食物那里就可以了
    //          不需要去抓老鼠。。。是否需要？ 需要的。 比如，猫步伐1，老鼠步伐2，。。 就是 Example 3. 如果猫往食物走，则老鼠可以在最后一步的时候偷掉
    // <= 8  64个位置， 老鼠64*猫64，4096
    // 感觉是，老鼠 向食物走，每次走最多，且接下来 猫走的时候，不会被猫吃掉。。 猫，老鼠不动，猫也不动。 老鼠动了， 猫就往食物那里走。不，有可能是，猫可以走到某个地方，然后老鼠动不了。
    // 一个byte 8 bit， long long 8 byte ... 不，直接 x*10 + y ...
    bool lt1728a(vector<string>& grid, int catJump, int mouseJump)
    {
        //unordered_map<int, bool> map2;          // (x*10+y)*100 + x*10+y ， can mouse win?

        unordered_map<int, int> mapm;
        unordered_map<int, int> mapc;
        int xm = 0, ym = 0, xc = 0, yc = 0;
        
        for (int i = 0; i < grid.size(); ++i)
        {
            string& s = grid[i];
            for (int j = 0; j < s.size(); ++j)
            {
                if (s[j] == 'C')
                {
                    xc = i, yc = j;
                }
                else if (s[j] == 'M')
                    xm = i, ym = j;
            }
        }

        return dfsa1(grid, xm, ym, xc, yc, mapm, mapc, catJump, mouseJump);
    }

    // mouse turn
    int dfsa1(vector<string>& grid, int xm, int ym, int xc, int yc, unordered_map<int, int>& mapm, unordered_map<int, int>& mapc, int cj, int mj)
    {
        // check cat
        //if (xc < 0 || yc < 0 || xc >= grid.size() || yc >= grid[0].size())
        //    return false;
        if (grid[xc][yc] == 'F')
            return -1;

        int t2 = (xm * 10 + ym) * 100 + xc * 10 + yc;
        if (mapm.find(t2) != mapm.end())
        {
#ifdef __test
            cout << "mouse memo " << t2 << ", " << mapm[t2] << endl;
#endif
            return mapm[t2];
        }

        //bool b2 = false;
        //mapm[t2] = b2;              // 本次 dfs 中，又回到了这个状态，说明 没有用。。所以先放一个 false。

        int b2 = 0;
        mapm[t2] = 0;

        bool barr[4] = { true, true, true, true };
        int arr[5] = { 1,0,-1,0,1 };

        for (int a = 1; a <= mj; ++a)       // mouse必须走一步。
        {
            for (int i = 0; i < 4; ++i)
            {
                if (barr[i])
                {
                    int x2 = xm + a * arr[i];
                    int y2 = ym + a * (arr[i + 1]);
                    if (x2 < 0 || y2 < 0 || x2 >= grid.size() || y2 >= grid[0].size() || grid[x2][y2] == '#')
                    {
                        barr[i] = false;
                    }
                    else
                    {
                        int t3 = dfsa2(grid, x2, y2, xc, yc, mapm, mapc, cj, mj);
                        if (t3 == 1)
                        {
                            b2 = 1;
                            goto AAA;
                        }
                    }
                }
            }
        }
        AAA:
        mapm[t2] = b2;

#ifdef __test
        cout << "mmmm : " << t2 << ", " << b2 << endl;
        if (t2 == 2412)
        {
            cout << "  ?????         ?     ?          ?  ????????? " << endl << endl;
        }
#endif

        return b2;
    }


    // bool, pending 当作了false， 但是 cat 需要全部都是 true 都行的。 导致 在 pending 结束前访问到的话，会变成false。
    // -1 : false, 0: pending, 1: true

    // cat turn
    int dfsa2(vector<string>& grid, int xm, int ym, int xc, int yc, unordered_map<int, int>& mapm, unordered_map<int, int>& mapc, int cj, int mj)
    {
        int t2 = (xm * 10 + ym) * 100 + xc * 10 + yc;
#ifdef __test
        cout << "cat -- start: " << t2 << endl;
        if (t2 == 2412)
        {
            cout << endl << "=================================" << endl << endl;
        }
#endif

        // check mouse
        if (grid[xm][ym] == 'F')        // mouse win
        {
#ifdef __test
            cout << "...." << endl;
#endif
            return 1;
        }

        // cat catch mouse
        if ((xm == xc && (abs(ym - yc) <= cj)) || (ym == yc && (abs(xm - xc) <= cj)))
        {
#ifdef __test
            cout << "catch.. " << endl;
#endif
            return -1;
        }
        
        if (mapc.find(t2) != mapc.end())
        {
#ifdef __test
            cout << " memo  " << endl;
#endif
            return mapc[t2];
        }

        //mapc[t2] = false;
        //bool b2 = true;             // cat 的可能中， mouse 必须全赢，才是赢。

        mapc[t2] = 0;
        int b2 = 0;

        bool barr[4] = { true, true, true, true };
        int arr[5] = { 1,0,-1,0,1 };


        if (dfsa1(grid, xm, ym, xc, yc, mapm, mapc, cj, mj) == -1)        // 猫可以不动。
        {
#ifdef __test
            cout << "    cat false111" << endl;
#endif
            //b2 = false;
            b2 = -1;
            goto AAA;
        }

        for (int a = 1; a <= cj; ++a)
        {
            for (int i = 0; i < 4; ++i)
            {
                if (barr[i])
                {
                    int x2 = xc + a * arr[i];
                    int y2 = yc + a * (arr[i + 1]);
                    if (x2 < 0 || y2 < 0 || x2 >= grid.size() || y2 >= grid[0].size() || grid[x2][y2] == '#')
                    {
                        barr[i] = false;
                    }
                    else
                    {
                        int t3 = dfsa1(grid, xm, ym, x2, y2, mapm, mapc, cj, mj);
                        if (t3 == -1)
                        {
#ifdef __test
                            cout << "  cat false222 " << endl;
#endif
                            //b2 = false;
                            b2 = -1;
                            goto AAA;
                        }
                    }
                }
            }
        }
        AAA:
        mapc[t2] = b2;
#ifdef __test
        cout << "cccc  ----   " << t2 << ", " << b2 << endl;
        if (t2 == 2412)
        {
            cout << "-----------------------------" << endl;
        }
#endif
        return b2;
    }

};

int main()
{

    LT1728 lt;

    vector<string> vs = { "####F","#C...","M...." };
    int cj = 1, mj = 2;

    //vector<string> vs = { "M.C...F" };
    //int cj = 1, mj = 4;

    //vector<string> vs = { "M.C...F" };
    //int cj = 1, mj = 3;


    //// false
    //vector<string> vs = { "#..C...", "M....#.", "######.", "######.", "######.", "######F" };
    //int cj = 1, mj = 5;



    cout << lt.lt1728a(vs, cj, mj) << endl;

    return 0;
}
