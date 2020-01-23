
#include "../header/myheader.h"

class LT0537
{
public:

//
//        int[] coef = Stream.of((a+b).split("\\+|i")).mapToInt(Integer::parseInt).toArray();
//        return (coef[0]*coef[2] - coef[1]*coef[3]) + "+" + (coef[1]*coef[2] + coef[0]*coef[3]) + "i";


//        int ra, ia, rb, ib;
//        char buff;
//        stringstream aa(a), bb(b), ans;
//        aa >> ra >> buff >> ia >> buff;
//        bb >> rb >> buff >> ib >> buff;
//        ans << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
//        return ans.str();



//Accepted	0 ms	8.5 MB	cpp
    string lt0537a(string a, string b)
    {
        int i = a.find("+");
        int a1 = std::stoi(a.substr(0, i));
        int a2 = std::stoi(a.substr(i + 1, a.size() - i - 2));

        i = b.find("+");
        int b1 = std::stoi(b.substr(0, i));
        int b2 = std::stoi(b.substr(i + 1, b.size() - i - 2));          // -1 也能用，估计最后的i被舍弃了。或者读到非数字就返回。

        #ifdef __test
        cout<<i<<", "<<a1<<", "<<a2<<", "<<b1<<", "<<b2<<endl;
        cout<<b.substr(0, i)<<", "<<b.substr(i + 1, b.size() - i - 2)<<endl;
        #endif // __test

        int r1 = a1 * b1 - a2 * b2;
        int r2 = a1 * b2 + a2 * b1;

        return to_string(r1) + "+" + to_string(r2) + "i";
    }
};

int main()
{

    string asd = "-234q34";
    cout<<". "<<std::stoi(asd)<<endl;       // -234。。。如果是-q234q23 的话，报错。 q123q3报错。。至少有个数字，才能提前返回。没有数字就报错。

    string a = "1+-1i";
    string b = "1+-1i";

    LT0537 lt;

    cout<<lt.lt0537a(a, b)<<endl;

    return 0;

}
