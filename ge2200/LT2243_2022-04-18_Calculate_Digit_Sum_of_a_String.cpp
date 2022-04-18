
#include "../header/myheader.h"

class LT2243
{
public:

// D D

//        for (int i = 0; i < s.size(); i += k)
//            s1 += to_string(accumulate(begin(s) + i, begin(s) + min((int)s.size(), i + k), 0,
//                [](int n, char ch){ return n + ch - '0'; }));


//        for(int i=0;i<s.size();i++){
//            if(i!=0 and i%k==0){
//                ans+=to_string(sum);
//                sum=0;
//            }
//            sum+=(s[i]-'0');
//        }//end of for
//        ans+=to_string(sum);
//        s=ans;
// 先判断，然后+，这样保证外面能直接+，不需要判断。



//Runtime: 4 ms, faster than 33.33% of C++ online submissions for Calculate Digit Sum of a String.
//Memory Usage: 6 MB, less than 83.33% of C++ online submissions for Calculate Digit Sum of a String.
    string lt2243a(string s, int k)
    {
        while (s.size() > k)
        {
            string s2;
            int t2 = 0;
            for (int i = 0; i < s.size(); ++i)
            {
                t2 += (s[i] - '0');
                if (((i + 1) % k) == 0)
                {
                    s2 += std::to_string(t2);
                    t2 = 0;
                }
            }
            if (s.size() % k != 0)
            {
                s2 += std::to_string(t2);
            }
            s = s2;
            #ifdef __test
            cout<<s<<endl;
            #endif // __test
        }
        return s;
    }

};

int main()
{

    LT2243 lt;

//    string s = "11111222223";
//    int k = 3;

    string s = "00000000";
    int k = 3;

    cout<<lt.lt2243a(s, k)<<endl;

    return 0;
}
