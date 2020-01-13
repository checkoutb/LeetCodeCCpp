
#include "../header/myheader.h"

class LT0546
{
public:





// 9 / 60 ... tle...
    int ans = 0;
    int lt0546a(vector<int>& boxes)
    {
        vector<int> v1;
        vector<int> v2;
        int t1 = 1;
        for (int i = 1; i < boxes.size(); i++)
        {
            if (boxes[i] == boxes[i - 1])
            {
                t1++;
            }
            else
            {
                v1.push_back(t1);
                v2.push_back(boxes[i - 1]);
                t1 = 1;
            }
        }
        v1.push_back(t1);
        v2.push_back(boxes[boxes.size() - 1]);

        #ifdef __test
        for_each(v1.begin(), v1.end(), fun_cout);
        cout<<endl;
        for_each(v2.begin(), v2.end(), fun_cout);
        cout<<endl;
        #endif // __test

        dfsa1(v1, v2, boxes.size(), 0);

        return ans;
    }

    void dfsa1(vector<int>& v1, vector<int>& v2, int max2, int prod)
    {
        max2 = v1.size();
        if (max2 == 0)
            ans = std::max(ans, prod);

        int ans = 0;
        int t1 = 0;
        int t2 = 0;
        for (int i = 0; i < max2; i++)
        {
            vector<int> v11(v1);
            vector<int> v22(v2);
            t1 = v11[i];

            v11.erase(v11.begin() + i);
            v22.erase(v22.begin() + i);
            if (i > 0)
            {
                if (v22[i] == v22[i - 1])
                {
                    v11[i - 1] += v11[i];
                    v11.erase(v11.begin() + i);
                    v22.erase(v22.begin() + i);
                }
            }
            dfsa1(v11, v22, max2 - 1, prod + t1 * t1);
        }
    }

};

int main()
{
    vector<int> v = {1, 3, 2, 2, 2, 3, 4, 3, 1};

    LT0546 lt;

    cout<<lt.lt0546a(v)<<endl;

    return 0;
}
