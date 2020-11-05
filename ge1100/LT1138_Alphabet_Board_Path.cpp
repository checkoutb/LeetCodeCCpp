
#include "../header/myheader.h"

class LT1138
{
public:


// D D

//  string res;
//  for (auto ch : target) {
//    int x1 = (ch - 'a') % 5, y1 = (ch - 'a') / 5;
//    res += string(max(0, y - y1), 'U') + string(max(0, x1 - x), 'R') +
//      string(max(0, x - x1), 'L') + string(max(0, y1 - y), 'D') + "!";
//    x = x1, y = y1;
//  }
//  return res;

// ... string's constructor
// 优先U， 这样就能从 Z 出来。  任何字符到Z 都不可能有 U 操作的。
// 任何字符到Z 都不可能有R操作。
// L，这样就 能到 Z 中去， 而不会越界。


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Alphabet Board Path.
//Memory Usage: 6.5 MB, less than 8.64% of C++ online submissions for Alphabet Board Path.
//a b c d e
//f g h i j
//k l m n o
//p q r s t
//u v w x y
//z
// (%5 /5)
    string lt1138a(string target)
    {
        int x{0}, y{0};
        string ans;
        bool lastZ = false;

        for (char ch : target)
        {
            int tx = (ch - 'a') % 5;
            int ty = (ch - 'a') / 5;
            int dx = x - tx;
            int dy = y - ty;

            // z...
            if (ch == 'z')
            {
                if (!lastZ)
                {
                    while (dx-- > 0)
                    {
                        ans += 'L';
                    }
                    dx++;           // to be 0.
                }
            }
            else
            {
                if (lastZ)
                {
                    dy--;
                    ans += 'U';
                }
            }

            if (dy > 0)
            {
                while (dy-- > 0)
                {
                    ans += 'U';
                }
            }
            else
            {
                if (dy < 0)
                {
                    while (dy++ < 0)                // while + if == while...
                    {
                        ans += 'D';
                    }
                }
            }
            if (dx > 0)
            {
                while (dx-- > 0)
                {
                    ans += 'L';
                }
            }
            else
            {
                if (dx < 0)
                {
                    while (dx++ < 0)
                    {
                        ans += 'R';
                    }
                }
            }
            x = tx;
            y = ty;
            ans += '!';
            lastZ = ch =='z';
        }

        return ans;
    }

};

int main()
{

//    string s = "code";
//    string s = "leet";
    string s = "zdz";


    LT1138 lt;

    cout<<lt.lt1138a(s)<<endl;

    return 0;
}
