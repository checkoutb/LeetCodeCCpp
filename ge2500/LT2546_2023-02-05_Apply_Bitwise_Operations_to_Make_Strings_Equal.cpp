
#include "../header/myheader.h"

class LT2546
{
public:

    // D D

    // return (s.find('1') != string::npos) == (t.find('1') != string::npos);

    // return (count(begin(s), end(s), '1') > 0) == (count(begin(t), end(t), '1') > 0);


    //Runtime37 ms
    //    Beats
    //    58.63 %
    //    Memory13.2 MB
    //    Beats
    //    40.75 %
    // 0->1 : 0|1=1, 0^1=1 , 需要借1， 且 1 没有任何变化。所以随便找个1 ，就可以 完成 0->1 的转换。
    // 1->0 : 1^1=0, 1|1=1 , 需要借一个 1， 且 1没有任何变化。
    bool lt2546a(string s, string target)
    {
        int sz1 = s.size();
        int cnt1 = 0;
        int cnt2 = 0;

        for (int i = 0; i < sz1; ++i)
        {
            cnt1 += s[i] == '1';
            cnt2 += target[i] == '1';
        }

        return (cnt1 == 0 && cnt2 == 0) || (cnt2 != 0 && cnt1 != 0);
    }

};

int main()
{

    LT2546 lt;


    return 0;
}
