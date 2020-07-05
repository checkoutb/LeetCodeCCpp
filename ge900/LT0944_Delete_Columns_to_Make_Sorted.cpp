
#include "../header/myheader.h"

class LT0944
{
public:






// 看details 的代码都一样啊，怎么我这就108了。。基本都是76-84的。
//Runtime: 108 ms, faster than 16.75% of C++ online submissions for Delete Columns to Make Sorted.
//Memory Usage: 12.2 MB, less than 81.82% of C++ online submissions for Delete Columns to Make Sorted.
    int lt0944a(vector<string>& A)
    {
        int sz1 = A.size();
        int sz2 = A[0].size();
        int ans = 0;
        for (int j = 0; j < sz2; j++)
        {
            for (int i = 1; i < sz1; i++)
            {
                if (A[i][j] < A[i - 1][j])
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }

};

int main()
{

//    vector<string> v = {"cba","daf","ghi"};
//    vector<string> v = {"a", "b"};
    vector<string> v = {"zyx","wvu","tsr"};

    LT0944 lt;

    cout<<lt.lt0944a(v)<<endl;

    return 0;
}
