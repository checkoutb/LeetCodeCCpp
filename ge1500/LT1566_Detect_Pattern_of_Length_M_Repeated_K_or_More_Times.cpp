
#include "../header/myheader.h"

class LT1566
{
public:

// D D

//        int n = arr.size(), count = 0;
//        for (int i = 0; i + m < n; ++i) {
//            if (arr[i] == arr[i + m]) {
//                ++count;
//                if (count == (k - 1) * m) return true;
//            } else count = 0;
//        }
//        return false;


//    for (int i = 0; i + m < a.size() && cnt < m * (k - 1); ++i)
//        cnt = a[i] == a[i + m] ? cnt + 1 : 0;
//    return cnt == m * (k - 1);




//Runtime: 4 ms, faster than 61.96% of C++ online submissions for Detect Pattern of Length M Repeated K or More Times.
//Memory Usage: 8.6 MB, less than 59.10% of C++ online submissions for Detect Pattern of Length M Repeated K or More Times.
    bool lt1566a(vector<int>& arr, int m, int k)
    {
        for (int i = 0; i <= ((int) arr.size() - m * k); ++i)           // so  auto i ..  and use < ?
        {
            for (int j = 0; j < m; ++j)         // length
            {
                for (int x = 1; x < k; ++x)         // times
                {
                    if ((i + j + x * m >= arr.size()) || arr[i + j] != arr[i + j + x * m])
                    {
                        goto AAA;
                    }
                }
            }

            return true;

            AAA:
            continue;
        }
        return false;
    }

};

int main()
{

//    myvi v = {1,2,4,4,4,4};
//    int m{1}, k{3};

//    myvi v = {3,1,2,1,2,3,3,2,1};
//    int m{2}, k{2};

//    myvi v = {1,2,1,2,1,3};
//    int m{2}, k{3};

    myvi v = {2,2,2,2};
    int m{2}, k{3};

    LT1566 lt;

    cout<<lt.lt1566a(v,m,k);

    return 0;
}
