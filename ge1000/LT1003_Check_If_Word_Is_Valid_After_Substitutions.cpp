
#include "../header/myheader.h"

class LT1003
{
public:


// D D
// replace("abc", "")

//  for (auto i = S.find("abc"); i != string::npos; i = S.find("abc"))
//    S.erase(i, 3);
//  return S.empty();


//        vector<char> st;
//        for (auto c: s){
//            if ( c == 'c'){
//                int n = st.size();
//                if ( n < 2 || st[n-1] != 'b' || st[n-2] != 'a') return false;
//                st.pop_back(); st.pop_back();
//            }
//            else {
//                st.push_back(c);
//            }
//        }
//
//        return st.empty();
// 。。碰到c，就pop2个，这2个必然是b，a，如果不是，就false。


//Runtime: 324 ms, faster than 14.85% of C++ online submissions for Check If Word Is Valid After Substitutions.
//Memory Usage: 8.3 MB, less than 5.12% of C++ online submissions for Check If Word Is Valid After Substitutions.
// 感觉是 遍历，a.数量 >= b.数量 >= c.数量。。最终数量要相等
// no, aabbcc
// 肯定存在一个 substring 是 abc，并且 删除abc 后，肯定还会有一个abc.
    bool lt1003a(string s)
    {
//        int sz1 = s.size() + 1;
//        while (s.size() != sz1)
//        {
//            sz1 = s.size();
//            int idx = s.find("abc");
//            if ()
//        }

        int idx = 1;
        while ((idx = s.find("abc")) != std::string::npos)
        {
            s.erase(idx, 3);        // 应该能用这个取代find的。
        }
        return s.empty();
    }

};

int main()
{

    string s = "aabcabc";

    LT1003 lt;

    cout<<lt.lt1003a(s)<<endl;

    return 0;
}
