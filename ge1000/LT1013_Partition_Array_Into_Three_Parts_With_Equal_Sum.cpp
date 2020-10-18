
#include "../header/myheader.h"

class LT1013
{
public:

// D D

//return (found >= 3) ? true : false;


//        int sum = Arrays.stream(A).sum(), part = 0, average = sum / 3, cnt = 0;
//        for (int a : A) {
//            part += a;
//            if (part == average) { // find the average: sum / 3
//                ++cnt; // find an average, increase the counter.
//                part = 0; // reset part.
//            }
//        }
//        return cnt >= 3 && sum % 3 == 0;



//Runtime: 76 ms, faster than 98.78% of C++ online submissions for Partition Array Into Three Parts With Equal Sum.
//Memory Usage: 32.4 MB, less than 6.32% of C++ online submissions for Partition Array Into Three Parts With Equal Sum.
    bool lt1013a(vector<int>& A)
    {
        int sum = std::accumulate(begin(A), end(A), 0);
        if (sum % 3 != 0)
            return false;
        int tar = sum / 3;
        int cnt = 0;
        sum = 0;
        int i = 0;
        for (; i < A.size(); i++)
        {
            sum += A[i];
            if (sum == tar)
            {
                cnt++;
                sum = 0;
                if (cnt == 2)
                    break;
            }
        }
        i++;
        bool third = false;
        for (; i < A.size(); i++)
        {
            sum += A[i];
            third = true;
        }
        return sum == tar && cnt == 2 && third;
    }

};

int main()
{
//    vector<int> v = {0,2,1,-6,6,-7,9,1,2,0,1};
    vector<int> v = {0,2,1,-6,6,7,9,-1,2,0,1};
//    vector<int> v = {3,3,6,5,-2,2,5,1,-9,4};
//    vector<int> v = {10,-10,10,-10,10,-10,10,-10};            // [-1,1,-1,1]

    LT1013 lt;

    cout<<lt.lt1013a(v)<<endl;

    return 0;
}
