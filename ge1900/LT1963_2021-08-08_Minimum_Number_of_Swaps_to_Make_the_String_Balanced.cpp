
#include "../header/myheader.h"

class LT1963
{
public:

// D D

//        int n = s.size();
//        int reversePairs = 0, left = 0;
//        for(char c : s){
//            if(c == '['){
//                left++;
//            }else{
//                if(left == 0){
//                    reversePairs++;
//                }else{
//                    left--;
//                }
//            }
//        }
//        if(reversePairs < 2){
//            return reversePairs;
//        }else{
//            return (reversePairs-1)/2 + 1;
//        }


//    int res = 0, bal = 0;
//    for (int i = 0, j = s.size() - 1; i < j; ++i) {
//        bal += s[i] == '[' ? 1 : -1;
//        if (bal < 0) {
//            for (int bal1 = 0; bal1 >= 0; --j)
//                bal1 += s[j] == ']' ? 1 : -1;
//            swap(s[i], s[j + 1]);
//            ++res;
//            bal = 1;
//        }
//    }
//    return res;

//    int res = 0, bal = 0;
//    for (int i = 0; i < s.size(); ++i) {
//        bal += s[i] == '[' ? 1 : -1;
//        if (bal < 0) {
//            ++res;
//            bal = 1;
//        }
//    }
//    return res;


//One sentence explanation:
//First cancel out all the valid pairs, then you will be left with something like]]][[[, and the answer will be ceil(m/2). Where m is the number of pairs left.






//Runtime: 112 ms, faster than 75.00% of C++ online submissions for Minimum Number of Swaps to Make the String Balanced.
//Memory Usage: 31.2 MB, less than 25.00% of C++ online submissions for Minimum Number of Swaps to Make the String Balanced.
// 感觉是从两边开始，各自找到一个 不符合的然后 互换。 对于前面来说 只有] 才会不符合， 对于后面来说 只有[ 才会不符合。所以互换是可以的。
//      但不知道怎么证明这个是最少的交换。
    int lt1963a(string s)
    {
        int cnts = 0;   // [++, ]--
        int cnte = 0;   // ]++, [--
        int l = 0;
        int r = s.size() - 1;
        int ans = 0;
        while (l < r)
        {
            while (cnts >= 0)
            {
                if (l >= s.size())
                    break;
                if (s[l++] == '[')
                    cnts++;
                else
                    cnts--;
            }
            while (cnte >= 0)
            {
                if (r < 0)
                    break;
                cnte += (s[r--] == ']' ? 1 : -1);
            }
            l--;
            r++;
            if (l < r)
            {
                ans++;
                s[l] = '[';
                s[r] = ']';
                cnts = cnte = 0;
            }
        }
        return ans;
    }

};

int main()
{

//    string s = "][][";
//    string s = "]]][[[";
//    string s = "[]";
    string s = "][";

    LT1963 lt;

    cout<<lt.lt1963a(s)<<endl;

    return 0;
}
