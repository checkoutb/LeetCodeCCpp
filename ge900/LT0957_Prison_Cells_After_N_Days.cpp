
#include "../header/myheader.h"

class LT0957
{
public:

// D D
//int numDays = (N % 14 == 0) ? 14 : N % 14;
//vector<int> cellsAfterNDays(8,0);

// 8个位，一共2^8次方，所以%(2^8) 是必然可以的。





//Runtime: 16 ms, faster than 17.77% of C++ online submissions for Prison Cells After N Days.
//Memory Usage: 12.4 MB, less than 43.01% of C++ online submissions for Prison Cells After N Days.
    vector<int> lt0957b(vector<int> cells, int N)
    {
        unordered_map<int, int> map2;
        while (N-- > 0)
        {
            int a = changeb1(cells);
            if (map2[a])
            {
                int n2 = map2[a];
                map2[a] = N;
                n2 -= N;
                N = N % n2;
            }
            else
            {
                map2[a] = N;
            }
        }
        return cells;
    }

    int changeb1(vector<int>& c)
    {
        int c0 = 0;
        int c1 = (c[0] == c[2]);
        int c2 = c[1] == c[3];
        int c3 = c[2] == c[4];
        int c4 = c[3] == c[5];
        int c5 = c[4] == c[6];
        int c6 = c[5] == c[7];
        int c7 = 0;
        c[0] = c0;
        c[1] = c1;
        c[2] = c2;
        c[3] = c3;
        c[4] = c4;
        c[5] = c5;
        c[6] = c6;
        c[7] = c7;
        return c0*1E7 + c1*1E6 + c2*1E5 + c3*1E4 + c4*1e3 + c5*1e2 + c6*1e1 + c7;
    }

    vector<int> lt0957a(vector<int> cells, int N)
    {
        while (N-- > 0)
        {
            changea1(cells);

            #ifdef __test
            for_each(begin(cells), end(cells), fun_cout);
            cout<<endl;
            #endif // __test

        }
        return cells;
    }

    void changea1(vector<int>& c)
    {
        int c0 = 0;
        int c1 = (c[0] == c[2]);
        int c2 = c[1] == c[3];
        int c3 = c[2] == c[4];
        int c4 = c[3] == c[5];
        int c5 = c[4] == c[6];
        int c6 = c[5] == c[7];
        int c7 = 0;
        c[0] = c0;
        c[1] = c1;
        c[2] = c2;
        c[3] = c3;
        c[4] = c4;
        c[5] = c5;
        c[6] = c6;
        c[7] = c7;
    }
};

int main()
{

//    vector<int> v = {0,1,0,1,1,0,0,1};
//    int n = 7;

    vector<int> v = {1,0,0,1,0,0,1,0};
    int n = 1000000000;

    LT0957 lt;

//    for (; n < 30; n++)
//    {
        vector<int> v2 = lt.lt0957b(v, n);
        for_each(v2.begin(), v2.end(), fun_cout);
        cout<<endl;
//    }
    return 0;
}
