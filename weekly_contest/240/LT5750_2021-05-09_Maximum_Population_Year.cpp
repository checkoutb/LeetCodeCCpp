
#include "../../header/myheader.h"

class LT5750
{
public:




// AC
    int lt5750a(vector<vector<int>>& logs)
    {
        int arr[101] = {0};
        for (vector<int>& vi : logs)
        {
            for (int i = vi[0] - 1950; i < vi[1] - 1950; ++i)
            {
                arr[i]++;
            }
        }
        int year = 0;
        int mx = arr[0];
        for (int i = 1; i < 101; ++i)
        {
            if (arr[i] > mx)
            {
                year = i;
                mx = arr[i];
            }
        }
        return year + 1950;
    }

};

int main()
{

    LT5750 lt;


    return 0;
}
