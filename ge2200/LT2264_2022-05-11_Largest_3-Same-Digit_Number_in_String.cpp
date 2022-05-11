
#include "../header/myheader.h"

class LT2264
{
public:

// D D

//        for(int i=0;i<num.size()-2;i++){
//            int j=i+2;
//            if(num[i]==num[j] && num[i]==num[i+1]){
//                string curr=num.substr(i, 3);
//                if(ans.size()==0 || ans<curr){
//                    ans=curr;
//                }
//            }
//        }

//        for(int i = 0; i < num.size()-2; ++i)
//            if(num[i] == num[i+1] and num[i+1] == num[i+2])
//                if(ans < num.substr(i, 3))
//                    ans = num.substr(i,3);


//        for(int i = 9; i >= 0; i--){
//            string s = string(3, i+'0');
//            if(num.find(s) != string::npos)
//                return s;
//        }


//        for(int i=2;i<num.size();i++){
//            if(num[i-2]==num[i-1] && num[i-1]==num[i])
//                ans = max(ans,num[i]);
//        }
//        if(ans==0) return "";
//        else return string(3,ans);


//    char res = 0;
//    for(int i = 2; i < num.size(); ++i)
//        if (num[i] == num[i - 1] && num[i] == num[i - 2])
//            res = max(res, num[i]);
//    return res == 0 ? "" : string(3, res);


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Largest 3-Same-Digit Number in String.
//Memory Usage: 6.4 MB, less than 79.82% of C++ online submissions for Largest 3-Same-Digit Number in String.
    string lt2264a(string num)
    {
        string ans = "";
        int val = -1;
        for (int i = 2; i < num.size(); )
        {
            if (num[i] != num[i - 1])
            {
                i += 2;
                continue;
            }
            if (num[i] == num[i - 2])
            {
                if ((num[i] - '0') > val)
                {
                    ans = num.substr(i - 2, 3);
                    val = num[i] - '0';
                }
            }
            ++i;
        }
        return ans;
    }

};

int main()
{

    LT2264 lt;


    return 0;
}
