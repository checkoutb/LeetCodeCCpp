
#include "../header/myheader.h"

class LT1010
{
public:

// D D
//        vector<int> c(60);
//        int res = 0;
//        for (int t : time) {
//            res += c[(600 - t) % 60];
//            c[t % 60] += 1;
//        }
//        return res;



//Runtime: 52 ms, faster than 92.78% of C++ online submissions for Pairs of Songs With Total Durations Divisible by 60.
//Memory Usage: 23.4 MB, less than 24.21% of C++ online submissions for Pairs of Songs With Total Durations Divisible by 60.
    int lt1010a(vector<int>& time)
    {
        int arr[60] = {0};
        for (int n : time)
        {
            arr[n % 60]++;
        }
        int ans = arr[0] * (arr[0] - 1) / 2;
        ans = max(0, ans);
        ans += max(0, arr[30] * (arr[30] - 1) / 2);
        for (int i = 1; i < 30; i++)                // 30.
        {
            if (i == 30)
                continue;
            ans += arr[i] * arr[60 - i];
        }
        return ans;
    }

};

int main()
{

//    vector<int> v = {30,20,150,100,40};
    vector<int> v = {60,60,60};

    LT1010 lt;

    cout<<lt.lt1010a(v)<<endl;

    return 0;
}
