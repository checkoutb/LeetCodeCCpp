
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //string st = s;
    //reverse(st.begin(), st.end());
    //if (st == s) {
    //    return 1;

    //return 2 - equal(s.begin(), s.end(), s.rbegin());



//Runtime: 4 ms, faster than 30.61 % of C++ online submissions for Remove Palindromic Subsequences.
//Memory Usage : 6 MB, less than 97.70 % of C++ online submissions for Remove Palindromic Subsequences.
    // ����ֻ��a,b������������
    // Ӧ�����2����  ��һ�θɵ����е�a�� Ȼ��ȫb���� ��Ϊȫa������ ����sz1��odd��even�����ǻ��ġ�
    // ���Ծ��� �ж� s �ǲ��ǻ��ģ� �ǻ��ģ��� return 1�� ���Ǿ� return 2...
    // ͦ���˵ġ�����
    int lta(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j)
        {
            if (s[i] != s[j])
                return 2;
        }
        return 1;
    }

};

int main()
{

    LT lt;


    return 0;
}
