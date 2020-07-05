
#include "../header/myheader.h"

class LT0948
{
public:


// D D
//        while (i <= j) {
//            if (P >= tokens[i]) {
//                P -= tokens[i++];
//                res = max(res, ++points);
//            } else if (points > 0) {
//                points--;
//                P += tokens[j--];
//            } else {
//                break;
//            }
//        }

//  while (i <= j && pt >= 0) {
//    if (t[i] <= pw) pw -= t[i++], max_pt = max(max_pt, ++pt);
//    else pw += t[j--], --pt;
//  }



//Runtime: 12 ms, faster than 91.46% of C++ online submissions for Bag of Tokens.
//Memory Usage: 10.7 MB, less than 35.41% of C++ online submissions for Bag of Tokens.
// 描述真的很拉。
    int lt0948a(vector<int>& tokens, int P)
    {
        sort(begin(tokens), end(tokens));
        int st = 0;
        int en = tokens.size() - 1;
        int ans = 0;
        int pts = 0;
        bool moved = true;
        while (st <= en && moved)
        {
            moved = false;
            while (st <= en && P >= tokens[st])         // .<=  then >= , or index out of bound.
            {
                moved = true;
                P -= tokens[st];
                tokens[st] = -tokens[st] - 1;
                pts++;
                st++;
            }
            #ifdef __test
            cout<<ans<<" : "<<pts<<endl;
            #endif // __test
            ans = max(ans, pts);
            if (pts > 0 && en >= st)
            {
                moved = true;
                pts--;
                P += tokens[en];
                tokens[en] = -tokens[en] - 1;
                en--;
            }
        }
        return ans;
    }

};

int main()
{

//    vector<int> v = {100};
//    int p = 50;

//    vector<int> v = {100,200};
//    int p = 150;

//    vector<int> v = {100,200,300,400};
//    int p = 200;

    vector<int> v = {26};
    int p = 51;

    LT0948 lt;

    cout<<lt.lt0948a(v, p)<<endl;

    return 0;
}
