
#include "../header/myheader.h"

class LT2094
{
public:

// D D

//        for (int i = 1; i < 10; ++i)
//            for (int j = 0; cnt[i] > 0 && j < 10; ++j)
//                for (int k = 0; cnt[j] > (i == j) && k < 10; k += 2)
//                    if (cnt[k] > (k == i) + (k == j))
//                        res.push_back(i * 100 + j * 10 + k);


//    for (int num = 100; num < 999; num += 2) {


//Runtime: 12 ms, faster than 71.19% of C++ online submissions for Finding 3-Digit Even Numbers.
//Memory Usage: 9.2 MB, less than 79.19% of C++ online submissions for Finding 3-Digit Even Numbers.
// 先尾巴，然后头，然后剩下的。
    vector<int> lt2094a(vector<int>& digits)
    {
        vector<int> ans;
        int arr[10] = {0};
        for (int i = 0; i < digits.size(); ++i)
            arr[digits[i]]++;

        for (int i = 0; i < 9; i += 2)      // tail
        {
            if (arr[i] <= 0)
            {
                continue;
            }
            int t2 = i;
            arr[i]--;
            for (int j = 1; j <= 9; ++j)        // head
            {
                if (arr[j] <= 0)
                    continue;
                t2 += j * 100;
                arr[j]--;
                for (int k = 0; k <= 9; ++k)
                {
                    if (arr[k] <= 0)
                        continue;
                    ans.push_back(t2 + k * 10);
                }
                t2 -= j * 100;
                arr[j]++;
            }
            arr[i]++;
        }

        std::sort(begin(ans), end(ans));
        return ans;
    }

//    void dfsa1(vector<int>& digits, int n, int depth, vector<int>& ans)
//    {
//        if (depth == 3)
//        {
//            ans.push_back(n);
//            return;
//        }
//        if (depth == 0)     // tail % 2 == 0
//        {
//            for (int i = 0; i < digits.size(); ++i)
//            {
//                if (digits[i] % 2 == 0)
//                {
//                    int
//                }
//            }
//        }
//        else if (depth == 1)        // head != 0
//        {
//
//        }
//        else        // mid, all
//        {
//
//        }
//    }

};

int main()
{

    LT2094 lt;

//    myvi v = {2,1,3,0};
//    myvi v = {2,2,2,8,8};
    myvi v = {3,5,7};

    myvi v2 = lt.lt2094a(v);

    showVectorInt(v2);

    return 0;
}
