
#include "../header/myheader.h"

class LT1111
{
public:

    // D D







//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Maximum Nesting Depth of Two Valid Parentheses Strings.
//Memory Usage : 7.2 MB, less than 99.24 % of C++ online submissions for Maximum Nesting Depth of Two Valid Parentheses Strings.
    // ���� ��Ŀ�ˡ�����
    // ���� 2�� sub-sequence��  ��2�� �� max(depth, depth) ��С��   sub-sequence.
    // ���� Ƕ�׵� () һ��� A һ��� B  �Ϳ����ˡ�
    vector<int> lt1111a(string seq)
    {
        int sz1 = seq.size();
        vector<int> vi(sz1);
        bool isb = false;
        for (int i = 0; i < sz1; ++i)
        {
            if (seq[i] == '(')
            {
                vi[i] = isb;
                isb = !isb;
            }
            else
            {
                isb = !isb;
                vi[i] = isb;
            }
        }

        return vi;
    }

};

int main()
{

    LT1111 lt;

    //string s = "(()())";
    string s = "()(())()";

    myvi v = lt.lt1111a(s);

    showVectorInt(v);

    return 0;
}
