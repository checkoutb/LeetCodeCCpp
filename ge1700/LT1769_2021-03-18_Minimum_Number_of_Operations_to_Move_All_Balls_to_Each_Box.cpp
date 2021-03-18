
#include "../header/myheader.h"

class LT1769
{
public:

// D D

//    vector<int> res(boxes.length());
//    for (int i = 0, ops = 0, cnt = 0; i < boxes.length(); ++i) {
//       res[i] += ops;
//       cnt += boxes[i] == '1' ? 1 : 0;
//       ops += cnt;
//    }
//    for (int i = boxes.length() - 1, ops = 0, cnt = 0; i >= 0; --i) {
//        res[i] += ops;
//        cnt += boxes[i] == '1' ? 1 : 0;
//        ops += cnt;
//    }
//    return res;
//We first "move" balls from left to right, and track how many ops it takes for each box.
//For that, we count how many balls we got so far in cnt, and accumulate it in ops.
//Then, we do the same from right to left.




//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Minimum Number of Operations to Move All Balls to Each Box.
//Memory Usage: 8.9 MB, less than 75.00% of C++ online submissions for Minimum Number of Operations to Move All Balls to Each Box.
    vector<int> lt1769a(string boxes)
    {
        int len = 0;
        int cnt1 = 0;
        vector<int> ans(boxes.size(), 0);
        for (int i = 0; i < boxes.size(); ++i)
        {
            len += (boxes[i] == '1' ? i : 0);
            cnt1 += boxes[i] - '0';
        }
        int t2 = 0;
        int cnt2 = 0;
        for (int i = 0; i < boxes.size(); ++i)
        {
            ans[i] = len + t2;
            if (boxes[i] == '1')
            {
                cnt1--;
                cnt2++;
            }
            len -= cnt1;
            t2 += cnt2;
            #ifdef __test
            cout<<len<<" , "<<t2<<endl;
            #endif // __test
        }
        return ans;
    }

};

int main()
{
//    string s = "110";
    string s = "001011";

    LT1769 lt;

    myvi v = lt.lt1769a(s);

    showVectorInt(v);

    return 0;
}
