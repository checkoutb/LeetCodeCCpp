
#include "../header/myheader.h"

class LT2259
{
public:

// D D

//        vector<int> idx;
//        for(int i =0; i<number.size(); i++){
//            if(number[i] == digit) idx.push_back(i);
//        }
//
//        string ans = "";
//        for(int i : idx){
//            string tmp = number;
//            tmp.erase(tmp.begin() + i);
//            ans = max(ans, tmp);
//        }
// brute-force


//    for (int i = 0; i < n.size() - 1; ++i)
//        if (n[i] == digit && n[i + 1] > digit)
//            return n.substr(0, i) + n.substr(i + 1);
//    int last_d = n.rfind(digit);
//    return n.substr(0, last_d) + n.substr(last_d + 1);


//        for(int i=0; i<number.size(); i++){
//            if(number[i] == digit){
//                string temp = number.substr(0, i) + number.substr(i+1);
//                res = max(res, temp);
//            }
//        }


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Digit From Number to Maximize Result.
//Memory Usage: 6.1 MB, less than 79.64% of C++ online submissions for Remove Digit From Number to Maximize Result.
// 54325
// 56725
// 如果下一个数 比digit 大，就移除这个。  没有就最后一个
    string lt2259a(string number, char digit)
    {
        int lst = -1;
        for (int i = 0; i < number.size() - 1; i++)
        {
            if (number[i] == digit)
            {
                lst = i;
                if (number[i + 1] > digit)
                {
                    return number.erase(i, 1);
//                    return number;
                }
            }
        }
        if (number[number.size() - 1] == digit)
        {
            lst = number.size() - 1;
        }
        return number.erase(lst, 1);
    }

};

int main()
{

    LT2259 lt;

//    string s = "123";
//    char c = '3';

//    string s = "53215";
    string s = "56785";
    char c = '5';

    cout<<lt.lt2259a(s, c)<<endl;

    return 0;
}
