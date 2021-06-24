
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        vector<vector<int>> res(numRows);
//        for(int i=0;i<numRows;i++){
//            res[i].resize(i+1);
//            res[i][0]= res[i][i]=1;
//
//            for(int j=1;j<i;j++){
//                res[i][j]= res[i-1][j-1] + res[i-1][j];
//            }
//        }



// 图裂了。。。。不过我知道他想说什么。
    vector<vector<int>> lta(int numRows)
    {
        vector<vector<int>> ans;
//        vector<int> vi(1,1)
        ans.emplace_back(vector<int>(1,1));
        for (int i = 1; i < numRows; ++i)
        {
            vector<int> vi(i + 1);
            vi[0] = vi[vi.size() - 1] = 1;
            for (int j = 1; j < ans[i - 1].size(); ++j)
            {
                vi[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            ans.push_back(vi);
        }
        return ans;
    }

};

int main()
{

//    int n = 1;
    int n = 6;

    LT lt;

    myvvi vv = lt.lta(n);

    for (myvi& v : vv)
        showVectorInt(v);

    return 0;
}
