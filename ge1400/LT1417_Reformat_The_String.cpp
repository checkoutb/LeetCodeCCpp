
#include "../header/myheader.h"

class LT1417
{
public:


// D D

// std::islower, isdigit, labs,
// auto fn = (lettercnt > sz-lettercnt) ? isletter : isnum;
//
//        while (i < sz || j < sz) {
//            for (; i < sz; ) {
//                if (fn(s[i])) {
//                    res.push_back(s[i++]);
//                    break;
//                } else {
//                    i++;
//                }
//            }
//
//            for (; j < sz; ) {
//                if (!fn(s[j])) {


//return {};



//        string a="",d="";
//        // split string into alpha string and digit strings
//        for(auto x:s)
//            isalpha(x)?a.push_back(x):d.push_back(x);
//
//            while(i<s.size()){
//                if(alpha){
//                    s[i++]=a[j++];
//                }
//                else{
//                    s[i++]=d[k++];
//                }
//                alpha=!alpha;
//            }




//Runtime: 8 ms, faster than 61.38% of C++ online submissions for Reformat The String.
//Memory Usage: 7.4 MB, less than 89.56% of C++ online submissions for Reformat The String.
    string lt1417a(string s)
    {
        int alpha = 0;
        int numeric = 0;
        for (char ch : s)
            if (ch < 'a')
                numeric++;
            else
                alpha++;
        if (abs(numeric - alpha) > 1)
            return "";
        string ans;
        int idxnum = 0;
        int idxalp = 0;
        int sz1 = s.size();
        if (numeric > alpha)
            while (idxnum < sz1)
            {
                if (s[idxnum] < 'a')
                {
                    ans += s[idxnum];
                    idxnum++;
                    break;
                }
                idxnum++;
            }
        while (ans.size() < sz1)
        {
            while (idxalp < sz1)
            {
                if (s[idxalp] >= 'a')
                {
                    ans += s[idxalp];
                    idxalp++;
                    break;
                }
                idxalp++;
            }
            while (idxnum < sz1)
            {
                if (s[idxnum] < 'a')
                {
                    ans += s[idxnum];
                    idxnum++;
                    break;
                }
                idxnum++;
            }
        }
        return ans;
    }

};

int main()
{

    string s = "covid2019";

    LT1417 lt;

    cout<<lt.lt1417a(s)<<endl;

    return 0;
}
