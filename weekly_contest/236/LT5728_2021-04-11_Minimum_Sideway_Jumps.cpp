
#include "../../header/myheader.h"

class LT5728
{
public:




// AC
    int lt5728a(vector<int>& obstacles)
    {
        vector<int> vi(3, 0);
        vi[0] = 1;
        vi[2] = 1;
        for (int i = 1; i < obstacles.size(); ++i)
        {
            #ifdef __test
            cout<<" - - -- "<<i<<endl;
            showVectorInt(vi);
            #endif // __test
            if (obstacles[i] == 0)
            {
//                for (int j = 0; j < 3; ++j)
//                {
//                    if (vi[j] == INT_MAX)
//                        vi[j] = min() + 1;
//                }
//                if (vi[0] == INT_MAX)
//                    vi[0] = min(vi[1], vi[2]) + 1
                for (int j = 0; j < 3; ++j)
                {
                    if (vi[j] == INT_MAX)
                        vi[j] = *min_element(begin(vi), end(vi)) + 1;
                }
                continue;
            }
            int t2 = obstacles[i] - 1;
            if (vi[t2] == INT_MAX)
            {
//                cout<<vi[t2]<<" , "<<t2<<endl;
                continue;
            }
//            int t3 = obstacles[i - 1];
            for (int j = 0; j < 3; ++j)
            {
                if (j != t2)
                {
                    if (vi[j] != INT_MAX)
                    {
                        vi[j] = min(vi[j], vi[t2] + 1);
//                        cout<<"     "<<j<<", "<<vi[j]<<", "<<vi[t2]<<endl;
                    }
                    else
                    {
//                        cout<<"    ?"<<j<<endl;
                        --vi[j];
                    }
                }
            }
            vi[t2] = INT_MAX;
        }
        return *min_element(begin(vi), end(vi));
    }

};

int main()
{
//    myvi v = {0,1,2,3,0};
//    myvi v = {0,1,1,3,3,0};
    myvi v = {0,2,1,0,3,0};

    LT5728 lt;

    cout<<lt.lt5728a(v)<<endl;

    return 0;
}
