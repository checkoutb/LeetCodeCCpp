
#include "../header/myheader.h"

class LT1845
{
public:



};

// D D

//    bitset<100000> res;
//    SeatManager(int n) {
//        res.set(); // set all the bits
//    }
//
//    int reserve() {
//        int pos = res._Find_first(); //find the first bit set
//        res.reset(pos); // reset this to zero, as it is reserved.
//        return pos+1;
//    }
//
//    void unreserve(int seatNumber) {
//
//        res.set(seatNumber-1); // set it to on again, as sit is available.
//    }





//Runtime: 336 ms, faster than 50.00% of C++ online submissions for Seat Reservation Manager.
//Memory Usage: 136.5 MB, less than 100.00% of C++ online submissions for Seat Reservation Manager.
class SeatManager {
    int mxn;
    set<int> set2;      // or pri_q

public:
    SeatManager(int n) {
        this->mxn = 1;
    }

    int reserve() {
        if (set2.empty())
            return mxn++;
        int t2 = *set2.begin();
        set2.erase(set2.begin());
        return t2;
    }

    void unreserve(int seatNumber) {
        if (seatNumber + 1 == mxn)
        {
            mxn--;
            return;
        }
        set2.insert(seatNumber);
    }
};



int main()
{

    SeatManager sm(5);
    cout<<sm.reserve()<<endl;
    cout<<sm.reserve()<<endl;
    sm.unreserve(2);
    cout<<sm.reserve()<<endl;
    cout<<sm.reserve()<<endl;
    cout<<sm.reserve()<<endl;
    cout<<sm.reserve()<<endl;
    sm.unreserve(5);


    LT1845 lt;


    return 0;
}
