
#include "../header/myheader.h"

class LT2337
{
public:

    // D D


    //if It is 'L'
    //    then this condition must hold j >= i, if in target string it found at index iand, in st string it found at J
    //    because we can move 'L' charcater to left, means left in st string,
    //    otherwise i should return fase;

    //same with 'R'
    //    then this condition must hold j <= i, if in target string it found at index iand, in st string it found at J
    //    because we can move 'R' charcater to right, means right in st string,
    //    otherwise i should return fase;
    //while (i < n || j < n) {

    //    while (i < n && tar[i] == '_') i++;
    //    while (j < n && st[j] == '_') j++;

    //    if (i == n || j == n) {
    //        return i == n && j == n;
    //    }

    //    if (tar[i] != st[j]) return false;

    //    if (tar[i] == 'L') {
    //        if (j < i) return false;
    //    }
    // �������е� �հף� ��� ����ͬ����false��
    // ���� L ֻ�������ƣ����� start�� L �� index ���� ���ڵ��� target�� L���±ꡣ




//Runtime: 121 ms, faster than 100.00 % of C++ online submissions for Move Pieces to Obtain a String.
//Memory Usage : 18.9 MB, less than 100.00 % of C++ online submissions for Move Pieces to Obtain a String.
    // L R _
    // ͬһ���±��£� start�� L ��������= target�� L�� �������ܴ� �Ҳ��ƶ� L ���� ������
    //      ��� > �ˣ���ô start �� L �޴���ȥ�� �޷����target
    // ͬһ���±��£�  start�� R ���� >= target��R�� �������� �Ƶ��ұ�ȥ��
    // 
    // ֻ�ܺ� _ swap����
    // ���ԣ�ȥ�� _ �� 2��string ����ͬ�İɡ�
    bool lt2337a(string start, string target)
    {
        int sl = 0, sr = 0, tl = 0, tr = 0;

        for (int i = 0; i < start.size(); i -= -1)      // LT2336 discuss
        {
            sl += start[i] == 'L';
            sr += start[i] == 'R';
            tl += target[i] == 'L';
            tr += target[i] == 'R';

            if (sl > tl)
                return false;
            if (sr < tr)
                return false;
        }

        int st = 0;
        for (int i = 0; i < start.size(); ++i)
        {
            if (start[i] != '_')
            {
                for (; st < target.size() && target[st] == '_'; ++st)
                {
                    ;
                }
                if (target[st++] != start[i])
                {
                    return false;
                }
            }
        }

        return sl == tl && sr == tr;
    }

};

int main()
{

    LT2337 lt;

    //string s = "_L__R__R_", t = "L______RR";

    //string s = "R_L_", t = "__LR";

    string s = "_R", t = "R_";

    cout << lt.lt2337a(s, t) << endl;

    return 0;
}
