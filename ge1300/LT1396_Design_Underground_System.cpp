
#include "../header/myheader.h"

class LT1396
{
public:



};

// D D


//    const auto &[startStation, timeIn] = m[id];
//    auto &[totalDuration, tripsCnt] = stats[startStation + ">" + endStation];
//    totalDuration += timeOut - timeIn;
//    ++tripsCnt;
// ...  auto &[totalDuration, tripsCnt] , 感觉 a,b=b,a 不远了。。



//Runtime: 192 ms, faster than 97.34% of C++ online submissions for Design Underground System.
//Memory Usage: 57.7 MB, less than 89.06% of C++ online submissions for Design Underground System.
class UndergroundSystem {

    unordered_map<int, pair<int, string>> map2;
    unordered_map<string, map<string, pair<int, int>>> map3;        // start: end: <count, time>

public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        map2[id] = {t, stationName};
    }

    void checkOut(int id, string stationName, int t) {
        pair<int, string>& p = map2[id];
        pair<int, int>& p2 = map3[p.second][stationName];
        p2.first++;
        p2.second += (t - p.first);
    }

    double getAverageTime(string startStation, string endStation) {
        pair<int, int>& p = map3[startStation][endStation];
        return 1.0 * p.second / p.first;
    }
};


int main()
{

    UndergroundSystem undergroundSystem;

//    undergroundSystem.checkIn(45, "Leyton", 3);
//    undergroundSystem.checkIn(32, "Paradise", 8);
//    undergroundSystem.checkIn(27, "Leyton", 10);
//    undergroundSystem.checkOut(45, "Waterloo", 15);
//    undergroundSystem.checkOut(27, "Waterloo", 20);
//    undergroundSystem.checkOut(32, "Cambridge", 22);
//    cout<<endl<<undergroundSystem.getAverageTime("Paradise", "Cambridge");       // return 14.00000. There was only one travel from "Paradise" (at time 8) to "Cambridge" (at time 22)
//    cout<<endl<<undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 11.00000. There were two travels from "Leyton" to "Waterloo", a customer with id=45 from time=3 to time=15 and a customer with id=27 from time=10 to time=20. So the average time is ( (15-3) + (20-10) ) / 2 = 11.00000
//    undergroundSystem.checkIn(10, "Leyton", 24);
//    cout<<endl<<undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 11.00000
//    undergroundSystem.checkOut(10, "Waterloo", 38);
//    cout<<endl<<undergroundSystem.getAverageTime("Leyton", "Waterloo");          // return 12.00000

    undergroundSystem.checkIn(10, "Leyton", 3);
    undergroundSystem.checkOut(10, "Paradise", 8);
    cout<<endl<<undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 5.00000
    undergroundSystem.checkIn(5, "Leyton", 10);
    undergroundSystem.checkOut(5, "Paradise", 16);
    cout<<endl<<undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 5.50000
    undergroundSystem.checkIn(2, "Leyton", 21);
    undergroundSystem.checkOut(2, "Paradise", 30);
    cout<<endl<<undergroundSystem.getAverageTime("Leyton", "Paradise"); // return 6.66667



    LT1396 lt;


    return 0;
}
