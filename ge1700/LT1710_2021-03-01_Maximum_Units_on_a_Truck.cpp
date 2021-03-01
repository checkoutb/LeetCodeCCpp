
#include "../header/myheader.h"

class LT1710
{
public:

// D D

//        for (int[] box : boxTypes) {
//            if (truckSize >= box[0]) {
//                boxes += box[0] * box[1];
//                truckSize -= box[0];
//            }else {
//                boxes += truckSize * box[1];
//                return boxes;
//            }
//        }




//Runtime: 40 ms, faster than 93.08% of C++ online submissions for Maximum Units on a Truck.
//Memory Usage: 15.8 MB, less than 99.89% of C++ online submissions for Maximum Units on a Truck.
// 所有箱子都是一个尺寸， 箱子里的unit 个数不同，  箱子个数不同。
    int lt1710a(vector<vector<int>>& boxTypes, int truckSize)
    {
        std::sort(begin(boxTypes), end(boxTypes), [](const vector<int>& v1, const vector<int>& v2){ return v1[1] > v2[1]; });
        #ifdef __test
        for (int i = 0; i < boxTypes.size(); ++i)
        {
            cout<<boxTypes[i][0]<<", "<<boxTypes[i][1]<<endl;
        }
        #endif // __test
        int ans = 0;
        for (int idx = 0; idx < boxTypes.size() && truckSize > 0; ++idx)
        {
            int cnt = min(truckSize, boxTypes[idx][0]);
            ans += boxTypes[idx][1] * cnt;
            truckSize -= cnt;
        }
        return ans;

//        int idx = 0;
//        while (truckSize > 0 && )
//        {
//
//        }
    }

};

int main()
{
//    myvvi vv = {{1,3},{2,2},{3,1}};
//    int t = 4;

    myvvi vv = {{5,10},{2,5},{4,7},{3,9}};
    int t = 10;

    LT1710 lt;

    cout<<lt.lt1710a(vv, t);

    return 0;
}
