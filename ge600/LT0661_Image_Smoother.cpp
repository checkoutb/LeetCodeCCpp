
#include "../header/myheader.h"

class LT0661
{
public:


// D D
//                for(int n=i-1; n<=i+1; n++)
//                {
//                    for(int m=j-1; m<=j+1; m++)
//                    {
//                        if(n>=0 && n<M.size() && m>=0 && m<M[0].size())
//                        {
//                            sum+=M[n][m];
//                            count++;
//                        }
//                    }
//                }
//                res[i][j]=sum/count;
//                count=0;
//                sum=0;




// vvd应该保存 sum，不需要除以2/3。。
// quan shi keng.
//Runtime: 108 ms, faster than 43.53% of C++ online submissions for Image Smoother.
//Memory Usage: 24.2 MB, less than 14.59% of C++ online submissions for Image Smoother.
    vector<vector<int>> imageSmoother(vector<vector<int>>& M)
    {
        vector<vector<double>> vvd(M.size(), vector<double>(M[0].size(), 0));
        for (int j = 0; j < M.size(); j++)
        {
            vector<int>& v = M[j];
            for (int i = 1; i < v.size() - 1; i++)
            {
                vvd[j][i] = ((double) (v[i-1] + v[i] + v[i+1])) / 3.0;
            }
            if (vvd[0].size() > 1)
            {
                vvd[j][0] = (v[0] + v[1]) / 2.0;
                vvd[j][v.size() - 1] = (v[v.size() - 1] + v[v.size() - 2]) / 2.0;
            }
            else
            {
                vvd[j][0] = v[0];
            }
        }
        #ifdef __test
        for (vector<double>& vd : vvd)
        {
            for (double d : vd)
            {
                cout<<d<<", ";
            }
            cout<<endl;
        }

        #endif // __test

        for (int i = 0; i < M[0].size(); i++)
        {
            if (M.size() > 1)
            {
                M[0][i] = int ((vvd[0][i] + vvd[1][i] + 0.001) / 2.0);
                M[M.size() - 1][i] = int ((vvd[M.size() - 1][i] + vvd[M.size() - 2][i] + 0.001) / 2.0);
            }
            else
            {
                M[0][i] = (int) (vvd[0][i] + 0.001);
            }
        }
        for (int i = 1; i < M.size() - 1; i++)
        {
            for (int j = 0; j < M[0].size(); j++)
            {
                M[i][j] = (int) ((vvd[i - 1][j] + vvd[i][j] + vvd[i + 1][j] + 0.001) / 3.0);
            }
        }
        return M;
    }

};

int main()
{

//    vector<vector<int>> vv = {{1,1,1},{1,0,1},{1,1,1}};
//    vector<vector<int>> vv = {{2,3}};
//    vector<vector<int>> vv = {{1}};

    vector<vector<int>> vv = {
    {6,64,94,3,37,67,35},
    {91,48,44,18,82,67,44},
    {19,63,38,36,84,18,5},
    {87,41,11,32,26,6,60},
    {68,9,99,70,29,66,94},
    {59,36,8,31,22,18,51},
    {64,66,20,66,9,48,15}};

    LT0661 lt;

    vector<vector<int>> vv2 = lt.imageSmoother(vv);

    for (vector<int>& v : vv2)
    {
        for_each(begin(v), end(v), fun_cout);
        cout<<endl;
    }

    return 0;
}
