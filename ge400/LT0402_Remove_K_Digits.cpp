
#include "../header/myheader.h"

class LT0402
{
public:


// details
// 借助stack，遍历时，每次和top比较大小。

//        string ans="";
//        int n=num.size();
//        int rest=n-k;
//        for(char c:num){
//            while(ans.size()&&k&&ans.back()>c){
//                ans.pop_back();
//                k--;
//            }
//            ans.push_back(c);
//        }
//        ans.resize(rest);
//        //0200=>200
//        while(!ans.empty()&&ans[0]=='0'){ans.erase(ans.begin());}
//        if(ans.empty()) ans='0';
//        return ans;
// string作为stack




//    Runtime: 20 ms, faster than 31.25% of C++ online submissions for Remove K Digits.
//    Memory Usage: 16.2 MB, less than 14.82% of C++ online submissions for Remove K Digits.

    string lt0402a(string num, int k)
    {
        int i = 0;
        int sz1 = num.size();

        if (k >= sz1)
            return "0";

        int t1 = -1;
        while (t1 != sz1)
        {
            t1 = sz1;
            i = 0;
#ifdef __test
            cout<<num<<endl;
#endif // __test
            while (k > 0 && i < sz1 - 1)
            {
                if (num[i] > num[i + 1])
                {
                    if (i == 0 && num[i + 1] == '0')
                    {
                        int j = 1;
                        while (num[j] == '0')
                        {
                            j++;
                        }
                        num = num.substr(j);
                        i--;
                        if (i > 0)
                            i--;
                        k--;
                        sz1 = num.size();
                    }
                    else
                    {
                        num.erase(num.begin() + i);
                        i--;
                        k--;
                        sz1--;
                        if (i > 0)
                            i--;
                    }
                    break;          // 删除一个后，立刻重新开始，防止990000000321.删除2个，这种，不break的话，结果应该是9000000021.
                                        // 上面的i--，是无意义的。
                }
                i++;
            }
        }

        #ifdef __test
        cout<<sz1<<", "<<num<<endl;
        #endif // __test

        if (k >= num.size() || num.size() == 0)
        {
            return "0";
        }
        else if (k != 0)
        {
            num = num.substr(0, num.size() - k);
        }
        return num;
    }
};

int main()
{
//    string num = "1432219";
//    int k = 3;

//    string num = "10";
//    int k = 2;

//    string num = "10200";
//    int k = 1;

    string num = "1234567890";
    int k = 9;


    LT0402 lt;
    cout<<lt.lt0402a(num, k)<<endl;

    return 0;
}
