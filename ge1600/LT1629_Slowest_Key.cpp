
#include "../header/myheader.h"

class LT1629
{
public:

// D D

//        for(int i = 1; i < keysPressed.size(); ++i){
//            int new_time = releaseTimes[i] - releaseTimes[i-1];
//            if(new_time > time){
//                result = keysPressed[i];
//                time = new_time;
//            }
//            else if(new_time == time){
//                if(keysPressed[i] > result){
//                    result = keysPressed[i];
//                    time = new_time;
//                }
//            }
//        }

//    for (auto i = 1; i < times.size(); ++i)
//        if (max_p <= times[i] - times[i - 1]) {
//            if (max_p == times[i] - times[i - 1])
//                res = max((char)res, keys[i]);
//            else
//                res = keys[i];
//            max_p = times[i] - times[i - 1];
//        }


//Runtime: 16 ms, faster than 52.66% of C++ online submissions for Slowest Key.
//Memory Usage: 11 MB, less than 44.11% of C++ online submissions for Slowest Key.
    char lt1629a(vector<int>& releaseTimes, string keysPressed)
    {
        int arr[123] = {0};
        int sz1 = keysPressed.size();
        arr[keysPressed[0]] = releaseTimes[0];
        for (int i = 1; i < sz1; ++i)
        {
            char ch = keysPressed[i];
            int tm = releaseTimes[i] - releaseTimes[i - 1];
            arr[ch] = max(arr[ch], tm);
        }
        int mx = 0;
        char mxch = 'a';
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (mx <= arr[i])
            {
                mx = arr[i];
                mxch = (char) i;
            }
        }
        return mxch;

//        map<char, int> map2;
//        map2[keysPressed[0]] = releaseTimes[0];
//        for (int i = 1; i < keysPressed.size(); ++i)
//        {
//            map2[]
//        }
    }

};

int main()
{

//    myvi v = {9,29,49,50};
//    string s = "cbcd";

    myvi v = {12,23,36,46,62};
    string s = "spuda";

    LT1629 lt;

    cout<<lt.lt1629a(v, s);

    return 0;
}
