
#include "../header/myheader.h"

class LT1221
{
public:

// D D

//            if(a=='L')
//                nums+=1;
//            else
//                nums-=1;
//            if(!nums)
//                ans++;

//            if (c == 'L')
//                left++;
//            else
//                right++;
//            if (left == right)
//                score++;
// 不需要 归0。


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Split a String in Balanced Strings.
//Memory Usage: 6.4 MB, less than 38.50% of C++ online submissions for Split a String in Balanced Strings.
// 这个是要求  不能 丢弃 char 的。 那就意味着，s中 L 和 R 的数量应该是一样的。
    int lt1221a(string s)
    {
        int nl = 0;
        int nr = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L')
                nl++;
            else
                nr++;
            if (nr == nl)
            {
                nr = nl = 0;
                ans++;
            }
        }
        return ans;
    }

};

int main()
{

    string arr[] = {"RLRRLLRLRL","RLLLLRRRLR","LLLLRRRR","RLRRRLLRLL"};

    LT1221 lt;

    for (string& s : arr)
    {
        cout<<lt.lt1221a(s)<<endl;
    }

    return 0;
}
