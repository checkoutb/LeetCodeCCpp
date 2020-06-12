
#include "../header/myheader.h"

class LT0838
{
public:


// D D
//        d = 'L' + d + 'R';
//        string res = "";
//        for (int i = 0, j = 1; j < d.length(); ++j) {
//            if (d[j] == '.') continue;
//            int middle = j - i - 1;
//            if (i > 0) res += d[i];
//            if (d[i] == d[j]) res += string(middle, d[i]);
//            else if (d[i] == 'L' && d[j] == 'R') res += string(middle, '.');
//            else res += string(middle / 2, 'R') + string(middle % 2,'.') + string(middle / 2, 'L');
//            i = j;
//        }
//        return res;



//Runtime: 52 ms, faster than 63.45% of C++ online submissions for Push Dominoes.
//Memory Usage: 9.5 MB, less than 100.00% of C++ online submissions for Push Dominoes.
    string lt0838b(string dominoes)
    {
        int i = 0;
        int sz2 = dominoes.size();
        bool lastR = false;
        while (i < sz2)
        {
            if (dominoes[i] == 'L')
            {
                if (i > 0 && dominoes[i - 1] == '.' && !lastR)
                {
                    int j = i - 1;
                    while (j >= 0 && dominoes[j] == '.')
                    {
                        dominoes[j] = 'L';
                        j--;
                    }
                }
                lastR = false;
            }
            else if (dominoes[i] == 'R')
            {
                lastR = true;
                int j = i + 1;
                while (j < dominoes.size() && dominoes[j] == '.')
                {
                    j++;
                }
                if (j < dominoes.size())
                {
                    if (dominoes[j] == 'R')
                    {
                        for (int k = i + 1; k < j; k++)
                        {
                            dominoes[k] = 'R';
                        }
                    }
                    else
                    {
                        int k = j - 1;
                        i++;
                        while (i < k)
                        {
                            dominoes[i] = 'R';
                            dominoes[k] = 'L';
                            i++;
                            k--;
                        }
                    }
                }
                else
                {
                    while (i < dominoes.size())
                        dominoes[i++] = 'R';
                }
                i = j - 1;
            }
            i++;
        }
        return dominoes;
    }


// error
    string lt0838a(string dominoes)
    {
        int i = 0;
        for (; i < dominoes.size(); i++)
        {
            if (dominoes[i] == 'L')
            {
                if (dominoes[i] == 'L')
                {
                    for (int j = 0; j < i; j++)
                    {
                        dominoes[j] = 'L';
                    }
                }
            }
            else if (dominoes[i] == 'R')
            {
                break;
            }
        }
        for (; i < dominoes.size(); i++)
        {
            if (dominoes[i] == 'R')
            {
                int j = i + 1;
                while (j < dominoes.size() && dominoes[j] == '.')
                {
                    j++;
                }
                if (j < dominoes.size())
                {
                    if (dominoes[j] == 'R')
                    {
                        for (int k = i + 1; k < j; k++)
                        {
                            dominoes[k] = 'R';
                        }
                    }
                    else
                    {
                        int k = j - 1;
                        i++;
                        while (i < k)
                        {
                            dominoes[i] = 'R';
                            dominoes[k] = 'L';
                            i++;
                            k--;
                        }
                    }
                }
                else
                {
                    while (i < dominoes.size())
                        dominoes[i++] = 'R';
                }
                i = j - 1;
            }
        }
        return dominoes;
    }

};

int main()
{

//    string s = ".L.R...LR..L..";
    string s = "RR.L";
//    string s = ".L.R.";
//    string s = ".RR..";
//    string s = "L.LL......";
//    string s = "L.....RR.RL.....L.R.";


    LT0838 lt;

    cout<<lt.lt0838b(s)<<endl;

    return 0;
}
