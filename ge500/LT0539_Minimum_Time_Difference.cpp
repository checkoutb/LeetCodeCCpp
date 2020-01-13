
#include "../header/myheader.h"

class LT0539
{
public:


//There is only 24 * 60 = 1440 possible time points.
//boolean[] mark = new boolean[24 * 60];

//if ( == ':')
//{ return substr(0,i) + substr(i,2)}


// 是05:30 所以可以直接 substr(3,2)， 或者 （(s[0]-'0')*10+s[1]-'0') *60 +
// 05 可以直接sort。。 sort后， 相邻string，对比 s[0]*10+s[1] - s1[0]*10-s1[1]。。。。的值。

//Runtime: 20 ms, faster than 65.36% of C++ online submissions for Minimum Time Difference.
//Memory Usage: 11.8 MB, less than 80.00% of C++ online submissions for Minimum Time Difference.

    // 5:30 还是 05:30 ? suan le.
    // zhi jie sort timePoints ?
    int lt0539a(vector<string>& timePoints)
    {
        vector<int> times(timePoints.size());
        int a = 0;
        for (string s : timePoints)
        {
            int i = 0;
            int j = 0;
            for (char c : s)
            {
                if (c == ':')
                {
                    i *= 60;
                    j = i;
                    i = 0;
                }
                else
                {
                    i *= 10;
                    i += (c - '0');
                }
            }
            times[a++] = i + j;
        }
        sort(times.begin(), times.end());

        #ifdef __test
        for_each(times.begin(), times.end(), fun_cout);
        cout<<endl;
        #endif // __test

        int ans = times[0] + 60*24 - times[times.size() - 1];
        for (int i = 1; i < times.size(); i++)
        {
            ans = std::min(ans, times[i] - times[i - 1]);
        }
        return ans;
    }
};

int main()
{
    vector<string> v = {"00:00","01:00","03:02","01:03","23:59","05:04"};

    LT0539 lt;

    cout<<lt.lt0539a(v)<<endl;

    return 0;

}
