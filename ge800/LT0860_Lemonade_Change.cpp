
#include "../header/myheader.h"

class LT0860
{
public:


// D D
//        int five = 0, ten = 0;
//        for (int i : bills) {
//            if (i == 5) five++;
//            else if (i == 10) five--, ten++;
//            else if (ten > 0) ten--, five--;
//            else five -= 3;
//            if (five < 0) return false;
//        }



//Runtime: 48 ms, faster than 23.46% of C++ online submissions for Lemonade Change.
//Memory Usage: 17.2 MB, less than 34.60% of C++ online submissions for Lemonade Change.
    bool lt0860a(vector<int>& bills)
    {
        int arr[][2] = {{5,10},{0,0}};
        for (int b : bills)
        {
            if (b > 5)
            {
                if (canCharge(arr, b - 5))
                {

                }
                else
                {
                    return false;
                }
            }

            switch (b)
            {
            case 5:
                arr[1][0]++;
                break;
            case 10:
                arr[1][1]++;
                break;
            }

        }
        return true;
    }

    bool canCharge(int arr[][2], int target)
    {
        if (target == 5)
        {
            if (arr[1][0] > 0)
            {
                arr[1][0]--;
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {       // 15
            if (arr[1][1] > 0 && arr[1][0] > 0)
            {
                arr[1][0]--;
                arr[1][1]--;
                return true;
            }
            else
            {
                if (arr[1][0] > 2)
                {
                    arr[1][0] -= 3;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        return false;
    }
};

int main()
{

//    vector<int> v = {5,5,5,10,20};
//    vector<int> v = {10,10};
    vector<int> v = {5,5,10,10,20};

    LT0860 lt;

    cout<<lt.lt0860a(v)<<endl;

    return 0;
}
