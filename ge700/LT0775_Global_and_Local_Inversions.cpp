
#include "../header/myheader.h"

class LT0775
{
public:


// ...D D
//	for (int i = 0; i < A.size(); ++i) {
//            if (abs(A[i] - i) > 1) return false;
//        }
//	return true;
// a local must be a grobal, a grobal maybe is a local...
//

//        int cmax = 0, n = A.size();
//        for (int i = 0; i < n - 2; ++i) {
//            cmax = max(cmax, A[i]);
//            if (cmax > A[i + 2]) return false;
//        }
//discuss: we can not find A[i] > A[j] with i+2<=j. In other words, max(A[i]) < A[i+2]



//Runtime: 336 ms, faster than 5.02% of C++ online submissions for Global and Local Inversions.
//Memory Usage: 35.8 MB, less than 14.29% of C++ online submissions for Global and Local Inversions.
// kao，global是随即2个位置之间 低位值>高位值， local是和下标+1比较。 md。。
    bool lt0775b(vector<int>& A)
    {
        if (A.size() <= 1)
            return true;
        int global = 0, local = A[0] > A[1];
        for (int i = 1; i < A.size(); i++)
        {
            if (i != A.size() - 1)
                local += (A[i] > A[i + 1]);
            vector<int>::iterator it = std::lower_bound(A.begin(), A.begin() + i, A[i]);
            global += i - (it - A.begin());
            int temp2 = A[i];
            int temp3 = (it - A.begin());
            for (int j = i - 1; j >= temp3; j--)
            {
                A[j + 1] = A[j];
            }
            A[temp3] = temp2;
        }

        #ifdef __test
        cout<<global<<", "<<local<<endl;;
        for_each(A.begin(), A.end(), fun_cout);
        cout<<endl;
        #endif // __test

        return global == local;
    }



// error ...  真得靠 插入排序。一次插入排序就能知道多少比它大，多少比它小，就知道多少global,local.. 而且插入排序能用lower_bound。。 但是估计list不能用，毕竟不能fase random access.. list是double link, forward_list是single link
// for { for { }}
// 0..n-1...知道下标和值，能计算出后续的吧。 插入排序？
    bool lt0775a(vector<int>& A)
    {
        vector<int> v1(A.begin(), A.end());
        vector<int> v2(A.size(), -1);
        vector<int> v3(A.size(), -1);
        vector<int> vi2(A.size(), -1);
        vector<int> vi3(A.size(), -1);

        #ifdef __test
        for_each(v1.begin(), v1.end(), fun_cout);
        cout<<endl;
        #endif // __test

        int global = 0;
        int local = 0;
        for (int i = 0; i < A.size(); i++)
        {
            int val = v1[i];
            vi2[val] = i;
            for (int j = val - 1; j >= 0; j--)
            {
                if (v2[j] != -1)
                {
                    v2[val] = v2[j] + (vi2[val] - vi2[j]);
                }
            }
            if (v2[val] == -1)
            {
                v2[val] = 0;
            }
            global += v2[val];
        }

        for (int i = A.size() - 1; i >= 0; i--)
        {
            int val = v1[i];
            vi3[val] = i;
            for (int j = val + 1; j < A.size(); j++)
            {
                if (v3[j] != -1)
                    v3[val] = v3[j] + (vi3[j] - vi3[val] - 1);
            }
            if (v3[val] == -1)
                v3[val] = 0;

            local += v3[val];
        }

        #ifdef __test
        cout<<global<<", "<<local<<endl;

        for_each(v2.begin(), v2.end(), fun_cout);
        cout<<endl;
        for_each(vi2.begin(), vi2.end(), fun_cout);
        cout<<endl;
        for_each(v3.begin(), v3.end(), fun_cout);
        cout<<endl;
        for_each(vi3.begin(), vi3.end(), fun_cout);
        cout<<endl;
        #endif // __test
        return local == global;
    }

};

int main()
{

    vector<int> v = {1,2,0};

    LT0775 lt;

    cout<<lt.lt0775b(v)<<endl;

    return 0;
}
