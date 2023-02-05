
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
    // 0->1 : 0|1=1, 0^1=1 , ��Ҫ��1�� �� 1 û���κα仯����������Ҹ�1 ���Ϳ��� ��� 0->1 ��ת����
    // 1->0 : 1^1=0, 1|1=1 , ��Ҫ��һ�� 1�� �� 1û���κα仯��
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
