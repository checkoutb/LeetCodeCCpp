
#include "../header/myheader.h"

class LT1189
{
public:

// D D

//return min ( { mm['b'] , mm['a'] , mm['l']/2 , mm['o']/2 ,mm['n'] } ) ;
// 组vector，然后 std::min。。

//        for (char c : "balloon".toCharArray())
//            ++cntBaloon[c - 'a'];
//        for (char c : "balloon".toCharArray())
//            min = Math.min(min, cnt[c - 'a'] / cntBaloon[c - 'a']);


//Runtime: 4 ms, faster than 87.51% of C++ online submissions for Maximum Number of Balloons.
//Memory Usage: 6.9 MB, less than 98.22% of C++ online submissions for Maximum Number of Balloons.
// balloon
    int lt1189a(string text)
    {
        int arr[128] = {0};
        for (char ch : text)
        {
            arr[ch]++;
        }
        int ans = INT_MAX;
        ans = min(ans, min(arr['b'], min(arr['a'], min(arr['n'], min(arr['l'] / 2, arr['o'] / 2)))));
        return ans;
    }

};

int main()
{

//    string s = "nlaebolko";
    string s = "loonbalxballpoon";

    LT1189 lt;

    cout<<lt.lt1189a(s)<<endl;

    return 0;
}
