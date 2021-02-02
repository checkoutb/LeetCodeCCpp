
#include "../header/myheader.h"

class LT0076
{
public:

// D D


//        while(eIndex < s.size()){
//            charMap[s[eIndex] - ' ']--;
//            if(charMap[s[eIndex] - ' '] > -1){
//                count++;
//                while(count == t.size()){
//                    if(eIndex - sIndex + 1 < minLength){
//                        minLength = (eIndex - sIndex + 1);
//                        subStr = s.substr(sIndex, minLength);
//                    }
//                    if(charMap[s[sIndex] - ' ']++ == 0)
//                        count--;
//                    sIndex++;
//                }
//            }
//            eIndex++;
//        }
// 直接对比，不需要 vector<pair<int, int>>


//        for(int i=0;i<s.size();i++){
//            hm[s[i]]--;
//            count-=hm[s[i]]>=0;
//            if(count == 0){
//                //cout << "here" << endl;
//                while(hm[s[start]] <0) {
//                    hm[s[start]]++;
//                    start++;
//                }
//                if(minval > i-start+1){
//                   minval=i-start+1;
//                   minstart=start;
//                  // cout << minval << "  " << minstart << endl;
//                }
//                hm[s[start]]++;
//                count++;
//                start++;
//            }
//        }


//        vector<int> map(128,0);
//        for(auto c: t) map[c]++;
//        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
//        while(end<s.size()){
//            if(map[s[end++]]-->0) counter--; //in t
//            while(counter==0){ //valid
//                if(end-begin<d)  d=end-(head=begin);
//                if(map[s[begin++]]++==0) counter++;  //make it invalid
//            }
//        }
//        return d==INT_MAX? "":s.substr(head, d);





//Runtime: 20 ms, faster than 63.60% of C++ online submissions for Minimum Window Substring.
//Memory Usage: 10.2 MB, less than 22.04% of C++ online submissions for Minimum Window Substring.
    string lt0076a(string s, string t)
    {
        int arr[123] = {0};
        int cntt = 0;
        for (char& ch : t)
        {
            arr[ch]++;
            if (arr[ch] == 1)
                cntt++;
        }
        int st = 0;
        int cnts = 0;
        vector<pair<int, int>> vp;
        for (int i = 0; i < s.size(); ++i)
        {
            char ch = s[i];
            arr[ch]--;
            if (arr[ch] == 0)
                cnts++;
            if (cnts == cntt)
            {
                for (; st < s.size(); ++st)
                {
                    char ch2 = s[st];
                    if (arr[ch2] == 0)
                    {
                        vp.push_back({st, i});
                        break;
                    }
                    arr[ch2]++;
                }
            }
        }
        if (vp.empty())
            return "";
        sort(begin(vp), end(vp), [](const pair<int, int>& p1, const pair<int, int>& p2){ return p1.second - p1.first < p2.second - p2.first; });
        return s.substr(vp[0].first, vp[0].second - vp[0].first + 1);
    }

};

int main()
{
//    string s{"ADOBECODEBANC"}, t{"ABC"};
//    string s{"a"}, t{"a"};
    string s{"cfabeca"}, t{"cae"};

    LT0076 lt;

    cout<<lt.lt0076a(s, t)<<endl;

    return 0;
}
