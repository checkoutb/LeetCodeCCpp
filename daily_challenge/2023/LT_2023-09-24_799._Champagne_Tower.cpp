
#include "../../header/myheader.h"

class LT
{
public:




//Runtime3 ms
//Beats
//87.91%
//Memory10.5 MB
//Beats
//68.14%
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<double> vd(1, poured);
        while (query_row > 0)
        {
            --query_row;
            vector<double> vd2(vd.size() + 1, 0.0);
            for (int i = 0; i < vd.size(); ++i)
            {
                if (vd[i] > 1.0)
                {
                    vd2[i] += (vd[i] - 1.0) / 2.0;
                    vd2[i + 1] += (vd[i] - 1.0) / 2.0;
                }
            }
            swap(vd, vd2);
        }
        return min(vd[query_glass], 1.0);
    }

};

int main()
{

    LT lt;


    return 0;
}
