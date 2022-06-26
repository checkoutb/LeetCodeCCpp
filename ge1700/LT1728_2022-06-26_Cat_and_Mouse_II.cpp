
#include "../header/myheader.h"

class LT1728
{
public:






    // gg



    // ����ֻ����ʳ�������ߣ�������Ļ�������1000�����֡�
    // ����Ĳ��� �� è��2��(+1)�� ���� û�ã���Ҫ�����룬 è����ʳ����ڵĻ��� ֻҪ�����޷�һ����������䡣
    // è�� �������󣬻��� ʳ� ����йؿڡ������� �����������è��
    // �������Բ���ת��
    // Example 3 ��������1000�� ���� è��һ��������Ҳֻ����һ���� ����è�ȵ�ʳ�
    // ���� ��������ʳ������ܽ��� è�ķ�Χ�� èҲ����ʳ�
    // èץ����ֻ�е� è�Ĳ����ܴ�������ʱ�����л���ġ� ���� ������Ҫ�ﵽʳ�����Ӯ����ôèҲֱ��ȥʳ������Ϳ�����
    //          ����Ҫȥץ���󡣡����Ƿ���Ҫ�� ��Ҫ�ġ� ���磬è����1�����󲽷�2������ ���� Example 3. ���è��ʳ���ߣ���������������һ����ʱ��͵��
    // <= 8  64��λ�ã� ����64*è64��4096
    // �о��ǣ����� ��ʳ���ߣ�ÿ������࣬�ҽ����� è�ߵ�ʱ�򣬲��ᱻè�Ե����� è�����󲻶���èҲ������ �����ˣ� è����ʳ�������ߡ������п����ǣ�è�����ߵ�ĳ���ط���Ȼ�����󶯲��ˡ�
    // һ��byte 8 bit�� long long 8 byte ... ����ֱ�� x*10 + y ...
    bool lt1728a(vector<string>& grid, int catJump, int mouseJump)
    {
        //unordered_map<int, bool> map2;          // (x*10+y)*100 + x*10+y �� can mouse win?

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
        //mapm[t2] = b2;              // ���� dfs �У��ֻص������״̬��˵�� û���á��������ȷ�һ�� false��

        int b2 = 0;
        mapm[t2] = 0;

        bool barr[4] = { true, true, true, true };
        int arr[5] = { 1,0,-1,0,1 };

        for (int a = 1; a <= mj; ++a)       // mouse������һ����
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


    // bool, pending ������false�� ���� cat ��Ҫȫ������ true ���еġ� ���� �� pending ����ǰ���ʵ��Ļ�������false��
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
        //bool b2 = true;             // cat �Ŀ����У� mouse ����ȫӮ������Ӯ��

        mapc[t2] = 0;
        int b2 = 0;

        bool barr[4] = { true, true, true, true };
        int arr[5] = { 1,0,-1,0,1 };


        if (dfsa1(grid, xm, ym, xc, yc, mapm, mapc, cj, mj) == -1)        // è���Բ�����
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
