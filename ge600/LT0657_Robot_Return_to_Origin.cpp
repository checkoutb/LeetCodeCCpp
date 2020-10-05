
#include "../header/myheader.h"

class LT0657
{
public:


// D D

//    c = collections.Counter(moves)
//    return c['L'] == c['R'] and c['U'] == c['D']

//    direct = {'U': 1, 'D': -1, 'L': 1j, 'R': -1j}
//    return 0 == sum(direct[m] for m in moves)

//    return not sum(1j**'RUL'.find(m) for m in moves)

// up is py, down is ruby...

//moves.chars.map { |m| 1i**"RULD".index(m) }.sum == 0

//moves.chars.sort.join.match?(/^(|D\g<1>U|L\g<1>R)$/)



//Runtime: 20 ms, faster than 92.45% of C++ online submissions for Robot Return to Origin.
//Memory Usage: 8.1 MB, less than 52.19% of C++ online submissions for Robot Return to Origin.
    bool lt0657a(string moves)
    {
        int l{0}, r{0}, u{0}, d{0};
        for (char ch : moves)
        {
            switch(ch)
            {
            case 'L':
                l++;
                break;
            case 'R':
                r++;
                break;
            case 'U':
                u++;
                break;
            case 'D':
                d++;
                break;
            }
        }
        return l == r && u == d;
    }

};

int main()
{

    LT0657 lt;


    return 0;
}
