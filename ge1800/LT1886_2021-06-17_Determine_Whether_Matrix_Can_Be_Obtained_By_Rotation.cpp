
#include "../header/myheader.h"

class LT1886
{
public:


// D D

//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			if(mat[i][j]!=target[i][j]) c[0]=false;
//			if(mat[i][j]!=target[n-j-1][i]) c[1]=false;
//			if(mat[i][j]!=target[n-i-1][n-j-1]) c[2]=false;
//			if(mat[i][j]!=target[j][n-i-1]) c[3]=false;
//		}
//	}
//	return c[0]||c[1]||c[2]||c[3];


//bool findRotation(vector<vector<int>>& m, vector<vector<int>>& t) {
//    vector<int> mc(m.size()), mr(m.size()), tc(m.size()), tr(m.size());
//    for (int i = 0; i < m.size(); ++i)
//        for (int j = 0; j < m.size(); ++j) {
//            mc[i] += m[i][j];
//            mr[j] += m[i][j];
//            tc[i] += t[i][j];
//            tr[j] += t[i][j];
//        }
//    vector<int> rev_mc(rbegin(mc), rend(mc)), rev_mr(rbegin(mr), rend(mr));
//    return (mc == tc && mr == tr) || (rev_mc == tr && mr == tc)
//        || (rev_mc == tc && rev_mr == tr) || (mc == tr && rev_mr == tc);
//}




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Determine Whether Matrix Can Be Obtained By Rotation.
//Memory Usage: 11.4 MB, less than 14.67% of C++ online submissions for Determine Whether Matrix Can Be Obtained By Rotation.
// 90 顺时针
// 00 - 0,sz
// 01 - 1,sz
// 2,3  -
// lie -> as hang
// hang -> sz-hang as lie
// 本以为是只转90度， 结果example3是 转180度。  那么不转 就相等的话， 是true? ..... 是的。。
// 还有一种： 每个点，尝试旋转1,2,3次， 如果旋转x次后，相等,则map[x]++.  最终看 map中有没有一个key的value是sz1*sz1.  还可以减枝，如果有一个点旋转1次，不相等，其他点就不必测试旋转1次了。
    bool lt1886a(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        int sz1 = mat.size();
        for (int i = 0; i < 4; ++i)
        {
            for (int i = 0; i < sz1; ++i)
            {
                for (int j = 0; j < sz1; ++j)
                {
                    if (mat[i][j] != target[i][j])
                    {
                        goto AAA;
                    }
                }
            }
            return true;

            AAA:
            if (i != 3)
                rotatea1(mat);
            continue;
        }

        return false;
    }
    void rotatea1(vector<vector<int>>& mat)
    {
        int sz2 = mat.size();
        vector<vector<int>> vvi(sz2, vector<int>(sz2, 0));          // ... in-place is hard..
        for (int i = 0; i < sz2; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                vvi[j][sz2 - i - 1] = mat[i][j];
            }
        }

        swap(mat, vvi);

    }

};

int main()
{
//    myvvi vv = {{0,1},{1,0}};
//    myvvi vv2 = {{1,0},{0,1}};

    myvvi vv = {{0,0,0},{0,1,0},{1,1,1}};
    myvvi vv2 = {{1,1,1},{0,1,0},{0,0,0}};

    LT1886 lt;

    cout<<lt.lt1886a(vv, vv2)<<endl;

    return 0;
}
