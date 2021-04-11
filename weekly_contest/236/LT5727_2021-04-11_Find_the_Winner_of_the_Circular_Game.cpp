
#include "../../header/myheader.h"

class LT5727
{
public:



// AC
// 约瑟夫环，但。。
    int lt5727a(int n, int k)
    {
        vector<int> vi(n, 0);
        for (int i = 0; i < n; ++i)
            vi[i] = i + 1;

        int st = 0;
        while (vi.size() > 1)
        {
            int t2 = (k - 1) % vi.size();
            st = (st + t2) % vi.size();
            vi.erase(vi.begin() + st);
            if (st == vi.size())
                st = 0;
        }
        return vi[0];
    }

};

int main()
{
//    int n = 5;
//    int k = 2;

    int n = 6;
    int k = 5;

    LT5727 lt;

    cout<<lt.lt5727a(n, k)<<endl;

    return 0;
}
