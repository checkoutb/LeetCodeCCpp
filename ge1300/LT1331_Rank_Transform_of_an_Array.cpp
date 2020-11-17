
#include "../header/myheader.h"

class LT1331
{
public:

// D D




// sort 然后遍历。i,i-1不同和rank+1。
//Runtime: 216 ms, faster than 60.69% of C++ online submissions for Rank Transform of an Array.
//Memory Usage: 39.4 MB, less than 67.98% of C++ online submissions for Rank Transform of an Array.
    vector<int> lt1331a(vector<int>& arr)
    {
        map<int, int> map2;
        for (int i : arr)
            map2[i] = 1;
        int rk = 1;
        for (map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            it->second = rk++;
        }
        for (int i = 0; i < arr.size(); ++i)
        {
            arr[i] = map2[arr[i]];
        }
        return arr;
    }

};

int main()
{

//    vector<int> v = {40,10,20,30};
//    vector<int> v = {100,100,100};
//    vector<int> v = {37,12,28,9,100,56,80,5,12};
    vector<int> v = {-10,-5,-5,-2,0,1,1,3,3,5};

    LT1331 lt;

    lt.lt1331a(v);

    showVectorInt(v);

    return 0;
}
