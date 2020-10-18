
#include "../header/myheader.h"

class LT1041
{
public:

// D D

// 一遍： return state != 0 || (x == 0 && y == 0);

// 一遍后，0，0，肯定是在范围内的。

// 如果面向不同，则 4次后，回到 原地。 而且 每一遍的 起始点和终止点，组成的线段， 4遍后 会是一个 正方形。 因为 起始的面向 发生了 90度。。。嗯，可能180度。。。所以4遍后，可能线段，可能正方形。


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Robot Bounded In Circle.
//Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Robot Bounded In Circle.
    bool lt1041b(string instructions)
    {
        instructions = (instructions+instructions+instructions+instructions);
        int x{0},y{0},f{0};
        int go[][2] = {{0,1},{1,0},{0,-1},{-1,0}};

        for (int i = 0; i < instructions.size(); i++)
        {
            switch(instructions[i])
            {
            case 'G':
                x += go[f][0];
                y += go[f][1];
                break;
            case 'L':
                f = (f - 1 + 4) % 4;
                break;
            case 'R':
                f = (f + 1) % 4;
                break;
            }
        }
        return x==0 && y==0;
    }


// error, 螺旋上升
// 感觉 instructions * 4， 没有重复点的话 就应该是无限的。
    bool lt1041a(string instructions)
    {
        instructions = (instructions+instructions+instructions+instructions);
        unordered_set<int> set2;
        set2.insert(0);
        int x{0},y{0},f{0};
        int go[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int t = 0;
        for (int i = 0; i < instructions.size(); i++)
        {
            switch(instructions[i])
            {
            case 'G':
                x += go[f][0];
                y += go[f][1];
                break;
            case 'L':
                f = (f - 1 + 4) % 4;
                break;
            case 'R':
                f = (f + 1) % 4;
                break;
            }
            t = f * 100000000 + x * 10000 + y;
            if (set2.find(t) != set2.end())
                return true;
            set2.insert(t);
        }
        return false;
    }

};

int main()
{

    string arr[4] = {
    "GGLLGG","GG",
    "GL","GLGLGGLGL"};

    LT1041 lt;

    for (string s : arr)
    {
        cout<<lt.lt1041b(s)<<endl;
    }

    return 0;
}
