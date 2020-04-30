
#include "../header/myheader.h"

class LT0744
{
public:


// discuss
// return letters[(upper_bound(letters.begin(), letters.end(), target) - letters.begin()) % letters.size()];


//Runtime: 12 ms, faster than 87.95% of C++ online submissions for Find Smallest Letter Greater Than Target.
//Memory Usage: 6.9 MB, less than 100.00% of C++ online submissions for Find Smallest Letter Greater Than Target.
// upper_bound?
    char lt0744a(vector<char>& letters, char target)
    {
        vector<char>::iterator it = upper_bound(letters.begin(), letters.end(), target);
        if (it == letters.end())
            return letters[0];
        return *it;
    }

};

int main()
{

    vector<char> vv = {'c', 'f', 'j'};
    char tar = 'g';

    LT0744 lt;

    cout<<lt.lt0744a(vv, tar);

    return 0;
}
