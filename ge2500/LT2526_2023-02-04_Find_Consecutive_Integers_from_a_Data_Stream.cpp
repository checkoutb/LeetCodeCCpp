
#include "../header/myheader.h"

class LT2526
{
public:



};

// D D

//if (num != val) cnt = 0;
//else cnt++;
//if (cnt >= k) return true;




//Runtime305 ms
//Beats
//63.80 %
//Memory122.6 MB
//Beats
//64.52 %
class DataStream {

    int k;
    int tar;
    int cnt;
    int lst;        // last    not equal

public:
    DataStream(int value, int k) {
        this->cnt = 0;
        this->tar = value;
        this->k = k;
        this->lst = 0;
    }

    bool consec(int num) {
        ++(this->cnt);      // 1st is 1
        if (num != this->tar)
        {
            lst = this->cnt;
        }
        if ((this->cnt - this->lst) >= this->k)
        {
            return true;
        }
        return false;
    }
};


int main()
{

    LT2526 lt;


    return 0;
}
