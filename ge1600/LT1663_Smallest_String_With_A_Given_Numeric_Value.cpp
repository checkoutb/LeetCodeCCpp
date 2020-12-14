
#include "../header/myheader.h"

class LT1663
{
public:

// D D

//        string res = string(n, 'a');
//        k -= n;
//        for (int i = n-1; i >= 0; --i) {
//            if (k < 26) {
//                res[i] = 'a' + k;
//                break;
//            }
//            else {
//                res[i] = 'z';
//                k -= 25;
//            }
//        }
//        return res;


//        for(int i=0;i<n;i++){
//            int take = k - (n-i-1)*26;
//            take = (take>=1? take: 1);
//
//            k -= take;
//            res += 'a'+take-1;
//        }


//    string res = string(n, 'a');
//    k -= n;
//    while (k > 0) {
//        res[--n] += min(25, k);
//        k -= min(25, k);
//    }





//Runtime: 76 ms, faster than 59.08% of C++ online submissions for Smallest String With A Given Numeric Value.
//Memory Usage: 21.5 MB, less than 69.56% of C++ online submissions for Smallest String With A Given Numeric Value.
    string lt1663a(int n, int k)
    {
        string ans(n, ' ');
        for (int i = n - 1; i >= 0; --i)
        {
            int ch = min(26, k - i);
            k -= ch;
            ans[i] = char ('a' + ch - 1);
        }
        return ans;
    }

};

int main()
{
//    int n{3}, k{27};
    int n{5}, k{73};

    LT1663 lt;

    cout<<lt.lt1663a(n, k);

    return 0;
}
