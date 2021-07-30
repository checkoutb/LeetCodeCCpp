
#include "../header/myheader.h"

class LT1946
{
public:


// D D

//        for (int i = 0; i < num.size(); ++i) {
//            int x = num[i] - '0';
//            if (x < change[x]) {
//                on = true;
//                num[i] = change[x] + '0';
//            } else if (x > change[x] && on) break;
//        }

//    for (auto i = 0; i < num.size(); ++i) {
//        int d = num[i] - '0';
//        num[i] = '0' + max(d, change[d]);
//        if (change[d] < d && mutated)
//            break;
//        mutated |= change[d] > d;
//    }



//Runtime: 76 ms, faster than 47.27% of C++ online submissions for Largest Number After Mutating Substring.
//Memory Usage: 28.8 MB, less than 49.15% of C++ online submissions for Largest Number After Mutating Substring.
    string lt1946b(string num, vector<int>& change)
    {
        bool chg = false;       // changed
        for (int i = 0; i < num.size(); ++i)
        {
            int t2 = num[i] - '0';
            if (change[t2] > t2)
            {
                num[i] = (char) ('0' + change[t2]);
                chg = true;
            }
            else if (change[t2] == t2)
            {

            }
            else
            {
                if (chg)
                    break;
            }
        }
        return num;
    }



// ？？ 能转几次？？  一次。。 Example 3, 可以 5-2-7 的。。
// error
// ? 好像只能 转 一个 substring。。。
    string lt1946a(string num, vector<int>& change)
    {
        for (int i = 0; i < change.size(); ++i)
        {
            change[i] = getMxa1(change, i, i, 0);
        }
        char arr[123] = {0};
        for (int i = 0; i < change.size(); ++i)
        {
            arr['0' + i] = (char) ('0' + change[i]);
        }
        for (int i = 0; i < num.size(); ++i)
        {
            num[i] = arr[num[i]];
        }
        return num;
    }

    int getMxa1(vector<int>& vi, int ori_i, int i, int cnt)
    {
        if (cnt > 10)
            return vi[i];
        if (i < ori_i)
            return vi[i];
        int ans = vi[i];
        ans = max(ans, getMxa1(vi, ori_i, vi[i], cnt + 1));
        return ans;
    }

};

int main()
{
//    string s = "132";
//    myvi v = {9,8,5,0,3,6,4,2,6,8};

//    string s = "021";
//    myvi v = {9,4,3,5,7,2,1,9,0,6};

    string s = "5";
    myvi v = {1,4,7,5,3,2,5,6,9,4};

    LT1946 lt;

    cout<<lt.lt1946b(s, v)<<endl;

    return 0;
}
