
#include "../../header/myheader.h"

class LT
{
public:

// D D

// return *max_element(begin(n), end(n)) - '0';


// AC
    int lt(string n)
    {
        char ch = '0';
        for (int i = 0; i < n.size(); ++i)
            if (n[i] > ch)
                ch = n[i];
        return ch - '0';
    }

};

int main()
{

    LT lt;


    return 0;
}
