
#include "../header/myheader.h"

class LT2086
{
public:

// D D

//    public int minimumBuckets(String s) {
//        return (s.equals("H") || s.startsWith("HH") || s.endsWith("HH") || s.contains("HHH")) ?
//               -1 : s.replace("H.H", "  ").length() - s.replace("H", "").length();
//    }


//Runtime: 20 ms, faster than 89.55% of C++ online submissions for Minimum Number of Buckets Required to Collect Rainwater from Houses.
//Memory Usage: 10.4 MB, less than 61.42% of C++ online submissions for Minimum Number of Buckets Required to Collect Rainwater from Houses.
// 就是看 H 后面有没有位置，后面没有位置 就放前面，前面没有 就 -1了。  然后 放好以后 就把 关联的 H 跳过。 放后面的话可以直接多跳一个..2ge
    int lt2086a(string street)
    {
        int ans = 0;
        for (int i = 0; i < street.size(); ++i)
        {
            if (street[i] == 'H')
            {
                if ((i + 1) < street.size() && street[i + 1] == '.')        // 放后面
                {
                    ans++;
                    i += 2;
                }
                else
                {
                    if ((i - 1) >= 0 && street[i - 1] == '.')
                    {
                        ans++;
                    }
                    else
                    {
                        return -1;
                    }
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT2086 lt;

//    string s = "H..H";
//    string s = "H.H";
    string s = ".H.H.H.H";

    cout<<lt.lt2086a(s)<<endl;

    return 0;
}
