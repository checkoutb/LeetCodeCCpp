
#include "../header/myheader.h"

class LT1812
{
public:

// D D

//return a[0] % 2 != a[1] % 2;

//return (c[0] + c[1]) % 2;


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Determine Color of a Chessboard Square.
//Memory Usage: 5.8 MB, less than 85.16% of C++ online submissions for Determine Color of a Chessboard Square.
    bool lt1812a(string coordinates)
    {
//        char ch1 = coordinates[0];
//        char ch2 = coordinates[1];
        return (coordinates[0] - 'a' + 1 + coordinates[1] - '0') % 2 != 0;
    }

};

int main()
{

    LT1812 lt;


    return 0;
}
