
#include "../header/myheader.h"

class LT1625
{
public:

// D D


//    inline int shift(int x, int a){ // given a, the shifts needed for x to be minimal.
//        // assert(0<=x && x<=9 && 1<=a && a<=9);
//        if (a==5) {
//            if (x<5) return 0;
//            return 5;
//        }
//        if ((a&1)==0 && x&1) return 11-x;
//        return 10-x;
//    }
//        do {
//            s = s.substr(b) + s.substr(0, b);
//            int x = shift(s[1]-'0', a);
//            for(int i=1; i<s.size(); i += 2){
//                s[i] = (s[i]-'0'+x) % 10 + '0';
//            }
//            if (b&1) {
//                x = shift(s[0]-'0', a);
//                for (int i=0; i<s.size(); i += 2){
//                    s[i] = (s[i]-'0'+x) % 10 + '0';
//                }
//            }
//            ans = min(ans, s);
//            B = (B+b) % s.size();
//        } while(B);


//    while (odd[s[0] - '0'] == false) {
//        odd[s[0] - '0'] = true;
//        bool even[10] = {};
//        while (even[s[1] - '0'] == false) {
//            even[s[1] - '0'] = true;
//            int best_r = 0;
//            vector<bool> rotate(s.size());
//            for (int r = b; !rotate[r]; r = (r + b) % s.size()) {
//                rotate[r] = true;
//                if (less(s, r, best_r))
//                    best_r = r;
//            }
//            res = min(res, s.substr(best_r) + s.substr(0, best_r));
//            for (int k = 1; k < s.size(); k += 2)
//                s[k] = '0' + (s[k] - '0' + a) % 10;
//        }
//        if (b % 2) {
//            for (int k = 0; k < s.size(); k += 2)
//                s[k] = '0' + (s[k] - '0' + a) % 10;
//        }
//    }


//Runtime: 316 ms, faster than 72.50% of C++ online submissions for Lexicographically Smallest String After Applying Operations.
//Memory Usage: 89.1 MB, less than 51.79% of C++ online submissions for Lexicographically Smallest String After Applying Operations.
    string lt1625a(string s, int a, int b)
    {
        b = s.size() - b;
        set<string> set2;
        queue<string> que2;
        que2.push(s);
        while (!que2.empty())
        {
            int sz1 = que2.size();
            while (sz1-- > 0)
            {
                string fnt = que2.front();
                que2.pop();
                string fnt2 = fnt.substr(b) + fnt.substr(0, b);
                if (set2.find(fnt2) == set2.end())
                {
                    set2.insert(fnt2);
                    que2.push(fnt2);
                }

                for (int i = 1; i < s.size(); i += 2)
                {
                    fnt[i] = char (((fnt[i] - '0' + a) % 10) + '0');
                }
                if (set2.find(fnt) == set2.end())
                {
                    set2.insert(fnt);
                    que2.push(fnt);
                }
            }
        }
        string ans = *set2.begin();
        return ans;
    }

};

int main()
{
//    string s{"5525"};
//    int a{9}, b{2};

//    string s{"74"};
//    int a{5}, b{1};

    string s{"0011"};
    int a{4}, b{2};

    LT1625 lt;

    cout<<lt.lt1625a(s,a,b);

    return 0;
}
