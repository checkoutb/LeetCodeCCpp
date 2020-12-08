
#include "../header/myheader.h"

class LT1603
{
public:



};

// D D

//        if( carType == 1 )
//        {
//            if( b-- > 0)
//                return true;
//        }
//        else if( carType == 2 )
//        {
//            if( m-- > 0)
//                return true;
//        }
//        else if( carType == 3 )
//        {
//            if( s-- > 0)
//                return true;
//        }
//        return false;
// ... 只有add， 没有 remove。。。不需要保存 最大容量。。

// 数组， map。


//    vector<int> count;
//    ParkingSystem(int big, int medium, int small) {
//        count = {big, medium, small};
//    }
//
//    bool addCar(int carType) {
//        return count[carType - 1]-- > 0;
//    }


//Runtime: 192 ms, faster than 5.54% of C++ online submissions for Design Parking System.
//Memory Usage: 33.6 MB, less than 13.53% of C++ online submissions for Design Parking System.
class ParkingSystem {
    int b,m,s;
    int q,w,e;
public:
    ParkingSystem(int big, int medium, int small) {
        this->b = big;
        this->m = medium;
        this->s = small;
        this->q = this->w = this->e = 0;
    }

    bool addCar(int carType) {
        switch(carType)
        {
        case 1:
            if (this->q == this->b)
                return false;
            this->q++;
            return true;
        case 2:
            if (this->w == this->m)
                return false;
            this->w++;
            return true;
        case 3:
            if (this->e == this->s)
                return false;
            this->e++;
            return true;
        }
        return false;           // .
    }
};

int main()
{
    ParkingSystem ps(1,2,3);

    LT1603 lt;


    return 0;
}
