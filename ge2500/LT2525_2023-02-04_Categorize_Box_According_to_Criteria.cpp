
#include "../header/myheader.h"

class LT2525
{
public:





    //Runtime3 ms
    //    Beats
    //    43.57 %
    //    Memory6 MB
    //    Beats
    //    52.8 %

    // volume  Με»ύ‘£
    bool isBulky(int length, int width, int height, int mass)
    {
        return length >= 10000 || width >= 10000 || height >= 10000
            || (1LL * height * width * length) >= 1000000000LL;
    }

    bool isHeavy(int length, int width, int height, int mass)
    {
        return mass >= 100;
    }

    string lt2525a(int length, int width, int height, int mass)
    {
        bool b = isBulky(length, width, height, mass);
        bool h = isHeavy(length, width, height, mass);

        if (b)
        {
            if (h)
            {
                return "Both";
            }
            return "Bulky";
        }
        else
        {
            return h ? "Heavy" : "Neither";
        }
    }

};

int main()
{

    LT2525 lt;


    return 0;
}
