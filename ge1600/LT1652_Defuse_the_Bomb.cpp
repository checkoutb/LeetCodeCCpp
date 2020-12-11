
#include "../header/myheader.h"

class LT1652
{
public:

// D D

//        if (k < 0) {//If k < 0, the starting point will be end of the array.
//            k = -k;
//            start = code.length - k;
//            end = code.length - 1;
//        }
//        for (int i = start; i <= end; i++) sum += code[i];
//        //Scan through the code array as i moving to the right, update the window sum.
//        for (int i = 0; i < code.length; i++) {
//            res[i] = sum;
//            sum -= code[(start++) % code.length];
//            sum += code[(++end) % code.length];
//        }




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Defuse the Bomb.
//Memory Usage: 8.5 MB, less than 86.84% of C++ online submissions for Defuse the Bomb.
    vector<int> lt1652a(vector<int>& code, int k)
    {
        if (k == 0)
        {
            std::fill(begin(code), end(code), 0);
            return code;
        }
        vector<int> ans(code.size());
        int sz1 = code.size();
        if (k > 0)
        {
            int t2 = 0;
            for (int i = 1; i <= k; ++i)
            {
                t2 += code[i];
            }
            for (int i = 0; i < code.size(); ++i)
            {
                ans[i] = t2;
                t2 -= code[(i + 1) % sz1];
                t2 += code[(i + k + 1) % sz1];
//                cout<<t2<<", "<<code[i]<<", "<<code[(i+k+1)%sz1]<<", "<<i<<", "<<(i+k+1)%sz1<<", "<<i<<", "<<k<<", "<<endl;
            }
        }
        else
        {
            int t2 = 0;
            k = -k;
            for (int i = 0; i < k; ++i)
            {
                t2 += code[(sz1 - i - 1) % sz1];
            }
            for (int i = 0; i < code.size(); ++i)
            {
                ans[i] = t2;
                t2 += code[i];
                t2 -= code[(sz1 - k + i) % sz1];
            }
        }
        return ans;
    }

};

int main()
{
    myvi v = {5,7,1,4};
    int k{3};

//    myvi v = {2,4,9,3};
//    int k{-2};

    LT1652 lt;

    vector<int> vi = lt.lt1652a(v,k);
    showVectorInt(vi);

    return 0;
}
