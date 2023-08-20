
#include "../header/myheader.h"

class LT2671
{
public:



};




// Runtime473 ms
// Beats
// 70.86%
// Memory198.3 MB
// Beats
// 80.47%

class FrequencyTracker {
    map<int, int> map2;     // value : count
    map<int, int> map3;     // count : count
public:
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if (map2[number] != 0)
        {
            --map3[map2[number]];
        }
        ++map2[number];
        ++map3[map2[number]];
    }
    
    void deleteOne(int number) {
        if (map2[number] == 0)
            return;
        --map3[map2[number]];
        --map2[number];
        ++map3[map2[number]];
    }
    
    bool hasFrequency(int frequency) {
        return map3[frequency] != 0;
    }
};


int main()
{

    LT2671 lt;


    return 0;
}
