
#include "../header/myheader.h"

class LT2424
{
public:



};




//Runtime: 914 ms, faster than 40.02% of C++ online submissions for Longest Uploaded Prefix.
//Memory Usage: 160.2 MB, less than 86.55% of C++ online submissions for Longest Uploaded Prefix.
class LUPrefix {

    int n;
    int mx;         // min un-upload
    vector<bool> vi;

public:
    LUPrefix(int n) {
        this->n = n;
        this->mx = 1;
        this->vi.resize(n + 1);
    }

    void upload(int video) {
        this->vi[video] = true;
    }

    int longest() {
        while (this->mx <= n && this->vi[this->mx])
        {
            ++(this->mx);
        }
        return this->mx - 1;
    }
};



int main()
{

    LT2424 lt;


    return 0;
}
