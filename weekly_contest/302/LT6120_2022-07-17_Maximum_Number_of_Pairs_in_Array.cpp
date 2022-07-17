
#include "../../header/myheader.h"

class LT6120
{
public:




    // AC
    vector<int> numberOfPairs(vector<int>& nums) {
        int arr[101] = { 0 };
        for (int i : nums)
        {
            arr[i]++;
        }
        int cntpair = 0;
        for (int i = 0; i < 101; ++i)
        {
            cntpair += arr[i] / 2;
        }
        return { cntpair, (int) nums.size() - cntpair * 2 };
    }

};

int main()
{

    LT6120 lt;


    return 0;
}
